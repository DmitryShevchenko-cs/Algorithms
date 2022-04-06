#include "list.h"

circularList::~circularList() 
{
    Data* temp;
    while (_root)
    {
        temp = _root->n;
        delete _root;
        _root = temp;
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

    while (_root)
    {
        temp = _root->n;
        delete _root;
        _root = temp;
    }
    
    temp = new Data;
    cout << "Введіть символ > ";
    cin >> ch;
    temp->data = ch;
    if(num > 1)
        for (int i = 0; i < num - 1; i++) {
            cout << "Введіть символ > ";
            cin >> ch;
            Add(ch);
        }

}
void circularList::createFromFile(string file) 
{
    Data* temp;
    while (_root)
    {
        temp = _root->n;
        delete _root;
        _root = temp;
    }

    ifstream fin(file);
    char ch;
    if (!fin) {
        cout << "Не вдалося відкрити файл";
    }
    else {
        while (fin.get(ch)) {
            if (ch != '\t')
                Add(ch);
        }
    }

}
void circularList::show() 
{
    Data* temp;
    temp = _root;
    while (temp != _root)
    {
        cout << temp->data;
        temp = temp->n; 
    } 
}
void circularList::Add(char ch) 
{

    Data* temp = new Data;
    temp->data = ch;

    if (_root != NULL)
    {
        temp->n = _root;
        if (_root->n) 
        {
            temp->p = _root->p->n;
            _root->p->n = temp;
        }
            
        else
            _root->n = temp;
        _root->p = temp;
       
    }
    else
    {
        create(1);
    }

}
void circularList::del(char ch) 
{

    Data* temp = _root->n;

    while (temp != _root)
    {
        if (temp->data == ch) 
        {
            temp->p->n = temp->n;
            temp->n->p = temp->p;

            break;
        }
        else
            temp = temp->n;
    }

}
short circularList::number() 
{
    short num = 0;
    Data* temp = _root->n;

    while (temp != _root)
    {
        num++;
        temp = temp->n;
    }

    return num;

}
void circularList::swap(char ch)
{
    Data* temp1 = _root, * temp2;

    while (ch != temp1->data)
    {
        temp1 = temp1->n;
    }
    temp2 = temp1->n;//наступний елемент після темп

    temp1->p->n = temp2;
    temp2->n->p = temp1;

    temp1->n = temp2->n;
    temp2->n = temp1;

    temp2->p = temp1->p;
    temp1->p = temp2;
}
void circularList::merge(circularList& LIST) 
{



}
void circularList::save() 
{
    Data* temp = _root;

    fstream f("List.txt", ios::out);
    if (!f.is_open())
        cout << "Ошибка открытия файла на запись";
    else {
        while (temp != _root) {
            f << temp->data << '\t';
            temp = temp->n;
        }
    }



}