#include "list.h"

circularList::~circularList() 
{
    Data* temp;
    while (root)
    {
        temp = root->n;
        delete root;
        root = temp;
    }

   /* do{
        temp = root->n;
        delete root;
        root = temp;
    } while (root->n);*/


}
void circularList::create(int num) 
{
    char ch;
    Data* temp;

    while (root)
    {
        temp = root->n;
        delete root;
        root = temp;
    }
    
    temp = new Data;
    cout << "ֲגוה³עü סטלגמכ > ";
    cin >> ch;
    temp->data = ch;
    if(num > 1)
        for (int i = 0; i < num - 1; i++) {
            cout << "ֲגוה³עü סטלגמכ > ";
            cin >> ch;
            Add(ch);
        }

}
void circularList::createFromFile(string file) 
{


}
void circularList::show() 
{
    Data* temp;
    temp = root;
    do {
        cout << temp->data;
        temp = temp->n; 
    } while (temp != root);
}
void circularList::Add(char ch) 
{

    Data* temp = new Data;
    temp->data = ch;

    if (root != NULL)
    {
        temp->n = root;
        if (root->n) 
        {
            temp->p = root->p->n;
            root->p->n = temp;
        }
            
        else
            root->n = temp;
        root->p = temp;
       
    }
    else
    {
        create(1);
    }

}
void circularList::del(char ch) 
{

}
short circularList::number() 
{
    return 2;
}
void circularList::swap(int choice) 
{

}
void circularList::merge(circularList& LIST) 
{



}
void circularList::save() 
{

}