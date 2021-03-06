#include "FirstIncludes.h"
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <math.h>
#include "MemoryDebug.h"
using namespace std;


#include "OSservices.h"
using namespace KKB;


#include "KKBaseTypes.h"
#include "MLClass.h"
using namespace KKMLL;


#include "ClassSummary.h"


ClassSummary::ClassSummary ():
  mlClass        (NULL),
  lloydsEntries  (NULL),
  realDataU2Stat (0.0f),
  z_Score        (0.0f)

{
}




ClassSummary::ClassSummary (MLClassPtr          _mlClass,
                            LLoydsEntryListPtr  _lloydsEntries,
                            float               _realDataU2Stat,
                            float               _z_Score
                            ):

  mlClass     (_mlClass),
  lloydsEntries  (_lloydsEntries),
  realDataU2Stat (_realDataU2Stat),
  z_Score        (_z_Score)

{
}



ClassSummary::~ClassSummary ()
{
  delete  lloydsEntries;
  lloydsEntries = NULL;
}





const KKStr&  ClassSummary::ClassName ()  const
{
  if  (!mlClass)
  {
    return  KKStr::EmptyStr ();
  }

  return  mlClass->Name ();
}  /* ClassName */





kkuint32 ClassSummary::NumOfLLoydsEntries ()  const
{
  if  (lloydsEntries)
    return kkuint32 (lloydsEntries->size ());
  else
    return 0;
}



kkuint32  ClassSummary::NumOfLLoydsBins () const /**< Returns the largest number of lloydsBins in 'lloydsEntries' */
{
  if  (!lloydsEntries)
    return 0;

  kkuint32  numOfLLoydsBins = 0;

  LLoydsEntryList::const_iterator  idx;
  for  (idx = lloydsEntries->begin ();  idx != lloydsEntries->end ();  idx++)
  {
    const LLoydsEntryPtr  le = *idx;
    numOfLLoydsBins = Max (numOfLLoydsBins, le->NumOfLLoydsBins ());
  }

  return  numOfLLoydsBins;
}  /* NumOfLLoydsBins */



LLoydsEntryPtr  ClassSummary::LLoydsEntryByIndex (kkuint32 idx)
{
  if  (!lloydsEntries)
    return NULL;

  if  (idx >= kkuint32 (lloydsEntries->QueueSize ()))
    return NULL;

  return  lloydsEntries->IdxToPtr (idx);
}



LLoydsEntryPtr  ClassSummary::LLoydsEntryByBinSize (kkint32 binSize)
{
  if  (!lloydsEntries)
    return NULL;

  return  lloydsEntries->LLoydsEntryByBinSize (binSize);
}  /* LLoydsEntryByBinSize */





kkint32  ClassSummary::LLoydsBinSize (kkuint32 lloydsEntryIDX) const
{
  if  (!lloydsEntries)
    return NULL;

  if  (lloydsEntryIDX >= kkuint32 (lloydsEntries->QueueSize ()))
    return NULL;

  return  lloydsEntries->IdxToPtr (lloydsEntryIDX)->LLoydsBinSize ();
}




ClassSummaryList::ClassSummaryList (RunLog&  _log):
  KKQueue<ClassSummary>  (true),
  log                    (_log)
{}



kkuint32  ClassSummaryList::NumOfLLoydsBins ()  const
{
  kkuint32  numOfBins = 0;
  ClassSummaryList::const_iterator  idx;

  for  (idx = begin ();  idx != end ();  idx++)
  {
    ClassSummaryPtr  cs = *idx;
    numOfBins = Max (numOfBins, cs->NumOfLLoydsBins ());
  }
  return  numOfBins;
}


