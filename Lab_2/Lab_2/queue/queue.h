#include <iostream>
#include "windows.h"
#include <fstream>

using namespace std;

struct obj {
	short data;
	obj* prev;
};

class queue {

	obj* first;
	obj* tail;

public:

	queue() : first(NULL), tail(NULL) {};
	void Add(short el);
	void show();
	int count();
	short average();
	short Min();
	short Max();
	short prevMin();

	void readFile();
	void saveFile();

};