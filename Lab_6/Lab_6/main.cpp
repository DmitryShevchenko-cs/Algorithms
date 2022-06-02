#include "Hash.h"

void menu() {
	cout << "\n\n-------------------------------------------------" << endl;
	cout << "1 - Хеш-Таблица с цепями" << endl;
	cout << "2 - Хеш-Таблица с открытой адресацией" << endl;
	cout << "Виберите вариант --> ";
}

void menu2() {
	cout << "\n\n-------------------------------------------------" << endl;
	cout << "1 - Линейный метод" << endl;
	cout << "2 - Квадратический метод" << endl;
	cout << "3 - Двойное хеширование" << endl;
	cout << "Виберите вариант --> ";
}

void menuArr() {
	cout << "\n\n-------------------------------------------------" << endl;
	cout << "1 - Массив из задания" << endl;
	cout << "2 - Свой массив" << endl;
	cout << "3 - Выход" << endl;
	cout << "Виберите вариант --> ";
}

void actionMenu() {
	cout << "\n\n-------------------------------------------------" << endl;
	cout << "1 - Добавление елемента" << endl;
	cout << "2 - Удаление" << endl;
	cout << "3 - Найти елемент" << endl;
	cout << "4 - Вывод" << endl;
	cout << "4 - Выход" << endl;
	cout << "Виберите вариант --> ";
}

void tralala() {
	int key[] = { 63, 64, 65, 66, 67 };
	int data[] = { 3, 42, 31, 12, 33, 24, 13, 40, 10 };

	ChainHash h1(6);

	for (int i = 0; i < 5; i++)
		h1.insertItem(key[i]);

	h1.displayHash();
	cout << "----------------------------------" << endl;
	h1.deleteItem(63);
	h1.displayHash();
	cout << "----------------------------------" << endl;
	h1.searchItem(64);
	cout << "\n-------------------------------------------" << endl;


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

void TableChains() {
	int ch = 0;
	int key[] = { 63, 64, 65, 66, 67 };
	int data;
	int* arr;
	int size;
	menuArr();
	cin >> ch;
	if (ch == 1) {
		ChainHash chainHash(6);
		for (int i = 0; i < 5; i++)
			chainHash.insertItem(key[i]);
		chainHash.displayHash();
		while (1) {
			actionMenu();
			cin >> ch;
			switch (ch) {
			case 1:
				cout << "Введите елемент --> ";
				cin >> data;
				chainHash.insertItem(data);
				chainHash.displayHash();
				break;
			case 2:
				cout << "Введите елемент --> ";
				cin >> data;
				chainHash.deleteItem(data);
				chainHash.displayHash();
				break;
			case 3:
				cout << "Введите елемент --> ";
				cin >> data;
				chainHash.searchItem(data);
				break;
			case 4:
				chainHash.displayHash();
				break;
			case 5:
				return;
			default:
				cout << "Ошибка ввода" << endl;
				break;
			}
		}
	}

	else if (ch == 2) {
		cout << "Введите размер массива --> "; cin >> size;
		cout << "Введите массив размером:" << size << endl;
		arr = new int[size];
		for (int i = 0; i < size; i++) {
			cin >> data;
			arr[i] = data;
		}
		cout << "Введите размер таблицы -->"; cin >> size;
		ChainHash chainHash(size);
		for (int i = 0; i < size; i++)
			chainHash.insertItem(arr[i]);
		while (1) {
			actionMenu();
			cin >> ch;
			switch (ch) {
			case 1:
				cout << "Введите елемент --> ";
				cin >> data;
				chainHash.insertItem(data);
				chainHash.displayHash();
				break;
			case 2:
				cout << "Введите елемент --> ";
				cin >> data;
				chainHash.deleteItem(data);
				chainHash.displayHash();
				break;
			case 3:
				cout << "Введите елемент --> ";
				cin >> data;
				chainHash.searchItem(data);
				break;
			case 4:
				chainHash.displayHash();
				break;
			case 5:
				return;
			default:
				cout << "Ошибка ввода" << endl;
				break;
			}
		}
	}

	else if (ch == 3) return;
	else
		cout << "Ошибка ввода" << endl;
}
	

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//tralala();
	int choice= -1;

	while (1) {
		menu();
		cin >> choice;

		if (choice == 1)
		{
			TableChains();
		}
		if (choice == 2)
		{

		}
		else
			cout << "Ошибка ввода" << endl;
	}


}