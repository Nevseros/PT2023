#include "vector.hpp"
#include <iostream>

using namespace std;

int Vector::count = 0;

// constructor (int)
Vector::Vector(int d){
    count++;
    number = count;
    
    cout << "Constructor Vector(int) made vector #"<< number << endl;
    dim = d;
    
    v = new double[dim];
    
    for (int i=0; i<dim; ++i){
        v[i] = 0;
    }
}

//constructor (int, double)
Vector::Vector(int d, double *var){
    count++;
    number = count;
    
    cout << "Constructor Vector(int, double*) made vector #"<< number << endl;
    dim = d;
    
    v = new double[dim];
    
    for (int i=0; i<dim; ++i){
        v[i]=var[i];
    }
}

// destructor
Vector::~Vector(){
    cout << "Destructor of vector #"<< number << endl;
    delete[] v;
}

// print vector
void Vector::print(){
    cout << "Vector #"<<number<< "(";
    for (int i=0; i<dim-1; ++i){
        cout << v[i] << ", ";
    }
    cout << v[dim-1] << ")" << endl;
}

// method-operator "+"
Vector Vector::operator+(Vector &vect2){
    cout << "Summing Vector #" << number << " with vector #" << vect2.number << endl;
    Vector tmp(dim);
    for (int i=0;i<tmp.dim; ++i){
        tmp.v[i] = v[i] + vect2.v[i];
    }
    return tmp;
}
