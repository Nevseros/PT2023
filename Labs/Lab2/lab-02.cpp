#include <stdio.h>
#include <iostream>
#include <cstdlib>
using namespace std;

class Vector {
    public:
        static int vectorsCreated;

        Vector(int dim);
        Vector(int dim, double *arr);
        ~Vector();
        
        Vector operator+(Vector &vector2);
        Vector operator-(Vector &vector2);
        Vector operator-();
        double operator*(Vector &vector2);
        Vector operator=(Vector &vector2);

        void print();

    private:
        int dimensions, number;
        double *arrayOfCoordinates;
};

Vector::Vector(int dim) {
    vectorsCreated++;
    number = vectorsCreated;

    cout << "Constructor Vector(int) created a new vector #" << number << endl;
    dimensions = dim;

    arrayOfCoordinates = new double[dim];
    for (int i = 0; i < dimensions; i++) {
        arrayOfCoordinates[i] = 0;
    }
}

Vector::Vector(int dim, double *arr) {
    vectorsCreated++;
    number = vectorsCreated;

    cout << "Constructor Vector(int, double *) created a new vector #" << number << endl;
    dimensions = dim;

    arrayOfCoordinates = new double[dim];
    for (int i = 0; i < dimensions; i++) {
        arrayOfCoordinates[i] = arr[i];
    }
}

Vector::~Vector() {
    cout << "Destructing vector #"<< number << endl;
    delete[] arrayOfCoordinates;
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
        res.arrayOfCoordinates[i] = arrayOfCoordinates[i] + vector.arrayOfCoordinates[i];
    }

    if (maxDims != minDims) {
        if (flag) {
            for (int i = minDims; i < maxDims; i++) {
                res.arrayOfCoordinates[i] = arrayOfCoordinates[i];
            }
        } else {
            for (int i = minDims; i < maxDims; i++) {
                res.arrayOfCoordinates[i] = vector.arrayOfCoordinates[i];
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
        res.arrayOfCoordinates[i] = arrayOfCoordinates[i] - vector.arrayOfCoordinates[i];
    }

    if (maxDims != minDims) {
        if (flag) {
            for (int i = minDims; i < maxDims; i++) {
                res.arrayOfCoordinates[i] = arrayOfCoordinates[i];
            }
        } else {
            for (int i = minDims; i < maxDims; i++) {
                res.arrayOfCoordinates[i] = -1 * vector.arrayOfCoordinates[i];
            }
        }
        
    }

    return res;
}

Vector Vector::operator-() {
    cout << "Opposite vector of vector #" << number << endl;

    Vector res(dimensions);
    for (int i = 0; i < res.dimensions; i++){
        res.arrayOfCoordinates[i] = -1 * arrayOfCoordinates[i];
    }

    return res;
}

double Vector::operator*(Vector &vector) {
    cout << "Multiple of vector #" << number << " and vector #" << vector.number << endl;

    double res;
    for (int i = 0; i < dimensions && i < vector.dimensions; i++) {
        res += arrayOfCoordinates[i] * vector.arrayOfCoordinates[i];
    }

    return res;
}

Vector Vector::operator=(Vector &vector) {
    Vector res(dimensions);
    for (int i = 0; i < dimensions; i++) {
        res.arrayOfCoordinates[i] = arrayOfCoordinates[i];
    }

    return res;
}

void Vector::print() {
    cout << "Vector #" << number << "(";

    for (int i = 0; i < dimensions - 1; i++){
        cout << arrayOfCoordinates[i] << ", ";
    }
    
    cout << arrayOfCoordinates[dimensions - 1] << ")\n";
}

int Vector::vectorsCreated = 0;

int main() {
    int dims1 = 5, dims2 = 7, dims3 = 2;
    double *arr1 = new double[dims1]{1, 2, 3, 4, 5};
    double *arr2 = new double[dims1]{2, 2, 2, 2, 2};
    double *arr3 = new double[dims2]{1, 2, 3, 2, 0, 1, 4};
    double *arr4 = new double[dims3]{7, 4};
    double *arr5 = new double[dims2]{1, 3, 2, 1, 5, 0, 0};

    Vector a(dims1, arr1);
    Vector b(dims1, arr2);
    Vector c(dims2, arr3);
    Vector d(dims3, arr4);
    Vector e(dims2, arr5);
    cout << "\n";
   
    a.print();
    b.print();
    c.print();
    d.print();
    e.print();
    cout << "\n";

    // Сумма a и b + присваивание
    Vector x = a + b;
    x.print();
    cout << "\n";

    // Разность c и b + присваивание
    Vector t = b - c;
    t.print();
    cout << "\n";

    // Произведение c и d + присваивание
    cout << c * d;
    cout << "\n\n";

    // Унарный минус для e + присваивание
    Vector z = -e;
    z.print();
    cout << "\n";
    
    return 0;
}