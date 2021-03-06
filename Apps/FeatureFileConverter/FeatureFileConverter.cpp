#include "FirstIncludes.h"

#include <stdlib.h>
#include <stdio.h>
#include <memory>
#include <math.h>
#include <time.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>


#include  "MemoryDebug.h"

using namespace std;


#include "KKBaseTypes.h"
#include "KKException.h"
#include "OSservices.h"
#include "KKStr.h"
#include "XmlStream.h"
using namespace  KKB;

#include "FeatureEncoder2.h"
#include "FeatureFileIO.h"
#include "FeatureFileIOPices.h"
#include "FeatureFileIOC45.h"
#include "FeatureVector.h"
#include "MLClass.h"
#include "ImageFeatures.h"
#include "ModelParamKnn.h"
#include "NormalizationParms.h"
using namespace  MLL;

#include  "FeatureFileConverter.h"

// -s C:\TrainingApp\ClassifiedImages\hrs020701 -r NeighborReport.txt


/******************************************************************************
 * command line parameters that have been used for testing purposes
 ******************************************************************************/

// -s "C:\TrainingApp\ClassifiedImages" -r "report.txt"


// 2005-06-03
// -src C:\TrainingApp\ClassifiedImages\HRS030208b  -Report TestTeport.txt  -random

// -src K:\Plankton\Papers\BitReduction\WEB_Data\anonymous-msweb.data -sff DstWeb  -dest K:\Plankton\Papers\BitReduction\WEB_Data\anonymous-msweb_raw.data -dff raw

// 2005-12-29
// For purposes of the Bit reduction paper, converting Web Data set to C45 format with attribute '1008' used as Class label.
// K:\Plankton\Papers\BitReduction\WEB_Data
// -src anonymous-msweb.test -sff DstWeb  -dest anonymous-msweb_Test-C45.data -dff c45 -STATS -Report anonymous-msweb_Test-C45.txt

// K:\Plankton\Papers\BitReduction\Phoneme
// -src phoneme.data -sff C45  -dest  phoneme_sparse.data -dff sparse  -stats -report phoneme_sparse.txt

// F:\Users\kkramer\GradSchool\Plankton\Papers\BitReduction\WEB_Data
// -src anonymous-msweb.data -sff dstweb -dest anonymous-msweb_sparse.data -dff sparse -stats -report anonymous-msweb_sparse.txt

// -src K:\v1\Plankton\ActiveLearning\Results\2004_Sep_Expirements\ActiveLearning_MasterTestImages.data  -sff raw  -dest ActiveLearning_MasterTestImages.data -dff raw -report ActiveLearning_MasterTestImages_raw.txt


// 2006-01-26     Convert Feature Files used for JMLR paper to c45 & ARFF formats
// K:\v1\Plankton\ActiveLearning\Results\2004_Sep_Expirements
// -src ActiveLearning_MasterTestImages.data -sff Raw  -Dest K:\public.html\sipper\papers\JMLR\ActiveLearning_MasterTestImages_arff.data -dff arff

// 2006-01-26     Convert Feature Files used for JMLR paper to c45 & ARFF formats
// K:\public.html\sipper\papers\JMLR
// -src ActiveLearning_ValidationImages.data  -sff raw  -Dest ActiveLearning_ValidationImages_c45.data  -dff c45
// -src ActiveLearning_ValidationImages.data  -sff raw  -Dest ActiveLearning_ValidationImages_17_c45.data  -dff c45  -FEATURES=1,8,9,18,20,22,24,28,29,32,34,39,40,41,42,43,46

//  K:\public.html\sipper\papers\planktonVIM
// -src TEST_OCT_24.data -sff raw  -dest TEST_OCT_24_c45.data -dff c45

