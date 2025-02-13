// Name:
// Student Number:
// Date:

// Filename: tempMain.cpp
// Purpose: Demonstrate the use of function templates.

#include <iostream>
#include <string>
#include "matrix.h"

using namespace std;

template <typename T1>
void demoTemplate(Matrix<T1>& M, T1 array1[][MAXCOLS], T1 array2[][MAXCOLS]);

int main()
{
  string str1[MAXROWS][MAXCOLS] =
  {
    {"Congra", "Eric ", "ha"},
    {"alm", "fin", "La"}
  };
  string str2[MAXROWS][MAXCOLS] =
  {
    {"tulations,", "Harder", "s"},
    {"ost", "ished    the", "b!"}
  };
  int nums1[MAXROWS][MAXCOLS] =
  {
    {1,2,3},
    {4,5,6}
  };
  int nums2[MAXROWS][MAXCOLS] =
  {
    {6,5,4},
    {3,2,1}
  };
   float fnums1[MAXROWS][MAXCOLS] =
  {
    {6.953489,5.428534,4.234859},
    {3.21,2.873495,1.4189}
  };
   float fnums2[MAXROWS][MAXCOLS] =
  {
    {6.812349,5.1289,4.342189},
    {3.421378,2.4321789,1.241389}
  };

    Matrix<float> floatMatrix;


  Matrix<string> stringMatrix;
  Matrix<int> intMatrix;

  cout << "\nDemonstrating with string matrix:\n";
  demoTemplate(stringMatrix, str1, str2);

  cout << "\nDemonstrating with int matrix:\n";
  demoTemplate(intMatrix, nums1, nums2);
 
  cout << "\nDemonstrating with float matrix:\n";
  demoTemplate(floatMatrix, fnums1, fnums2);
  

  return 0;
}


template <typename T1>
void demoTemplate(Matrix<T1>& M, T1 array1[][MAXCOLS], T1 array2[][MAXCOLS])
{
  M.setMatrix(array1);
  cout << "\nMatrix set to first array" << endl;
  M.printMatrix();

  M.addMatrix(array2);
  cout << "\nMatrix incremented by second array" << endl;
  M.printMatrix();
} // end of demoTemplate function
