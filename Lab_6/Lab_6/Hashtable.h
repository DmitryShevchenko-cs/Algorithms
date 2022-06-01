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
    void searchItem(int key);
    int hashFunction(int key);
    void displayHash();
};

class HashTable2 {
    int capacity;
    list <int>* table;

public:
    HashTable2(int V);
    void insertItem(int key, int data);
    void deleteItem(int key);

    int checkPrime(int n);
    int getPrime(int n);

    int hashFunction(int key);
    void displayHash();
};

class HashTable3 {
    int capacity;
    list <int>* table;

public:
    HashTable3(int V);
    void insertItem1(int key, int data);
    void insertItem2(int key, int data);
    void insertItem3(int key, int data);
    void deleteItem(int key);

    int checkPrime(int n);
    int getPrime(int n);

    int hashFunction(int key);
    void displayHash();
};