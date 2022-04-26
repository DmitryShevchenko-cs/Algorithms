#include "deque.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice = -1;
	deque dq;
	short el = 0;
	while (true) {
		cout << "----------------------------------------------------------" << endl;
		cout << "0 - ������� � �����" << endl;
		cout << "1 - �������� ���" << endl; 
		cout << "2 - ������� ������" << endl;  
		cout << "3 - ������ � �������" << endl;
		cout << "4 - ������ � �����" << endl;  
		cout << "5 - ��������� �� ���������" << endl;
		cout << "6 - ��������� ������ �������" << endl;
		cout << "7 - ��������� ������� �������" << endl;
		cout << "8 - ������� � ����" << endl;
		cout << "9 - �����" << endl;  
		cout << "---------------------------" << endl;

		cin >> choice;

		switch (choice) {

		case 0:
			dq.readFile();
			dq.show();
			cout << "----------------------------------------------------------" << endl;
			break;
		case 1:

			cout << "������ ������� (short int) > ";
			cin >> el;
			dq.pushBack(el);
			dq.show();
			cout << "----------------------------------------------------------" << endl;
			break;
		case 2:
			dq.show();
			cout << "----------------------------------------------------------" << endl;
			break;
		case 3:
			cout << "������ ������� (short int) > ";
			cin >> el;
			dq.pushFront(el);
			dq.show();
			cout << "----------------------------------------------------------" << endl;
			break;
		case 4:
			cout << "������ ������� (short int) > ";
			cin >> el;
			dq.pushBack(el);
			dq.show();
			cout << "----------------------------------------------------------" << endl;
			break;

		case 5:
			if (dq.isEmpty())
				cout << "��� ������" << endl;
			else cout << "��� ����������" << endl;
			
			cout << "----------------------------------------------------------" << endl;
			break;

		case 6:
			cout << dq.read6El() << endl;
			cout << "----------------------------------------------------------" << endl;
			break;

		case 7:
			cout << dq.readlast() << endl;
			cout << "----------------------------------------------------------" << endl;
			break;

		case 8:
			dq.saveFile();
			cout << "��� ���������" << endl;
			cout << "----------------------------------------------------------" << endl;
			break;

		case 9:
			cout << "�����..." << endl;
			cout << "----------------------------------------------------------" << endl;
			return 1;
			break;

		default:
			cout << "�� ����� ������� �����" << endl;
			break;
		}



	}
	return 0;
}