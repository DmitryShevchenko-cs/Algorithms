#include <iostream>
#include "windows.h"
#include "fstream"

using namespace std;

struct obj {
	string name;
	int year;
	int num;

	obj *r, *l;
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
	void show(obj* temp);

	//������ �������������� ������ � �������� ����, �������� ��� � ������.
	void avarageNum(obj* temp);
	int getAv();

	void preOrder(obj* temp);
	void postOrder(obj* temp);
	void symmetricOrder(obj* temp);

	void delBT(obj* temp);

	void print_Tree(obj* temp, int level = 0);

	bool isEpty();
};