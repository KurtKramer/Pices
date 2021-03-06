#ifndef  _INSTRUMENTDATAFILEMANAGER_
#define  _INSTRUMENTDATAFILEMANAGER_
/**
 @class  MLL::InstrumentDataFileManager
 @author Kurt Kramer
 @details
 @code
 ***************************************************************************************************************
 *  @author Kurt Kramer                                                                                        *
 *                                                                                                             *
 *  Developer:   Kurt Kramer                                                                                   *
 *  Date:        2007-10                                                                                       *
 *  Place:       Eastern Tropical Pacific (ETP)  aboard the Seward Johnson.                                    *
 *                                                                                                             *
 *  Purpose                                                                                                    *
 *  =======                                                                                                    *
 *  My purpose in life is to provide a means for getting instrument data for a specified Plankton image. Given *
 *  an image file name we can derive the original SIPPER file that it came from and the scan line from within  *
 *  this file where the image was extracted from.                                                              *
 *                                                                                                             *
 *  I will maintain InstrumentDataList objects; one for each SIPPER file that I am queried about.  When I get  *
 *  an image to look up If I do not already have its related 'InstrumentDataList' object I will:               *
 *     1) Look to see if a InstrumentData file already exists with this data.                                  *
 *     2) If no file available I will then go to the Original SIPPER file for the data and build a file that    *
 *        can be used the next time rather than scanning the whole SIPPER file.                                *
 *                                                                                                             *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *
 *                                                                                                             *
 *  HOW TO USE:                                                                                                *
 *  "InitializePush" -  Before using any functions call this static method.  It will create the necessary data *
 *                    structures needed.  Then for each SIPPER image file that you need Instrument data for    *
 *                    call the static method "GetClosestInstrumentData".                                       *
 *                                                                                                             *
 *  "InitializePop"  -  Before the application terminates call this static method to free up allocated memory. *
 *                                                                                                             *
 *  "GetClosestInstrumentData" - Call this static method to get the instrument data that is closest to the     *
 *                    SIPPER image file provided.                                                              *
 *                                                                                                             *
 *  "InitializePush"  and  "IniailizePop" replace "Initialize" and "CleanUp" respectively.   The "Push" and    *
 *                    "Pop" describe the additional functionality provided.  This way you no longer need to    *
 *                    worry if a caller has already initialized "IntrumenDdataFileNamager".                    *
 *                                                                                                             *
 *                                                                                                             *
 *  Sipper File Directories.                                                                                   *
 *  ========================                                                                                   *
 *  This module will automatically look in a default directory "%PicesHomeDir%\SipperFiles".  If you want it   *
 *  to search other directories for SipperFiles you need to create a text file "SipperDirectoryList.txt"       *
 *  in "%PicesHomeDir%\DataFiles\".  Create one text line for each additional SubDirectory structure that you  *
 *  want this module to search for SipperFiles.                                                                *
 *                                                                                                             *
 ***************************************************************************************************************
 @endcode
 */
#include "KKBaseTypes.h"

#include "GoalKeeper.h"

//#ifdef  WIN32
//#include  "..\\BaseLibrary\\GoalKeeper.h"
//#else
//#include "../BaseLibrary/GoalKeeper.h"
//#endif

#include "RasterSipper.h"
#include "RunLog.h"
#include "KKStr.h"
using  namespace KKB;

#include "SipperFile.h"



namespace  MLL
{
  #ifndef  _INSTRUMENTDATALIST_
  class  InstrumentDataList;
  typedef  InstrumentDataList*  InstrumentDataListPtr;
  #endif

  #ifndef  _INSTRUMENTDATA_
  class  InstrumentData;
  typedef InstrumentData*  InstrumentDataPtr;
  #endif 


  #if  !defined(_SIPPERFILE_)
  class  SipperFile;
  typedef  SipperFile*  SipperFilePtr;
  class  SipperFileList;
  typedef  SipperFileList*  SipperFileListPtr;
  #endif



  class InstrumentDataFileManager
  {
  public:
    typedef  KKB::kkint32 kkint32;
    typedef  KKB::kkuint32  kkuint32;
    typedef  KKB::kkint64 kkint64;
    typedef  KKB::kkuint64  kkuint64;

    InstrumentDataFileManager ();
    ~InstrumentDataFileManager ();
  
    void   GetClosestInstrumentData (const KKStr&        imageFileName,
                                     InstrumentDataPtr&  instrumentData,
                                     VolConstBool&       cancelFlag,
                                     RunLog&             log
                                    );

    void  GetClosestInstrumentData (const KKStr&        sipperFileRootName,
                                    kkuint32            scanLine,
                                    InstrumentDataPtr&  instrumentData,
                                    VolConstBool&       cancelFlag,
                                    RunLog&             log
                                   );
  
    VectorFloat  GetVolumePerMeterProfile2 (const KKStr&   sipperFileName,
                                            SipperFilePtr  sipperFile,
                                            VolConstBool&  cancelFlag,
                                            RunLog&        log
                                           );
  
    VectorUlong  GetScanLinesPerMeterProfile2 (const KKStr&   sipperFileName,
                                               SipperFilePtr  sipperFile,
                                               VolConstBool&  cancelFlag,
                                               RunLog&        log
                                              );
  
  
    static  InstrumentDataPtr  GetClosestInstrumentData (const KKStr&   imageFileName,
                                                         VolConstBool&  cancelFlag,
                                                         RunLog&        log
                                                       );

    
    static InstrumentDataPtr   GetClosestInstrumentData (const KKStr&   sipperFileRootName,
                                                         kkuint32       scanLine,
                                                         VolConstBool&  cancelFlag,
                                                         RunLog&        log
                                                        );

    
  
