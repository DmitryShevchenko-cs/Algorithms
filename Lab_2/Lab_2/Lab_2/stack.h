#include <iostream>
#include "windows.h"
#include "fstream"

using namespace std;

struct obj{
	short data;
	obj* next;
};

class stack {

	obj* top;

public:
	stack() : top(NULL) {};
	~stack();
	void push(short d);
	void pop();
	short pull();
	void show();

	void readFile();
	void saveFile();

	void swapTopTail();
	void reverse();
	void delEvery2();
	void delMin();
	void delHead();
	void delTail();
	void maxZero();
	void putStar();

	bool isEmpty();
};