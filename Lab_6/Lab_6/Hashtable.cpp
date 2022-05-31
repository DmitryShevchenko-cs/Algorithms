#include "Hashtable.h"

HashTable1::HashTable1(int c)
{
    int size = getPrime(c);
    this->capacity = size;
    table = new list<int>[capacity];
}
void HashTable1::insertItem(int key, int data)
{
    int index = hashFunction(key);
    table[index].push_back(data);
}

int HashTable1::checkPrime(int n)
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

int HashTable1::getPrime(int n)
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

int HashTable1::hashFunction(int key)
{
    return capacity * fmod(key * ((sqrt(5) - 1 / 2)), 1);
}

void HashTable1::deleteItem(int key)
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