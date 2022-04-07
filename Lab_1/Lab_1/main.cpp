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
		cout << "0 - лінійний, 1 - кільцевий" << endl;
		cout << "----------------------\n";
		cin >> choiceList;
		if (choiceList > 1 || choiceList < 0) {
			cout << "Ви ввели невірне значення, спробуйте ще раз" << endl;
			cout << "-----------------------------------------------------\n";
		}
		else
			break;
	}
	cout << "-----------------------------------------------------\n";

	while (true) {
		cout << "Сформувати список" << endl;
		cout << "1 - Введення власноруч" << endl;
		cout << "2 - Зчитування з файлу" << endl;
		cout << "Оберіть спосіб формування списку> ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Кількість елементів > ";
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
				cout << "Помилка вводу..." << endl;
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
			cout << "Ви ввели невірний номер, спробуйте ще раз" << endl;
			cout << "-----------------------------------------------------\n\n";
		}

		break;

	}
	
	while (true) {
		cout << "-----------------------------------------------------\n";
		cout << "Оберіти дію" << endl;
		cout << "1 - Показати список" << endl;
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
		case 1: 
			if (!choiceList)
				lst.show();
			else
				cLst.show();
			cout << "-----------------------------------------------------\n\n";
			break;
			
		case 2:
			cout << "Введіть символ > ";
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
				cout << "Введіть номер символу для видалення > ";
				cin >> choice;
				if (choice <= lst.number() && choice > 0) {
					lst.del(choice);
					lst.show();
				}
				else cout << "Ви ввели невірний номер, спробуйте ще раз > \n";
			}
			else {
				cLst.show();
				cout << "Введіть символ для видалення > ";
				cin >> ch;
				if (cLst.isChar(ch)) {
					cLst.del(ch);
					cLst.show();
				}
				else cout << "Ви ввели невірний номер, спробуйте ще раз > \n";
				
			}
			cout << "-----------------------------------------------------\n\n";
			break;

		case 4:
			if (!choiceList) {
				cout << "Кількість символів у списку: " << lst.number() << endl;
			}
			else {
				cout << "Кількість символів у списку: " << cLst.number() << endl;

			}
			break;

		case 5:
			if (!choiceList) {
				lst.show();
				cout << "Введіть номер символу, щоб замінити його з наступним > ";
				cin >> choice;
				if (choice < lst.number() && choice > 0) {
					lst.swap(choice);
					lst.show();
				}
				else
					cout << "Помилка вводу..." << endl;
			}
			else {
				cLst.show();
				cout << "Введіть символ, щоб замінити його з наступним > ";
				cin >> ch;
				if (cLst.isChar(ch)) {
					cLst.swap(ch);
					cLst.show();
				}
				else
					cout << "Помилка вводу..." << endl;

			}
			
			cout << "-----------------------------------------------------\n\n";
			break;

		case 6:
			cout << "Кількість елементів > ";
			cin >> choice;
			if (!choiceList) {
				if (choice >= 0) {
					LST.create(choice);
					lst.merge(LST);
					lst.show();
				}
				else
					cout << "Помилка вводу..." << endl;
			}
			else {
				if (choice >= 0) {
					cLST.create(choice);
					cLst.merge(cLST);
					cLst.show();
				}
				else
					cout << "Помилка вводу..." << endl;
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
			cout << "Список збережено" << endl;
			cout << "-----------------------------------------------------\n\n";
			break;

		case 8:
			if (!choiceList) {
				lst.~list();
			}
			else {
				cLst.~circularList();
			}
			cout << "Список видалено..." << endl;
			cout << "-----------------------------------------------------\n\n";
			break;

		case 9:
			cout << "Вихід ..." << endl;
			cout << "-----------------------------------------------------\n\n";
			
			exit(1);

		default:
			cout << "Ви ввели невірний номер, спробуйте ще раз" << endl;
			cout << "-----------------------------------------------------\n\n";

		}

	}

}