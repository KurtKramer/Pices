#if  !defined(_IEM_FRAMEPROCESSORTHREAD_)
#define  _IEM_FRAMEPROCESSORTHREAD_

#include "KKBaseTypes.h"
#include "RunLog.h"
using namespace KKB;


#include "Classifier2.h"
#include "FactoryFVProducer.h"
#include "FeatureVectorProducer.h"
#include "FileDesc.h"
#include "MLClass.h"
#include "TrainingProcess2.h"
using namespace  KKMLL;


#include "DataBase.h"
#include "ImageFeatures.h"
#include "InstrumentDataManager.h"
#include "SipperBlob.h"
#include "SipperExtractionImageManager.h"
using namespace  MLL;


#include "PreDefinedClasses.h"
#include "ExtractionParms.h"
#include "ImageExtractionThread.h"


namespace  ImageExtractionManager
{
  class  FrameProcessorThread:  public  ImageExtractionThread
  {
  public:
    FrameProcessorThread (ExtractionParms&        _parms,
                          ExtractionManagerPtr    _extractionManager,
                          const KKStr&            _threadName,
                          MsgQueuePtr             _msgQueue,
                          LogicalFrameQueuePtr    _framePool,
                          ExtractedImageQueuePtr  _imagesAwaitingUpdate,
                          bool&                   _successful
                         );

    virtual  ~FrameProcessorThread ();

    virtual  ThreadTypes   ThreadType ()  {return ThreadTypes::FrameProcessor;}

    void  GetRunTimeStats (kkuint32&  _framesProcessed,
                           kkuint32&  _scanLinesProcessed,
                           kkuint32&  _imagesFound,
                           kkuint32&  _imagesClassified
                          );

    virtual  void  Run ();

  private:
    void              LoadClassifier (bool&  _successful);
    void              ProcessFrame (LogicalFramePtr  frame);
    KKStr             SipperFileFormatStr ();
    LogicalFramePtr   GetNextFrameToProcess ();

    Classifier2Ptr            classifier;
    FactoryFVProducerPtr      fvProducerFactory;
    FeatureVectorProducerPtr  fvProducer;
    FileDescConstPtr          fileDesc;
    LogicalFrameQueuePtr      framePool;
    kkuint32                  framesProcessed;
    ExtractedImageQueuePtr    imagesAwaitingUpdate;
    kkuint32                  imagesClassified;
    kkuint32                  imagesFound;
    RunLog                    log;
    kkuint32                  scanLinesProcessed;
    KKStr                     sipperRootName;
    TrainingProcess2Ptr       trainer;
    MLClassPtr                unKnownMLClass;
  };  /* FrameProcessorThread */

  typedef  FrameProcessorThread*  FrameProcessorThreadPtr;

  typedef  KKQueue<FrameProcessorThread>  FrameProcessorThreadList;
  typedef  FrameProcessorThreadList*      FrameProcessorThreadListPtr;

}  /* ImageExtractionManager */



#endif