// K:\Plankton\Papers\BitReduction\DataSets\Plankton
// -src ActiveLearning_MasterTestImages.data -sff raw  -dest PlanctionTrain_17.data -dff raw -FEATURES 1,8,9,18,20,22,24,28,29,32,34,39,40,41,42,43,46
// -src ActiveLearning_ValidationImages.data -sff raw  -dest PlanctionTest_17.data -dff raw -FEATURES 1,8,9,18,20,22,24,28,29,32,34,39,40,41,42,43,46

// C:\Temp\NearstNeighbor
// -src CpCoral20060310C_01.data  -sff raw  -dest CpCoral20060310C01.data -dff raw

// -src iris.data -sff uci  -dest iris.sparse  -dff sparse
// -src anonymous-msweb_Data-C45.data  -sff c45  -dest anonymous-msweb_Data.sparse -dff sparse  -ec  -Report anonymous-msweb_Data_Report.txt
// -src anonymous-msweb_Test-C45.data  -sff c45  -dest anonymous-msweb_Test.sparse -dff sparse  -ec  -Report anonymous-msweb_Test_Report.txt

// C:\bigpine\Plankton\Papers\BitReduction\DataSets\Adult
// -src adult.data  -sff c45  -dest adult_data.sparse -dff sparse  -ec -ef  -Report adult_data_Report.txt -Norm  adult.NormParms
// -src adult.test  -sff c45  -dest adult_test.sparse -dff sparse  -ec -ef  -Report adult_test_Report.txt -Norm  adult.NormParms

// C:\bigpine\Plankton\Papers\BitReduction\DataSets\ForestCover
// -src CovType_TwoClass.data  -sff c45  -dest CovType_TwoClass_data.sparse -dff sparse  -ec -ef scale  -Report CovType_TwoClass_data_Report.txt  -Norm  CovType_TwoClass.NormParms
// -src CovType_TwoClass.test  -sff c45  -dest CovType_TwoClass_test.sparse -dff sparse  -ec -ef scale  -Report CovType_TwoClass_test_Report.txt  -Norm  CovType_TwoClass.NormParms

// C:\bigpine\Plankton\Papers\BinaryFeatureSelection\Experiments\Plankton9Classes
// -src NineClasses_TestData.data  -sff raw  -dest  NineClasses_TestData_c45.data -dff c45

// D:\Users\kkramer\GradSchool\SipperProject\Papers\BinaryFeatureSelection\Experiments\MNIST
// -src MNIST_TEST_10000.data -sff  Pices  -dest MNIST_TEST_10000_C45.data -dff C45

FeatureFileConverter::FeatureFileConverter ():
  PicesApplication  (),

  cancelFlag        (false),
  data              (NULL),
  destFileFormat    (FeatureFileIOPices::Driver ()),
  destFileName      (),
  destFileDesc      (NULL),
  encodeFeatureData (false),
  encodingMethod    (ModelParam::EncodingMethodType::NoEncoding),
  enumerateClasses  (false),
  features          (NULL),
  normalizeData     (false),
  nornParmsFileName (),
  srcFileDesc       (NULL),
  mlClasses      (),
  report            (NULL),
  reportFile        (NULL),
  srcFileName       (),
  srcFileFormat     (FeatureFileIOPices::Driver ()),
  statistics        (true)

{
}






/******************************************************************************
 * Destructor
 ******************************************************************************/
FeatureFileConverter::~FeatureFileConverter ()
{
  if  (reportFile)
  {
     reportFile->close ();
	 delete  reportFile;
  }

  delete  data;
}




