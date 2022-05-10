#include "queue.h"

void queue::Add(short el) {
    obj* temp = new obj;
    temp->data = el;
    if (!first) {
        first = temp;
        tail = first;
    }
    else {
        tail->prev = temp;
        tail = temp;
    }
    temp->prev = NULL;
}
void queue::show() {
    obj* temp = first;
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
    obj* temp = first;
    while (temp) {
        count++;
        temp = temp->prev;
    }
    return count;
}

short queue::average()
{
    
    short avarage = 0;
    obj* temp = first;
    while (temp) {
        avarage += temp->data;
        temp = temp->prev;
    }
    return avarage/count();
}

short queue::prevMin()
{
    short prevMin = 0;
    obj* temp = first;
    if (Min() == first->data)
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
    obj* temp = first;

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

short queue::Min()
{
    short min = first->data;
    obj* temp = first->prev;
    while (temp) {
        if (min > temp->data)
            min = temp->data;
        temp = temp->prev;
    }

    return min;
}

short queue::Max()
{
    short max = first->data;
    obj* temp = first->prev;
    while (temp) {
        if (max < temp->data)
            max = temp->data;
        temp = temp->prev;
    }

    return max;
}
