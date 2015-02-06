#include "FirstIncludes.h"
#include <algorithm>
#include <iostream>
#include <ostream>
#include <stdio.h>
#include "MemoryDebug.h"
using namespace std;


#include "BasicTypes.h"
#include "KKException.h"
using namespace  KKU;


#include "ImageSizeDistribution.h"
using namespace  MLL;



ImageSizeDistributionRow::ImageSizeDistributionRow (float     _depth,
                                                    kkuint32  _numSizeBuckets,
                                                    kkuint32  _imageCount,
                                                    kkuint32  _totalPixels,
                                                    kkuint32  _totalFilledArea
                                                   ):
   depth           (_depth),
   distribution    (_numSizeBuckets, 0),
   imageCount      (_imageCount),
   totalPixels     (_totalPixels),
   totalFilledArea (_totalFilledArea)
{
}




ImageSizeDistributionRow::ImageSizeDistributionRow (const ImageSizeDistributionRow&  row):
   depth            (row.depth),
   distribution     (row.distribution),
   imageCount       (row.imageCount),
   totalPixels      (row.totalPixels),
   totalFilledArea  (row.totalFilledArea)
{
  
}




void  ImageSizeDistributionRow::AddImageCountPixelCount (kkuint32  _imageCount,
                                                         kkuint32  _pixelCount,
                                                         kkuint32  _filledArea
                                                        )
{
  imageCount       += _imageCount;
  totalPixels      += _pixelCount;
  totalFilledArea  += _filledArea;
}  /* AddImageCountPixelCount */




void  ImageSizeDistributionRow::AddData (kkuint32  _sizeIdx,
                                         kkuint32  _count
                                        )
{
  while  (_sizeIdx >= distribution.size ())
    distribution.push_back (0);
  distribution[_sizeIdx] += _count;
}  /* AddData */



void  ImageSizeDistributionRow::AddIn (const ImageSizeDistributionRow&  right)
{
  kkint32  xL = distribution.size ();
  kkint32  xR = right.distribution.size ();

  kkint32  xM = Min (xL, xR);

  for  (kkint32  x = 0;  x < xM;  ++x)
    distribution[x] += right.distribution[x];

  imageCount      += right.imageCount;
  totalPixels     += right.totalPixels;
  totalFilledArea += right.totalFilledArea;
}  /* AddIn */




ImageSizeDistribution::ImageSizeDistribution (float               _depthBinSize,
                                              float               _initialValue,
                                              float               _growtRate,
                                              float               _endValue,
                                              const VectorFloat&  _sizeStartValues,
                                              const VectorFloat&  _sizeEndValues,
                                              RunLog&             _runLog
                                             ):

    depthBinSize       (_depthBinSize),
    initialValue       (_initialValue),
    growthRate         (_growtRate),
    endValue           (_endValue),
    numSizeBuckets     (0),
    sizeStartValues    (_sizeStartValues),
    sizeEndValues      (_sizeEndValues),
    depthDistributions (),
    allDepths          (NULL)
{
  numSizeBuckets = sizeStartValues.size ();
  if  (sizeStartValues.size () != sizeEndValues.size ())
  {
    KKStr  errMsg = "Size of 'sizeStartValues' and 'sizeEndValues'  don't match.";
    _runLog.Level (-1) << endl << "ImageSizeDistribution   ***ERROR***   " << errMsg << endl << endl;
    throw KKException (errMsg);
  }
  allDepths = new ImageSizeDistributionRow (-1.0f, numSizeBuckets, 0, 0, 0);
}


ImageSizeDistribution::~ImageSizeDistribution ()
{
  for  (kkuint32  x = 0;  x < depthDistributions.size ();  ++x)
  {
    delete  depthDistributions[x];
    depthDistributions[x] = NULL;
  }
}



/**
 *@brief  Returns pointer to ImageSizeDistributionRow  that is index 'depthBinIdx'.
 *@details  Caller will not own the entry;  so do not delete it!
 */
