//
// Created by radek on 30.03.17.
//

#include "Matrix.h"
Matrix::Matrix(int _row, int _col) {
    row=_row;
    col=_col;
    *var=new complex<double>[col];
    for (int j = 0; j <col ; ++j) {
        var[j]=new complex<double> [row];
    }
}

Matrix::Matrix(string string1) {
    for (int i = 0; i <string1.length() ; i++) {
        if (string1[i]==' ' and row==0) col++;
        if (string1[i]==';') row++;
    }
    row++;
    col++;
    *var=new complex<double>[col];
    for (int j = 0; j <col ; ++j) {
        var[j]=new complex<double> [row];
    }
    string tmp,tmp2;
    int r=0,c=0;
    for (int k = 0; k <string1.length() ; k++) {
        if (string1[k]!=' ' or string1[k]!=';') tmp+=string1[k];
        else
        {
            var[r][c].complex(stod(tmp.substr(0,tmp.find('i')-1)),stod(tmp.substr(tmp.find('i')+1,tmp.length())));
            r++;
            c++;
            tmp.clear();
        }

    }
}
Matrix Matrix::additon(Matrix m2) {
    if(col==m2.col and row==m2.row)
    {
        for (int i = 0; i <row ;i++) {
            for (int j = 0; j <col ; j++) {
                m2.var[i][j]+=var[i][j];
            }

        }
    }
    return m2;
}
Matrix Matrix::subtraction(Matrix m2)  {

    if(col==m2.col and row==m2.row)
    {
        for (int i = 0; i <row ;i++) {
            for (int j = 0; j <col ; j++) {
                m2.var[i][j]-=var[i][j];
            }

        }
    }
    return m2;
}
Matrix Matrix::div(complex<double> compscalar) {


    for (int i = 0; i <row ;i++) {
        for (int j = 0; j <col ; j++) {
            var[i][j].real(var[i][j].real()*compscalar.real()-var[i][j].imag()*compscalar.imag());
            var[i][j].imag(var[i][j].real()*compscalar.imag()+var[i][j].imag()*compscalar.real());
        }

    }
    return *this;
}
Matrix Matrix::div(Matrix m2) {

    if( col==m2.row)
    {
        double real,imag;
        Matrix res(row,m2.col);
        for(int i = 0; i < row; i++)
            for(int j = 0; j < m2.col; j++)
            {
                real=0;
                imag=0;
                for(int k = 0; k < col; k++)
                {
                    imag+=(var[i][k].real()*m2.var[k][j].imag()+var[i][k].imag()*m2.var[k][j].real());
                    real+=(var[i][k].real()*m2.var[k][j].real()-var[i][k].imag()*m2.var[k][j].imag());

                }
                res.var[i][j].imag(imag);
                res.var[i][j].real(real);
            }

    }
}
