#include <iostream>
#include <list>
#include <windows.h>
#include <vector>

using namespace std;

class ChainHash
{
    int capacity;
    list<int>* table;
public:
    ChainHash(int V);
    void insertItem(int key);
    void deleteItem(int key);
    int searchItem(int key);
    int hashFunction(int key);
    void displayHash();
};

class OpenHash {
    int capacity;
    vector<int> table;
    vector<int> infoNode; // 0 - empty; 1 - full; 2 - deleted
public:
    OpenHash(int V);
    void insertItemL(int key);
    void deleteItemL(int key);
    int searchItemL(int key);

    void insertItem2(int key);
    void deleteItem2(int key);
    int searchItem2(int key);


    void insertItemQuad(int key);
    void deleteItemQuad(int key);
    int searchItemQuad(int key);
    int hashFunctionQuad(int key, int i) {
        return fmod(hashFunction((key) + (i * i)) , capacity);
    }

    int hashFunction(int key);
    int hashFunction2(int key) {
        return (1 + fmod(key, capacity - 1));
    };
    void displayHash();
};