//
// Created by radek on 30.03.17.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <string.h>
#include <complex>
using namespace std;
class Matrix{
    complex<double> **var;
    int row,col;
public:
    Matrix(string string1);
    Matrix(int _row, int _col);
    Matrix additon(Matrix m2);
    Matrix subtraction(Matrix m2);
    Matrix div (complex<double> compscalar);
    Matrix div (Matrix m2);






};

#endif //JIMP_EXERCISES_MATRIX_H
