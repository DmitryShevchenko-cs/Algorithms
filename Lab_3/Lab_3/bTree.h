#pragma once
#include <iostream>
#include "windows.h"

using namespace std;

struct node {
	string name;
	int year;
	int num;

	node* right = NULL, * left = NULL;
	node* parent;
	string color;
};

class rbTree {

	node* root;
public:

	rbTree() : root(NULL) {};
	node* getRoot() { return root; };

	void addRB(string Name, int Year, int Num);
	void RB_Insert_Fixup(node* z);
	void LeftRotate(node* x);
	void RightRotate(node* x);
	void print_RBTree(node* temp, int level = 0);
	void RemoveNodeRB(node* parent, node* curr, int Num);
	void RB_Delete_Fixup(node* z);
	void RemoveRBNode(int Num);

	bool isEmpty() { return root == NULL ? true : false; };
};

class bTree {
	node* root;
	int count;
	int avarage;

	void avarageNum(node* temp);
	void add4num(string Name, int Year, int Num);
	void RemoveNode(node* parent, node* curr, string Name);
public:

	node* getRoot() { return root; }
	bTree(): root(NULL), count(0), avarage(0) {};

	//добавление и печать
	void add(string Name, int Year, int Num);
	void print_Tree(node* temp, int level = 0);

	//Знайти середнєзначення одного з числових полів, зчитуючи дані з дерева.
	
	int getAv();

	//обходы
	void preOrder(node* temp);
	void postOrder(node* temp);
	void symmetricOrder(node* temp);

	// удаления
	void delBT(node* temp);
	void delL();
	void delR();
	void Remove(string Name);
	void delete_tree(node* temp);
	
	void newTree(node* temp, bTree& tr);

	void RB(node* temp, rbTree& rb);

	bool isEmpty() { return root==NULL ? true : false; }
};

void menu_b();
void menu_rb();