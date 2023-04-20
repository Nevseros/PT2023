#include <stdio.h>
#include <iostream>
#include <cstdlib>
using namespace std;

struct product {
    string name;
    float price;
    int amount;
    product *next;
};

product *createEntry() {
    product *newProduct = new product;

    cout << "Enter item name: ";
    cin >> newProduct->name;

    cout << "Enter item price: ";
    cin >> newProduct->price;

    cout << "Enter the amount of item: ";
    cin >> newProduct->amount;

    newProduct->next = NULL;

    return newProduct;
}

// Выводит на экран всю информацию о каждом элементе
void printList(product *products) {
    if (products == NULL) {
        cout << "The list is empty.\n";
    }
    else {
        product *tmp = products;
        while (tmp != NULL) {
            cout << "* Name: " << tmp->name
            << ", price: " << tmp->price
            << ", amount: " << tmp->amount << ".\n"; //выводим имя, цену, всё такое; как-то красиво
            tmp = tmp->next;
        }
        cout << endl;
    }
}

// Выводит на экран всю информацию об одном выбранном элементе
void printItem(product *products, string nameToPrint) {
    product *tmp = products;
    
    while (tmp != NULL) {
        if (tmp->name == nameToPrint) {
            break;
        }
        tmp = tmp->next;
    }

    if (tmp == NULL) {
        cout << "There is no such item." << endl;
    } else {
        cout << "Name: " << tmp->name << endl
        << "Price: " << tmp->price << endl
        << "Amount: " << tmp->amount << endl;
    }
}

// Добавляет элемент в начало списка
// Создает первую запись о товаре, если список пустой
product *addFirst(product *products) {
    product *newProduct = createEntry();
    newProduct->next = products;

    return newProduct;
}

// Добавляет новый элемент в конец списка
product *addLast(product *products) {
    product *tmp = products;

    if (tmp == NULL) {
        products = addFirst(products);
    } else {
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = createEntry();
    }

    return products;
}

// Вставляет новый элемент сразу после выбранного элемента
product *addAfter(product *products, string nameAfter) {
    if (products == NULL) {
        cout << "The list is empty. Try adding an item at the end or on top of the list.\n";
        return products;
    }

    product *tmp = products;
    while (tmp != NULL) {
        if (tmp->name == nameAfter) {
            break;
        }
        tmp = tmp->next;
    }

    if (tmp == NULL) {
        cout << "There is no such item." << endl;
    } else {
        product *nextOne = tmp;
        nextOne = nextOne->next;
        tmp->next = createEntry();
        tmp = tmp->next;
        tmp->next = nextOne;
    }

    return products;
}

// Вставляет новый элемент перед выбранным элементом
product *addBefore(product *products, string nameBefore) {
    if (products == NULL) {
        cout << "The list is empty. Try adding an item at the end or on top of the list.\n";
        return products;
    }

    product *tmp = products;
    product *tmp1 = products;

    if (tmp->name == nameBefore) {
        products = addFirst(products);
    } else {
        while (tmp1->next != NULL) {
            tmp1 = tmp1->next;
            if (tmp1->name == nameBefore) {
                break;
            }
            tmp = tmp->next;
        }
        if (tmp1->next == NULL) {
            cout << "There is no such item." << endl;
        } else {
            tmp->next = createEntry();
            tmp = tmp->next;
            tmp->next = tmp1;
        }
    }

    return products;
}

// Удаляет выбранный элемент из списка
product *deleteItem(product *products) {
    product *tmp = products;

    if (tmp == NULL) {
        cout << "The list is empty." << endl;
        return products;
    } 

    cout << "Enter the name of the item to delete: ";
    string nameToDelete;
    cin >> nameToDelete;
    if (tmp->name == nameToDelete) {
        cout << "The item has been deleted succesfully.\n";
        return tmp->next;
    }

    product *tmp1 = products;
    while (tmp1->next != NULL) {
        tmp1 = tmp1->next;
        if (tmp1->name == nameToDelete) {
            break;
        }
        tmp = tmp->next;
    }

    if (tmp1->next == NULL) {
        cout << "There is no such item." << endl;
    } else {
        tmp->next = tmp1->next;
        cout << "The item has been deleted succesfully.\n";
    }

    return products;
}

int main() {
    product *products = NULL;
    
    int k = 100;
    
    while (k != 0){
        while (k != 0 && k != 1 && k != 2 && k != 3 && k != 4 && k != 5 && k != 6 && k != 7){
            cout << "* To add an item at the end of the list, enter 1.\n"
            << "* To add an item to the top of the list, enter 2.\n"
            << "* To delete an item, enter 3.\n"
            << "* To add after an item, enter 4.\n"
            << "* To add before an item, enter 5.\n"
            << "* To find an item, enter 6.\n"
            << "* To print the list, enter 7.\n"
            << "* To exit, enter 0: ";
            cin >> k;
            cout << "\n\n";
        
            if (k != 0 && k != 1 && k != 2 && k != 3 && k != 4 && k != 5 && k != 6 && k != 7){
                cout<<"Wrong code!\n\n";
                system("pause");
            } 
            else {
                switch(k) {
                    case 0: {
                        break;
                    }
                    case 1: {
                        products = addLast(products);
                        k = 100;
                        break;
                    }
                    case 2: {
                        products = addFirst(products);
                        k = 100;
                        break;
                    }
                    case 3: {
                        products = deleteItem(products);
                        k = 100;
                        break;
                    }
                    case 4: {
                        cout << "Enter the name of the item after which to add a new one: ";
                        string nameAfter;
                        cin >> nameAfter;
                        products = addAfter(products, nameAfter);
                        k = 100;
                        break;
                    }
                    case 5: {
                        cout << "Enter the name of the item before which to add a new one: ";
                        string nameBefore;
                        cin >> nameBefore;
                        products = addBefore(products, nameBefore);
                        k = 100;
                        break;
                    }
                    case 6: {
                        cout << "Enter the name of the item to find: ";
                        string nameToPrint;
                        cin >> nameToPrint;
                        printItem(products, nameToPrint);
                        k = 100;
                        break;
                    }
                    case 7: {
                        printList(products);
                        k = 100;
                        break;
                    }
                }
            }
            cout << "\n\n";
        }
    }
    
    return 0;
}
