#include "matrix.hpp"
#include <iostream>

using namespace std;

int Matrix::countmatr=0;

Matrix::Matrix(int d)
{
    countmatr++;
    number=countmatr;
    dim=d;
    
    b=new double*[dim];
    for(int i=0;i<dim;i++)
    {
        b[i]=new double[dim];
    }
    
    for(int i=0;i<dim;i++)
        for(int j=0;j<dim;j++)
            b[i][j]=0;
    
    cout << endl << "Constructor matr(int) made new matrix #"<< number << endl<<endl;
}

Matrix::Matrix(int d,double **x)
{
    countmatr++;
    number=countmatr;
    dim=d;
    
    b=new double*[dim];
    for(int i=0;i<dim;i++)
        b[i]=new double[dim];
    
    for(int i=0;i<dim;i++)
        for(int j=0;j<dim;j++)
            b[i][j]=x[i][j];
    
    cout << endl << "Constructor matr(int, double**) made new matrix #"<< number << endl<<endl;
}

Matrix Matrix::operator+(const Matrix &m)//сумма матриц
{
    cout<<"summing matrix #"<<number<<" with matrix #"<<m.number<<endl;
    Matrix tmp(dim);
    for(int i=0;i<dim;i++)
        for(int j=0;j<dim;j++)
            tmp.b[i][j]=b[i][j]+m.b[i][j];
    return tmp;
}

void Matrix::print() const
{
    cout<<"matrix #"<<number<<endl;
    for(int i=0;i<dim;i++)
    {
        for(int j=0;j<dim;j++)
            cout<<b[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}
