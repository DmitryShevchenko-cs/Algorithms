#include "list.h"

list::~list() {

    while (head)
    {
        tail = head->n;
        delete head;
        head = tail;
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
    while (head)
    {
        tail = head->n;
        delete head;
        head = tail;
    }

    char ch;
    for (int i = 0; i < num; i++) {
        cout << "¬вед≥ть символ > ";
        cin >> ch;
        Add(ch);
    }
}

void list::createFromFile(string file) {

    while (head)
    {
        tail = head->n;
        delete head;
        head = tail;
    }

    ifstream fin(file);
    char ch;
    if (!fin) {
        cout << "File can't be open";
    }
    else {
        while (fin.get(ch)) {
            if(ch!= '\t')
                Add(ch);
        }
    }


}

void list::show()
{
   
    Data* temp = head;
    if (temp == 0)
        cout << "—писок пуст";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->n;
    }
    cout << endl;
    
}

short list::number() {

    short number = 0;
    Data* tempH = head;
  
    while (tempH)
    {
        number++;
        tempH = tempH->n;
    }
    return number;
}

void list::del(int num) {

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

    Data* temp = head, *temp2;
 
    for (int i = 0; i < num - 1; ++i)
        temp = temp->n;
    temp2 = temp;
    temp2->p->n = temp->n;
    temp2->n->p = temp->p;
    
}


void list::swap(int choice) {

    Data* temp1 = head, * temp2 = head;

    for (int i = 0; i < choice - 1; ++i)
        temp1 = temp1->n;

    for (int i = 0; i < choice; ++i)
        temp2 = temp2->n;

    if (temp1== head && temp2 == tail) { // если список из двух елементов

        temp1->n = NULL;
        temp2->n = temp1;
        temp1->p = temp2;
        temp2->p = NULL;
        head = temp2;
        tail = temp1;
        return;

    }

    if (temp1->p == NULL) { // если два первых елемента
       
        temp2->n->p = temp1;

        temp1->n = temp2->n;
        temp2->n = temp1;
        temp1->p = temp2;
        temp2->p = NULL;
        head = temp2;
        return;
    }

    if (temp2->n == NULL) { // если два последних елемента
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

void list::merge(list &LIST) {

    Data* temp = LIST.head;

    while (temp) {
        this->Add(temp->data);
        temp = temp->n;

    }
    LIST.~list();
}

void list::save() {

    Data* temp = head;

    fstream f("List.txt", ios::out); 
    if (!f.is_open())
        cout << "ќшибка открыти€ файла на запись";
    else {
        while (temp) {
            f << temp->data << '\t';
            temp = temp->n;
        }
    }
}