#include "queue.h"

void queue::Add(short el) {
    obj* temp = new obj;
    temp->data = el;
    if (!head) {
        head = temp;
        tail = head;
    }
    else {
        temp->data = el;
        tail->prev = temp;
        tail = temp;
    }
    temp->prev = NULL;
}
void queue::show() {
    obj* temp = head;
    cout << "queue: ";
    while (temp) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int queue::count()
{
    int count = 0;
    obj* temp = head;
    while (temp) {
        count++;
        temp = temp->prev;
    }
    return count;
}

short queue::average()
{
    
    short avarage = 0;
    obj* temp = head;
    while (temp) {
        avarage += temp->data;
        temp = temp->prev;
    }
    return avarage/count();
}

short queue::Min()
{
    short min = head->data;
    obj* temp = head->prev;
    while (temp) {
        if (min > temp->data)
            min = temp->data;
        temp = temp->prev;
    }

    return min;
}

short queue::Max()
{
    short max = head->data;
    obj* temp = head->prev;
    while (temp) {
        if (max < temp->data)
            max = temp->data;
        temp = temp->prev;
    }

    return max;
}

short queue::prevMin()
{
    short prevMin = 0;
    obj* temp = head;
    if (Min() == head->data)
        return Min();
    while (temp) {
        
        if (temp->prev->data == Min())
            return temp->data;
        temp = temp->prev;
    }

}

void queue::readFile()
{
    obj* temp = new obj;

    ifstream fin("queue.txt");
    short el;
    if (!fin) {
        cout << "Не вдалося відкрити файл";
    }
    else {

        while (fin >> el) {
            if (el != ' ')
                Add(el);
        }
    }
}

void queue::saveFile()
{
    obj* temp = head;

    fstream f("queue.txt", ios::out);
    if (!f.is_open())
        cout << "Ошибка открытия файла на запись";
    else {
        while (temp) {
            f << temp->data << ' ';
            temp = temp->prev;
        }
    }
}