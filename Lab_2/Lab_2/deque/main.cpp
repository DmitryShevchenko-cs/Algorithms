#include "deque.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice = -1;
	deque dq;
	short el = 0;
	while (true) {
		cout << "----------------------------------------------------------" << endl;
		cout << "0 - Зчитати з файлу" << endl;
		cout << "1 - Створити дек" << endl; 
		cout << "2 - Вивести список" << endl;  
		cout << "3 - Додати у початок" << endl;
		cout << "4 - Додати в кінець" << endl;  
		cout << "5 - Перевірити на порожнечу" << endl;
		cout << "6 - Прочитати шостий елемент" << endl;
		cout << "7 - Прочитати останній елемент" << endl;
		cout << "8 - Зберігти у файл" << endl;
		cout << "9 - Вихід" << endl;  
		cout << "---------------------------" << endl;

		cin >> choice;

		switch (choice) {

		case 0:
			dq.readFile();
			dq.show();
			cout << "----------------------------------------------------------" << endl;
			break;
		case 1:

			cout << "Введіть елемент (short int) > ";
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
			cout << "Введіть елемент (short int) > ";
			cin >> el;
			dq.pushFront(el);
			dq.show();
			cout << "----------------------------------------------------------" << endl;
			break;
		case 4:
			cout << "Введіть елемент (short int) > ";
			cin >> el;
			dq.pushBack(el);
			dq.show();
			cout << "----------------------------------------------------------" << endl;
			break;

		case 5:
			if (dq.isEmpty())
				cout << "Дек пустий" << endl;
			else cout << "Дек заповнений" << endl;
			
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
			cout << "Дек збережено" << endl;
			cout << "----------------------------------------------------------" << endl;
			break;

		case 9:
			cout << "Вихід..." << endl;
			cout << "----------------------------------------------------------" << endl;
			return 1;
			break;

		default:
			cout << "Ви ввели невірний номер" << endl;
			break;
		}



	}
	return 0;
}