#include "list.h"

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	short choice = -1;
	short choiceList = -1;
	char ch;
	list lst;
	list LST;
	circularList cLst;
	circularList cLST;

	while (true) {
		cout << "-----------------------------------------------------\n";
		cout << "0 - ������, 1 - ��������" << endl;
		cout << "----------------------\n";
		cin >> choiceList;
		if (choiceList > 1 || choiceList < 0) {
			cout << "�� ����� ������ ��������, ��������� �� ���" << endl;
			cout << "-----------------------------------------------------\n";
		}
		else
			break;
	}
	cout << "-----------------------------------------------------\n";

	while (true) {
		cout << "���������� ������" << endl;
		cout << "1 - �������� ���������" << endl;
		cout << "2 - ���������� � �����" << endl;
		cout << "������ ����� ���������� ������> ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "ʳ������ �������� > ";
			cin >> choice;
			if (choice >= 0) {
				if (!choiceList) {
					lst.create(choice);
					lst.show();
				}
				else {
					cLst.create(choice);
					cLst.show();
				}
			}
			else
				cout << "������� �����..." << endl;
			cout << "-----------------------------------------------------\n\n";
			break;

		case 2:
			if (!choiceList) {
				lst.createFromFile("List.txt");
				lst.show();
			}
			else {
				cLst.createFromFile("List.txt");
				cLst.show();
			}
			cout << "-----------------------------------------------------\n\n";
			break;
		default:
			cout << "�� ����� ������� �����, ��������� �� ���" << endl;
			cout << "-----------------------------------------------------\n\n";
		}

		break;

	}
	
	while (true) {
		cout << "-----------------------------------------------------\n";
		cout << "������ ��" << endl;
		cout << "1 - �������� ������" << endl;
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
		case 1: 
			if (!choiceList)
				lst.show();
			else
				cLst.show();
			cout << "-----------------------------------------------------\n\n";
			break;
			
		case 2:
			cout << "������ ������ > ";
			cin >> ch;
			if (!choiceList) {
				lst.Add(ch);
				lst.show();
			}
			else {
				cLst.Add(ch);
				cLst.show();
			}
			
			cout << "-----------------------------------------------------\n\n";
			break;
		
		case 3:
			
			if (!choiceList) {
				lst.show();
				cout << "������ ����� ������� ��� ��������� > ";
				cin >> choice;
				if (choice <= lst.number() && choice > 0) {
					lst.del(choice);
					lst.show();
				}
				else cout << "�� ����� ������� �����, ��������� �� ��� > \n";
			}
			else {
				cLst.show();
				cout << "������ ������ ��� ��������� > ";
				cin >> ch;
				if (cLst.isChar(ch)) {
					cLst.del(ch);
					cLst.show();
				}
				else cout << "�� ����� ������� �����, ��������� �� ��� > \n";
				
			}
			cout << "-----------------------------------------------------\n\n";
			break;

		case 4:
			if (!choiceList) {
				cout << "ʳ������ ������� � ������: " << lst.number() << endl;
			}
			else {
				cout << "ʳ������ ������� � ������: " << cLst.number() << endl;

			}
			break;

		case 5:
			if (!choiceList) {
				lst.show();
				cout << "������ ����� �������, ��� ������� ���� � ��������� > ";
				cin >> choice;
				if (choice < lst.number() && choice > 0) {
					lst.swap(choice);
					lst.show();
				}
				else
					cout << "������� �����..." << endl;
			}
			else {
				cLst.show();
				cout << "������ ������, ��� ������� ���� � ��������� > ";
				cin >> ch;
				if (cLst.isChar(ch)) {
					cLst.swap(ch);
					cLst.show();
				}
				else
					cout << "������� �����..." << endl;

			}
			
			cout << "-----------------------------------------------------\n\n";
			break;

		case 6:
			cout << "ʳ������ �������� > ";
			cin >> choice;
			if (!choiceList) {
				if (choice >= 0) {
					LST.create(choice);
					lst.merge(LST);
					lst.show();
				}
				else
					cout << "������� �����..." << endl;
			}
			else {
				if (choice >= 0) {
					cLST.create(choice);
					cLst.merge(cLST);
					cLst.show();
				}
				else
					cout << "������� �����..." << endl;
			}
			
			cout << "-----------------------------------------------------\n\n";
			break;

		case 7:
			if (!choiceList) {
				lst.save();
			}
			else {
				cLst.save();
			}
			cout << "������ ���������" << endl;
			cout << "-----------------------------------------------------\n\n";
			break;

		case 8:
			if (!choiceList) {
				lst.~list();
			}
			else {
				cLst.~circularList();
			}
			cout << "������ ��������..." << endl;
			cout << "-----------------------------------------------------\n\n";
			break;

		case 9:
			cout << "����� ..." << endl;
			cout << "-----------------------------------------------------\n\n";
			
			exit(1);

		default:
			cout << "�� ����� ������� �����, ��������� �� ���" << endl;
			cout << "-----------------------------------------------------\n\n";

		}

	}

}