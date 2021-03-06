#include "FirstIncludes.h"

#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

#include "MemoryDebug.h"

using namespace  std;


#include "KKBaseTypes.h"
#include "KKQueue.h"
#include "OSservices.h"
#include "RunLog.h"
#include "KKStr.h"
using namespace  KKB;

#include "MLClass.h"
using namespace  KKMLL;


#include "BinaryClass.h"
using namespace  FeatureSelectionApp;


BinaryClass::BinaryClass (MLClassPtr  _class1,
                          MLClassPtr  _class2,
                          int                 _numProcessors
                         ):

   class1                (_class1),
   class2                (_class2),
   numProcessors         (_numProcessors),
   status                (ClassPairStatus::NotStarted),
   resultType            (FinalResultType::Null),
   finalResultsFileName  (),
   selectionMethod       (SVM_SelectionMethod::Null),
   configFileName        ()

{
}


BinaryClass::BinaryClass (int                  _numProcessors,
                          FinalResultType      _resultType,
                          SVM_SelectionMethod  _selectionMethod,
                          const KKStr&         _finalResultsFileName,
                          const KKStr&         _configFilename
                          ):

   class1                (NULL),
   class2                (NULL),
   numProcessors         (_numProcessors),
   status                (ClassPairStatus::NotStarted),
   resultType            (_resultType),
   finalResultsFileName  (_finalResultsFileName),
   selectionMethod       (_selectionMethod),
   configFileName        (_configFilename)
{
}



BinaryClass::BinaryClass (KKStr                   statusStr,
                          MLClassListPtr  mlClasses
                          ):
   class1                (NULL),
   class2                (NULL),
   numProcessors         (0),
   status                (ClassPairStatus::Null),
   resultType            (FinalResultType::Null),
   finalResultsFileName (),
   selectionMethod        (SVM_SelectionMethod::Null),
   configFileName        ()
{
  ProcessStatusStr (statusStr, mlClasses);
}




KKStr  BinaryClass::BinaryClassStatusToStr (ClassPairStatus  status)
{
  if  (status == ClassPairStatus::NotStarted)
    return  "NotStarted";

  if  (status == ClassPairStatus::Started)
    return "Started";

  if  (status == ClassPairStatus::Done)
    return "Done";

  return  "";
}  /* BinaryClassStatusToStr */




ClassPairStatus  BinaryClass::BinaryClassStatusFromStr (KKStr  statusStr)
{
  statusStr.Upper ();

  if  (statusStr == "NOTSTARTED")
    return  ClassPairStatus::NotStarted;

  if  (statusStr == "STARTED")
    return  ClassPairStatus::Started;

  if  (statusStr == "DONE")
    return  ClassPairStatus::Done;

  return ClassPairStatus::Null;
}  /* BinaryClassStatusFromStr */




BinaryClass::~BinaryClass ()
{
}


 
void  BinaryClass::ProcessStatusStr  (KKStr                   statusStr,
                                      MLClassListPtr  mlClasses
                                     )
{
  KKStr  fieldName;

  class1 = NULL;
  class2 = NULL;

  fieldName = statusStr.ExtractToken2 ("\t");

  while  (!fieldName.Empty ())
  {
    fieldName.TrimLeft  ("\n\r\t ");
    fieldName.TrimRight ("\n\r\t ");
    fieldName.Upper ();

    if  (fieldName == "ALLCLASSES")
    {
      class1 = NULL;
      class2 = NULL;
    }

    else if  (fieldName == "BINARYCLASSES")
    {
      class1 = mlClasses->GetMLClassPtr (statusStr.ExtractToken2 ("\t"));
      class2 = mlClasses->GetMLClassPtr (statusStr.ExtractToken2 ("\t"));

      if  ((class1 == NULL)  ||  (class2== NULL))
      {
        cout << "Class1 or Class2 == NULL" << endl;
      }

      else
      {
        if  ((class1->Name ().Empty ())  ||  (class1->Name ().Empty ()))
        {
          cout << "Class1Name or Class2Name   are empty" << endl;
        }
      }
    }
    
    else if  (fieldName == "STATUS")
      status = BinaryClassStatusFromStr (statusStr.ExtractToken2 ("\t"));

    else if  (fieldName == "NUMPROCESSORS")
      numProcessors = statusStr.ExtractTokenInt ("\t");
 
    else if  (fieldName.CompareIgnoreCase ("FinalResultType") == 0)
      resultType  = FinalResultTypeFromStr (statusStr.ExtractToken2 ("\t"));

    else if  (fieldName.CompareIgnoreCase ("ResultsFileName") == 0)
      finalResultsFileName = statusStr.ExtractToken2 ("\t");

    else if  (fieldName.CompareIgnoreCase ("SelectionMethod") == 0)
      selectionMethod = SelectionMethodFromStr (statusStr.ExtractToken2 ("\t"));

    else if  (fieldName.CompareIgnoreCase ("configFileName") == 0)
      configFileName = statusStr.ExtractToken2 ("\t");

    fieldName = statusStr.ExtractToken2 ("\t");
  }
}  /* ProcessStatusStr */



KKStr  BinaryClass::ToStr ()
{
  KKStr  str (300);

  KKStr  class1Name;
  if  (class1)
    class1Name = class1->Name ();

  KKStr  class2Name;
  if  (class2)
    class2Name = class2->Name ();

  if  (class1 == NULL)
    str << "AllClasses";
  else
    str << "BinaryClasses"     << "\t" << class1Name << "\t"  << class2Name;

  str << "\t"
      << "Status"              << "\t" << BinaryClassStatusToStr (status) << "\t"
      << "NumProcessors"       << "\t" << numProcessors;

  if  ((resultType != FinalResultType::Null)  ||  (selectionMethod != SVM_SelectionMethod::Null))
  {
   str << "\t"
       << "FinalResultType"  << "\t" << FinalResultTypeToStr (resultType)      << "\t"
       << "ResultsFileName"  << "\t" << finalResultsFileName                   << "\t"
       << "SelectionMethod"  << "\t" << SelectionMethodToStr (selectionMethod) << "\t"
       << "configFileName"   << "\t" << configFileName;
  }

  return  str;
}  /* ToStr */



const KKStr&  BinaryClass::Class1Name    () const
{
  if  (class1)
    return  class1->Name ();
  else
    return  KKStr::EmptyStr ();
}


const KKStr&  BinaryClass::Class2Name    () const
{
  if  (class2)
    return  class2->Name ();
  else
    return  KKStr::EmptyStr ();
}



void  BinaryClass::IncrementNumProcessors ()
{
  numProcessors++;
}  /* IncrementNumProcessors */



void  BinaryClass::DecrementNumProcessors ()
{
  numProcessors--;
}  /* IncrementNumProcessors */



BinaryClassList::BinaryClassList ():
  KKQueue<BinaryClass> (true)

{
}

