#ifndef vector_hpp
#define vector_hpp

//#pragma once

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
        int getDimensions();
        double *getArrayOfValues();

    private:
        int dimensions, number;
        double *arrayOfValues;
};

#endif