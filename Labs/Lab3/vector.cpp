#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "vector.hpp"
using namespace std;

Vector::Vector(int dim) {
    vectorsCreated++;
    number = vectorsCreated;

    cout << "Constructor Vector(int) created a new vector #" << number << endl;
    dimensions = dim;

    arrayOfValues = new double[dim];
    for (int i = 0; i < dimensions; i++) {
        arrayOfValues[i] = 0;
    }
}

Vector::Vector(int dim, double *arr) {
    vectorsCreated++;
    number = vectorsCreated;

    cout << "Constructor Vector(int, double *) created a new vector #" << number << endl;
    dimensions = dim;

    arrayOfValues = new double[dim];
    for (int i = 0; i < dimensions; i++) {
        arrayOfValues[i] = arr[i];
    }
}

Vector::~Vector() {
    cout << "Destructing vector #"<< number << endl;
    delete[] arrayOfValues;
}

Vector Vector::operator+(Vector &vector){
    cout << "Summ of vector #" << number << " and vector #" << vector.number << endl;

    int maxDims, minDims;
    bool flag = true;
    if (dimensions < vector.dimensions) {
        maxDims = vector.dimensions;
        minDims = dimensions;
        flag = false;
    } else {
        maxDims = dimensions;
        minDims = vector.dimensions;
    }

    Vector res(maxDims);
    for (int i = 0; i < minDims; i++){
        res.arrayOfValues[i] = arrayOfValues[i] + vector.arrayOfValues[i];
    }

    if (maxDims != minDims) {
        if (flag) {
            for (int i = minDims; i < maxDims; i++) {
                res.arrayOfValues[i] = arrayOfValues[i];
            }
        } else {
            for (int i = minDims; i < maxDims; i++) {
                res.arrayOfValues[i] = vector.arrayOfValues[i];
            }
        } 
    }

    return res;
}

Vector Vector::operator-(Vector &vector) {
    cout << "Diff of vector #" << number << " and vector #" << vector.number << endl;

    int maxDims, minDims;
    bool flag = true;
    if (dimensions < vector.dimensions) {
        maxDims = vector.dimensions;
        minDims = dimensions;
        flag = false;
    } else {
        maxDims = dimensions;
        minDims = vector.dimensions;
    }

    Vector res(maxDims);
    for (int i = 0; i < minDims; i++){
        res.arrayOfValues[i] = arrayOfValues[i] - vector.arrayOfValues[i];
    }

    if (maxDims != minDims) {
        if (flag) {
            for (int i = minDims; i < maxDims; i++) {
                res.arrayOfValues[i] = arrayOfValues[i];
            }
        } else {
            for (int i = minDims; i < maxDims; i++) {
                res.arrayOfValues[i] = -1 * vector.arrayOfValues[i];
            }
        }
        
    }

    return res;
}

Vector Vector::operator-() {
    cout << "Opposite vector of vector #" << number << endl;

    Vector res(dimensions);
    for (int i = 0; i < res.dimensions; i++){
        res.arrayOfValues[i] = -1 * arrayOfValues[i];
    }

    return res;
}

double Vector::operator*(Vector &vector) {
    cout << "Multiple of vector #" << number << " and vector #" << vector.number << endl;

    double res;
    for (int i = 0; i < dimensions && i < vector.dimensions; i++) {
        res += arrayOfValues[i] * vector.arrayOfValues[i];
    }

    return res;
}

Vector Vector::operator=(Vector &vector) {
    Vector res(dimensions);
    for (int i = 0; i < dimensions; i++) {
        res.arrayOfValues[i] = arrayOfValues[i];
    }

    return res;
}

void Vector::print() {
    cout << "Vector #" << number << "(";

    for (int i = 0; i < dimensions - 1; i++){
        cout << arrayOfValues[i] << ", ";
    }
    
    cout << arrayOfValues[dimensions - 1] << ")\n";
}

int Vector::getDimensions() {
    return dimensions;
}

double* Vector::getArrayOfValues() {
    double *arrayOfCoordinates = new double[dimensions];

    for (int i = 0; i < dimensions; i++) {
        arrayOfCoordinates[i] = arrayOfValues[i];
    }

    return arrayOfCoordinates;
}