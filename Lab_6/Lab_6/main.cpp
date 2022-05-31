#include "Hashtable.h"

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int key[] = { 63, 64, 65, 66, 67 };
	int data[] = { 3, 42, 31, 12, 33, 24, 13, 40, 10 };
	//int size = sizeof(key) / sizeof(key[0]);
	//size = 9;

	HashTable1 h(9);

	for (int i = 0; i < 5; i++)
		h.insertItem(key[i], data[i]);

	h.deleteItem(12);
	h.displayHash();

}