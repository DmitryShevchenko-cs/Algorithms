#include "stack.h"

int main() {
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	stack st;
	int choice = -1;
	short el = 0;
	
	while (true) {
		cout << "----------------------------------------------------------" << endl;
		cout << "1 - ������ �������" << endl; // + st.push(1);
		cout << "2 - ������� ������" << endl; //+ st.show();
		cout << "3 - ������� ������ ������ � ������� �������� �����" << endl; //+ st.swapTopTail()
		cout << "4 - ���������� ����" << endl; // + st.reverse();
		cout << "5 - �������� ����� ������ ������� �����" << endl; //+ st.delEvery2();
		cout << "6 - �������� ������ '*' � �������� �����" << endl;
		cout << "7 - ������ ������������ ������� � �������� ���� ����� 0" << endl; // st.maxZero();
		cout << "8 - �������� ��������� �������" << endl; //+ st.delMin();
		cout << "9 - �������� �� ��������, ��� �������" << endl; //+ st.delTail();
		cout << "10 - ���������� ��������, ��� ����������" << endl; //+ st.delHead();
		cout << "11 - �����" << endl;// + ~  
		cout << "---------------------------" <<endl;
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "������ ������� (short int) > ";
			cin >> el;
			st.push(el);
			st.show();
			cout << "----------------------------------------------------------" << endl;
			break;
		case 2:
			st.show();
			cout << "----------------------------------------------------------" << endl;
			break;
		case 3:
			st.swapTopTail();
			st.show();
			cout << "----------------------------------------------------------" << endl;
			break; 
		case 4:
			st.reverse();
			st.show();
			cout << "----------------------------------------------------------" << endl;
			break; 
		case 5:
			st.delEvery2();
			st.show();
			cout << "----------------------------------------------------------" << endl;
			break;
		case 6:
			
			st.putStar();
			cout << "----------------------------------------------------------" << endl;
			break;
		case 7:
			st.maxZero();
			st.show();
			cout << "----------------------------------------------------------" << endl;
			break;
		case 8:
			st.delMin();
			st.show();
			cout << "----------------------------------------------------------" << endl;
			break;
		case 9:
			st.delTail();
			st.show();
			cout << "----------------------------------------------------------" << endl;
			break;
		case 10:
			st.delHead();
			st.show();
			cout << "----------------------------------------------------------" << endl;
			break;
		case 11:
			cout << "³���" << endl;
			return 1;
			break;

		default:
			cout << "�� ����� ������� �����" << endl;
			break;

		}
	}
}