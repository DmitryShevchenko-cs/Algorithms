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
		cout << "Оберіти дію" << endl;
		cout << "1 - Сформувати список" << endl;
		cout << "2 - Додати елемент до писку (в кінець)" << endl;
		cout << "3 - Вилучити вказаний елемент зі списку" << endl;
		cout << "4 - Визначити кількість елементів у списку" << endl;
		cout << "5 - Поміняти два сусідні елемента місцями" << endl;
		cout << "6 - Об'еднати два списки в один" << endl;
		cout << "7 - Очистити список" << endl;
		cout << "8 - Вихід" << endl;
		cout << "-----------------------------------------------------\n";

		cin >> choice;

		switch (choice) {
		case 1:
			lst.create(2);
			lst.show();
			break;

		case 2:
			cout << "Введите символ > ";
			cin >> ch;
			lst.Add(ch);
			lst.show();
			break;
		
		case 3:
			lst.show();
			cout << "Введите номер удаляемого символа > ";
			
			cin >> choice;
			if(choice <= lst.number() && choice > 0)
				lst.del(choice);
			else cout << "Вы ввели неверный номер, попробуйте еще раз > \n";
			lst.show();
			break;

		case 4:
			cout << lst.number() << endl;
			break;

		case 5:

			cout << "Введите номер удаляемого символа > ";
			cin >> choice;
			if (choice < lst.number() && choice > 0) {
				lst.swap(choice);
				lst.show();
			}
			else cout << "Вы ввели неверный номер, попробуйте еще раз > \n";
			
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
			cout << "Вихід ..." << endl;
			return 1;
		
		default:
			cout << "Вы ввели неверный номер, попробуйте еще раз" << endl << endl;

		}

	}

}