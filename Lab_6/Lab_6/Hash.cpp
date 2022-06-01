#include "Hash.h"

HashTable1::HashTable1(int c)
{
    this->capacity = c;
    table = new list<int>[capacity];
}
void HashTable1::insertItem(int key)
{
    table[hashFunction(key)].push_back(key);
}

int HashTable1::hashFunction(int key)
{
    return capacity * fmod(key * ((sqrt(5) - 1 / 2)), 1);
}

void HashTable1::deleteItem(int key)
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

int HashTable1::searchItem(int key)
{
    int index = hashFunction(key);
    cout << "table[" << index << "]";
    for (auto x : table[index])
        cout << " --> " << x;
    return 1;
}

void HashTable1::displayHash()
{
    for (int i = 0; i < capacity; i++)
    {
        cout << "table[" << i << "]";
        for (auto x : table[i])
            cout << " --> " << x;
        cout << endl;
    }
}