ImageSizeDistributionRowPtr  ImageSizeDistribution::GetDepthBin (kkuint32  depthBinIdx)
{
  if  (depthBinIdx >= depthDistributions.size ())
    return NULL;
  else
    return depthDistributions[depthBinIdx];
}






void  ImageSizeDistribution::PopulateDistributions (kkuint32  depthIdx)
{
  while  (depthDistributions.size () <= depthIdx)
  {
    kkuint32  idx = depthDistributions.size ();
    depthDistributions.push_back (new ImageSizeDistributionRow (idx * depthBinSize, numSizeBuckets, 0, 0, 0));
  }
}  /* PopulateDistributions */




void  ImageSizeDistribution::DefineRow (float     _depth,
                                        kkuint32  _imageCount,
                                        kkuint32  _totalPixelCount,
                                        kkuint32  _totalFilledArea
                                       )
{
  kkuint32  depthIdx = (int)(_depth / depthBinSize);
  PopulateDistributions (depthIdx);
  ImageSizeDistributionRowPtr  row = depthDistributions[depthIdx];
  row->ImageCount      (_imageCount);
  row->TotalPixels     (_totalPixelCount);
  row->TotalFilledArea (_totalFilledArea);
  allDepths->AddImageCountPixelCount (_imageCount, _totalPixelCount, _totalFilledArea);
}  /* DefineRow */





 
void  ImageSizeDistribution::AddData  (float     _depth,
                                       kkuint32  _sizeBucketIdx,
                                       kkuint32  _count
                                      )
{
  kkuint32  depthIdx = (kkuint32)(_depth / depthBinSize);
  PopulateDistributions (depthIdx);
  ImageSizeDistributionRowPtr  row = depthDistributions[depthIdx];
  row->AddData (_sizeBucketIdx, _count);
  allDepths->AddData (_sizeBucketIdx, _count);
}
                    


void  ImageSizeDistribution::AddIn (const ImageSizeDistribution&  right,
                                    RunLog&                       log
                                   )
{
  if  (numSizeBuckets != right.numSizeBuckets)
  {
    KKStr  errMsg (128);
    errMsg << "ImageSizeDistribution::AddIn   ***ERROR***  SizeBuckets Difference   left[" << numSizeBuckets << "]  right[" << right.numSizeBuckets << "].";
    log.Level (-1) << endl << errMsg << endl << endl;
    throw KKException (errMsg);
  }

  if  (this->numSizeBuckets != right.numSizeBuckets)
  {
    KKStr  errMsg (128);
    errMsg << "ImageSizeDistribution::AddIn   ***ERROR***  SizeBuckets Difference   left[" << numSizeBuckets << "]  right[" << right.numSizeBuckets << "].";
    log.Level (-1) << endl << errMsg << endl << endl;
    throw KKException (errMsg);
  }

  if  (depthDistributions.size () < right.depthDistributions.size ())
    PopulateDistributions (right.depthDistributions.size ());


  for  (kkuint32 x = 0;  x < right.depthDistributions.size ();  ++x)
  {
    depthDistributions[x]->AddIn (*(right.depthDistributions[x]));
    allDepths->AddIn (*(right.depthDistributions[x]));
  }
}  /* AddIn */



kkint32  ImageSizeDistribution::IdentifySizeBucket (float  size)
{
  if  (sizeEndValues.size () < 1)
    return -1;
  if  ((size < sizeStartValues[0])  ||  (size > sizeEndValues[sizeEndValues.size () - 1]))
    return -1;

  kkuint32  left = 0;
  kkuint32  right = sizeStartValues.size () - 1;
  kkuint32  middle = 0;
  while  (left <= right)
  {
    middle = (left + right) / 2;
    if  (size < sizeStartValues[middle])
      right = middle - 1;
    else if   (size >= sizeEndValues[middle])
      left = middle + 1;

    else
      return  (kkint32)middle;
  }

  return -1;
}  /* IdentifySizeBucket */
