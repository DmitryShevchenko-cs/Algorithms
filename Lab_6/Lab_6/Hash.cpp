#include "Hash.h"

ChainHash::ChainHash(int c)
{
    this->capacity = c;
    table = new list<int>[capacity];
}
void ChainHash::insertItem(int key)
{
    table[hashFunction(key)].push_back(key);
}

int ChainHash::hashFunction(int key)
{
    return capacity * fmod(key * (( (sqrt(5) - 1) / 2)), 1);
}

void ChainHash::deleteItem(int key)
{
    int x = hashFunction(key);

    list<int>::iterator i;
    for (i = table[x].begin(); i != table[x].end(); i++) {
       
        if (*i == key)
            break;
    }

    // If the item was found in the list, then delete it:
    if (i != table[x].end())
        table[x].erase(i);
}

int ChainHash::searchItem(int key)
{
    int index = hashFunction(key);
    cout << "table[" << index << "]";
    for (auto x : table[index])
        cout << " --> " << x;
    return 1;
}

void ChainHash::displayHash()
{
    for (int i = 0; i < capacity; i++)
    {
        cout << "table[" << i << "]";
        for (auto x : table[i])
            cout << " --> " << x;
        cout << endl;
    }
}

OpenHash::OpenHash(int V)
{
    this->capacity = V;
    table.resize(capacity);
    infoNode.resize(capacity);
}

void OpenHash::insertItemL(int key)
{
    int index = hashFunction(key);
    int data = key;
    while (true) {
        if (infoNode[index] == 0) {
            table[index] = data;
            infoNode[index] = 1;
            return;
        }
        else index = hashFunction(key++);
    }
}


void OpenHash::deleteItemL(int key)
{
    int index = hashFunction(key);
    int data = key;
    while (true) {
        if (table[index] == data) {
            table[index] = 0;
            infoNode[index] = 2;
            return;
        }
        if (table[index] != data && infoNode[index + 1] != 1) {
            cout << "Такого елемента не найдено" << endl;
            return;
        }
        else{
            index = hashFunction(key++);
        }
    }
    

}

int OpenHash::searchItemL(int key)
{
    int index = hashFunction(key);
    int data = key;
    while (true) {
        if (table[index]==data) {
            cout << "table[" << index << "]";
            cout << " --> " << table[index];
            cout << endl;
            return table[index];
        }
        if (table[index] != data && infoNode[index + 1] != 1) {
            cout << "Такого елемента не найдено" << endl;
            return 0;
        }
        else index = hashFunction(key++);
    }
    return table[index];
}

void OpenHash::insertItem2(int key)
{
    int index = hashFunction(key);
    int data = key;
    while (true) {
        if (infoNode[index] == 0) {
            table[index] = data;
            infoNode[index] = 1;
            return;
        }
        else index = hashFunction(key++);
    }
}

int OpenHash::hashFunction(int key)
{
    return fmod(key, capacity);
}

void OpenHash::displayHash()
{

    for (int i = 0; i < capacity; i++)
    {
        if (infoNode[i] != 1) {
            cout << "table[" << i << "]";
            cout << " --> " << "Empty";
            cout << endl;
        }
        else {
            cout << "table[" << i << "]";
            cout << " --> " << table[i];
            cout << endl;
        }
    }

}
