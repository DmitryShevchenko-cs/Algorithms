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

void list::show()
{
   
    Data* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->n;
    }
    cout << "\n" << "\n";
   
   /* temp = tail;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->p;
    }
    cout << "\n";*/
}

short list::number() {

    short number = 0;
    Data* tempH = head;
    Data* tempT = tail;
    while (tempH)
    {
        number++;
        tempT = tempH->n;
        tempH = tempT;
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
    if (num == number()) {                 //last elem num==count
        Data* temp = tail;
        tail = tail->p;
        tail->n = NULL;
        delete temp;
        return;
    }

    Data* temp = head, *temp2;
 
    for (int i = 0; i < num - 1; ++i)
        temp = temp->n;
    temp2 = temp;
    temp2->p->n = temp->n;
    temp2->n->p = temp->p;
    delete temp;
}


void list::swap(int first, int second) {

    Data* temp1 = head, * temp2 = head;

    for (int i = 0; i < first - 1; ++i)
        temp1 = temp1->n;

    for (int i = 0; i < second - 1; ++i)
        temp2 = temp2->n;

    if (temp2 == tail) {

        temp1->n = NULL;
        temp2->n = temp1;
        temp1->p = temp2;
        head = temp2;
        tail = temp1;
        return;

    }

    if (temp1->p == NULL) {
       
        temp2->n->p = temp1;

        temp1->n = temp2->n;
        temp2->n = temp1;
        temp1->p = temp2;
        temp2->p = NULL;
        head = temp2;
        return;
    }

    if (temp2->n == NULL) {
        temp1->p->n = temp2;

        temp2->p = temp1->p;
        temp2->n = temp1;
        temp1->p = temp2;
        temp1->n = NULL;
        tail = temp1;
        return;
    }
    
  

    temp1->p->n = temp2;
    temp2->n->p = temp1;

    temp1->n = temp2->n;
    temp2->n = temp1;

    temp2->p = temp1->p;
    temp1->p = temp2;

}

void list::merge(list LIST) {

    this->tail->n = LIST.head;
    LIST.head->p = this->tail;
    this->tail = LIST.tail;

}