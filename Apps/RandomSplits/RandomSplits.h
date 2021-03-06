#if  !defined(_RANDOMSPLITS_)
#define  _RANDOMSPLITS_


#include "FeatureVector.h"
#include "Orderings.h"
#include "PicesApplication.h"
#include "KKJobManager.h"


using namespace  KKB;

class RandomSplits:  public PicesApplication
{
public:
  typedef  RandomSplits*  RandomSplitsPtr;

  RandomSplits ();

  RandomSplits (RunLog&  log);

  ~RandomSplits ();

  virtual
  void  InitalizeApplication (kkint32 argc,
                              char**  argv
                             );

	virtual const char* ApplicationName ()  const  {return  "RandomSplits";}

  void  Run ();


private:
  // Will be classed by base class  'Application'  
  bool  ProcessCmdLineParameter (const KKStr&  parmSwitch, 
                                 const KKStr&  parmValue
                                );

  void  DisplayCommandLineParameters ();


  KKStr              dataFileName;
  FeatureFileIOPtr   format;
  int                numSplits;
  int                numFolds;
  bool               restart;
  float              splitFraction;
};

typedef  RandomSplits::RandomSplitsPtr  RandomSplitsPtr;

#define  _RandomSplitsDefined_

#endif


