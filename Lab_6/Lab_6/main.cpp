#include "Hashtable.h"
#include "Hash.h"

void menu() {
	cout << "Хеш-Таблица с цепями" << endl;
	cout << "Хеш-Таблица с открытой адресацией" << endl;
}

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int key[] = { 63, 64, 65, 66, 67 };
	int data[] = { 3, 42, 31, 12, 33, 24, 13, 40, 10 };
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
	OpenHash h2(4);

	/*for (int i = 0; i < 9; i++)
		h2.insertItemL(data[i]);*/

	h2.insertItemL(5);
	h2.insertItemL(8);
	h2.insertItemL(9);
	h2.displayHash();
	cout << "----------------------------------" << endl;
	h2.searchItemL(31);
	cout << "\n-------------------------------------------" << endl;

	h2.deleteItemL(31);
	h2.displayHash();
	cout << "----------------------------------" << endl;
	h2.insertItemL(31);
	h2.displayHash();




}