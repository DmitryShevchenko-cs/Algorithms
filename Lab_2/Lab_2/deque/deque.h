#pragma once
#include <iostream>
#include <Windows.h>
#include <fstream>

using namespace std;

struct obj {
	short data;
	obj* prev;
	obj* next;
};

class deque {
	obj* left, *right;

public:
	deque() : left(NULL), right(NULL) {};

	void pushFront(short el);
	void pushBack(short el);
	void show();
	short read6El();
	short readlast();
	bool isEmpty();
	int count();

	void readFile();
	void saveFile();
};