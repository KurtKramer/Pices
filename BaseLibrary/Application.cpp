/* Application.cpp -- Generic Application class.  
 * Copyright (C) 1994-2011 Kurt Kramer
 * For conditions of distribution and use, see copyright notice in KKU.h
 */
#include  "FirstIncludes.h"

#include  <stdlib.h>
#include  <stdio.h>

#include  <string>
#include  <iostream>
#include  <fstream>
#include  <vector>

#include  "MemoryDebug.h"
using  namespace  std;

#include  "Application.h"
#include  "CmdLineExpander.h"
#include  "DateTime.h"
#include  "OSservices.h"
using  namespace  KKU;




Application::Application (RunLog&  _log):
  abort       (false),
  log         (_log),
  logFileName (),
  ourLog      (NULL)
{
}



Application::Application ():
  abort       (false),
  log         (*(new RunLog ())),
  logFileName (),
  ourLog      (NULL)
{
  ourLog = &log;
}




Application::Application (const Application&  _application):
  abort        (_application.abort),
  log          (_application.log),
  logFileName  (_application.logFileName),
  ourLog       (_application.ourLog)
{
}



Application::~Application ()
{
  delete  ourLog;
  ourLog = NULL;
}



void  Application::InitalizeApplication (int32   argc,
                                         char**  argv
                                        )
{
  ProcessCmdLineParameters (argc, argv);
  if  (!logFileName.Empty ())
    log.AttachFile (logFileName);
}



const char*  Application::ApplicationName ()
{
  return  "No-Application-Name-Provided";
}  /* ApplicationName */




void  Application::AssignLog (RunLog&  _log)
{
  log = _log;

  if  (ourLog)
  {
    delete  ourLog;
    ourLog = NULL;
  }
} /* AssignRunLog */




void  Application::ProcessCmdLineParameters (int32   argc, 
                                             char**  argv
                                            )
{
  uint32  x = 0;

  bool  allParmsGood = true;

  CmdLineExpander  cmdLineExpander (ApplicationName (), log, argc, argv);

  if  (!cmdLineExpander.ParmsGood ())
    Abort (true);

  if  (!cmdLineExpander.LogFileName ().Empty ())
    logFileName = cmdLineExpander.LogFileName ();

  expandedParameterPairs = cmdLineExpander.ExpandedParameterPairs ();

  vector<KKStrPair>::const_iterator  idx;

  for  (idx = expandedParameterPairs.begin ();  idx != expandedParameterPairs.end ();  ++idx)
  {
    const KKStr&  parmSwitch = idx->first;
    const KKStr&  parmValue  = idx->second;
    bool  parmGood = ProcessCmdLineParameter (parmSwitch, parmValue);
    if  (!parmGood)
      allParmsGood = false;
  }

  if  (!allParmsGood)
    abort = true;
}  /* ProcessCmdLineParameters */




bool  Application::ProcessCmdLineParameter (const KKStr&  parmSwitch, 
                                            const KKStr&  parmValue
                                           )
{
  log.Level (-1) << endl
    << "Application::ProcessCmdLineParameter   ***ERROR***    Unrecognized Parameter [" << parmSwitch << "]  Value [" << parmValue << "]" << endl
    << endl;
  return  false;
}




KKStr   Application::BuildDate ()  const
{
  DateType  buildDate (__DATE__);
  TimeType  buildTime (__TIME__);
  return  buildDate.YYYY_MM_DD () + "-" + buildTime.HH_MM_SS ();
}  /* BuildDate */
