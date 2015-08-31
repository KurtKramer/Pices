#ifndef  _SIZEDISTRIBUTION_
#define  _SIZEDISTRIBUTION_

//***************************************************************************
//*                                                                         *
//*-------------------------------------------------------------------------*
//*  History                                                                *
//*                                                                         *
//*  Prog       Date      Description                                       *
//*  ------- -----------  ------------------------------------------------- *
//*  Kurt    Oct-19-2002  Increment Will now take MLClasses instead of   *
//*                       numbers.  We will also make a unique copy of      *
//*                       mlClassList.  This way we will not have to     *
//*                       worry abount the numbering in the classList       *
//*                       behind our back.                                  * 
//***************************************************************************
//* 

//#define  BucketCount  50
//#define  BucketSize   100


#include "RunLog.h"


#include "MLClass.h"
#include "FeatureVector.h"
using  namespace  KKMLL;


class  ClassTotals;
typedef  ClassTotals*  ClassTotalsPtr;

class  ClassTotalsList;
typedef  ClassTotalsList*  ClassTotalsListPtr;


namespace  MLL
{
  class  SizeDistribution
  {
  public:
    SizeDistribution (kkint32  _bucketCount,
                      kkint32  _bucketSize,
                      RunLog&  _log
                      );
  
    ~SizeDistribution ();


    void     Increment (MLClassPtr       mlClass,
                        kkint32             size
                        );


    void     PrintFormatedDistributionMatrix (ostream&  _outFile)  const;


    void     PrintCSVDistributionMatrix (ostream&  _outFile)  const;


    void     PrintTabDelDistributionMatrix (ostream&  _outFile)  const;


    void     PrintByClassCollumns (ostream&      o,
                                    VectorUlong*  scanLinesPerMeter 
                                  )  const;


  private:
    MLClassListPtr   BuildMLClassList ()  const;

    void  PrintCSVHeader      (ostream&  o)  const;
    void  PrintFormatedHeader (ostream&  o)  const;
    void  PrintTabDelHeader   (ostream&  o)  const;


    class  ClassTotals;
    class  ClassTotalsList;

    typedef  ClassTotalsList*  ClassTotalsListPtr;



    kkint32             bucketCount;
    kkint32             bucketSize;
    RunLog&             log;
    ClassTotalsListPtr  totals;
  };  /* SizeDistribution */

  typedef  SizeDistribution*  SizeDistributionPtr;

}  /* namespace  MLL */

#endif
