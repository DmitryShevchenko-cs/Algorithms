#include "Hash.h"

void menu() {
	cout << "���-������� � ������" << endl;
	cout << "���-������� � �������� ����������" << endl;
}

void tralala() {
	int key[] = { 63, 64, 65, 66, 67 };
	//int data[] = { 3, 42, 31, 12, 33, 24, 13, 40, 10 };
	int data[] = { 3, 42, 3, 12, 3, 24, 13, 40, 10 };
	/*ChainHash h1(6);

	for (int i = 0; i < 5; i++)
		h1.insertItem(key[i]);

	h1.displayHash();
	cout << "----------------------------------" << endl;
	h1.deleteItem(63);
	h1.displayHash();
	cout << "----------------------------------" << endl;
	h1.searchItem(64);
	cout << "\n-------------------------------------------" << endl;*/


	for (int i = 0; i < 9; i++)
		cout << data[i] << '\t';
	cout << endl;
	for (int i = 0; i < 9; i++)
		cout << fmod(data[i], 11) << '\t';
	cout << endl;
	OpenHash h2(11);
	for (int i = 0; i < 9; i++)
		h2.insertItemL(data[i]);
	h2.displayHash();
	cout << "----------------------------------" << endl;


	//OpenHash h3(11);
	//for (int i = 0; i < 9; i++)
	//	cout << data[i] << '\t';
	//cout << endl;
	//for (int i = 0; i < 9; i++)
	//	h3.insertItem2(data[i]);
	//cout << endl;
	//h3.displayHash();
	//cout << "----------------------------------" << endl;
	//h3.deleteItem2(12);
	//h3.displayHash();
	//cout << "----------------------------------" << endl;
	//h3.searchItem2(3);

	for (int i = 0; i < 9; i++)
		cout << data[i] << '\t';
	cout << endl;

	OpenHash QuadHash(11);
	for (int i = 0; i < 9; i++)
		QuadHash.insertItemQuad(data[i]);
	cout << endl;
	QuadHash.displayHash();
	cout << endl;
	cout << "----------------------------------" << endl;
	cout << "----------------------------------" << endl;
	QuadHash.deleteItem2(3);
	QuadHash.displayHash();
	cout << "----------------------------------" << endl;
	QuadHash.searchItem2(3);
	QuadHash.insertItemQuad(3);
	cout << endl;
	cout << endl;
	QuadHash.displayHash();
}

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	tralala();
	
}