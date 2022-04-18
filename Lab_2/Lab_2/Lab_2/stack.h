#include <iostream>
#include "windows.h"

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

	void swapTopTail();
	void reverse();
	void delEvery2();
	void delMin();
	void delTail();
	void delHead();
	void maxZero();


	bool isEmpty();
};