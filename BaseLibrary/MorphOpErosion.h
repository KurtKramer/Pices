/* MorphOpErosion.cpp -- Morphological operators use to perform erosion.
 * Copyright (C) 1994-2014 Kurt Kramer
 * For conditions of distribution and use, see copyright notice in KKB.h
 */
#if !defined(_MORPHOPEREROSION_)
#define  _MORPHOPEREROSION_

#include "BasicTypes.h"
#include "MorphOp.h"


#if  !defined(_RASTER_)
namespace  KKB
{
  class  Raster;
  typedef  Raster*  RasterPtr;
}
#endif



namespace  KKU
{
  class  MorphOpErosion :  public MorphOp
  {
  public:
    MorphOpErosion (StructureType  _structure,
                    kkuint16       _structureSize
                   );
    
    virtual ~MorphOpErosion ();

    virtual  OperationType   Operation ()  const  {return  moErosion;}

    virtual  RasterPtr   PerformOperation (RasterConstPtr  _image);

    kkint32  MemoryConsumedEstimated ();

  private:
    bool  Fit (kkint32  row, 
               kkint32  col
              )  const;

    StructureType  structure;
    kkuint16       structureSize;
  };  /* MorphOpErosion */

  typedef  MorphOpErosion*  MorphOpErosionPtr;
};  /* KKB */



#endif
