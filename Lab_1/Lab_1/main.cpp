#include "list.h"

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	list lst;
	short choice = -1;

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
			lst.Add('b');
			break;

		case 2:
			lst.Add('a');
			lst.show();
			break;
		
		case 3:
			lst.del(3);
			lst.show();
			break;

		case 4:
			cout << lst.number() << endl;
			break;

		case 5:

			break;

		case 6:

			break;

		case 7:

			break;

		case 8:
			lst.show();
			cout << "����� ..." << endl;
			return 1;


		}

	}

}