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
    
    //Деструктор
    ~Vector();
    
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

Vector::~Vector(){
    // Динамически удаляем массив для которого выделили память
    delete[] v;
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
    
    Vector v1(3,a1);
    Vector v2(3);
    
    v1.print();
    v2.print();
    return 0;
}
