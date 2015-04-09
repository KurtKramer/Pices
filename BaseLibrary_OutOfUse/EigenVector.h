/* EigenVector.h  Implements simploified Eigen Vector routine for 2 x 2 matrix 
 * code was derived from "Numerical Recipes in c++"
 */
#ifndef  _EIGENVECTOR_
#define  _EIGENVECTOR_

#include  <vector>

#include "KKBaseTypes.h"
//#include "Matrix.h"

namespace  KKB
{
  void  Tred2 (kkint32   n,
               double    a[2][2],
               double*   d,
               double*   e
              );


  void  tqli (kkint32   n,
              double*   d,
              double*   e,
              double    z[2][2]
             );
}

#endif

