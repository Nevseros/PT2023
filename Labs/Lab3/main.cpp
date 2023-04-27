#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "matrix.cpp"
#include "vector.cpp"
using namespace std;

int Vector::vectorsCreated = 0;
int Matrix::matrixesCreated = 0;

int main() {
    int val1 = 1, val2 = 2, val3 = 3, val4 = 4, val5 = 5, val6 = 6;

    double *arr1 = new double[val4]{1, 2, 3, 4};

    double **arr2 = new double *[val6];
    for (int i = 0; i < val6; i++) {
        arr2[i] = new double[val5];
    }
    for (int i = 0; i < val6; i++) {
        for (int j = 0; j < val5; j++) {
            arr2[i][j] = 10*i + j + 10;
        }
    }

    double **arr3 = new double *[val1];
    for (int i = 0; i < val1; i++) {
        arr3[i] = new double[val4];
    }
    for (int i = 0; i < val1; i++) {
        for (int j = 0; j < val4; j++) {
            arr3[i][j] = 10*i + j + 10;
        }
    }

    double **arr4 = new double *[val3];
    for (int i = 0; i < val3; i++) {
        arr4[i] = new double[val6];
    }
    for (int i = 0; i < val3; i++) {
        for (int j = 0; j < val6; j++) {
            arr4[i][j] = 7*j + 10;
        }
    }

    double **arr5 = new double *[val3];
    for (int i = 0; i < val3; i++) {
        arr5[i] = new double[val6];
    }
    for (int i = 0; i < val3; i++) {
        for (int j = 0; j < val6; j++) {
            arr5[i][j] = val6 - j + 10;
        }
    }

    Vector vector1(val4, arr1);
    vector1.print();
    cout << endl;

    Matrix matrix1(val6, val5, arr2);
    matrix1.print();
    cout << endl;

    Matrix matrix2(val1, val4, arr3);
    matrix2.print();
    cout << endl;

    Matrix matrix3(val3, val6, arr4);
    matrix3.print();
    cout << endl;

    Matrix matrix4(val3, val6, arr5);
    matrix4.print();
    cout << endl;

    Matrix matrix5 = matrix1 + matrix3;
    matrix5.print();
    cout << endl;

    Matrix matrix6 = matrix3 + matrix4;
    matrix6.print();
    cout << endl;

    Matrix matrix7 = matrix3 - matrix4;
    matrix7.print();
    cout << endl;

    Matrix matrix8 = -matrix2;
    matrix8.print();
    cout << endl;

    Matrix matrix9 = matrix1 * matrix4;
    matrix9.print();
    cout << endl;

    Matrix matrix10 = matrix2 * matrix1;
    matrix10.print();
    cout << endl;

    Matrix matrix11 = matrix2 * vector1;
    matrix11.print();
    cout << endl;

    Matrix matrix12 = matrix1 * 4;
    matrix12.print();
    cout << endl;

    return 0;
}