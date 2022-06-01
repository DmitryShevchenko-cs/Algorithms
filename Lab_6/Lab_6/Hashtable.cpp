#include "Hashtable.h"






HashTable22::HashTable22(int c)
{
    //int size = getPrime(c);
    this->capacity = c;
    table = new list<int>[capacity];
}

void HashTable22::insertItem(int key, int data)
{
    int index = hashFunction(key);
    table[index].push_back(data);
}

int HashTable22::checkPrime(int n)
{
    int i;
    if (n == 1 || n == 0)
    {
        return 0;
    }
    for (i = 2; i < n / 2; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int HashTable22::getPrime(int n)
{
    if (n % 2 == 0)
    {
        n++;
    }
    while (!checkPrime(n))
    {
        n += 2;
    }
    return n;
}

int HashTable22::hashFunction(int key)
{
    return key % capacity;
}

void HashTable22::deleteItem(int key)
{
    int index = hashFunction(key);

    list<int>::iterator i;
    for (i = table[index].begin();
        i != table[index].end(); i++)
    {
        if (*i == key)
            break;
    }

    if (i != table[index].end())
        table[index].erase(i);
}

void HashTable22::displayHash()
{
    for (int i = 0; i < capacity; i++)
    {
        cout << "table[" << i << "]";
        for (auto x : table[i])
            cout << " --> " << x;
        cout << endl;
    }
}




HashTable33::HashTable33(int c)
{
    //int size = getPrime(c);
    this->capacity = c;
    table = new list<int>[capacity];
}
void HashTable33::insertItem1(int key, int data)
{
    int index = hashFunction(key);
    while (true) {
        if (table[index].empty()) {
            table[index].push_back(data);
            return;
        }
        else index++;
    }
}
void HashTable33::insertItem2(int key, int data)
{
    int index = hashFunction(key);
    while (true) {
        if (table[index].empty()) {
            table[index].push_back(data);
            return;
        }
        else { 
            index += (index * index);
             
        
        }
    }
}
void HashTable33::insertItem3(int key, int data)
{
    int index = hashFunction(key);
    while (true) {
        if (table[index].empty()) {
            table[index].push_back(data);
            return;
        }
        else index = hashFunction(key++);
    }
}

int HashTable33::hashFunction(int key)
{
    return key % capacity;
}

void HashTable33::deleteItem(int key)
{
    int index = hashFunction(key);

    list<int>::iterator i;
    for (i = table[index].begin();
        i != table[index].end(); i++)
    {
        if (*i == key)
            break;
    }

    if (i != table[index].end())
        table[index].erase(i);
}

void HashTable33::displayHash()
{
    for (int i = 0; i < capacity; i++)
    {
        cout << "table[" << i << "]";
        for (auto x : table[i])
            cout << " --> " << x;
        cout << endl;
    }
}

int HashTable33::checkPrime(int n)
{
    int i;
    if (n == 1 || n == 0)
    {
        return 0;
    }
    for (i = 2; i < n / 2; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int HashTable33::getPrime(int n)
{
    if (n % 2 == 0)
    {
        n++;
    }
    while (!checkPrime(n))
    {
        n += 2;
    }
    return n;
}
