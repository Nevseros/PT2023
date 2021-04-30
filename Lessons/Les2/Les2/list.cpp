#include <iostream>
using namespace std;

// создаем структуру Student
struct Student{
    int id;
    int age;
    string name;
    int score;
    Student *next;  //указатель на следующий элемент списка
};
// Не забываем в конце описания структуры ставить ;


// Работа с указателем
void print_list(Student *a){
    if(a == NULL){
        cout<<"The list is empty" << endl;;
    }
    else {
        Student *tmp = a;
        while(tmp != NULL){
            cout <<"id:\t" << tmp->id << endl;
            cout <<"name:\t" << tmp->name << endl;
            cout <<"age:\t" << tmp->age << endl;
            cout <<"score:\t" << tmp->score << endl << endl;
            tmp = tmp->next;
            }
         }
}

int main(){
    // объявляем переменную типа Student
    Student *students = NULL;
    
    print_list(students);
    
    //Создадим первого студента
    Student *new_student = new Student;
    new_student->id = 1;
    new_student->name = "Ivan";
    new_student->age = 20;
    new_student->score = 86;
    
    // укажем на следующий элемент - наш список студентов
    // то есть поместим нового студента в начало списка
    new_student->next = students;
    
    students = new_student;
    
    print_list(students);
    
    cout << "-------" << endl;
    
    
    // Добавим еще одного студента
    Student *tmp = students;
    
    //Найдем последний элемент (конец списка)
    while(tmp -> next)
        tmp = tmp->next;
    
    Student *new_student2 = new Student;
    new_student2->id = 2;
    new_student2->name = "Oleg";
    new_student2->age = 18;
    new_student2->score = 75;
    new_student2->next = NULL;
    
    //Запишем нового студента в конец
    tmp->next = new_student2;

    print_list(students);
    
    
    cout << "-------" << endl;

    //Попробуем добавить нового студента в начало списка
    Student *new_student3 = new Student;
    new_student3->id = 3;
    new_student3->name = "Elena";
    new_student3->age = 19;
    new_student3->score = 80;
    new_student3->next = students;
    students = new_student3;
    
    print_list(students);
    
    return 0;
}
