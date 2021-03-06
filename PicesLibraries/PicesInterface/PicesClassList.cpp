#include "StdAfx.h"
#include "FirstIncludes.h"

#include <stdio.h>
#include <math.h>

#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <map>
#include <vector>


#include "MemoryDebug.h"
#include "KKBaseTypes.h"

#include "GoalKeeper.h"
using namespace KKB;

#include "MLClass.h"

//#include "PicesKKStr.h"
#include "PicesClass.h"
#include "PicesClassList.h"
#include "PicesDataBase.h"

using namespace  PicesInterface;


using namespace System;



PicesClassList::PicesClassList (int x, int y, int z):  
    List<PicesClass^> (),
    directory         (nullptr),
    rootNode          (nullptr)

{
  // Only the creation of 'allClassesInUniverse'  will call this constructor.
  directory = "";
  rootNode = gcnew PicesClass ("AllClasses", "");
  Add (rootNode);
}


PicesClassList::PicesClassList ():
    List<PicesClass^> (),
    directory         (nullptr),
    rootNode          (nullptr)

{
  directory = "";
}



PicesClassList::PicesClassList (String^  _directory):  
  List<PicesClass^> (),
  directory         (_directory),
  rootNode          (nullptr)

{
  rootNode = GetUniqueClass ("AllClasses", "");
  Add (rootNode);
  try  {LoadSubTreeFromDir ();}
  catch (Exception^ e)  
  {
    rootNode = nullptr;
    String^ exceptionStr = "PicesClassList  Could not load Directory[";
    exceptionStr += directory;
    exceptionStr += gcnew String ("]");
    throw  gcnew Exception (exceptionStr, e);
  }
}


PicesClassList::PicesClassList (PicesClassList^  _classes)
{
  directory = _classes->directory;
  rootNode  = _classes->rootNode;

  for each  (PicesClass^  pc in  _classes)
  {
    Add (pc);
  }
}



PicesClassList::PicesClassList (const MLClassListPtr  _classes):
    List<PicesClass^> (),
    directory         (nullptr),
    rootNode          (nullptr)
{
  directory = "";

  MLClassList::const_iterator  idx;
  for  (idx = _classes->begin ();  idx != _classes->end ();  ++idx)
  {
    MLClassPtr  ic = *idx;
    Add (PicesClassList::GetUniqueClass (ic));
  }
}



PicesClassList::~PicesClassList ()
{
  this->!PicesClassList ();
}


PicesClassList::!PicesClassList ()
{
 CleanUpUnmanagedResources ();
}


void  PicesClassList::CleanUpUnmanagedResources ()
{
}

MLClassListPtr  PicesClassList::ToMLClassConstList ()
{
  MLClassListPtr  result = new MLClassList ();
  for each (PicesClass^ pc in *this)
  {
    result->PushOnBack (pc->UnmanagedMLClass ());
  }
  return  result;
}  /* ToMLClassConstList */



PicesClassList^   PicesClassList::CreateARootedEmptyClassList ()
{
  PicesClassList^  classes = gcnew PicesClassList ();

  PicesClass^  rootNode = GetUniqueClass ("AllClasses", "");
  classes->Add (rootNode);
  classes->RootNode = rootNode;
  return  classes;
}  /* CreateARootedEmptyClassList */



PicesClassList^  PicesClassList::CreateFromCommaDelStr (String^  s)
{
  PicesClassList^ l = gcnew PicesClassList ();
  if  (String::IsNullOrEmpty (s))
    return  l;

  array<String^>^  fields = s->Split (',');
  for  (int  x = 0;  x < fields->Length;  x++)
  {
    String^  className = fields[x]->Trim ();
    if  (className->Length > 0)
      l->Add (GetUniqueClass (className, nullptr));
  }

  return  l;
}  /* CreateFromCommaDelStr */




int  PicesClassList::LookUpIndex (PicesClass^ c)
{
  int  index = 0;
  for  (index = 0;  index < Count;  index++)
  {
    if  (c == (*this)[index])
      return index;
  }
  return -1;
}  /* LookUpIndex */



