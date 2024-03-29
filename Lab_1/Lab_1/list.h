#pragma once 

#include <iostream>
#include "windows.h"
#include "fstream"

using namespace std;

struct Data {
	char data;
	Data* n;	
	Data* p;
};

class list {

	Data* head, * tail;
public:
	list() : head(NULL), tail(NULL) {};
	~list();
	void create(int num);
	void createFromFile(string file);
	void show();
	void Add(char data);
	void del(int num);
	short number();
	void swap(int choice);
	void merge(list& LIST);
	void save();	
};

class circularList {
	Data* head;

public:
	circularList() : head(NULL) {};
	~circularList();
	void create(int num);
	void createFromFile(string file);
	void show();
	void Add(char data);
	void del(char ch);
	short number();
	void swap(char ch);
	void save();
	bool isChar(char ch);
	bool isEmpty();
};

