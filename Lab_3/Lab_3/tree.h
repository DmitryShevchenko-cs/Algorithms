#include <iostream>
#include "windows.h"
#include "fstream"

using namespace std;

struct obj {
	string name;
	int year;
	int num;

	obj *right = NULL, *left = NULL;

	string color;
	obj* parent = NULL;
};

class bTree {

	obj* root;
	int avarage = 0;
	int count = 0;
public: 
	obj* getRoot() { return root; }
	bTree() { root = NULL; };

	//������ � ��������� ������� "��������" � ������� ������, 
	//����������� �� �������� ���������� ����. ������������ �������� ������ ������.
	void create(string Name, int Year, int Num);
	void add(string Name, int Year, int Num);
	void add4num(string Name, int Year, int Num);
	void print_Tree(obj* temp, int level = 0);

	//������ �������������� ������ � �������� ����, �������� ��� � ������.
	void avarageNum(obj* temp);
	int getAv();

	//������
	void preOrder(obj* temp);
	void postOrder(obj* temp);
	void symmetricOrder(obj* temp);

	// ��������
	void delBT(obj* temp);
	void delL();
	void delR();

	void RemoveNode(obj* parent, obj* curr, string Name);
	void Remove(string Name);
	void RemoveNode(obj* parent, obj* curr, int Num);
	void Remove(int Num);

	//�� ������ �����
	void newTree(obj* temp, bTree &tr);
	
	void paint(obj* temp);

	bool isEmpty();
};