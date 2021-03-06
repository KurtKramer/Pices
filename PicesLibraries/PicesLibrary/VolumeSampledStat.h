#if  !defined(_VOLUMESAMPLEDSTAT_)
#define _VOLUMESAMPLEDSTAT_


/**
 *@class MLL::VolumeSampledStat
 *@details
 *  Used to Pass Volume of water sampled per (depth in meters) groupings.  Each instance keeps track of binId, 
 *  binDepth, and volumeSampled.
 *  
 *@author  Kurt Kramer
 */
#include  <map>

#include  "KKBaseTypes.h"
#include  "KKQueue.h"
using namespace KKB;


namespace  MLL
{
  class VolumeSampledStat
  {
  public:
    typedef  KKB::kkint32 kkint32;
    typedef  VolumeSampledStat*  VolumeSampledStatPtr;

    VolumeSampledStat ();

    VolumeSampledStat (const VolumeSampledStat&  _stat);

    VolumeSampledStat (kkint32 _binId,
                       float   _binDepth,
                       float   _volumeSampled
                      );

    ~VolumeSampledStat ();

    kkint32 BinId         () const {return binId;}
    float   BinDepth      () const {return binDepth;}
    float   VolumeSampled () const {return volumeSampled;}

    void  BinId         (kkint32 _binId)         {binId         = _binId;}
    void  BinDepth      (float _binDepth)      {binDepth      = _binDepth;}
    void  VolumeSampled (float _volumeSampled) {volumeSampled = _volumeSampled;}

    void  AddToVolumeSampled (float _volumeSampled);

  private:
    kkint32 binId;
    float   binDepth;
    float   volumeSampled;
  };
  typedef  VolumeSampledStat::VolumeSampledStatPtr          VolumeSampledStatPtr;



  class VolumeSampledStatList:  public std::map<KKB::kkint32, VolumeSampledStatPtr>
  {
  public:
    typedef  KKB::kkint32 kkint32;
    typedef  VolumeSampledStatList*  VolumeSampledStatListPtr;

    VolumeSampledStatList ();
  
    ~VolumeSampledStatList ();

    void  Add (const VolumeSampledStat&  stat);

    /** Caller is giving ownership of 'stat' to this instance; upon return 'stat' may be set to NULL
     * indicating that it was merged with an existing instance already in the list.
     */
    void  Give (VolumeSampledStatPtr&  stat);
    
    VolumeSampledStatPtr  Locate (int binId);

    VolumeSampledStatList&  operator+= (const VolumeSampledStatList&  right);

 private:
   typedef  std::pair<kkint32, VolumeSampledStatPtr>  Pair;
  };
  
  typedef  VolumeSampledStatList::VolumeSampledStatListPtr  VolumeSampledStatListPtr;
}  /* MLL */

#endif


