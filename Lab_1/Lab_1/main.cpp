#include "list.h"

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	list lst;
	list LST;
	short choice = -1;
	char ch;

	while (true) {
		cout << "-----------------------------------------------------\n";
		cout << "������ ��" << endl;
		cout << "1 - ���������� ������" << endl;
		cout << "2 - ������ ������� �� ����� (� �����)" << endl;
		cout << "3 - �������� �������� ������� � ������" << endl;
		cout << "4 - ��������� ������� �������� � ������" << endl;
		cout << "5 - ������� ��� ����� �������� ������" << endl;
		cout << "6 - ��'������ ��� ������ � ����" << endl;
		cout << "7 - �������� ������" << endl;
		cout << "8 - �����" << endl;
		cout << "-----------------------------------------------------\n";

		cin >> choice;

		switch (choice) {
		case 1:
			lst.create(2);
			lst.show();
			break;

		case 2:
			cout << "������� ������ > ";
			cin >> ch;
			lst.Add(ch);
			lst.show();
			break;
		
		case 3:
			lst.show();
			cout << "������� ����� ���������� ������� > ";
			
			cin >> choice;
			if(choice <= lst.number() && choice > 0)
				lst.del(choice);
			else cout << "�� ����� �������� �����, ���������� ��� ��� > \n";
			lst.show();
			break;

		case 4:
			cout << lst.number() << endl;
			break;

		case 5:

			cout << "������� ����� ���������� ������� > ";
			cin >> choice;
			if (choice < lst.number() && choice > 0) {
				lst.swap(choice);
				lst.show();
			}
			else cout << "�� ����� �������� �����, ���������� ��� ��� > \n";
			
			break;

		case 6:
			
			LST.create(3);
			lst.merge(LST);
			lst.show();
			break;

		case 7:
			lst.save();
			lst.~list();
			break;

		case 8:
			lst.show();
			lst.save();
			cout << "����� ..." << endl;
			return 1;
		
		default:
			cout << "�� ����� �������� �����, ���������� ��� ���" << endl << endl;

		}

	}

}