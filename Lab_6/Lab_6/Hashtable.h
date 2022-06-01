#include <iostream>
#include <list>
#include <windows.h>

using namespace std;



class HashTable22 {
    int capacity;
    list <int>* table;

public:
    HashTable22(int V);
    void insertItem(int key, int data);
    void deleteItem(int key);

    int checkPrime(int n);
    int getPrime(int n);

    int hashFunction(int key);
    void displayHash();
};

class HashTable33 {
    int capacity;
    list <int>* table;

public:
    HashTable33(int V);
    void insertItem1(int key, int data);
    void insertItem2(int key, int data);
    void insertItem3(int key, int data);
    void deleteItem(int key);

    int checkPrime(int n);
    int getPrime(int n);

    int hashFunction(int key);
    void displayHash();
};

