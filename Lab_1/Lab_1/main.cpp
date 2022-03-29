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
		cout << "0 - Показати список" << endl;
		cout << "1 - Сформувати список" << endl;
		cout << "2 - Додати елемент до писку (в кінець)" << endl;
		cout << "3 - Вилучити вказаний елемент зі списку" << endl;
		cout << "4 - Визначити кількість елементів у списку" << endl;
		cout << "5 - Поміняти два сусідні елемента місцями" << endl;
		cout << "6 - Об'еднати два списки в один" << endl;
		cout << "7 - Зберегти список" << endl;
		cout << "8 - Очистити список" << endl;
		cout << "9 - Вихід" << endl;
		cout << "----------------------\n";

		cin >> choice;

		switch (choice) {
		case 0: 
			lst.show();
			cout << "-----------------------------------------------------\n\n";
			break;

		case 1:
			cout << "1 - Введення власноруч" << endl;
			cout << "2 - Зчитування з файлу" << endl;
			cout << "Оберіть спосіб формування списку> ";
			cin >> choice;
			switch (choice) {
			case 1:
				cout << "Кількість елементів > ";
				cin >> choice;
				if (choice >= 0) {
					lst.create(choice);
					lst.show();
				}
				else
					cout << "Помилка вводу..." << endl;
				cout << "-----------------------------------------------------\n\n";
				break;

			case 2:
				lst.createFromFile("List.txt");
				lst.show();
				cout << "-----------------------------------------------------\n\n";
				break;
			default:
				cout << "Ви ввели невірний номер, спробуйте ще раз" << endl;
				cout << "-----------------------------------------------------\n\n";
			}
			break;
		case 2:
			cout << "Введіть символ > ";
			cin >> ch;
			lst.Add(ch);
			lst.show();
			cout << "-----------------------------------------------------\n\n";
			break;
		
		case 3:
			lst.show();
			cout << "Введіть номер символу для видалення > ";
			
			cin >> choice;
			if(choice <= lst.number() && choice > 0)
				lst.del(choice);
			else cout << "Ви ввели невірний номер, спробуйте ще раз > \n";
			lst.show();
			cout << "-----------------------------------------------------\n\n";
			break;

		case 4:
			cout << "Кількість символів у списку: " << lst.number() << endl;
			break;

		case 5:
			cout << "Список: ";
			lst.show();
			cout << "Введіть номер символу, щоб замінити його з наступним > ";
			cin >> choice;
			if (choice < lst.number() && choice > 0) {
				lst.swap(choice);
				lst.show();
			}
			else
				cout << "Помилка вводу..." << endl;
			cout << "-----------------------------------------------------\n\n";
			break;

		case 6:
			cout << "Кількість елементів > ";
			cin >> choice;
			if (choice >= 0) {
				LST.create(choice);
				lst.merge(LST);
				lst.show();
			}
			else
				cout << "Помилка вводу..." << endl;
			cout << "-----------------------------------------------------\n\n";
			break;

		case 7:
			lst.save();
			cout << "Список збережено" << endl;
			cout << "-----------------------------------------------------\n\n";
			break;

		case 8:
			lst.~list();
			cout << "Список видалено..." << endl;
			cout << "-----------------------------------------------------\n\n";
			break;

		case 9:
			lst.show();
			cout << "Вихід ..." << endl;
			cout << "-----------------------------------------------------\n\n";
			return 1;
		
		default:
			cout << "Ви ввели невірний номер, спробуйте ще раз" << endl;
			cout << "-----------------------------------------------------\n\n";

		}

	}

}