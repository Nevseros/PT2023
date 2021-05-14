#include <iostream>

using namespace std;

class Vector{

// все содержимое класса по умолчанию является private
private:
    int dim;
    double *v;
    int number;
        
// Если мы хотим иметь доступ к каким-либо элементам, то объявляем их в public
public:
    static int count;
    //два разных конструктора
    Vector(int d);
    Vector(int d, double *var);
    
    // Выполним сложение двух векторов через метод класса
    // В данном случае в функцию передается только второй вектор, который находится справа от знака +
    Vector operator+(Vector &vect2);
    
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
//тут нужно указать, что данная функция является методом класса (Vector::operator)
Vector Vector::operator+(Vector &vect2)
    {
        // Тут мы можем использовать все переменные из private (например number)
        // По факту используется скрытый указатель, который говорит о том, что переменная number является элементом первого вектора
        // записи "this->number" и "number" эквивалентны
        cout<<"Summing vector #"<<number<<" with vector #"<<vect2.number<<endl;
        Vector tmp(dim);
        for(int i=0;i<dim;i++)
            tmp.v[i]=v[i]+vect2.v[i];
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
    double *a2 = new double[]{3,2,1};
    
    Vector v1(3,a1);
    Vector v2(3,a2);
    
    v1.print();
    v2.print();
    
    Vector v3 = v1 + v2;
    
    v3.print();
    return 0;
}