PicesClass^  PicesClassList::LookUpByName (String^  className)
{
  String^  classNameUpper = className->ToUpper ();
      
  for  (int x = 0;  x < this->Count;  x++)
  {
    PicesClass^  c = (*this)[x];
    if  (c->NameUpper == classNameUpper)
      return  c;
  }

  return nullptr;
}  /* LookUpByName */



PicesClass^  PicesClassList::LookUpByUnmanagedClass (MLClassPtr  unmanagedClass)
{
  for each (PicesClass^ pc in (*this))
  {
    if  (pc->UnmanagedMLClass () == unmanagedClass)
      return pc;
  }

  return  nullptr;
}



void  PicesClassList::Save  (String^  _directory)
{
  directory = _directory;
  ClearDirectory ();
  SaveSubTree (rootNode);
}  /* Save */




PicesClassList^  PicesClassList::CreateFromDirectoryStructure (String^  directoryName)
{
  PicesClassList^  list = gcnew PicesClassList ();
      
  PicesClass^  root = list->RootNode;
      
  DirectoryInfo^ di = nullptr;
  try  {di = gcnew DirectoryInfo (directoryName);}
  catch  (Exception^)  {di = nullptr;}
  
  if  (di == nullptr)
    return  list;

  if  (!di->Exists)
    throw gcnew Exception ("PicesClassList.CreateFromDirectoryStructure  Dir[" + directoryName + "] does not exist.");

  list->AddClassesUsingSubdirectoryStructure (di, root);
      
  return  list; 
}  /* CreateFromDirectoryStructure */
  
  
  
PicesClass^  PicesClassList::LoadSingleClass (String^  fileName)
{
  StreamReader^  sr = nullptr;
  try  {sr = gcnew StreamReader (fileName);}
  catch (Exception^)  {sr = nullptr;}
        
  if  (sr == nullptr)
    return  nullptr;
          
  String^  firstLine = sr->ReadLine ()->ToUpper ();
  while  ((firstLine != nullptr)  &&  (firstLine != "[IMAGE_CLASS]"))
    firstLine = sr->ReadLine ()->ToUpper ();
          
  if  (firstLine == nullptr)
  {
    sr->Close();
    delete  sr;
    sr = nullptr;
    return  nullptr;
  }

  String^  className   = "";
  String^  description = "";
  String^  parentName  = "";

  String^  line = sr->ReadLine ();
  while  (line != nullptr)
  {
    array<String^>^  lineParts = line->Split ('=');
    if  (lineParts->Length == 2)
    {
      String^  fieldName  = lineParts->GetValue (0)->ToString ()->ToUpper ();
      String^  fieldValue = lineParts->GetValue (1)->ToString ()->ToUpper ();

      if  (fieldName == "NAME")
        className = fieldValue;
              
      else if  (fieldName == "DESCRIPTION")
        description = fieldValue;
 
      else if  (fieldName == "PARENT")
        parentName = fieldValue;
    }
         
    line = sr->ReadLine ();
  }
      
  sr->Close ();
  delete  sr;
  sr = nullptr;
      
  PicesClass^  newClass = PicesClassList::GetUniqueClass (className, parentName);
  newClass->Description = description;
  return  newClass;
}  /* LoadSingleClass */