void  FeatureFileConverter::InitalizeApplication (kkint32 argc,
                                                  char**  argv
                                                 )
{
  PicesApplication::InitalizeApplication (argc, argv);
	if  (Abort ())
	{
		DisplayCommandLineParameters ();
		return;
	}

  if  (srcFileName.Empty ())
  {
    Abort (true);
    log.Level (-1) << endl
       << "FeatureFileConverter::InitalizeApplication   *** ERROR ***  There was not source file specified." << endl
       << endl;

    DisplayCommandLineParameters ();
    return;
  }


  if  (reportFileName.Empty ())
	{
		reportFile = NULL;
		report = &cout;
	}
	else
	{
		reportFile = new ofstream (reportFileName.Str ());
		report = reportFile;
	}


  if  (normalizeData)
  {
    if  (nornParmsFileName.Empty ())
    {
      nornParmsFileName = osRemoveExtension (srcFileName) + "." + "NormParms";
      if  (osFileExists (nornParmsFileName))
      {
        log.Level (-1) << endl
          << "FeatureFileConverter::InitalizeApplication    *** ERROR ***"
          << endl
          << "         Normalization Parameters File[" << nornParmsFileName << "]  Already exists." << endl
          << endl;
        Abort (true);
        return;
      }
    }
  }

  bool  successful;
  bool  changesMade = false;

  data = srcFileFormat->LoadFeatureFile 
         (srcFileName, 
          mlClasses,
          -1,          // Max number to load,  -1 means load all.
          cancelFlag,
          successful,
          changesMade,
          log
         );

  if  (!data  ||  !successful)
  {
    log.Level (-1) << endl
                   << endl
                   << "Error loading source file[" << srcFileName << "]" << endl
                   << endl;
    Abort (true);
    return;
  }

  destFileDesc = srcFileDesc = data->FileDesc ();

  if  (featureStr.Empty ())
  {
    features = new FeatureNumList (data->AllFeatures ());
  }
  else
  {
    bool  validFeatures = true;
    features = new FeatureNumList (featureStr, validFeatures);
    if  (!validFeatures)
    {
      log.Level (-1) << endl
                     << endl
                     << "Invalud feature string specified [" << featureStr << "]" << endl
                     << endl;
      Abort (true);
      return;
    }
  }

  if  (destFileName.Empty ())
  {
    destFileName = osRemoveExtension (srcFileName) + "_" + destFileFormat->DriverName () + ".data";
  }

  KKStr  encodeMethodStr = "No";
  if  (encodeFeatureData)
    encodeMethodStr = ModelParam::EncodingMethodToStr (encodingMethod);

  PicesApplication::PrintStandardHeaderInfo (*report);
  *report << endl;
  *report << "------------------------------------------------------------------------"  << endl;
  *report << "Source File Name    [" << srcFileName                            << "]."    << endl;
  *report << "Source File Format  [" << srcFileFormat->DriverName ()           << "]."    << endl;
  *report << "Dest File Name      [" << destFileName                           << "]."    << endl;
  *report << "Dest File Format    [" << destFileFormat->DriverName ()          << "]."    << endl;
  *report << "Report File Name    [" << reportFileName                         << "]."    << endl;
  *report << "FeaturesStr         [" << featureStr                             << "]."    << endl;
  *report << "Features            [" << features->ToString ()                  << "]."    << endl;
  *report << "Statistics          [" << (statistics ? "Yes" : "No")            << "]."    << endl;
  *report << "Enumerate Classes   [" << (enumerateClasses ? "Yes" : "No")      << "]."    << endl;
  *report << "Encode Feature Data [" << encodeMethodStr                        << "]."    << endl;
  *report << "Normalize Data      [" << (normalizeData ? "Yes" : "No")         << "]."    << endl;

  if  (normalizeData)
  {
    bool  alreadyExists = osFileExists (nornParmsFileName);
    *report << "Norm Parms File Name[" << nornParmsFileName << "] Already Exists["  << (alreadyExists ? "Yes" : "No")  << "]."    << endl;
  }

  *report << "------------------------------------------------------------------------"  << endl;
  *report << endl;
}  /* InitalizeApplication */




/******************************************************************************
 * ProcessCmdLineParamters
 * DESC: Extracts parameters from the command line
 ******************************************************************************/
