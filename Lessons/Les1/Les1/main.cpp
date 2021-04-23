
// всё, что находится справа от двойного слеша - игнорируется компилятором

/* Это многострочный комментарий.
Эта строка игнорируется
и эта тоже. */

// Подключение стандартной библиотеки <iostream>
#include <iostream>

//using namespace std;


//функция main - основное тело программы
//int main() {
//    int a;      // объявляем целочисленную переменную a
//    a = 5;      // 5 имеет значение 5, которое затем присваивается переменной а
//    a = 4 + 6;  // 4 + 6 имеет значение 10, которое затем присваивается переменной а
//
//    int b;      // объявляем целочисленную переменную b
//    b = a;      // a имеет значение 10 (исходя из предыдущих операций), которое затем присваивается переменной b
//    b = b;      // b имеет значение 10, которое затем присваивается переменной b (ничего не происходит)
//    b = b + 2;  // b + 2 имеет значение 12, которое затем присваивается переменной b
//
//    int c = 8;  // инициализируем переменную c значением 8
//    std::cout << c;
//    return 0;
//}



//int main() {
////    std::cout используется для вывода значения (cOUT = вывод);
////    std::cin используется для получения значения (cIN = ввод);
////    std::endl - перенос строки. Символ \n - тоже
//    int a;
//    std::cout << "Введите число \n";
//    std::cin >> a;
//    std::cout << "Вы ввели число: " << a << std::endl;
//
//    return 0;
//}




// void означает, что функция не возвращает значения
void returnNothing()
{
    std::cout << "Hi!" << std::endl;
    // Эта функция не возвращает никакого значения, поэтому оператор return здесь не нужен
}

// Функция getValueFromUser() получает значение от пользователя, а затем возвращает его обратно в caller
int getValueFromUser()
{
   std::cout << "Enter an integer: ";
   int x;
   std::cin >> x;
   return x;
}

//int main()
//{
//    int a, b;
//    returnNothing();
//    a = getValueFromUser(); // первый вызов функции getValueFromUser()
//    b = getValueFromUser(); // второй вызов функции getValueFromUser()
//    std::cout << a << " + " << b << " = " << a + b << std::endl;
//
//   return 0;
//}



// Эта функция имеет один параметр типа int: a
void printValue(int a)
{
   std::cout << a << std::endl;
}
 
// Эта функция имеет два параметра типа int: a и b
// Функция add() принимает два целых числа в качестве параметров и возвращает их сумму
// Значения a и b определяет caller
//int add(int a, int b)
//{
//   return a + b;
//}

//int main()
//{
//    int s;
//    printValue(7); // 7 – это аргумент функции printValue()
//    s = add(4, 5); // 4 и 5 – это аргументы функции add()
//    std::cout << s << std::endl;
//
//   return 0;
//}




// Правило: Имена, которые используются внутри функции (включая параметры), доступны/видны только внутри этой же функции.

//int add(int a, int b) // здесь создаются переменные a и b функции add()
//{
//   return a + b;
//} // здесь a и b функции add() выходят из области видимости и уничтожаются
//
//int main()
//{
//   int a = 7; // здесь создается переменная a функции main()
//   int b = 8; // здесь создается переменная b функции main()
//   std::cout << add(a, b) << std::endl; // значения переменных a и b функции main() копируются в переменные a и b функции add()
//   return 0;
//} // здесь a и b функции main() выходят из области видимости и уничтожаются




//Оформление кода
//int main() {
//
//    int value; // корректно
//
//    int Value; // некорректно (должно начинаться с буквы в нижнем регистре)
//    int VALUE; // некорректно (должно начинаться с буквы в нижнем регистре)
//    int VaLuE; // некорректно (должно начинаться с буквы в нижнем регистре)
//
//
//    int my_variable_name;    // корректно (разделяется символом подчёркивания)
//    void my_function_name(); // корректно (разделяется символом подчёркивания)
//
//    int myVariableName;    // корректно (используется CamelCase)
//    void myFunctionName(); // корректно (используется CamelCase)
//
//    int my variable name;    // некорректно (пробелы запрещены)
//    void my function name(); // некорректно (пробелы запрещены)
//
//    int MyVariableName;       // работает, но не рекомендуется (следует начинать с буквы в нижнем регистре)
//    void MyFunctionName();    // работает, но не рекомендуется
//}

