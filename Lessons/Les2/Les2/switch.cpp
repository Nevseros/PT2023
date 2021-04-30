#include <iostream>
using namespace std;

int if_check(int some_param){
    if (some_param==1) cout << "Выполняем 1" <<endl;
    else if (some_param==2) cout << "Выполняем 2" <<endl;
    else if (some_param==3) cout << "Выполняем 3" <<endl;
    else cout << "Выполняем при любом другом" << endl;
    return 0;
}

int switch_check(int some_param){
    switch (some_param) {
        case 1:
            cout << "Выполняем 1"  << endl;
            break;
        case 2:
            cout << "Выполняем 2" << endl;
            break;
        case 3:
            cout << "Выполняем 3" << endl;
            break;

        default:
            cout << "Выполняем при любом другом" << endl;
            break;
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    int a, res;
    cout<<"Введите значение:";
    cin>>a;
    res = switch_check(a);
//    cout << "Результат: " << res << endl;
    return 0;
}
