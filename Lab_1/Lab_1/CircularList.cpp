#include "list.h"

circularList::~circularList()
{
    Data* temp = head;
    short size = number();
    while (size != 0) 
    {
        Data* temp = head->n;
        delete head;                           
        head = temp;
        size--;                                
    }
    head = NULL;
}
void circularList::create(int num) //+++
{
    char ch;
    Data* temp;

    temp = new Data;
    cout << "Введіть символ > ";
    cin >> ch;
    temp->data = ch;
    head = temp;
    head->n = NULL;
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
        head = temp;
        head->n = NULL;
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
        temp = head;
        if (head->n)
            do
            {
                cout << temp->data << " ";
                temp = temp->n;
            } while (temp != head);
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

       
        
        if (head->n)
        {
            temp->p = head->p;
            head->p->n = temp;
            head->p = temp;
            temp->n = head;
        }

        else {
            temp->p = head;
            temp->n = head;
            head->n = temp;
            head->p = temp;
        }
        
    }
}
void circularList::del(char ch)
{
    if (isEmpty())
        cout << "Список пуст" << endl;
    else {
        Data* tempR;

        if (ch == head->data) { // first
            tempR = head->n;
            Data* temp = head->n;
            temp->p = head->p;
            head->p->n = temp;
            delete head;
            head = tempR;
        }

        else {
            Data* temp = head;
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
short circularList::number() 
{
    short num = 0;
    Data* temp = head;
    do
    {
        num++;
        temp = temp->n;
    } while (temp != head);
    return num;
}

void circularList::swap(char ch)//+++
{
    if (isEmpty())
        cout << "Список пуст" << endl;
    else {
        Data* temp1 = head, * temp2;

        while (ch != temp1->data)
        {
            temp1 = temp1->n;
        }
        temp2 = temp1->n; //наступний елемент після темп

        if (temp1 == head)
            head = temp2;

        else if (temp2 == head)
            head = temp1;
        
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
        Data* temp = head;

        fstream f("List.txt", ios::out);
        if (!f.is_open())
            cout << "Ошибка открытия файла на запись";
        else {
            do {
                f << temp->data << ' ';
                temp = temp->n;
            } while (temp != head);
        }
    }
}

bool circularList::isChar(char ch) {

    Data* temp = head;

    do
    {
        if (temp->data == ch)
        {
            return 1;
        }
        else
            temp = temp->n;

    } while (temp != head);

    return 0;

}

bool circularList::isEmpty() {
    return head == NULL ? true : false;
}