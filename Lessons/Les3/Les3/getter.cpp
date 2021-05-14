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
    
    // методы для получения элементов из private. Называются getter
    double *get_var(){return v;}
    int get_dim(){return dim;}
    
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

    double *ar = v1.get_var();
    int d = v1.get_dim();
    cout << endl << "lets print *ar:" << endl;
    cout << "(";
    for (int i=0;i<d-1;++i){
        cout << ar[i] <<", ";
    }
    cout<< ar[d-1] <<")"<<endl;
    return 0;
}
