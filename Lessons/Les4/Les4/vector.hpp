#ifndef vector_hpp
#define vector_hpp

#include <stdio.h>

class Vector{
    
private:
    int dim;
    double *v;
    int number;
    
//    friend Vector operator+(Vector &vect1, Vector &vect2);
    friend Vector vec_sum(Vector &vect1, Vector &vect2);
    friend class Matrix;
    
public:
    static int count;
    
    Vector(int d, double *var);
    Vector(int d);
    ~Vector();
    
    Vector operator+(Vector &vect2);
    
    int get_dim();
    void set_dim(int d);
    
    void print();
};

#endif /* vector_hpp */
