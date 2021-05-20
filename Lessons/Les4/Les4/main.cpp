#include <iostream>
#include "matrix.hpp"

int main(int argc, const char * argv[]) {
    
    int d = 5;
    double *array = new double[d]{1,2,3,4,5};
    double *array2 = new double[d]{2,2,2,2,2};

    
    Vector a(d, array);
    Vector b(d, array2);
   
    a.print();
    b.print();
    
    Vector c = a + b;
    
    c.print();
    
    double **matr_array1 = new double *[3]{
        new double[3]{1,2,3},
        new double[3]{4,5,6},
        new double[3]{7,8,9}
    };
    
    double **matr_array2 = new double *[3]{
        new double[3]{1,1,1},
        new double[3]{1,1,1},
        new double[3]{1,1,1}
    };
    
    Matrix m1(3, matr_array1);
    Matrix m2(3, matr_array2);
    
    m1.print();
    m2.print();
    
    Matrix m3 = m1 + m2;
    
    m3.print();
    
    return 0;
}
