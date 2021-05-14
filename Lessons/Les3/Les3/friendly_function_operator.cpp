#include <iostream>

using namespace std;

class Vector{

// все содержимое класса по умолчанию является private
private:
    int dim;
    double *v;
    int number;
    
    // выполним сложение векторов через дружественную функцию
    // дружественные функции имеют доступ к данным в private
    // не имеет значения где объявлена дружественная функция (private/public)
    // определим оператор сложения двух векторов
    friend Vector operator+(Vector &vect1, Vector &vect2);
        
// Если мы хотим иметь доступ к каким-либо элементам, то объявляем их в public
public:
    static int count;
    //два разных конструктора
    Vector(int d);
    Vector(int d, double *var);
    
    void print();
};

int Vector::count=0;


// Конструктор для создания нулевого вектора размера d
Vector::Vector(int d)
{
    count++;
    number=count;
    cout<<"Constructor vector(int) made vector #"<<number<<endl;
    dim=d;
    v=new double[dim];
    for(int i=0;i<dim;i++)
        v[i]=0;
}

// Конструктор для создания вектора размера d, со значениями массива *var
Vector::Vector(int d,double *var)
{
    count++;
    number=count;
    cout<<"Constructor vector(int,double*) made vector #"<<number<<endl;
    dim=d;
    v=new double[dim];
    for(int i=0;i<dim;i++)
        v[i]=var[i];
}

// Оператор сложения двух векторов
Vector operator+(Vector &vect1,Vector &vect2)
    {
        cout<<"Summing vector #"<<vect1.number<<" with vector #"<<vect2.number<<endl;
        Vector tmp(vect1.dim);
        for(int i=0;i<vect1.dim;i++)
            tmp.v[i]=vect1.v[i]+vect2.v[i];
        return tmp;
    }

void Vector::print()
{
    cout<<"Vector #"<<number<<"(";
    for(int i=0;i<dim-1;i++)
        cout<<v[i]<<",";
    if(dim!=0)
        cout<<v[dim-1]<<")\n";
    else
        cout<<")\n";
}



int main(int argc, const char * argv[]) {
    
    double *a1 = new double[]{1,2,3};
    double *a2 = new double[]{4,4,4};
    
    Vector v1(3,a1);
    Vector v2(3,a2);
    
    v1.print();
    v2.print();
    
    Vector v3 = v1 + v2;
    
    v3.print();
    return 0;
}
