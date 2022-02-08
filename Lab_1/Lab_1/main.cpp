#include "list.h"

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	list lst;
	short choice = -1;

	while (true) {
		
		cout << "Оберіти дію" << endl;
		cout << "1 - Сформувати список" << endl;
		cout << "2 - Додати елемент до писку (в кінець)" << endl;
		cout << "3 - Вилучити вказаний елемент зі списку" << endl;
		cout << "4 - Визначити кількість елементів у списку" << endl;
		cout << "5 - Поміняти два сусідні елемента місцями" << endl;
		cout << "6 - Об'еднати два списки в один" << endl;
		cout << "7 - Очистити список" << endl;
		cout << "8 - Вихід" << endl;
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

			break;

		case 4:

			break;

		case 5:

			break;

		case 6:

			break;

		case 7:

			break;

		case 8:
			lst.show();
			cout << "Вихід ..." << endl;
			return 1;


		}

	}

}