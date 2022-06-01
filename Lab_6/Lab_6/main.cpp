#include "Hashtable.h"
#include "Hash.h"

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int key[] = { 63, 64, 65, 66, 67 };
	int data[] = { 3, 42, 31, 12, 33, 24, 13, 40, 10 };
	HashTable1 h1(6);

	for (int i = 0; i < 5; i++)
		h1.insertItem(key[i]);
	
	h1.displayHash();
	cout << "----------------------------------" << endl;
	h1.deleteItem(321);
	h1.displayHash();
	cout << "----------------------------------" << endl;
	h1.searchItem(321);




	HashTable22 h2(9);
	/*for (int i = 0; i < 9; i++)
		h2.insertItem(data[i], data[i]);*/
	/*h2.displayHash();
	cout << "----------------------------------" << endl;

	HashTable3 h3(11);
	for (int i = 0; i < 9; i++)
		h3.insertItem2(data[i], data[i]);
	h3.displayHash();*/


}