bool  FeatureFileConverter::ProcessCmdLineParameter (const KKStr&  parmSwitch, 
                                                     const KKStr&  parmValue
                                                    )
{
  KKStr  parmValueUpper (parmValue);
  parmValueUpper.Upper ();

  bool  validParm = true;

  if  ((parmValueUpper == "-DEST")         ||  
       (parmValueUpper == "-D")            ||  
       (parmValueUpper == "-DESTFILE")     ||  
       (parmValueUpper == "-DF")           ||
       (parmValueUpper == "-DESTFILENAME") ||
       (parmValueUpper == "-DFN")    
      )
    destFileName = parmValue;


  else if  ((parmValueUpper == "-OUTFORMAT")      ||
            (parmValueUpper == "-OF")             ||
            (parmValueUpper == "-OUTFILEFORMAT")  ||
            (parmValueUpper == "-OFF")            ||
            (parmValueUpper == "-DESTFILEFORMAT") ||
            (parmValueUpper == "-DESTFORMAT")     ||
            (parmValueUpper == "-DFF")
           )
  {
    destFileFormat = FeatureFileIO::FileFormatFromStr (parmValue, 
                                                       false,      // Don't care if valid read format
                                                       true        // must be valid write format
                                                      );
    if  (destFileFormat == NULL)
    {
      log.Level (-1) << endl
                     << endl
                     << "Invalid Write File Format Specified[" << parmValue << endl
                     << endl
                     << "Valid Formats are <" << FeatureFileIO::FileFormatsWrittenOptionsStr () << ">" << endl
                     << endl;
      Abort (true);
      validParm = false;
    }
  }

  
  else if  ((parmValueUpper == "-ENCODEFEATUREDATA")  ||
            (parmValueUpper == "-ENCODEFEATURES")     ||
            (parmValueUpper == "-EF")
           )
  {
    encodingMethod = ModelParam::EncodingMethodFromStr (parmValue);
    if  (encodingMethod !=  ModelParam::EncodingMethodType::Null)
    {
      encodeFeatureData = true;
    }

    else
    {
      if  ((parmValueUpper == "NO")   || 
           (parmValueUpper == "OFF")  ||
           (parmValueUpper == "N") 
          )
        encodeFeatureData = false;
      else
      {
        encodingMethod = ModelParam::EncodingMethodType::Binary;
        encodeFeatureData = true;
      }
    }
  }

  else if  ((parmValueUpper == "-ENUMERATECLASSES")  ||
            (parmValueUpper == "-ENUMERATECLASS")    ||
            (parmValueUpper == "-EC")
           )
  {
    if  ((parmValueUpper == "NO")   || 
         (parmValueUpper == "OFF")  ||
         (parmValueUpper == "N") 
        )
      enumerateClasses = false;
    else
      enumerateClasses = true;
  }

  else if  (parmValueUpper == "-FEATURES")
  {
    featureStr = parmValue;
  }


  else if  ((parmValueUpper == "-IF")           ||
            (parmValueUpper == "-INPUTFORMAT")  ||
            (parmValueUpper == "-IFF")          ||
            (parmValueUpper == "-INFILEFORMAT") ||
            (parmValueUpper == "-SFF")          ||
            (parmValueUpper == "-SrcFileFormat")
           )
  {
    srcFileFormat = FeatureFileIO::FileFormatFromStr (parmValue, 
                                                      true,      // Valid Read Format
                                                      false      // Don't care if valid write format
                                                     );
    if  (srcFileFormat == NULL)
    {
      log.Level (-1) << endl
                     << endl
                     << "Invalid Source File Format Specified[" << parmValue << endl
                     << endl
                     << "Valid Formats are <" << FeatureFileIO::FileFormatsReadOptionsStr () << ">" << endl
                     << endl;
      Abort (true);
      validParm = false;
    }
  }


  else if  ((parmValueUpper == "-NORM")  ||  (parmValueUpper == "-NORMALIZE"))
  {
    normalizeData = true;
    if  (!parmValue.Empty ())
      nornParmsFileName = parmValue;
  }


  else if  ((parmValueUpper == "-R")  ||  (parmValueUpper == "-REPORT"))
		reportFileName = parmValue;

 
  else if  ((parmValueUpper == "-S")             ||
            (parmValueUpper == "-SRC")           ||
            (parmValueUpper == "-SF")            ||
            (parmValueUpper == "-SOURCFILE")     ||
            (parmValueUpper == "-SFN")           ||
            (parmValueUpper == "-SRCFILENAME")   ||
            (parmValueUpper == "-SOURCFILENAME")
           )
    srcFileName = parmValue;


  else if  ((parmValueUpper == "-STAT")          ||
            (parmValueUpper == "-STATS")         ||
            (parmValueUpper == "-STATISTICS")
           )
    statistics = true;

  else
  {
    validParm = PicesApplication::ProcessCmdLineParameter (parmSwitch, parmValue);
  }

	return  validParm;
}  /* ProcessCmdLineParameter */



