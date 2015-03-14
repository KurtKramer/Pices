/* Matrix.h -- A simple two dimensional floating point matrix.
 * Copyright (C) 1994-2011 Kurt Kramer
 * For conditions of distribution and use, see copyright notice in KKB.h
 */
#ifndef  _MATRIX_
#define  _MATRIX_
//****************************************************************************************
//*                                   Matrix Class                                       *
//*                                                                                      *
//*                                                                                      *
//*  Supports two dimensional matrices.                                                  *
//*                                                                                      *
//*  Developed for Machine Learning Project for support of Import Vector Machine.        *
//*  Handles two dimensional matrixes.  Functions supported are matrix addition, sub-    *
//*  traction, multiplication, transpose, determinant, and inversion.  Where appropriate *
//*  arithmetic operators +, -, * were overloaded.  Addition, Subtraction and Multipli-  *
//*  cation can be done against either another matrix or scaler.                         *
//*                                                                                      *
//*======================================================================================*
//*                                                                                      *
//*     Date      Descriptions                                                           *
//*  ===========  ====================================================================== *
//*  Nov-11-2002  Initial Development.                                                   *
//*                                                                                      *
//****************************************************************************************

#include <fstream>

#include  "KKBaseTypes.h"

namespace  KKB
{
  class  Row; 
  typedef Row*  RowPtr;

  /**
   *@class  Matrix
   *@brief  Supports two dimensional matrices.
   *@details  Developed for Machine Learning Project for support of Import Vector Machine.
   *  Handles two dimensional matrixes.  Functions supported are matrix addition, subtraction
   *  multiplication, transpose, determinant, and inversion.  Where appropriate arithmetic
   *  arithmetic operators +, -, * were overloaded.  Addition, Subtraction and Multiplication
   *  can be done against either another matrix or scaler.  Also Transpose and Determinant
   *  operations are supported.
   */
  class  Matrix
  {
  public:
    typedef  Matrix*  MatrixPtr;

    Matrix ();

    Matrix (kkint32  _numOfRows,
            kkint32  _numOfCols
           );

    Matrix (const Matrix&  _matrix);

    Matrix (const VectorDouble&  _v);

    ~Matrix ();

    template<typename T>
    static  MatrixPtr  BuildFromArray (kkint32 numOfRows,
                                       kkint32 numOfCols,
                                       T**   data
                                      );

    Matrix&  operator=  (const Matrix&  right);

    Matrix&  operator=  (const VectorDouble&  right);

    Matrix&  operator*= (double  right);

    Matrix&  operator+= (double  right);
  
    Matrix&  operator+= (const Matrix&  right);

    Matrix   operator+  (const Matrix&  right);

    Matrix   operator+  (double  right);

    Matrix   operator-  (const Matrix&  right);  

    Matrix   operator-  (double right);  

    Matrix   operator*  (const Matrix&  right);

    Matrix   operator*  (double right);

    Row&     operator[] (kkint32  rowIDX) const;

    friend  Matrix  operator- (double left, const Matrix& right);


    MatrixPtr       CalcCoFactorMatrix ();

    /**
     *@brief  Returns a Covariance matrix.
     *@details  Each column represents a variable and each row represents an instance of each variable.
     *@return  Returns a symmetric matrix that will be (numOfRows x numOfRows) where each element will represent the covariance 
     *         between their respective variables.
     */
    MatrixPtr       Covariance ()  const;

    double** const  Data ()  const  {return  data;}

    double          Determinant ();

    double          DeterminantSlow ();  /**<  @brief Recursive Implementation. */

    void            EigenVectors (MatrixPtr&      eigenVectors,
                                  VectorDouble*&  eigenValues
                                 )  const;

    /** @brief  Locates the maximum value in a matrix along with the row and column that is is located. */
    void            FindMaxValue (double&  maxVal, 
                                  kkint32&     row, 
                                  kkint32&     col
                                 );

    VectorDouble    GetCol (kkint32 col)  const;

    Matrix          Inverse ();

    kkint32         NumOfCols () const  {return numOfCols;}

    kkint32         NumOfRows () const  {return numOfRows;}

    void            ReSize (kkint32 _numOfRows,
                            kkint32 _numOfCols
                           );

    bool            Symmetric ()  const;  /**< Returns true is the matrix is Symmetric */

    Matrix          Transpose ();

    friend  std::ostream&  operator<< (      std::ostream&  os, 
                                       const Matrix&        matrix
                                      );

  private:
    void  Destroy ();

    void  AllocateStorage ();

    double DeterminantSwap (double**        mat, 
                            unsigned short  offset
                           );

    double  CalcDeterminent (kkint32*  rowMap,
                             kkint32*  colMap,
                             kkint32 size
                            );

    double  Pythag (const double a,
                    const double b
                   )  const;

    kkint32  Tqli (double*  d, 
                 double*  e,
                 kkint32  n,
                 double** z
                )  const;

    void  Tred2 (double** a, 
                 kkint32  n, 
                 double*  d, 
                 double*  e
                )  const;

    double**  data;       /**< A two dimensional array that will index into 'dataArea'.       */
    double*   dataArea;   /**< one dimensional array that will contain all the matrixes data. */
    kkint32   numOfCols;
    kkint32   numOfRows;
    RowPtr    rows;
    kkint32   totNumCells; /**<  Total number of cells allocated  = (numOfRows x nmumOfCols). */
  };  /* matrix */


  typedef  Matrix::MatrixPtr  MatrixPtr;

  class  Row
  {
  public:
     Row  ();
 
     Row (kkint32  _numOfCols,
          double*  _cells
         );

     Row (const Row&  _row);

     ~Row ();


     double*  Cols ()  {return cells;}

     double&  operator[] (kkint32  idx);

     void  Define (kkint32  _numOfCols,
                   double*  _cells
                  );

  private:
    double*  cells;
    kkint32  numOfCols;
  };  /* Row */

  Matrix  operator- (double left, const Matrix& right);
}  /* KKB */




#endif

