#pragma once 

#include <iostream>
#include "windows.h"

using namespace std;

struct Data {
	char data;
	Data* n;	//int
	Data* p;
};

class list {
	Data *head, *tail;
public:
	list() : head(NULL), tail(NULL) {};
	~list();
	void show();
	void Add(char data);
	void del(int num);
	short number();
	void swap(int first, int second);
	void merge(list& LIST);
};