void  PicesClassList::LoadSubTreeFromDir ()
{
  DirectoryInfo^  di = nullptr;
  try  {di = gcnew DirectoryInfo (directory);}
  catch  (Exception^ e){throw gcnew Exception ("Error getting directory info for DirName[" + directory + "]", e);}
      
  if  (!di->Exists)
    throw gcnew Exception ("ImageList.LoadSubTreeFromDir  Directory[" + directory + "] does not exist.");
      
   array<FileInfo^>^ files = di->GetFiles ("*.txt");

   if  (files == nullptr)
     return;
      
   int  x;

   for  (x = 0;  x < files->Length;  x++)
   {
     FileInfo^  fi = (FileInfo^)(files->GetValue (x));

     PicesClass^  c = LoadSingleClass (directory + fi->Name);
     if  (c == nullptr)
       continue;

     if  (c->NameUpper == "ALLCLASSES")
     {
       c = nullptr;
     }
     else
     {
       Add (c);          
     }
   }        

   for each (PicesClass^ c in *this)
   {
     if  (c != rootNode)
     {
       PicesClass^  parent = nullptr;
        
       if  (String::IsNullOrEmpty (c->ParentName))
         parent = rootNode;
       else
       {
         parent =  LookUpByName (c->ParentName);
         if  (parent == nullptr)
           parent = rootNode;
       }
          
       parent->AddAChild (c);
     }
   }
      
   files = nullptr;
   di = nullptr;
 }  /* LoadSubTreeFromDir */



 void  PicesClassList::ClearDirectory ()
 {
   DirectoryInfo^  di = nullptr;
   try  {di = gcnew DirectoryInfo (directory);}
   catch  (Exception^ e)  
   { 
     di = nullptr;
     throw gcnew Exception ("PicesClassList.ClearDirectory   Could not get directory info[" + directory + "]", e);
   }

   if  (!di->Exists)
   {
     try  {di->Create ();}
     catch  (Exception^ e2)  {throw gcnew Exception ("Could not create Directory[" + directory + "]", e2); }
   }
      
   array<FileInfo^>^ files = di->GetFiles ("*.txt");
   for  (int x = 0;  x < files->Length;  x++)
   {
     FileInfo^ fi = (FileInfo^)(files->GetValue (x));
     fi->Delete ();
   }

   delete  files;
   files = nullptr;

   delete  di;
   di = nullptr;

} /* ClearDirectory */



void  PicesClassList::SaveSubTree (PicesClass^  subTree)
{
  subTree->Save (directory);

  List<PicesClass^>^  children = subTree->Children;
  if  (children != nullptr)
  {
    for  (int x = 0;  x < children->Count;  x++)
    {
      PicesClass^ c = (*children)[x];
      SaveSubTree (c);
    }
  }
}  /* SaveSubTree */
    
    
  
void  PicesClassList::AddClassesUsingSubdirectoryStructure (DirectoryInfo^  di,
                                                            PicesClass^     subTree
                                                           )
{
  array<DirectoryInfo^>^  subDirectories = di->GetDirectories ();

  for  (int idx = 0;  idx < subDirectories->Length;  idx++)
  {
    DirectoryInfo^ subDirectory = (DirectoryInfo^)subDirectories->GetValue (idx);
    if  ((subDirectory->Name  == ".")  ||  (subDirectory->Name == ".."))
      continue;

    PicesClass^  c = PicesClassList::GetUniqueClass (subDirectory->Name, "");
    c->Parent = subTree;
    subTree->AddAChild (c);
    Add (c);
        
    AddClassesUsingSubdirectoryStructure (subDirectory, c);
  }
}  /* AddClassesUsingSubdirectoryStructure */
  
  

ref class  PicesClassList::ClassNameComparitor : public System::Collections::Generic::IComparer<PicesClass^>
{
public:
   virtual  int  Compare (PicesClass^ a, PicesClass^ b)
  {
    return  a->NameUpper->CompareTo (b->NameUpper);
  }
};
			

void  PicesClassList::SortByName ()
{
  ClassNameComparitor^ c = gcnew ClassNameComparitor ();
  Sort (c);
}



PicesClassList^  PicesClassList::GetAllKnownClasses ()
{
  getUniqueClassBlocker->StartBlock ();

  PicesClassList^  results = gcnew PicesClassList ();
  for each  (PicesClass^  pc in allClassesInUniverse)
  {
    results->Add (pc);
  }

  getUniqueClassBlocker->EndBlock ();

  return  results;
}  /* GetAllKnownClasses */




//********************************************************************************
//*  Supports the idea that there is only one instance of a class with the same  *
//*  name in memory.                                                             *
//********************************************************************************
//PicesClassList^  PicesClassList::allClassesInUniverse = nullptr;

