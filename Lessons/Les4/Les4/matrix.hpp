#ifndef matrix_hpp
#define matrix_hpp

#include <stdio.h>
#include "vector.hpp"

class Matrix
{
    int dim;
    double **b;
    friend Matrix& operator*(double c,Matrix& m);
public:
    static int countmatr;
    int number;
    Matrix(int d);
    Matrix(int d, double **x);
    
//    ~Matrix();
    
    void print()const;
    Matrix operator+(const Matrix &m);//сумма матриц
//    Matrix& operator-(const Matrix &m);//разность матриц
//    Matrix& operator-();//-матрица
//    Matrix operator*(const Matrix &m) const;//произведение матриц
//    Matrix& operator=(const Matrix &m);//присваивание (матр)
//    Matrix& operator*(double c);//умножение на число
//    void antimatr() const;//диагональ
//    Vector operator*(const Vector& v) const;//умножение на вектор
};

#endif /* matrix_hpp */
