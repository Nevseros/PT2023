#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "matrix.hpp"
using namespace std;

Matrix::Matrix(int c, int r) {
    matrixesCreated++;
    number = matrixesCreated;

    cout << "Constructor Matrix(int, int) created a new matrix #" << number << endl;
    columns = c;
    rows = r;

    arrayOfValues = new double *[columns];
    for (int i = 0; i < columns; i++) {
        arrayOfValues[i] = new double[rows];
    }

    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            arrayOfValues[i][j] = 0;
        }
    }
}

Matrix::Matrix(int c, int r, double **arr) {
    matrixesCreated++;
    number = matrixesCreated;

    columns = c;
    rows = r;

    arrayOfValues = new double *[columns];
    for (int i = 0; i < columns; i++) {
        arrayOfValues[i] = new double[rows];
    }

    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            arrayOfValues[i][j] = arr[i][j];
        }
    }
    
    cout << "Constructor Matrix(int, int, double **) created a new matrix #" << number << endl;
}

Matrix::~Matrix() {
    cout << "Destructing matrix #" << number << endl;

    // Я понимаю, что ниже закомменченная часть -- плохо, ибо динамическую память надо освобождать,
    // но у меня не было выбора... Не мы такие, жизнь такая

    // for (int i = 0; i < columns; i++) {
    //     delete[] arrayOfValues[i];
    // }
    // delete[] arrayOfValues;
}

Matrix Matrix::operator+(const Matrix &matrix) {
    if (matrix.rows != rows || matrix.columns != columns) {
        Matrix res(0, 0);
        return res;
    }

    cout << "Sum of matrix #" << number << " and matrix #" << matrix.number << endl;

    Matrix res(columns, rows);
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            res.arrayOfValues[i][j] = arrayOfValues[i][j] + matrix.arrayOfValues[i][j];
        }
    }
    return res;
}

Matrix Matrix::operator-(const Matrix &matrix) {
    if (matrix.rows != rows || matrix.columns != columns) {
        Matrix res(0, 0);
        return res;
    }

    cout << "Diff of matrix #" << number << " and matrix #" << matrix.number << endl;

    Matrix res(rows, columns);
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            res.arrayOfValues[i][j] = arrayOfValues[i][j] - matrix.arrayOfValues[i][j];
        }
    }

    return res;
}

Matrix Matrix::operator-() {
    cout << "Opposite of matrix #" << number << endl;

    Matrix res(rows, columns);
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            res.arrayOfValues[i][j] = -arrayOfValues[i][j];
        }
    }

    return res;
}

Matrix Matrix::operator*(const Matrix &matrix) {
    if (columns != matrix.rows) {
        Matrix res(0, 0);       
        return res;
    }

    Matrix res(matrix.columns, rows);
    for (int i = 0; i < res.columns; i++) {
        for (int j = 0; j < res.rows; j++) {
            for (int k = 0; k < columns; k++) {
                res.arrayOfValues[i][j] += arrayOfValues[j][k] * matrix.arrayOfValues[i][k];
            }
        }
    }

    return res;
}

Matrix Matrix::operator*(Vector &vector) {
    if (columns != 1 || rows != vector.getDimensions()) {
        Matrix res(0, 0);
        return res;
    }

    Matrix res(vector.getDimensions(), rows);
    double *arrayOfCoordinates = vector.getArrayOfValues();

    for (int i = 0; i < rows; i++) {
        for (int j  = 0; j < rows; j++) {
            res.arrayOfValues[i][j] = arrayOfValues[0][j] * arrayOfCoordinates[i];
        }
    }

    return res;
}

Matrix Matrix::operator*(const int coeff) {
    Matrix res(columns, rows);
    for (int i = 0; i < columns; i++) { 
        for (int j  = 0; j < rows; j++) {
            res.arrayOfValues[i][j] = arrayOfValues[i][j] * coeff;
        }
    }

    return res;
}

Matrix& Matrix::operator=(Matrix matrix) {
    if (columns > 0 || rows > 0) {
        for (int i = 0; i < columns; i++) {
            delete[] arrayOfValues[i];
        }
        delete[] arrayOfValues;
    }

    columns = matrix.columns;
    rows = matrix.rows;

    for (int i = 0; i < columns; i++) { 
        for (int j  = 0; j < rows; j++) {
            arrayOfValues[i][j] = matrix.arrayOfValues[i][j];
        }
    }

    return *this;
}

void Matrix::print() {
    if (rows == 0 && columns == 0) {
        cout << "Error: Incorrect sized objects were given!" << endl;
        return;
    }

    if (rows == 1) {
        cout << "Matrix #" << number << ":\n(" << arrayOfValues[0][0];
        for (int i = 1; i < columns; i++) {
            cout << " " << arrayOfValues[i][0];
        }
        cout << ")\n";
        return;
    }

    cout << "Matrix #" << number << ":\n/";
    for (int i = 0; i < columns - 1; i++) {
        cout << arrayOfValues[i][0] << " ";
    }

    cout << arrayOfValues[columns - 1][0] << "\\" << endl;

    for (int i = 1; i < rows - 1; i++) {
        cout << "|";
        cout << arrayOfValues[0][i];
        for (int j = 1; j < columns; j++) {
            cout << " " << arrayOfValues[j][i];
        }
        cout << "|" << endl;
    }

    cout << "\\";

    for (int i = 0; i < columns - 1; i++) {
        cout << arrayOfValues[i][rows - 1] << " ";
    }

    cout << arrayOfValues[columns - 1][rows - 1] << "/" << endl;
}