void func1() {
    int a = 5;
    std::cout << a;
}

void func2()
{
    int a = 5;
    std::cout << a;
}



//Типы данных
//void var_types(){
////    5 основных типов данных
//    bool bValue = true;         //true или false
//    char chValue = 'c';         //символ
//    int nValue = 123;           //целое число
//    float fValue = 2.34567;     //десятичная дробь
//    double dValue = 3.45678;    //десятичная дробь, диапазон значений больше чем float + точность выше
//
//
////    целочисленные типы
////    char        1 байт
////    short       2 байта
////    int         2 байта (но чаще всего 4 байта)
////    long        4 байта
////    long long   8 байт
//
////    signed      имеет знак + или -
////    unsigned    только +
//
//    signed char c;          // от -128 до 127
//    signed short s;         // от -32 768 до 32 767
//    signed int i;           // от -32 768 до 32 767 (если 2 байта)
//    signed long l;          // от -2 147 483 648 до 2 147 483 647
//    signed long long ll;    // от -9 223 372 036 854 775 808 до 9 223 372 036 854 775 807
//
//    unsigned char c1;       // от 0 до 255
//    unsigned short s1;      // от 0 до 65 535
//    unsigned int i1;        // от 0 до 65 535 (если 2 байта)
//    unsigned long l1;       // от 0 до 4 294 967 295
//    unsigned long long ll1; // от 0 до 18 446 744 073 709 551 615
//
//
//    // Числа с плавающей точкой
//    float floatValue;
//    double doubleValue;
//    long double doubleValue2;
//
//    char ch1(97);  // инициализация переменной типа char целым числом 97
//    char ch2('a'); // инициализация переменной типа char символом 'a' (97)
//
//    // Перевод переменной из одного типа данных в другой
//    std::cout << static_cast<int>(ch) << std::endl;
//}


// Логический тип переменных
//void check_bool(bool flag){
//
//    //Обычно логические переменные используются в условных операторах
//    if (flag){
//        std::cout << "flag is true" << std::endl;
//    }
//    else {
//        std::cout << "flag is false" << std::endl;
//    }
//}
//
//int main(){
//    bool test_flag = false;
//
//    //значение логических выражений является boolean
//    bool b1 = (5==1);
//    bool b2 = (5>1);
//    bool b3 = (5>5);
//    bool b4 = (5>=5);
//    bool b5 = (5!=1);
//
//    check_bool(test_flag);
//    check_bool(b1);
//    check_bool(b2);
//    check_bool(b3);
//    check_bool(b4);
//    check_bool(b5);
//
//
//    //Если в условный оператор if передать не нулевое число, то выполнится тело if
//    int a = 0;
//    if (a){
//        std::cout << "if body" << std::endl;
//    }
//    else{
//        std::cout << "else body" << std::endl;
//    }
//
//    return 0;
//}



// Массивы
//int main(){
//    // объявим массив из пяти целых чисел
//    int array[5]; // массив из пяти чисел
//
//    array[0] = 3; // индекс первого элемента - 0 (нулевой элемент)
//    array[1] = 2;
//    array[2] = 4;
//    array[3] = 8;
//    array[4] = 12; // индекс последнего элемента - 4
//
//    std::cout << "The array element with the smallest index has the value " << array[0] << "\n";
//    std::cout << "The sum of the first 5 numbers is " << array[0] + array[1] + array[2] + array[3] + array[4] << "\n";
//
//    return 0;
//}



//Циклы
//int main(){
//
//    for (int count = 0; count < 5; ++count) {
//        std::cout << count << " ";
//    }
//
//    int count = 0;
//    while (count < 10)
//    {
//        std::cout << count << " ";
//        ++count;
//    }
//
//
//////    Переменная choice должна быть объявлена вне цикла do while
//    int choice;
//
//    do
//    {
//        std::cout << "Please make a selection: \n";
//        std::cout << "1) Addition\n";
//        std::cout << "2) Subtraction\n";
//        std::cout << "3) Multiplication\n";
//        std::cout << "4) Division\n";
//        std::cin >> choice;
//    }
//    while (choice != 1 && choice != 2 &&
//        choice != 3 && choice != 4);
//
//    // Что-то делаем с переменной choice, например, используем оператор switch
//
//    std::cout << "You selected option #" << choice << "\n";
//
//    return 0;
//}




