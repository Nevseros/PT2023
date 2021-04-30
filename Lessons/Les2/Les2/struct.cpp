#include <iostream>
using namespace std;

// создаем структуру Student
struct Student{
    int id;
    int age;
    string name;
    int score;
}; // Не забываем в конце описания структуры ставить ;

// Работа с переменной
void print_student(Student a){
    cout <<"id:\t" << a.id << endl;
    cout <<"name:\t" << a.name << endl;
    cout <<"age:\t" << a.age << endl;
    cout <<"score:\t" << a.score << endl << endl;
}

// Работа с указателем
void print_student(Student *a){
    cout <<"id:\t" << a->id << endl;
    cout <<"name:\t" << a->name << endl;
    cout <<"age:\t" << a->age << endl;
    cout <<"score:\t" << a->score << endl << endl;

}

int main(){
    // объявляем переменную типа Student
    Student some_student;
    
    // задаем значения полей
    some_student.name = "Ivan";
    some_student.age = 20;
    some_student.id = 1;
    some_student.score = 86;
    
    //Динамически выделим еще один экземпляр
    Student *second_student = new Student;
        
    // задаем значения полей для указателя
    (*second_student).name = "Oleg";    // доступ к полю указателя
    second_student->age = 18;           // аналогичный способ доступа
    second_student->id = 2;
    second_student->score = 75;
    
    //Выводим все поля на экран
    print_student(some_student);
    print_student(second_student);
    return 0;
}
