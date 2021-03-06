#ifndef  __GRADE_CLASSIFICATION_H__
#define  __GRADE_CLASSIFICATION_H__

#include "HTMLReport.h"
using namespace  KKB;


#include "ConfusionMatrix2.h"
#include "DataBase.h"
#include "MLClass.h"
#include "TrainingConfiguration2.h"
using  namespace  KKMLL;


#include "ImageFeatures.h"
#include "PicesApplication.h"
#include "PicesTrainingConfiguration.h"
using  namespace  MLL;




class  GradeClassification: public PicesApplication
{
public:
  typedef  KKB::uint  uint;

  GradeClassification ();

  ~GradeClassification ();

  virtual
  void  InitalizeApplication (kkint32 argc,
                              char**  argv
                             );  
  
  void  Grade();

  virtual const char* ApplicationName () const  {return  "GradeClassification";}

  void  DisplayCommandLineParameters ();

  virtual bool ProcessCmdLineParameter (const KKStr&  parmSwitch, 
                                        const KKStr&  parmValue
                                       );

private:

  void       GradeSourceImagesAgainstGroundTruth ();

  void       GradeExamplesAgainstGroundTruth (FeatureVectorListPtr  examplesToGrade,
                                              FeatureVectorListPtr  groundTruth
                                             );

  void       GradeUsingTrainingConfiguration ();

 
  void       ReportResults ();


  void       ValidateThatBothListsHaveSameEntries (FeatureVectorList&  groundTruth, 
                                                   FeatureVectorList&  examplesToGrade,
                                                   bool&               theyAreTheSame
                                                  );

  bool                       cancelFlag;


  TrainingConfiguration2Ptr  config;
  KKStr                      configFileName;

  DataBasePtr                db;

  FileDescPtr                fileDesc;

  KKStr                      sourceRootDirPath;
  KKStr                      groundTruthDirName;
  ImageFeaturesListPtr       groundTruth;

  MLClassPtr                 mlClass;
  MLClassListPtr             mlClasses;

  ostream*                   report;
  ofstream*                  reportFile;
  HTMLReportPtr              html;
  KKStr                      reportFileName;
  KKStr                      htmlFileName;



  struct  SummaryRec
  {
    ConfusionMatrix2Ptr  confussionMatrix;
    KKStr                name;
    uint                 predLevel;
    uint                 tranLevel;

    SummaryRec (uint                  _tranLevel,
                uint                  _predLevel,
                ConfusionMatrix2Ptr  _confussionMatrix
                ):
     confussionMatrix (_confussionMatrix),
     predLevel        (_predLevel),
     tranLevel        (_tranLevel)
     {
       name = "CM" + StrFormatInt (tranLevel, "00") + "-" + StrFormatInt (predLevel, "00");
     }
  };

  typedef  vector<SummaryRec> SummaryList;
  SummaryList  resultsSummary;
};

#endif