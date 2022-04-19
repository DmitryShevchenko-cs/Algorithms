#include "stack.h"

int main() {
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	stack st;
	int choice = -1;
	short el = 0;
	
	while (true) {
		cout << "----------------------------------------------------------" << endl;
		cout << "1 - Додати елемент" << endl; // + st.push(1);
		cout << "2 - Вивести список" << endl; //+ st.show();
		cout << "3 - Поміняти місцями перший і останній елементи стека" << endl; //+ st.swapTopTail()
		cout << "4 - Розгорнути стек" << endl; // + st.reverse();
		cout << "5 - Видалити кожен другий елемент стека" << endl; //+ st.delEvery2();
		cout << "6 - Вставити символ '*' в середину стека" << endl;
		cout << "7 - Знайти максимальний елемент і вставити після нього 0" << endl; // st.maxZero();
		cout << "8 - Видалити мінімальний елемент" << endl; //+ st.delMin();
		cout << "9 - Видалити всі елементи, крім першого" << endl; //+ st.delTail();
		cout << "10 - Видалитивсі елементи, крім останнього" << endl; //+ st.delHead();
		cout << "11 - Вихід" << endl;// + ~  
		cout << "---------------------------" <<endl;
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Введіть елемент (short int) > ";
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
			cout << "Віхід" << endl;
			return 1;
			break;

		default:
			cout << "Ви ввели невірний номер" << endl;
			break;

		}
	}
}