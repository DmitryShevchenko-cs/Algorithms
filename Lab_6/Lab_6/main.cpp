#include "Hash.h"

void menu() {
	cout << "\n\n-------------------------------------------------" << endl;
	cout << "1 - ���-������� � ������" << endl;
	cout << "2 - ���-������� � �������� ����������" << endl;
	cout << "�������� ������� --> ";
}

void menu2() {
	cout << "\n\n-------------------------------------------------" << endl;
	cout << "1 - �������� �����" << endl;
	cout << "2 - �������������� �����" << endl;
	cout << "3 - ������� �����������" << endl;
	cout << "�������� ������� --> ";
}

void menuArr() {
	cout << "\n\n-------------------------------------------------" << endl;
	cout << "1 - ������ �� �������" << endl;
	cout << "2 - ���� ������" << endl;
	cout << "3 - �����" << endl;
	cout << "�������� ������� --> ";
}

void actionMenu() {
	cout << "\n\n-------------------------------------------------" << endl;
	cout << "1 - ���������� ��������" << endl;
	cout << "2 - ��������" << endl;
	cout << "3 - ����� �������" << endl;
	cout << "4 - �����" << endl;
	cout << "4 - �����" << endl;
	cout << "�������� ������� --> ";
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
				cout << "������� ������� --> ";
				cin >> data;
				chainHash.insertItem(data);
				chainHash.displayHash();
				break;
			case 2:
				cout << "������� ������� --> ";
				cin >> data;
				chainHash.deleteItem(data);
				chainHash.displayHash();
				break;
			case 3:
				cout << "������� ������� --> ";
				cin >> data;
				chainHash.searchItem(data);
				break;
			case 4:
				chainHash.displayHash();
				break;
			case 5:
				return;
			default:
				cout << "������ �����" << endl;
				break;
			}
		}
	}

	else if (ch == 2) {
		cout << "������� ������ ������� --> "; cin >> size;
		cout << "������� ������ ��������:" << size << endl;
		arr = new int[size];
		for (int i = 0; i < size; i++) {
			cin >> data;
			arr[i] = data;
		}
		cout << "������� ������ ������� -->"; cin >> size;
		ChainHash chainHash(size);
		for (int i = 0; i < size; i++)
			chainHash.insertItem(arr[i]);
		while (1) {
			actionMenu();
			cin >> ch;
			switch (ch) {
			case 1:
				cout << "������� ������� --> ";
				cin >> data;
				chainHash.insertItem(data);
				chainHash.displayHash();
				break;
			case 2:
				cout << "������� ������� --> ";
				cin >> data;
				chainHash.deleteItem(data);
				chainHash.displayHash();
				break;
			case 3:
				cout << "������� ������� --> ";
				cin >> data;
				chainHash.searchItem(data);
				break;
			case 4:
				chainHash.displayHash();
				break;
			case 5:
				return;
			default:
				cout << "������ �����" << endl;
				break;
			}
		}
	}

	else if (ch == 3) return;
	else
		cout << "������ �����" << endl;
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
			cout << "������ �����" << endl;
	}


}