// -sff c45 -srcFileName E:\Pices\Reports\FeatureData\AllValidatedDataNorm.data  -dff Sparse -DestFileName E:\Pices\Reports\FeatureData\AllValidatedDataNormSparse.data

/******************************************************************************
 * DisplayCommandLineParameters()
 * DESC: Displays a help message to the user
 ******************************************************************************/
void   FeatureFileConverter::DisplayCommandLineParameters ()
{
  cout << "FeatureFileConverter"                                                                      << endl
       << "       -SrcFileName      <Source File Name>"                                               << endl
       << "       -DestFileName     <Destination File Name>  Optional"                                << endl
       << "       -SrcFileFormat    <" << FeatureFileIO::FileFormatsReadOptionsStr ()    << ">   Defaults to 'Pices'"  << endl
       << "       -DestFileFormat   <" << FeatureFileIO::FileFormatsWrittenOptionsStr () << ">   Defaults to 'Pices'"  << endl
       << "       -Report           <Report file name>   Defaults to 'cout'"                          << endl
       << "       -STATistics       Print out feature statistics"                                     << endl
       << "       -Features         <Specific Features to extract>    Defaults to 'All'"              << endl
       << "       -EncodeFeatures   <'Yes' | 'No'>  Defaults to 'No'"                                 << endl
       << "       -EnumerateClasses <'Yes' | 'No'>  Defaults to 'No'"                                 << endl
       << "       -Normalize        <Parameter File Name>   Where to store/get parameters."           << endl
       << endl
       << endl
       << "ex:  FeatureFileConverter  -SFN Test.data  -DFN Test_out.data  -sff Raw  -dff c45"         << endl 
       << endl
       << "             Convert Pices format data in file 'Test.data' to C45 format"                  << endl
       << "             in file Test_out.data"                                                        << endl
       << endl
       << endl;
}





void   FeatureFileConverter::NormalizeExamples (ModelParam&         param,
                                                FeatureVectorList&  examples
                                               )
{
  KKStr  parameterStr = param.ToCmdLineStr ();
  NormalizationParms const *  normParms = NULL;
  if  (osFileExists (nornParmsFileName))
  {
    bool  successful = false;
    normParms = NormalizationParms::ReadFromFile (nornParmsFileName, log);
    if  (!normParms)
    {
      KKStr  errMsg = "Could not load normalization parameters file[" + nornParmsFileName + "]";
      log.Level (-1) << endl << "NormalizeExamples    *** ERROR ***    " << errMsg << endl << endl;
      throw KKException (errMsg);
    }
  }
  else
  {
    bool  successful = false;
    normParms = new NormalizationParms (param, examples, log);
    normParms->WriteToFile(nornParmsFileName, successful, log);
    if  (!successful)
    {
      KKStr  errMsg = "Could not save normalization parameters file[" + nornParmsFileName + "]";
      log.Level (-1) << endl << "NormalizeExamples   ***ERROR***  " << errMsg << endl << endl;
      throw KKException (errMsg);
    }
  }
  normParms->NormalizeExamples (&examples, log);
  delete  normParms;
  normParms = NULL;
}  /* NormalizeExamples */