void  ClassSummaryList::SaveLLoydsBinsData (const KKStr&  fileName,
                                            const KKStr&  srcDirName,
                                            kkint32       lastScanLine,
                                            kkint32         baseLLoydsBinSize
                                           )
{
  ofstream o (fileName.Str (), ios::out);
  if  (!o.is_open ())
  {
    log.Level (-1) << endl << endl << endl
                   << "ClassSummaryList::SaveLLoydsBinsData       *** Invalid File[" << fileName << "]."  << endl
                   << endl;
    return;
  }
  
  ClassSummaryList::const_iterator  idx;

  o << "//  LLoyds Bins  Data"                              << endl
    << "//"                                                 << endl
    << "// Run Date      [" << osGetLocalDateTime () << "]"   << endl
    << "// SrcDir        [" << srcDirName            << "]"   << endl
    << "// LastScanLin   [" << lastScanLine          << "]"   << endl
    << "// Base Bin Size [" << baseLLoydsBinSize     << "]"   << endl
    << "//"                                                 << endl;

  o << "BinSize" << "\t" << "BinNum" << "\t" << "ScanLines";
  kkuint32  numOfBins = NumOfLLoydsBins ();
  for  (idx = begin ();  idx != end ();  idx++)
  {
    ClassSummaryPtr  cs = *idx;
    o << "\t" << cs->ClassName ();
  }
  o << endl;

  VectorInt  binSizes = LLoydsBinSizes ();
  size_t  binSizeIndex = 0;
  for  (binSizeIndex = 0;  binSizeIndex < binSizes.size ();  binSizeIndex++)
  {
    kkint32  binSize = binSizes[binSizeIndex];

    kkint32 startScanLinNum = 0;
    kkint32 endScanLineNum  = startScanLinNum + binSize - 1;

    kkuint32  binNum = 0;
    for  (binNum = 0;  binNum < numOfBins;  binNum++)
    {
      o << binSize << "\t" << binNum <<"\t" << startScanLinNum << "-" << endScanLineNum;

      for  (idx = begin ();  idx != end ();  idx++)
      {
        kkint32  lloydsBin = 0;
        ClassSummaryPtr  cs = *idx;
        LLoydsEntryPtr  lloydsEntry = cs->LLoydsEntryByBinSize (binSize);
        if  (lloydsEntry != NULL)
          lloydsBin = lloydsEntry->LLoydsBin (binNum);
        o << "\t" << lloydsBin;
      }
      startScanLinNum += binSize;
      endScanLineNum  += binSize;
      o << endl;
    }

  }

  o.close ();
}  /* SaveLLoydsBinsData */




/**
 *@brief  Computes spatial index as described in paper.
 *@details
 * The calculations come from the following paper.
 *
 * "Small-scale spatial distribution of the euphausiid Euphausia pacifica and overlap with planktivorous fishes"
 * by Alex De Robertis, Scripps Institution Of Oceanography, La Jolla Ca 92093�0208,  alex.derobertis@noaa.gov
 * http://plankt.oxfordjournals.org/cgi/reprint/24/11/1207
 */
float  ClassSummaryList::SpatialOverlapIndex (kkint32          binSize,
                                              ClassSummaryPtr  c1,
                                              ClassSummaryPtr  c2
                                             )  const
{
  LLoydsEntryPtr  class1LLoydsEntry = c1->LLoydsEntryByBinSize (binSize);
  LLoydsEntryPtr  class2LLoydsEntry = c2->LLoydsEntryByBinSize (binSize);

  if  ((class1LLoydsEntry == NULL)  ||  (class2LLoydsEntry == NULL))
    return 0.0f;

  kkuint32 N = Min (class1LLoydsEntry->NumOfLLoydsBins (), class2LLoydsEntry->NumOfLLoydsBins ());

  kkuint32  x;

  kkint32  Xtotal  = 0;
  kkint32  Ytotal  = 0;
  kkint32  XYtotal = 0;
  for  (x = 0;  x < N;  x++)
  {
    XYtotal += class1LLoydsEntry->LLoydsBin (x) * class2LLoydsEntry->LLoydsBin (x);
    Xtotal  += class1LLoydsEntry->LLoydsBin (x);
    Ytotal  += class2LLoydsEntry->LLoydsBin (x);
  }

  double  xMean = double (Xtotal) / N;
  double  yMean = double (Ytotal) / N;


  float  spatialIndex = float ((double (XYtotal) /  double (Xtotal)) / yMean);

  return  spatialIndex;  
}  /* SpatialOverlapIndex */





