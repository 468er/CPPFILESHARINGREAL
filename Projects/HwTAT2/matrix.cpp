// Name:
// Student Number:
// Date:

#include "matrix.h"
#include <iostream>
using namespace std;

template <typename T>
 Matrix<T>::Matrix()
{
  rows = MAXROWS;
  cols = MAXCOLS;
  for (int x = 0; x < rows; x++)
  {
    for (int y = 0; y < cols; y++)
    {
      doubleArray[x][y] = '\0';
    }
  }
}

template<typename T>
void Matrix<T>::printMatrix()
{
  for (int r = 0; r < rows; r++)
  {
    for (int c = 0; c < cols; c++)
    {
      cout << doubleArray[r][c] << "   ";
    }
    cout << endl;
  }
}

template<typename T>
void Matrix<T>::setMatrix(T otherArray[][MAXCOLS])
{
  for (int rowNum = 0; rowNum < rows; rowNum++)
  {
    for (int colNum = 0; colNum < cols; colNum++)
    {
      doubleArray[rowNum][colNum] = otherArray[rowNum][colNum];
    }
  }
}

template<typename T>
void Matrix<T>::addMatrix(T otherArray[][MAXCOLS])
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      doubleArray[i][j] += otherArray[i][j];
    }
  }
}

template<typename T>
void Matrix<T>::addMatrix(Matrix otherMatrix)
{
  addMatrix(otherMatrix.doubleArray);
}

// add template types below.
template class Matrix<int>;
template class Matrix<string>;
template class Matrix<double>;
template class Matrix<float>;

