#include "list.h"

circularList::~circularList()
{
    Data* temp = _root;
    short size = number();
    while (size != 0) 
    {
        Data* temp = _root->n;
        delete _root;                           
        _root = temp;
        size--;                                
    }
    _root = NULL;
}
void circularList::create(int num) //+++
{
    char ch;
    Data* temp;

    temp = new Data;
    cout << "Введіть символ > ";
    cin >> ch;
    temp->data = ch;
    _root = temp;
    _root->n = NULL;
    if(num > 1)
        for (int i = 0; i < num - 1; i++) {
            cout << "Введіть символ > ";
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
        cout << "Не вдалося відкрити файл";
    }
    else {
        fin.get(ch);
        temp->data = ch;
        _root = temp;
        _root->n = NULL;
        while (fin.get(ch)) {
            if (ch != ' ')
                Add(ch);
        }
    }

}
void circularList::show() //+++
{
    if (isEmpty())
        cout << "Список пуст" << endl;
    else {
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
}
void circularList::Add(char ch)//+++
{
    if (isEmpty())
        cout << "Список пуст" << endl;
    else {
        Data* temp = new Data;
        temp->data = ch;

        temp->n = _root;

        if (_root->n)
        {
            temp->p = _root->p->n;
            _root->p->n = temp;
            _root->p = temp;
        }
        else {
            temp->p = _root;

            _root->n = temp;
        }
        _root->p = temp;
    }
}
void circularList::del(char ch)// если последний
{
    if (isEmpty())
        cout << "Список пуст" << endl;
    else {
       
        Data* tempR;

        if (ch == _root->data) { // first
            tempR = _root->n;
            Data* temp = _root->n;
            temp->p = _root->p;
            _root->p->n = temp;
            delete _root;
            _root = tempR;
        }

        if (ch == _root->p->data){
            
          
            
        }

        else {
            Data* temp = _root;

            while (ch != temp->data)
            {
                temp = temp->n;
            }

            Data* prev, * next;
            prev = temp->p;
            next = temp->n;
            prev->n = temp->n;
            next->p = temp->p;
        }


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
    if (isEmpty())
        cout << "Список пуст" << endl;
    else {
        Data* temp1 = _root, * temp2;

        while (ch != temp1->data)
        {
            temp1 = temp1->n;
        }
        temp2 = temp1->n; //наступний елемент після темп

        if (temp1 == _root)
            _root = temp2;
        
        temp1->p->n = temp2;
        temp2->n->p = temp1;

        temp1->n = temp2->n;
        temp2->n = temp1;

        temp2->p = temp1->p;
        temp1->p = temp2;
    }
}

void circularList::save() //+++
{
    if (isEmpty())
        cout << "Список пуст" << endl;
    else {
        Data* temp = _root;

        fstream f("List.txt", ios::out);
        if (!f.is_open())
            cout << "Ошибка открытия файла на запись";
        else {
            do {
                f << temp->data << ' ';
                temp = temp->n;
            } while (temp != _root);
        }
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

bool circularList::isEmpty() {
    return _root == NULL ? true : false;
}