PicesClass^  PicesClassList::GetUniqueClass (String^  _name,
                                             String^  _parentName
                                            )
{
  getUniqueClassBlocker->StartBlock ();

  if  (allClassesInUniverse == nullptr)
  {
    allClassesInUniverse               = gcnew PicesClassList (0, 0, 0);
    allClassesInUniverseUnManagedIndex = gcnew ManagedClassLocator ();
    allClassesInUniverseNameIndex      = gcnew NameIndex ();
  }

  PicesClass^  existingPicesClass = nullptr;
  String^  upperName = _name->ToUpper ();


  int  pcIDX = allClassesInUniverseNameIndex->IndexOfKey (upperName);
  if  (pcIDX >= 0)
  {
    existingPicesClass = allClassesInUniverseNameIndex->Values[pcIDX];
  }
  else
  {
    PicesClass^  newClass = gcnew PicesClass (_name, _parentName);
    allClassesInUniverse->Add (newClass);
    allClassesInUniverseNameIndex->Add (upperName, newClass);
    allClassesInUniverseUnManagedIndex->Add (newClass->UnmanagedMLClass (), newClass);
    existingPicesClass = newClass;
  }

  getUniqueClassBlocker->EndBlock ();

  return  existingPicesClass;
}  /* GetUniqueClass */





//********************************************************************************
//*  Supports the idea that there is only one instance of a class with the same  *
//*  name in memory.                                                             *
//********************************************************************************
PicesClass^  PicesClassList::GetUniqueClass (MLClassPtr  mlClass)
{
  if  (mlClass == NULL)
    int zed = 9999;

  if  (allClassesInUniverse == nullptr)
  {
    getUniqueClassBlocker->StartBlock ();
    if  (allClassesInUniverse == nullptr)
    {
      allClassesInUniverse               = gcnew PicesClassList (0, 0, 0);
      allClassesInUniverseUnManagedIndex = gcnew ManagedClassLocator ();
      allClassesInUniverseNameIndex      = gcnew NameIndex ();
      getUniqueClassBlocker->EndBlock ();
    }
  }

  PicesClass^  c = allClassesInUniverseUnManagedIndex->LookUp (mlClass);

  if  (c == nullptr)
  {
    c = GetUniqueClass (PicesKKStr::KKStrToSystenStr (mlClass->Name ()), PicesKKStr::KKStrToSystenStr (mlClass->ParentName ()));
  }

  return  c;

}  /* GetUniqueClass */



PicesClass^  PicesClassList::GetUnKnownClassStatic ()
{
  return  GetUniqueClass (MLClass::GetUnKnownClassStatic ());
}




/**
 *@brief Static method that is meant to only work on 'allClassesInUniverse'.
 */
void  PicesClassList::UpdateParent (PicesClass^  srcClass,
                                    PicesClass^  destClass
                                   )
{
  if  (allClassesInUniverse == nullptr)
    return;

  for each  (PicesClass^  pc  in allClassesInUniverse)
  {
    if  (pc->Parent == srcClass)
      pc->Parent = destClass;
  }
}  /* MergeClasses */




PicesClassList^   PicesClassList::ExtractMandatoryClasses ()
{
  PicesClassList^  result = gcnew PicesClassList ();
  for each (PicesClass^ c in *this)
  {
    if  (c->Mandatory)
      result->Add (c);
  }
  return result;
}



PicesClassList^   PicesClassList::ExtractSummarizeClasses ()
{
  PicesClassList^  result = gcnew PicesClassList ();
  for each (PicesClass^ c in *this)
  {
    if  (c->Summarize)
      result->Add (c);
  }
  return result;
}




