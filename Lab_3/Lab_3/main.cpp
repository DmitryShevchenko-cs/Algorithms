#include "tree.h"

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	bTree tr, trRB;
	int choice = -1;
	string name;
	int year, num;
	string st;
	while (true) {
		cout << "----------------------------------------------------------" << endl;
		cout << "1 - �������� ������" << endl; 
		cout << "2 - ������ �������" << endl; 
		cout << "3 - ������� � ������ ������" << endl; 
		cout << "4 - ������� ������ �������� ������" << endl; 
		cout << "5 - ������ �����" << endl; 
		cout << "6 - �������� �����" << endl; 
		cout << "7 - ����������� �����" << endl; 
		cout << "8 - �������� ����� ��������" << endl; 
		cout << "9 - �������� ��� ��������" << endl; 
		cout << "10 - �������� �����" << endl; 
		cout << "11 - ���������� �� ������ �����" << endl; 

		cout << "12 - ������������ � �������-�����" << endl; 
		cout << "13 - " << endl; 
		cout << "---------------------------" << endl;

		cin >> choice;

		switch (choice) {
		case 1: 
			cout << "������ �����, �� ��� ������� ������ �������> ";
			cin >> name >> year >> num;
			tr.create(name, year, num);
			cout << "---------------------------" << endl;
			tr.print_Tree(tr.getRoot());
			cout << "----------------------------------------------------------" << endl;
			break;
		case 2:
			cout << "������ �����, �� ��� ������� ������ �������> ";
			cin >> name >> year >> num;
			tr.add(name, year, num);
			cout << "---------------------------" << endl;
			tr.print_Tree(tr.getRoot());
			break;
			cout << "----------------------------------------------------------" << endl;
		case 3:
			cout << "---------------------------" << endl;
			tr.print_Tree(tr.getRoot());
			cout << "----------------------------------------------------------" << endl;
			break;
		case 4:
			cout << "������ ��������������: " << tr.getAv() << endl;
			cout << "---------------------------" << endl;
			tr.print_Tree(tr.getRoot());
			cout << "----------------------------------------------------------" << endl;
			break;
		case 5:
			tr.preOrder(tr.getRoot());
			cout << "\n---------------------------" << endl;
			tr.print_Tree(tr.getRoot());
			cout << "----------------------------------------------------------" << endl;
			break;
		case 6:
			tr.postOrder(tr.getRoot());
			cout << "\n---------------------------" << endl;
			tr.print_Tree(tr.getRoot());
			cout << "----------------------------------------------------------" << endl;
			break;
		case 7:
			tr.symmetricOrder(tr.getRoot());
			cout << "\n---------------------------" << endl;
			tr.print_Tree(tr.getRoot());
			cout << "----------------------------------------------------------" << endl;
			break;
		case 8:
			tr.delR();
			cout << "---------------------------" << endl;
			tr.print_Tree(tr.getRoot());
			cout << "----------------------------------------------------------" << endl;
			break;
		case 9:
			tr.delL();
			cout << "---------------------------" << endl;
			tr.print_Tree(tr.getRoot());
			cout << "----------------------------------------------------------" << endl;
			break;

		case 10:
			cout << "������ �����: ";
			cin >> st;
			tr.Remove(st);
			cout << "---------------------------" << endl;
			tr.print_Tree(tr.getRoot());
			cout << "----------------------------------------------------------" << endl;
			break;

		case 11:
			tr.newTree(tr.getRoot(), trRB);
			tr.delBT(tr.getRoot());
			tr = trRB;
			cout << "---------------------------" << endl;
			tr.print_Tree(tr.getRoot());
			cout << "----------------------------------------------------------" << endl;
			break;

		default:
			cout << "������� ������� �����" << endl;
			cout << "----------------------------------------------------------" << endl;
			break;

		}




	}
}