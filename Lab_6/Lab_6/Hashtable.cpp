#include "Hashtable.h"

HashTable1::HashTable1(int c)
{
    this->capacity = c;
    table = new list<int>[capacity];
}
void HashTable1::insertItem(int key, int data)
{
    int index = hashFunction(key);
    table[index].push_back(data);
}

int HashTable1::hashFunction(int key)
{
    return capacity * fmod(key * ((sqrt(5) - 1 / 2)), 1);
}

void HashTable1::deleteItem(int data)
{
    int index = hashFunction(data);

    list<int>::iterator i;
    for (i = table[index].begin();
        i != table[index].end(); i++)
    {
        if (*i == data)
            break;
    }

    if (i != table[index].end())
        table[index].erase(i);
}

void HashTable1::searchItem(int key)
{
    int index = hashFunction(key);
    cout << "table[" << index << "]";
    for (auto x : table[index])
        cout << " --> " << x;
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




HashTable2::HashTable2(int c)
{
    //int size = getPrime(c);
    this->capacity = c;
    table = new list<int>[capacity];
}

void HashTable2::insertItem(int key, int data)
{
    int index = hashFunction(key);
    table[index].push_back(data);
}

int HashTable2::checkPrime(int n)
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

int HashTable2::getPrime(int n)
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

int HashTable2::hashFunction(int key)
{
    return key % capacity;
}

void HashTable2::deleteItem(int key)
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

void HashTable2::displayHash()
{
    for (int i = 0; i < capacity; i++)
    {
        cout << "table[" << i << "]";
        for (auto x : table[i])
            cout << " --> " << x;
        cout << endl;
    }
}




HashTable3::HashTable3(int c)
{
    int size = getPrime(c);
    this->capacity = size;
    table = new list<int>[capacity];
}
void HashTable3::insertItem1(int key, int data)
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
void HashTable3::insertItem2(int key, int data)
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
void HashTable3::insertItem3(int key, int data)
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

int HashTable3::hashFunction(int key)
{
    return key % capacity;
}

void HashTable3::deleteItem(int key)
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

void HashTable3::displayHash()
{
    for (int i = 0; i < capacity; i++)
    {
        cout << "table[" << i << "]";
        for (auto x : table[i])
            cout << " --> " << x;
        cout << endl;
    }
}

int HashTable3::checkPrime(int n)
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

int HashTable3::getPrime(int n)
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