void  FeatureFileConverter::EncodeFeatureData ()
{
  bool  successful = false;

  ModelParamKnn  param;

  param.EncodingMethod    (encodingMethod);
  if  (features)
    param.SelectedFeatures  (*features);

  FeatureEncoder2  encoder (param, srcFileDesc);
  
  // We do the next line to generate a report of the encoded field assignments.
  *report << endl;
  FileDescConstPtr  encodedFileDesc = encoder.CreateEncodedFileDesc (report, log);

  NormalizeExamples (param, *data);

  FeatureVectorListPtr  featureVectorEncodedData = encoder.EncodeAllExamples (data);

  uint  numExamplesWritten = 0;
  destFileFormat->SaveFeatureFile (destFileName,
                                   featureVectorEncodedData->AllFeatures (),
                                   *featureVectorEncodedData,
                                   numExamplesWritten,
                                   cancelFlag,
                                   successful,
                                   log
                                  );

  // FileDesc objects never get deleted until very end of application; "FileDesc::FinalCleanUp" will delete it.
  //delete  encodedFileDesc;  encodedFileDesc = NULL;

  delete  featureVectorEncodedData;      featureVectorEncodedData = NULL;
}  /* EncodeFeatureData */





void   FeatureFileConverter::ConvertData ()
{
  cout << endl
       << "Saving [" << data->QueueSize () << "] records to data file[" << destFileName << "]" << endl
       << endl;

  bool  successful = false;

  int  numOfFeatures = data->NumOfFeatures ();
  int  numWithAllZeros = 0;

  {
    FeatureVectorListPtr  newData = data->ManufactureEmptyList (true);

    // Will store examples that have all zero's for all features in "zeroData"
    // container.  This way they can be deleted from memory later and not result
    // in a memory leak.  This has to be done because they are not going to
    // be placed into newData which is going to become the owner of all the
    // examples.
    FeatureVectorListPtr  zeroData = data->ManufactureEmptyList (true);

    // How many have all 0's for feature data.
    FeatureVectorList::iterator  idx;

    for  (idx = data->begin ();  idx != data->end ();  idx++)
    {
      FeatureVectorPtr  i = *idx;
      bool  allZeros = true;
      for  (int featureNum = 0;  featureNum < numOfFeatures;  featureNum++)
      {
        allZeros = (i->FeatureData (featureNum) == 0.0f);
        if  (!allZeros)
          break;
      }

      if  (allZeros)
      {
        numWithAllZeros++;
        zeroData->PushOnBack (i);
      }
      else
      {
        newData->PushOnBack (i);
      }
    }

    data->Owner (false);
    delete data;
    data = newData;
    delete  zeroData;
  }

  *report << endl
          << endl
          << "Num of data items with all zero feature data [" << numWithAllZeros << "]" << endl
          << endl;

  *report << data->ClassStatisticsStr ();
  *report << endl << endl << endl;

  if  (statistics)
  {
    *report << "Class Statistics:"  << endl;
    data->PrintClassStatistics (*report);
    *report << endl << endl;

    *report << "Feature Statistics:"  << endl;
    data->PrintFeatureStatisticsByClass (*report);
  }


  if  (enumerateClasses)
  {
    // We are going to change the name of the classes to numbers enumerated by className 

    MLClassListPtr  mlClasses = data->ExtractListOfClasses ();
    mlClasses->SortByName ();

    MLClassListPtr  newClassNames = new MLClassList ();

    int classIdx = 0;
    MLClassList::iterator idx;
    for  (idx = mlClasses->begin ();  idx !=  mlClasses->end ();  idx++)
    {
      KKStr  newName = StrFormatInt (classIdx, "zzz0");
      MLClassPtr  mlClass = newClassNames->GetMLClassPtr (newName);
      classIdx++;
    }

    for  (auto idx2: *data)
    {
      MLClassPtr  c = idx2->MLClass ();
      auto  classIndex = mlClasses->PtrToIdx (c);
      idx2->MLClass (newClassNames->IdxToPtr (classIndex.value ()));
    }

    delete  mlClasses; mlClasses = NULL;
    delete  newClassNames;  newClassNames = NULL;
  }

  if  (encodeFeatureData)
  {
    EncodeFeatureData ();
  }
  else
  {
    uint  numExamplesWritten = 0;
    destFileFormat->SaveFeatureFile (destFileName,
                                     *features,
                                     *data,
                                     numExamplesWritten,
                                     cancelFlag,
                                     successful,
                                     log
                                    );
  }

}  /* ConvertData */




