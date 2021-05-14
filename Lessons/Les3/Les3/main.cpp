#include <iostream>

using namespace std;

class Vector{
    
private:
    int dim;
    double *v;
    int number;
    
//    friend Vector operator+(Vector &vect1, Vector &vect2);
    friend Vector vec_sum(Vector &vect1, Vector &vect2);
    
public:
    static int count;
    
    Vector(int d, double *var);
    Vector(int d);
    
    ~Vector(){
        cout << "Destructor of vector #"<< number << endl;
        delete[] v;
    }
    
    Vector operator+(Vector &vect2);
    
    int get_dim(){return dim;}
    void set_dim(int d){dim = d;}
    
    void print();
};


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

void Vector::print(){
    cout << "Vector #"<<number<< "(";
    for (int i=0; i<dim-1; ++i){
        cout << v[i] << ", ";
    }
    cout << v[dim-1] << ")" << endl;
}

Vector Vector::operator+(Vector &vect2){
    cout << "Summing Vector #" << number << " with vector #" << vect2.number << endl;
    Vector tmp(dim);
    for (int i=0;i<tmp.dim; ++i){
        tmp.v[i] = v[i] + vect2.v[i];
    }
    return tmp;
}

Vector vec_sum(Vector &vect1, Vector &vect2){
    cout << "Summing Vector #" << vect1.number << " with vector #" << vect2.number << endl;
    Vector tmp(vect1.dim);
    for (int i=0;i<tmp.dim; ++i){
        tmp.v[i] = vect1.v[i] + vect2.v[i];
    }
    return tmp;
}

int Vector::count = 0;

int main() {
    
    int d = 5;
    double *array = new double[d]{1,2,3,4,5};
    double *array2 = new double[d]{2,2,2,2,2};

    
    Vector a(d, array);
    Vector b(d, array2);
   
    a.print();
    b.print();
    
    Vector c = a + b;
    
    c.print();
        
    return 0;
}
