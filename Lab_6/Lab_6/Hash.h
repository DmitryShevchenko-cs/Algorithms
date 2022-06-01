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
    void insertItem(int key);
    void deleteItem(int key);
    int searchItem(int key);
    int hashFunction(int key);
    void displayHash();
};