void  ForestCover_AddMnemonicClassName ()
{
  const char*  classNames[] = {"Spruce_Fir",
                               "Lodgepole_Pine",
                               "Ponderosa_Pine",
                               "Cottonwood_Willow",
                               "Aspen",
                               "Douglas_fir",
                               "Krummholz",
                               NULL
                              };

  FILE* in = osFOPEN  ("K:\\Plankton\\Papers\\BitReduction\\DataSets\\ForestCover\\covtype.data", "r");
  ofstream o ("K:\\Plankton\\Papers\\BitReduction\\DataSets\\ForestCover\\covtype_alpha.data");

  char  buff[20480];

  int  lc = 0;

  while  (fgets (buff, sizeof (buff), in))
  {
    KKStr  ln (buff);

    vector<KKStr>  tokens;

    while  (!ln.Empty ())
    {
      KKStr  token = ln.ExtractToken (",\n\t\r");
      tokens.push_back (token);
    }

    int  lastFieldNum = (int)tokens.size () - 1;
    KKStr  lastToken = tokens[lastFieldNum];
    int  classNum = atoi (lastToken.Str ()) - 1;

    if  ((classNum < 0)  ||  (classNum > 6))
    {
      // Something has gone very wrong.
      cerr  << endl
            << "    *** ERROR ***" << endl
            << endl
            << buff << endl
            << endl
            << "ClassNum[" << classNum << "] Out of range." << endl
            << endl;
      osWaitForEnter ();
      exit (-1);
    }

    KKStr  className = classNames[classNum];
    tokens[lastFieldNum] = className;

    int  x = 0;
    vector<KKStr>::const_iterator idx;
    for (idx = tokens.begin ();  idx != tokens.end ();  idx++)
    {
      if  (x > 0)
        o << ",";
        o << *idx;
      x++;
    }
    o << endl;
    lc++;

    if ((lc % 100) == 0)
      cout << lc << endl;
  }

  fclose (in);
  o.close ();
}  /* ForestCover_AddMnemonicClassName */







//*****************************************************************************
//*                          SplitForestCoverFile                             *
//*                                                                           *
//*  One time only function to split the two bigest classes in forest coverage*
//*  data set into training and test sets with counts                         *
//*                                                                           *
//*            Lodgepole_Pine   Spruce_Fir                                    *
//*   Train       56,404          226,897                                     *
//*   Test        42,480          169,360                                     *
//*                                                                           *
//*  This was done to support BitReduction paper.                             *
//*                                                                           *
//*****************************************************************************


