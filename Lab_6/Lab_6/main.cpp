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
	cout << "4 - �����" << endl;
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
	cout << "5 - �����" << endl;
	cout << "�������� ������� --> ";
}

void tableChains() {
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
	
void lineMethod(){
	int ch = 0;
	int key[] = { 3, 42, 31,12, 33, 24, 13, 40, 10 };
	int data;
	int* arr;
	int size;
	menuArr();
	cin >> ch;
	if (ch == 1) {
		OpenHash LineHash(11);
		for (int i = 0; i < 9; i++)
			LineHash.insertItemL(key[i]);
		LineHash.displayHash();
		while (1) {
			actionMenu();
			cin >> ch;
			switch (ch) {
			case 1:
				cout << "������� ������� --> ";
				cin >> data;
				LineHash.insertItemL(data);
				LineHash.displayHash();
				break;
			case 2:
				cout << "������� ������� --> ";
				cin >> data;
				LineHash.deleteItemL(data);
				LineHash.displayHash();
				break;
			case 3:
				cout << "������� ������� --> ";
				cin >> data;
				LineHash.searchItemL(data);
				break;
			case 4:
				LineHash.displayHash();
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
		OpenHash LineHash(size);
		for (int i = 0; i < size; i++)
			LineHash.insertItemL(arr[i]);
		while (1) {
			actionMenu();
			cin >> ch;
			switch (ch) {
			case 1:
				cout << "������� ������� --> ";
				cin >> data;
				LineHash.insertItemL(data);
				LineHash.displayHash();
				break;
			case 2:
				cout << "������� ������� --> ";
				cin >> data;
				LineHash.deleteItemL(data);
				LineHash.displayHash();
				break;
			case 3:
				cout << "������� ������� --> ";
				cin >> data;
				LineHash.searchItemL(data);
				break;
			case 4:
				LineHash.displayHash();
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

void QuadMethod(){
	int ch = 0;
	int key[] = { 3, 42, 31,12, 33, 24, 13, 40, 10 };
	int data;
	int* arr;
	int size;
	menuArr();
	cin >> ch;
	if (ch == 1) {
		OpenHash QuadHash(11);
		for (int i = 0; i < 9; i++)
			QuadHash.insertItemQuad(key[i]);
		QuadHash.displayHash();
		while (1) {
			actionMenu();
			cin >> ch;
			switch (ch) {
			case 1:
				cout << "������� ������� --> ";
				cin >> data;
				QuadHash.insertItemQuad(data);
				QuadHash.displayHash();
				break;
			case 2:
				cout << "������� ������� --> ";
				cin >> data;
				QuadHash.deleteItemQuad(data);
				QuadHash.displayHash();
				break;
			case 3:
				cout << "������� ������� --> ";
				cin >> data;
				QuadHash.searchItemQuad(data);
				break;
			case 4:
				QuadHash.displayHash();
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
		OpenHash QuadHash(size);
		for (int i = 0; i < size; i++)
			QuadHash.insertItemQuad(arr[i]);
		while (1) {
			actionMenu();
			cin >> ch;
			switch (ch) {
			case 1:
				cout << "������� ������� --> ";
				cin >> data;
				QuadHash.insertItemQuad(data);
				QuadHash.displayHash();
				break;
			case 2:
				cout << "������� ������� --> ";
				cin >> data;
				QuadHash.deleteItemQuad(data);
				QuadHash.displayHash();
				break;
			case 3:
				cout << "������� ������� --> ";
				cin >> data;
				QuadHash.searchItemQuad(data);
				break;
			case 4:
				QuadHash.displayHash();
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
			tableChains();
		}
		if (choice == 2)
		{
			while (choice!=4) {
				menu2();
				cin >> choice;
				switch (choice)
				{
				case 1:
					lineMethod();
					break;
				case 2:
					QuadMethod();
					break;
				case 3:
					break;

				case 4:
					break;
				default:
					cout << "������ �����" << endl;
					break;
				}


			}
		}
		else
			cout << "������ �����" << endl;
	}
}