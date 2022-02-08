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
    cout << "\n";
   
   /* temp = tail;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->p;
    }
    cout << "\n";*/
}