PicesClassList^  PicesClassList::ExtractListOfClassesForAGivenHierarchialLevel (uint level)
{
  PicesClassList^  newList = gcnew PicesClassList ();
  for each (PicesClass^ c in *this)
  {
    PicesClass^  levelClass = c->MLClassForGivenHierarchialLevel (level);
    if  (newList->LookUpIndex (levelClass) < 0)
      newList->Add (levelClass);
  }
  return  newList;
}  /* ExtractListOfClassesForAGivenHierarchialLevel */





  //************************************************************************************
  //*  Needed by PicesClassList to help locate instances of 'PicesClass'  when given   *
  //*  a pointer to a 'MLClass' object.  It implements a simple Binary Tree with       *
  //*  that supports only 2 operations  'Add'  and  'LookUp'.                          *
  //*                                                                                  *
  //*  neither 'map<>' or 'SortedList<>' could work with both Managed and Unmanaged    *
  //*  objects together.                                                               *
  //*                                                                                  *
  //*  This is an UnBalanced tree so some thought into re-balancing it needs 2 b done. *
  //************************************************************************************
PicesClassList::ManagedClassLocator::ManagedClassLocator  ()
{
  root = nullptr;
}


PicesClassList::Node::Node (MLClassPtr   _unmanagedClass,
                            PicesClass^  _managedClass
                           ):
       unmanagedClass (_unmanagedClass),
       managedClass   (_managedClass),
       left           (nullptr),
       right          (nullptr)
{}


 
  

bool  PicesClassList::ManagedClassLocator::Add (MLClassPtr   unmanagedClass,
                                                PicesClass^  managedClass
                                               )
{
  if  (root == nullptr)
  {
    root = gcnew Node (unmanagedClass, managedClass);
    return  true;
  }

  Node^  next = root;
  while  (true)
  {
    if  (unmanagedClass == next->unmanagedClass)
    {
      // We have a duplicate entry.
      return  false;  // Not Successful
    }

    if  (unmanagedClass < next->unmanagedClass)
    {
      if  (next->left == nullptr)
      {
        next->left = gcnew Node (unmanagedClass, managedClass);
        return true;
      }
      else
      {
        next = next->left;
      }
    }
    else
    {
      if  (next->right == nullptr)
      {
        next->right = gcnew Node (unmanagedClass, managedClass);
        return true;
      }
      else
      {
        next = next->right;
      }
    }
  }  /* End of while loop */
}  /* Add */



PicesClass^   PicesClassList::ManagedClassLocator::LookUp (MLClassPtr  unmanagedClass)
{
  if  (root == nullptr)
    return nullptr;

  Node^  next = root;
  while  (next != nullptr)
  {
    if  (next->unmanagedClass == unmanagedClass)
      return  next->managedClass;
    if  (unmanagedClass < next->unmanagedClass)
      next = next->left;
    else
      next = next->right;
  }

  return  nullptr;
}


array<String^>^  PicesClassList::ExtractTwoTitleLines ()
{
  String^  hd1 = "";
  String^  hd2 = "";

  int x = 0;
  for each (PicesClass^% pc in (*this))
  {
    if  (x > 0)
    {
      hd1 += "\t";
      hd2 += "\t";
    }

    int y = pc->Name->IndexOf ('_');
    if  (y < 0)
    {
      hd2 += pc->Name;
    }
    else
    {
      hd1 += pc->Name->Substring (0, y);
      hd2 += pc->Name->Substring (y + 1);
    }

    ++x;
  }

  array<String^>^  results = gcnew array<String^> (2);
  results[0] = hd1;
  results[1] = hd2;

  return  results;
} /* ExtractTwoTitleLines */





array<String^>^  PicesClassList::ExtractThreeTitleLines ()
{
  cli::array<String^>^  headerLines = gcnew cli::array<String^> (3);
  headerLines[0] = "";
  headerLines[1] = "";
  headerLines[2] = "";

  int x = 0;
  for each (PicesClass^% pc in (*this))
  {
    if  (x > 0)
    {
      headerLines[0] += "\t";
      headerLines[1] += "\t";
      headerLines[2] += "\t";
    }

    cli::array<String^>^  parts= pc->Name->Split ('_');
    int y = Math::Max (0, 3 - parts->Length);
    int z = 0;
    while  (y < 3)
    {
      headerLines[y] += parts[z];
      ++y;
      ++z;
    }

    while  (z < parts->Length)
    {
      headerLines[2] += ("_" + parts[z]);
      ++z;
    }
    ++x;
  }

  return  headerLines;
}  /* ExtractThreeTitleLines */
