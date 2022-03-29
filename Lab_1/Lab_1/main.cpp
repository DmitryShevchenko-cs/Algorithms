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
		cout << "0 - �������� ������" << endl;
		cout << "1 - ���������� ������" << endl;
		cout << "2 - ������ ������� �� ����� (� �����)" << endl;
		cout << "3 - �������� �������� ������� � ������" << endl;
		cout << "4 - ��������� ������� �������� � ������" << endl;
		cout << "5 - ������� ��� ����� �������� ������" << endl;
		cout << "6 - ��'������ ��� ������ � ����" << endl;
		cout << "7 - �������� ������" << endl;
		cout << "8 - �������� ������" << endl;
		cout << "9 - �����" << endl;
		cout << "----------------------\n";

		cin >> choice;

		switch (choice) {
		case 0: 
			lst.show();
			cout << "-----------------------------------------------------\n\n";
			break;

		case 1:
			cout << "1 - �������� ���������" << endl;
			cout << "2 - ���������� � �����" << endl;
			cout << "������ ����� ���������� ������> ";
			cin >> choice;
			switch (choice) {
			case 1:
				cout << "ʳ������ �������� > ";
				cin >> choice;
				if (choice >= 0) {
					lst.create(choice);
					lst.show();
				}
				else
					cout << "������� �����..." << endl;
				cout << "-----------------------------------------------------\n\n";
				break;

			case 2:
				lst.createFromFile("List.txt");
				lst.show();
				cout << "-----------------------------------------------------\n\n";
				break;
			default:
				cout << "�� ����� ������� �����, ��������� �� ���" << endl;
				cout << "-----------------------------------------------------\n\n";
			}
			break;
		case 2:
			cout << "������ ������ > ";
			cin >> ch;
			lst.Add(ch);
			lst.show();
			cout << "-----------------------------------------------------\n\n";
			break;
		
		case 3:
			lst.show();
			cout << "������ ����� ������� ��� ��������� > ";
			
			cin >> choice;
			if(choice <= lst.number() && choice > 0)
				lst.del(choice);
			else cout << "�� ����� ������� �����, ��������� �� ��� > \n";
			lst.show();
			cout << "-----------------------------------------------------\n\n";
			break;

		case 4:
			cout << "ʳ������ ������� � ������: " << lst.number() << endl;
			break;

		case 5:
			cout << "������: ";
			lst.show();
			cout << "������ ����� �������, ��� ������� ���� � ��������� > ";
			cin >> choice;
			if (choice < lst.number() && choice > 0) {
				lst.swap(choice);
				lst.show();
			}
			else
				cout << "������� �����..." << endl;
			cout << "-----------------------------------------------------\n\n";
			break;

		case 6:
			cout << "ʳ������ �������� > ";
			cin >> choice;
			if (choice >= 0) {
				LST.create(choice);
				lst.merge(LST);
				lst.show();
			}
			else
				cout << "������� �����..." << endl;
			cout << "-----------------------------------------------------\n\n";
			break;

		case 7:
			lst.save();
			cout << "������ ���������" << endl;
			cout << "-----------------------------------------------------\n\n";
			break;

		case 8:
			lst.~list();
			cout << "������ ��������..." << endl;
			cout << "-----------------------------------------------------\n\n";
			break;

		case 9:
			lst.show();
			cout << "����� ..." << endl;
			cout << "-----------------------------------------------------\n\n";
			return 1;
		
		default:
			cout << "�� ����� ������� �����, ��������� �� ���" << endl;
			cout << "-----------------------------------------------------\n\n";

		}

	}

}