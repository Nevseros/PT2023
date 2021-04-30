#include <iostream>
using namespace std;


void bad_func(){
    int len;
    cout << "Введите размер массива: ";
    cin>>len;
    int array[len]; // размер массива должен быть известен на этапе компилляции
    
    cout << "Размер массива (байт): " << sizeof(array) << endl;
    
    for (int i=0; i<len; ++i){
        array[i] = i;
    }
    cout << array[len-1] << endl;
}

void good_func(){
    // Желательно заводить константу для определения размера массива и далее использовать ее
    const int len = 100;
    
    int array[len]; // размер массива должен быть известен на этапе компилляции
    
    for (int i=0; i<len; ++i){
        array[i] = i;
    }
    cout << array[len-1] << endl;
}

void dynamic_func(){
    int len;
    
    cout << "Введите размер массива: ";
    cin>>len;
    
    int *array = new int[len]; // используем оператор new[] для выделения массива. Обратите внимание, переменная length не обязательно должна быть константой!
    
    cout << "Размер массива (байт): " << sizeof(array) << endl;
    
    for (int i=0; i<len; ++i){
        array[i] = i;
    }
    cout << array[len-1] << endl;
}


int main(){
    dynamic_func();
    return 0;
}