void  SplitForestCoverFile ()
{
  RunLog  log;

  MLClassList  mlClasses;  
  bool  cancelFlag  = false;
  bool  successful;
  bool  changesMade = false;

  FeatureVectorListPtr  images = FeatureFileIOC45::Driver ()->LoadFeatureFile 
                    ("covtype_alpha.data", mlClasses, -1, cancelFlag, successful, changesMade, log);

  FileDescConstPtr  fileDesc = images->FileDesc ();

  images->RandomizeOrder ();
  images->RandomizeOrder ();
  images->RandomizeOrder ();
  images->RandomizeOrder ();
  images->RandomizeOrder ();

  MLClassPtr  lodgepolePine = mlClasses.GetMLClassPtr ("Lodgepole_Pine");
  MLClassPtr  spruceFir     = mlClasses.GetMLClassPtr ("Spruce_Fir");

  int  lodgepolePineTrainCount = 0;
  int  spruceFirTrainCount     = 0;
  FeatureVectorList::iterator  idx;

  FeatureVectorListPtr  trainData = images->ManufactureEmptyList (false);
  FeatureVectorListPtr  testData  = images->ManufactureEmptyList (false);

  int  c = 0;

  for  (idx = images->begin ();  idx != images->end ();  idx++)
  {
    FeatureVectorPtr i = *idx;

    if  (c % 5000)
      cout << c << endl;

    if  (i->MLClass () == lodgepolePine)
    {
      if  (lodgepolePineTrainCount < 56404)
      {
        trainData->PushOnBack (i);
        lodgepolePineTrainCount++;
      }
      else
      {
        testData->PushOnBack (i);
      }
    }
    else if  (i->MLClass () == spruceFir)
    {
      if  (spruceFirTrainCount < 42480)
      {
        trainData->PushOnBack (i);
        spruceFirTrainCount++;
      }
      else
      {
        testData->PushOnBack (i);
      }
    }

    c++;
  }

  KKB::uint  numExamplesWritten = 0;
  FeatureFileIOC45::Driver ()->SaveFeatureFile 
                  ("CovType_TwoClass.data", 
                   trainData->AllFeatures (),
                   *trainData, 
                   numExamplesWritten,
                   cancelFlag,
                   successful,
                   log
                  );

  FeatureFileIOC45::Driver ()->SaveFeatureFile 
                  ("CovType_TwoClass.test", 
                   testData->AllFeatures (),
                   *testData, 
                   numExamplesWritten,
                   cancelFlag,
                   successful,
                   log
                  );

  delete  trainData;
  delete  testData;
  delete  images;
}  /* SplitForestCoverFile */



void  NormalizeAllValidatdData ()
{
  MLClassList  classes;
  bool  _cancelFlag = false;
  bool  _successful = false;
  bool  _changesMade = false;

  RunLog log;

  FeatureVectorListPtr  fd =   FeatureFileIOC45::Driver ()->LoadFeatureFile 
    ("C:\\Pices\\Reports\\FeatureDataFiles\\AllValidatedImages\\AllValidatedImages.data",
     classes,
     -1,
     _cancelFlag,
     _successful,
     _changesMade,
     log
    );

  kkuint32  numWritten = 0;

  NormalizationParms parms (true, *fd, log);
  parms.NormalizeExamples (fd, log);
  FeatureFileIOC45::Driver ()->SaveFeatureFile 
    ("C:\\Pices\\Reports\\FeatureDataFiles\\AllValidatedImages\\AllValidatedImagesNorm.data",
     fd->AllFeatures (),
     *fd,
     numWritten,
     _cancelFlag,
     _successful,
     log
    );

  {
    ofstream f("C:\\Pices\\Reports\\FeatureDataFiles\\AllValidatedImages\\AllValidatedImagesNorm.parms.txt");
    parms.WriteXML("parms", f);
  }
}  /* NormalizeAllValidatdData */


int  main (int     argc,
           char**  argv
          )
{

  //  NormalizeAllValidatdData ();
  //  exit (-1);
  //ForestCover_AddMnemonicClassName ();
  //exit (0);

  //SplitForestCoverFile ();
  //exit (0);

  time_t     long_time;
  SRand48 ((KKB::uint)time (&long_time));
  FeatureFileConverter fileConverter;
  fileConverter.InitalizeApplication (argc, argv);
  if  (!fileConverter.Abort ())
    fileConverter.ConvertData ();
}