void  ClassSummaryList::SpatialOverlapReport (ostream&  o)  const
{
  KKStr classTitle1, classTitle2;

  MLClassListPtr  classes = GetListOfClasses ();
  classes->ExtractTwoTitleLines (classTitle1, classTitle2);


  VectorInt binSizes = LLoydsBinSizes ();
  for  (kkuint32 binSizeIdx = 0;  binSizeIdx < kkuint32 (binSizes.size ());  binSizeIdx++)
  {
    kkint32  binSize = binSizes[binSizeIdx];

 
    o << endl 
      << endl 
      << endl
      << "Spatial Overlap Indexes for BinSize[" << binSize << "]" << endl
      << endl
      << "Class" << "\t" << classTitle1 << endl
      << "Name"  << "\t" << classTitle2 << endl;


    ClassSummaryList::const_iterator  idx;

    for  (idx = begin ();  idx != end ();  idx++)
    {
      ClassSummaryPtr  cs1 = *idx;

      o << cs1->ClassName ();

      ClassSummaryList::const_iterator  idx2;
      for  (idx2 = begin ();  idx2 != end ();  idx2++)
      {
        ClassSummaryPtr  cs2 = *idx2;
        if  (idx == idx2)
          o << "\t" << "-";
        else
        {
          double  spatialIndex = SpatialOverlapIndex (binSize, cs1, cs2);
          o << "\t" << spatialIndex;
        }
      }

      o << endl;
    }
  }

  delete  classes;
}  /* SpatialOverlapReport */



VectorInt  ClassSummaryList::LLoydsBinSizes ()  const
{
  VectorInt  binSizes;

  ClassSummaryList::const_iterator  idx;
  for  (idx = begin ();  idx != end ();  idx++)
  {
    const ClassSummaryPtr  cs = *idx;
    for  (kkuint32 lloydsEntryIdx = 0;  lloydsEntryIdx < cs->NumOfLLoydsEntries ();  lloydsEntryIdx++)
    {
      LLoydsEntryPtr  lloydsEntry = cs->LLoydsEntryByIndex (lloydsEntryIdx);
      if  (lloydsEntry)
      {
        kkuint32 zed = 0;
        kkint32 binSize = lloydsEntry->LLoydsBinSize ();
        // if 'binSize' not in 'binSizes'  then add
        for  (zed = 0;  zed < kkuint32 (binSizes.size ());  zed++)
        {
          if  (binSizes[zed] == binSize)
            break;
        }
        if  (zed >= binSizes.size ())
          binSizes.push_back (binSize);
      }
    }
  }


  sort (binSizes.begin (), binSizes.end ());

  return  binSizes;
}  /* LLoydsBinSizes */





MLClassListPtr  ClassSummaryList::GetListOfClasses ()  const
{
  MLClassListPtr  classes = new MLClassList ();
  ClassSummaryList::const_iterator  idx;
  for  (idx = begin ();  idx != end ();  idx++)
    classes->AddMLClass ((*idx)->MLClass ());

  return  classes;
}  /* GetListOfClasses */






void  ClassSummaryList::SummaryReport (ostream&  r)  const
{
  kkuint32  binSizeIDX = 0;


  r << "Statistic Summary by Class" << endl
    << endl;

  VectorInt  binSizes = LLoydsBinSizes ();
  r << ""           << "\t"  << ""       << "\t" << ""          << "\t" << "LLoydsIndex's" << endl;
  r << "ClassName"  << "\t"  << "U2Stat" << "\t" << "Z-Score";

  for  (binSizeIDX = 0;  binSizeIDX < binSizes.size ();  binSizeIDX++)
    r << "\t" << binSizes[binSizeIDX];
  r << endl;

  const_iterator  idx;

  for  (idx = begin ();  idx != end ();  idx++)
  {
    ClassSummaryPtr  cs = *idx;
    r << cs->ClassName () << "\t"
      << cs->U2Stat    () << "\t"
      << cs->ZScore    ();

    for  (binSizeIDX = 0;  binSizeIDX < binSizes.size ();  binSizeIDX++)
    {
      kkint32 binSize = binSizes[binSizeIDX];

      LLoydsEntryPtr  lloydsEntry = cs->LLoydsEntryByBinSize (binSize);
      if  (lloydsEntry == NULL)
        r << "\t" << "-";
      else
        r << "\t" << lloydsEntry->LLoydsIndex ();
    }
    r << endl;
  }
}  /* SummaryReport */
