#include "list.h"

circularList::~circularList()
{
    
    Data* temp =_root;
    while (_root)
    {
        temp = _root->n;
        delete _root;
        _root = temp;
    }

}
void circularList::create(int num) //+++
{
    char ch;
    Data* temp;

    temp = new Data;
    cout << "������ ������ > ";
    cin >> ch;
    temp->data = ch;
    _root = temp;
    _root->n = NULL;
    if(num > 1)
        for (int i = 0; i < num - 1; i++) {
            cout << "������ ������ > ";
            cin >> ch;
            Add(ch);
        }

}
void circularList::createFromFile(string file) //+++
{
    Data* temp = new Data;


    ifstream fin(file);
    char ch;
    if (!fin) {
        cout << "�� ������� ������� ����";
    }
    else {
        fin.get(ch);
        temp->data = ch;
        _root = temp;
        _root->n = NULL;
        while (fin.get(ch)) {
            if (ch != '\t')
                Add(ch);
        }
    }

}
void circularList::show() //+++
{
    Data* temp;
    temp = _root;
    if (_root->n) 
        do
        {
            cout << temp->data << " ";
            temp = temp->n;
        } while (temp != _root);
    else
        cout << temp->data;
    
    cout << endl;
}
void circularList::Add(char ch)//+++
{

    Data* temp = new Data;
    temp->data = ch;

    temp->n = _root;
    
    if (_root->n)
    {
        temp->p = _root->p->n;
        _root->p->n = temp;
    }

    else {
        temp->p = _root;
        _root->n = temp;
    }
    _root->p = temp;


}
void circularList::del(char ch) // ���� ������� ������� ����� ������ ��� ��������� ��� � ��
{
   
    Data* temp = _root;

    if (_root->data == ch) {

        return;
    }
    else
    {
        while (ch != temp->data)
        {
            temp = temp->n;
        }

        Data* tprev, * tnext;
        tprev = temp->p;
        tnext = temp->n;
        tprev->n = temp->n;
        tnext->p = temp->p;
        delete temp;
    }
    

   



}
short circularList::number() //+++
{
    short num = 0;
    Data* temp = _root;

    do
    {
        num++;
        temp = temp->n;
    } while (temp != _root);

    return num;

}
void circularList::swap(char ch)//+++
{
    Data* temp1 = _root, * temp2;

    while (ch != temp1->data)
    {
        temp1 = temp1->n;
    }
    temp2 = temp1->n;//��������� ������� ���� ����

    temp1->p->n = temp2;
    temp2->n->p = temp1;

    temp1->n = temp2->n;
    temp2->n = temp1;

    temp2->p = temp1->p;
    temp1->p = temp2;
}
void circularList::merge(circularList& LIST) 
{

    _root->p->n = LIST._root;
    LIST._root->p->n = _root;
    _root->p = LIST._root->p;
    LIST._root->p = _root->p;
       

}
void circularList::save() //+++
{
    Data* temp = _root;

    fstream f("List.txt", ios::out);
    if (!f.is_open())
        cout << "������ �������� ����� �� ������";
    else {
        do {
            f << temp->data << '\t';
            temp = temp->n;
        } while (temp != _root);
    }

}

bool circularList::isChar(char ch) {

    Data* temp = _root;

    do
    {
        if (temp->data == ch)
        {
            return 1;
        }
        else
            temp = temp->n;

    } while (temp != _root);

    return 0;

}