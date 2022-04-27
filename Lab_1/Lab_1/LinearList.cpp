#include "list.h"

list::~list() {
    
    Data* temp;
   
    while (head)
    {
        temp = head->n;
        delete head;
        head = temp;
    }
}

void list::Add(char ch)
{

    Data* temp = new Data;
    temp->n = NULL;
    temp->data = ch;

    if (head != NULL)
    {
        temp->p = tail;
        tail->n = temp;
        tail = temp;
    }
    else
    {
        temp->p = NULL;
        head = tail = temp;
    }

}

void list::create(int num) {

    char ch;
    for (int i = 0; i < num; i++) {
        cout << "Введіть символ > ";
        cin >> ch;
        Add(ch);
    }
}

void list::createFromFile(string file) {

    ifstream fin(file);
    char ch;
    if (!fin) {
        cout << "Не вдалося відкрити файл";
    }
    else {
        while (fin.get(ch)) {
            if(ch!= ' ')
                Add(ch);
        }
    }


}

void list::show()
{
    if (number() == 0)
        cout << "Список пуст" << endl;
    else {
        Data* temp = head;

        cout << "Список: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->n;
        }
        cout << endl;
    }

}

short list::number() {

    short number = 0;
    Data* temp = head;
  
    while (temp)
    {
        number++;
        temp = temp->n;
    }
    return number;
}

void list::del(int num) {

    if (number() == 0)
        cout << "Список пуст" << endl;
    else {
        if (num == 1 && head->n) {
            Data* temp = head;
            head = head->n;
            head->p = NULL;
            return;

        }
        else if ((num == 1) && (head == tail)) {

            head->n = NULL;
            head = NULL;
            delete head;
            return;

        }
        if (num == number()) {
            Data* temp = tail;
            tail = tail->p;
            tail->n = NULL;
            return;
        }

        Data* temp = head, * temp2;

        for (int i = 0; i < num - 1; ++i)
            temp = temp->n;
        temp2 = temp;
        temp2->p->n = temp->n;
        temp2->n->p = temp->p;
    }
}


void list::swap(int choice) {

    if (number() == 0)
        cout << "Список пуст" << endl;
    else {
        Data* temp1 = head, * temp2 = head;

        for (int i = 0; i < choice - 1; ++i)
            temp1 = temp1->n;

        temp2 = temp1->n;

        if (temp1 == head && temp2 == tail) // если список из двух елементов
        { 
            temp1->n = NULL;
            temp2->n = temp1;
            temp1->p = temp2;
            temp2->p = NULL;
            head = temp2;
            tail = temp1;
            return;
        }

        if (temp1->p == NULL) // если два первых елемента
        { 
            temp2->n->p = temp1;
            temp1->n = temp2->n;
            temp2->n = temp1;
            temp1->p = temp2;
            temp2->p = NULL;
            head = temp2;
            return;
        }

        if (temp2->n == NULL) // если два последних елемента
        { 
            temp1->p->n = temp2;
            temp2->p = temp1->p;
            temp2->n = temp1;
            temp1->p = temp2;
            temp1->n = NULL;
            tail = temp1;
            return;
        }

        else {
            temp1->p->n = temp2;
            temp2->n->p = temp1;
            temp1->n = temp2->n;
            temp2->n = temp1;
            temp2->p = temp1->p;
            temp1->p = temp2;
            return;
        }
    }
}

void list::merge(list &LIST) { 
    if (number() == 0)
        cout << "Список пуст" << endl;
    else {
        Data* temp = LIST.head;

        temp->p = tail;
        tail->n = temp;
        tail = LIST.tail;
    }
}

void list::save() {
    if (number() == 0)
        cout << "Список пуст" << endl;
    else {
        Data* temp = head;

        fstream f("List.txt", ios::out);
        if (!f.is_open())
            cout << "Ошибка открытия файла на запись";
        else {
            while (temp) {
                f << temp->data << ' ';
                temp = temp->n;
            }
        }
    }
}

