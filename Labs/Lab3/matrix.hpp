#ifndef matrix_hpp
#define matrix_hpp

#include "vector.hpp"
//#pragma once

class Matrix {

    public:
        static int matrixesCreated;

        Matrix(int c, int r);
        Matrix(int c, int r, double **arr);
        ~Matrix();

        Matrix operator+(const Matrix &matrix);
        Matrix operator-(const Matrix &matrix);
        Matrix operator-();
        Matrix operator*(const Matrix &matrix);
        Matrix operator*(Vector &vector);
        Matrix operator*(const int coeff);
        Matrix& operator=(Matrix matrix);

        void print();

    private:
        int columns, rows, number;
        double **arrayOfValues;
};

#endif