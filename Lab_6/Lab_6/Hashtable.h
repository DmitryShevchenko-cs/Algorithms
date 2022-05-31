#include <iostream>
#include <list>
#include <windows.h>

using namespace std;

class HashTable1
{
    int capacity;
    list<int>* table;
public:
    HashTable1(int V);
    void insertItem(int key, int data);
    void deleteItem(int key);

    int checkPrime(int n);
    int getPrime(int n);
    
    int hashFunction(int key);
    void displayHash();
};

