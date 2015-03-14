#ifndef  _FEATUREENCODER_
#define  _FEATUREENCODER_
//***********************************************************************
//*                           FeatureEncoder                            *
//*                                                                     *
//*                                                                     *
//*---------------------------------------------------------------------*
//*  History                                                            *
//*                                                                     *
//*    Date      Programmer   Description                               *
//*                                                                     *
//*  2005-09-10  Kurt Kramer  Removing Feature compression and encoding *
//*                           code from FeatureEncoder                  *
//*                                                                     *
//***********************************************************************
#include  "RunLog.h"

#include  "Attribute.h"
#include  "BitReduction.h"
#include  "FeatureVector.h"
#include  "FileDesc.h"
#include  "MLClass.h"
#include  "svm.h"
#include  "SVMparam.h"



namespace MLL 
{

  #ifndef  _FEATURENUMLIST_
  class  FeatureNumList;
  typedef  FeatureNumList*  FeatureNumListPtr;
  #endif


  typedef  struct svm_node*     XSpacePtr;


  typedef  enum  {FeAsIs, FeBinary, FeScale}  FeWhatToDo;
  typedef  FeWhatToDo*  FeWhatToDoPtr;


  class  FeatureEncoder
  {
  public:
    FeatureEncoder (const SVMparam&            _svmParam,
                    FileDescPtr                _fileDesc,
                    MLL::AttributeTypeVector&  _attributeTypes,   
                    VectorInt&                 _cardinalityTable,
                    MLClassConstPtr            _class1,
                    MLClassConstPtr            _class2,
                    RunLog&                    _log
                   );
    
    
    ~FeatureEncoder ();


    kkint32  CodedNumOfFeatures () const  {return codedNumOfFeatures;}


    MLClassConstPtr  Class1 () const  {return class1;}
    MLClassConstPtr  Class2 () const  {return class2;}

    /**
     *@brief  Compresses 'src' images, allocating new 'xSpace' data structure.
     *@param[in]  src              Images that are to be compressed
     *@param[in]  assignments      Class Assignments
     *@param[in]  xSpace           will allocate enough xSpace nodes and place compressed results in this structure.
     *@param[out] totalxSpaceUsed  number nodes used in xSpace</param>
     *@param[out] prob             Data Structure that is used by SVMLib
     */
    CompressionStats  Compress (FeatureVectorListPtr  src,
                                ClassAssignments&     assignments,
                                XSpacePtr&            xSpace,
                                kkint32&                totalxSpaceUsed,
                                struct svm_problem&   prob
                               );

    FileDescPtr       CreateEncodedFileDesc (ostream*  o);

    FeatureVectorListPtr  CreateEncodedFeatureVector (FeatureVectorList&  srcData);

    XSpacePtr         EncodeAImage (FeatureVectorPtr  image);

    void              EncodeAImage (FeatureVectorPtr  image,
                                    svm_node*         xSpace,
                                    kkint32&            xSpaceUsed
                                   );

    FeatureVectorListPtr  EncodeAllExamples (const FeatureVectorListPtr  srcData);


    FeatureVectorPtr      EncodeAImage (FileDescPtr       encodedFileDesc,
                                        FeatureVectorPtr  src
                                       );

    kkint32             MemoryConsumedEstimated ()  const;

    kkint32             XSpaceNeededPerImage ()  {return xSpaceNeededPerImage;}



  private:
    CompressionStats  CompressImages (FeatureVectorListPtr   srcImages,
                                      FeatureVectorListPtr   compressedImages,
                                      ClassAssignments&     assignments
                                     );

    /**  
     * Computes the number of XSpace nodes that need to be allocated to 
     * represent the contents of a specified FeatureVectorList.  Will 
     * account for features that have a value of 0;  that is features 
     * that have a value of '0' do not need a xSpace node allocated for
     * them.
     */
    kkint32  DetermineNumberOfNeededXspaceNodes (FeatureVectorListPtr   src)  const;



    MLL::AttributeTypeVector&  attributeTypes;     /**< Will not own, passed in by creator */
    kkint32*                     cardinalityDest;
    VectorInt&                 cardinalityTable;   /**< Will not own, passed in by creator */
    MLClassConstPtr            class1;
    MLClassConstPtr            class2;
    kkint32                    codedNumOfFeatures;
    SVM_CompressionMethod      compressionMethod;
    kkint32*                     destFeatureNums;
    FileDescPtr                destFileDesc;
    FeWhatToDoPtr              destWhatToDo;
    SVM_EncodingMethod         encodingMethod;
    FileDescPtr                fileDesc;
    RunLog&                    log;
    kkint32                    numEncodedFeatures;
    kkint32                    numOfFeatures;
    FeatureNumList             selectedFeatures;
    kkint32*                     srcFeatureNums;
    const SVMparam&            svmParam;
    kkint32                    xSpaceNeededPerImage;
  };  /* FeatureEncoder */




  typedef  FeatureEncoder*  FeatureEncoderPtr;


} /* namespace MLL */

#endif
