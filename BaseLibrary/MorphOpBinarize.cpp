/* MorphOpBinarize.cpp -- Morphological operator used to Binarize image.
 * Copyright (C) 1994-2014 Kurt Kramer
 * For conditions of distribution and use, see copyright notice in KKB.h
 */

#include "FirstIncludes.h"
#include <stdlib.h>
#include <iostream>
#include <map>
#include <vector>

#include "MemoryDebug.h"
using namespace std;

#include "MorphOp.h"
#include "MorphOpBinarize.h"
#include "Raster.h"
using namespace KKU;



MorphOpBinarize::MorphOpBinarize (kkuint16  _pixelValueMin,
                                  kkuint16  _pixelValueMax
                                 ):
  MorphOp (),
  pixelValueMin (_pixelValueMin),
  pixelValueMax (_pixelValueMax)
{
}

    
    
MorphOpBinarize::~MorphOpBinarize ()
{
}



kkint32  MorphOpBinarize::MemoryConsumedEstimated ()
{
  return  sizeof (*this);
}



bool  MorphOpBinarize::Fit (kkint32  row,
                            kkint32  col
                           )  const
{

  if  ((row < 0)  || (row >= srcHeight))
    return false;

  if  ((col < 0)  || (col >= srcWidth))
    return false;

  return   ((srcGreen[row][col] >= pixelValueMin)  &&  (srcGreen[row][col] <= pixelValueMin));
}  /* Fit */



RasterPtr   MorphOpBinarize::PerformOperation (RasterConstPtr  _image)
{
  SetSrcRaster (_image);

  kkint32  r = 0;
  kkint32  c = 0;

  kkint32  binarizedForegroundPixelCount = 0;

  RasterPtr   binarizedRaster = new Raster (srcRaster->Height (), srcRaster->Width ());

  uchar*      srcRow     = NULL;
  uchar**     destGreen  = binarizedRaster->Green ();
  uchar*      destRow    = NULL;

  uchar       backgroundPixelValue = srcRaster->BackgroundPixelValue ();

  for  (r = 0;  r < srcHeight;  r++)
  {
    destRow = destGreen[r];
    srcRow  = srcGreen[r];

    for  (c = 0; c  < srcWidth;  c++)
    {
      uchar  srcCh = srcRow[c];
      if  ((srcCh >= pixelValueMin)  &&  (srcCh <= pixelValueMax))
      {
        destRow[c] = srcCh;
        ++binarizedForegroundPixelCount;
      }
      else
      {
        destRow[c] = backgroundPixelValue;
      }
    }  /* for (c) */
  }  /* for (r) */

  binarizedRaster->ForegroundPixelCount (binarizedForegroundPixelCount);

  return  binarizedRaster;
}  /* PerformOperation */




