#include "deque.h"

void deque::pushFront(short el)
{
    obj* temp = new obj;
    temp->data = el;
    if (!left) {
        left = temp;
        right = left;
    }
    else {
        temp->next = left;
        left->prev = temp;
        left = temp;
    }
}
void deque::pushBack(short el)
{
    obj* temp = new obj;
    temp->data = el;
    if (!left) {
        left = temp;
        right = left;
    }
    else {
        right->next = temp;
        temp->prev = right;
        right = temp;
    }
    temp->next = NULL;
    temp->prev = NULL;
}
void deque::show()
{
    obj* temp = left;
    cout << "deque: ";
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
short deque::read6El()
{
    obj* temp = left;
    if (count() >= 6) {
        for (int i = 0; i < 5; i++)
            temp = temp->next;
        return temp->data;
    }
    else cout << "Дек містить меньше 6 елементів" << endl;
    return 0;
}

short deque::readlast()
{
    return right->data;
}

bool deque::isEmpty()
{
    if (left)
        return false;
    else return true;
}

void deque::readFile()
{
    obj* temp = new obj;

    ifstream fin("deque.txt");
    short el;
    if (!fin) {
        cout << "Не вдалося відкрити файл";
    }
    else {

        while (fin >> el) {
            if (el != ' ')
                pushBack(el);
        }
    }
}

void deque::saveFile()
{
    obj* temp = left;

    fstream f("deque.txt", ios::out);
    if (!f.is_open())
        cout << "Ошибка открытия файла на запись";
    else {
        while (temp) {
            f << temp->data << ' ';
            temp = temp->next;
        }
    }
}

int deque::count()
{
    int count = 0;
    obj* temp = left;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}