//Циклы c массивами
//int main(){
//    // еще один способ инициализировать массив
//    int students[] = { 73, 85, 84, 44, 78};
//
//    const int numStudents = sizeof(students) / sizeof(students[0]);
//    int totalScore = 0;
//
//    // Используем цикл для вычисления totalScore
//    for (int person = 0; person < numStudents; ++person){
//        totalScore += students[person]; // totalScore = totalScore + students[person];
//        std::cout << person << "\t" << students[person] << std::endl;
//    }
//    std::cout << totalScore << std::endl;
//}
//


//Указатели
//int main(){
//
//    int *iPtr; // указатель на значение типа int
//    double *dPtr; // указатель на значение типа double
//
//    int a = 7;
//    double d = 3.5;
//
//    std::cout << a << std::endl;     // выводим значение переменной a
//    std::cout << &a << std::endl;    // выводим адрес переменной a
//    std::cout << *&a << std::endl;   // выводим значение ячейки памяти переменной a
//
//    iPtr = &a;
//    dPtr = &d;
//
//    std::cout << iPtr << std::endl;
//    std::cout << *iPtr << std::endl;
//    std::cout << *dPtr << std::endl;
//
//    return 0;
//}


// Пример
//int i_increase(int x){
//    x = x+1;
//    return x;
//}
//
//void v_increase(int *x){
//    *x += 1;
//}
//
//int main(){
//
//    int x = 10;
//    int y;
//
//    y = i_increase(x);
//
//    std::cout << "x:" << x << "\ny:" << y << std::endl;
//    std::cout << "-----" << std::endl;
//
//    v_increase(&x);
//
//    std::cout << "x:" << x << "\ny:" << y << std::endl;
//
//
//    return 0;
//}



//Передача массивов в функции
//void printSize(int *array)
//{
//    // Здесь массив рассматривается как указатель
//    std::cout << sizeof(array) << '\n'; // выведется размер указателя, а не длина массива
//
//    // Мы также можем изменять значения в массиве
//    array[0] = 100;
//}
//
//int main()
//{
//    int array[] = {1, 2, 3, 4, 4, 9, 15, 25};
//    std::cout << sizeof(array) << '\n'; // выведется sizeof(int) * длина массива
//
//    std::cout << "Element 0 has value: " << array[0] << '\n';
//
//    printSize(array); // здесь аргумент array распадается на указатель
//    std::cout << "Element 0 has value: " << array[0] << '\n';
//
//    return 0;
//}

//Задача 1
//int add(int a, int b){
//    int s = 0;
//    s = a + b;
//    return s;
//}
//
//int main() {
//    int a, b, sum;
//
//    // Пользователь вводит два значения с клавиатуры (std::cin)
//    std::cout << "Введите первое значение: ";
//    std::cin >> a;
//
//    std::cout << "Введите второе значение: ";
//    std::cin >> b;
//
//    // Используя функцию add складываем эти два значения
//    sum = add(a,b);
//
//    // выводим на экран их сумму
//    std::cout << a << "+" << b << "=" << sum <<std::endl;
//}


//Задача 2
int sum(int *array, int array_length){
    int res = 0;
    // суммируем все элементы массива с помощью цикла
    for (int i = 0; i < array_length; ++i) {
        res += array[i];
    }
    return res;
}

int main(){
    int array[5] = {1,2,3,4,5};
    int len = sizeof(array) / sizeof(array[0]);
    int s;


    // создаем цикл в котором пользователь заполняет массив с клавиатуры
    for (int i = 0; i < len; ++i) {
        std::cout << "Введите значение элемента с индексом " << i << ": ";
        std::cin >> array[i];
    }

    // используем функцию sum(array, len) для получения суммы всех элементов массива
    s = sum(array, len);

    // выводим сумму
    std::cout << "Сумма всех элементов: " << s << std::endl;
    return 0;
}