    static  KKStr        GetFullSipperFileName (const KKStr&  rootName);  // Will return Sipper File name including full directory path.
  
  
    static  VectorKKStr  GetListOfSipperFiles (RunLog&  log);
    
    static  VectorUlong  GetScanLinesPerMeterProfile (const KKStr&   sipperFileName,
                                                      SipperFilePtr  sipperFile,
                                                      VolConstBool&  cancelFlag,
                                                      RunLog&        log
                                                     );
  
    static  VectorFloat  GetVolumePerMeterProfile (const KKStr&   sipperFileName,
                                                   SipperFilePtr  sipperFile,
                                                   VolConstBool&  cancelFlag,
                                                   RunLog&        log
                                                  );
  
   
    static  InstrumentDataListPtr   GetInstrumentDataForSipperFile (const KKStr&   sipperFileName,
                                                                    SipperFilePtr  sipperFile,
                                                                    bool           forceReExtract,
                                                                    VolConstBool&  cancelFlag,
                                                                    RunLog&        log
                                                                   );
  
    static  InstrumentDataListPtr   ReExtractInstrumentDataForSipperFile (const KKStr&   sipperFileName,
                                                                          SipperFilePtr  sipperFile,
                                                                          VolConstBool&  cancelFlag,
                                                                          RunLog&        log
                                                                         );
  
    static  RasterSipperPtr  GetOrigSipperImage (const KKStr&  sipperFileRootName,
                                                 KKB::kkuint64 byteOffset,              /**< Byte offset into SipperFile where Scan-Line 'topLeftRow' starts. */
                                                 kkuint32      topLeftRow,              /**< Top left scan-line where the Sipper-Image resides.  */
                                                 kkuint32      tooLeftCol,              /**< Top left column   where the Sipper-Image resides.  */
                                                 kkuint32      height,                  /**< Height */
                                                 kkuint32      width,                   /**< Width */
                                                 KKB::uchar    connectedComponentDist,  /**< Size of structure used by Connected Component Analysis to locate in Sipper-Image. */
                                                 RunLog&       log                      /**< Where logging messages are sent.*/
                                                );
  
    static  void  Initialize ();
  
    static  void  FinalCleanUp ();
  
    static  void  InitializePush ();
  
    static  void  InitializePop  ();
  
    static  KKStr  SipperFileRootNameFromSipperImageFileName (const KKStr&  sipperFileName);
  
    static  bool  Initialized ();
  
  
  private:
    typedef  std::map<KKStr, InstrumentDataListPtr>   DataFileList;    /**< Lists of InstrumentDataList already loaded.
                                                                        * if ('InstrumentDataListPtr' == null)
                                                                        *    |it means that we looked for that file once
                                                                        *    |before but it does not exist.
                                                                        */
  
    typedef  std::pair<KKStr, InstrumentDataListPtr>  DataFileListPair;
  
  
    typedef  std::map<KKStr, KKStr>                   StringLookUpTable;
    typedef  StringLookUpTable*                       StringLookUpTablePtr;
  
    static  InstrumentDataFileManager*                instrumentDataManager;
     
    static  kkint32                                   initializedStackSize;
  
    static  GoalKeeperPtr                             blocker;
  
    static  void  InitializeBlocker ();
  
  
    /**
     * Reads from a text file the root directory names where SIPPER files may be located.
     * the 'sipperDirectories'data structure will be populated.  The text file name comes
     * from 'PicesVariables::SipperDirectoryListFileName ()'
     * PicesHomeDir + "\" + "DataFiles" + "\" + "SipperDirectoryList.txt";
     */
    static
    void  LoadSipperDirectoryNames ();
  
  
  
    /**
     **************************************************************************************
     * Populates 'knownSipperFiles' with all the known SIPPER files that can be found.    *
     * It will search all sub directory trees that are specified in the text file         *
     * 'SipperDirectoryList.txt".  "LoadSipperDirectoryNames" will retrieve these names.  *
     **************************************************************************************
     */
    static
    void  LoadKnownSipperFileNames ();
  
  
    InstrumentDataListPtr   GetInstrumentDataListForSipperFile (const KKStr&   sipperRootName,
                                                                SipperFilePtr  sipperFile,
                                                                bool           forceReExtract,
                                                                VolConstBool&  cancelFlag,
                                                                RunLog&        log
                                                               );
  
  
    InstrumentDataListPtr   currentDataFile;
    DataFileList            dataFiles;
  
    static
    StringLookUpTablePtr    knownSipperFiles;    /**< Index list of known Sipper Files.  This list will
                                                  * be built once in the constructor.  This way we can
                                                  * determine quickly if and where a Sipper file is 
                                                  * when a request is made for instrument data from 
                                                  * a given Sipper file.
                                                  */
    
    KKStr                   instrumentDataFilesDir;
  
    KKStr                   picesHomeDir;
  
    static
    VectorKKStr*            sipperDirectories;   /**> Directories where I can find SIPPER files.  This list can be found in a 
                                                  * a data file in "%PicesHomeDir%\DataFiles\SipperDirectoryList.txt".  If this 
                                                  * file does not exist then We will assume only one directory 
                                                  * "%PicesHomeDir%\SipperFiles".
                                                  */
  };
}  /* MLL */
  
#endif
  




