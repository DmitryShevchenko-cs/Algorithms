#include "tree.h"

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	bTree tr, trRB;
	int choice = -1;
	string name;
	int year, num;
	string st;
	while (true) {
		cout << "----------------------------------------------------------" << endl;
		cout << "1 - Створити дерево" << endl; 
		cout << "2 - Додати елемент" << endl; 
		cout << "3 - Вивести у вигляді дерева" << endl; 
		cout << "4 - Вивести середнє значення номерів" << endl; 
		cout << "5 - Прямий обхід" << endl; 
		cout << "6 - Зворотній Обхід" << endl; 
		cout << "7 - Симетричний обхід" << endl; 
		cout << "8 - Видалити праве піддерево" << endl; 
		cout << "9 - Видалити ліве піддерево" << endl; 
		cout << "10 - Видалити вузол" << endl; 
		cout << "11 - Переписати по новому ключу" << endl; 

		cout << "12 - Розфарбувати у червоно-чорне" << endl; 
		cout << "13 - " << endl; 
		cout << "---------------------------" << endl;

		cin >> choice;

		switch (choice) {
		case 1: 
			cout << "Введіть назву, рік так кількість номерів журналу> ";
			cin >> name >> year >> num;
			tr.create(name, year, num);
			cout << "---------------------------" << endl;
			tr.print_Tree(tr.getRoot());
			cout << "----------------------------------------------------------" << endl;
			break;
		case 2:
			cout << "Введіть назву, рік так кількість номерів журналу> ";
			cin >> name >> year >> num;
			tr.add(name, year, num);
			cout << "---------------------------" << endl;
			tr.print_Tree(tr.getRoot());
			break;
			cout << "----------------------------------------------------------" << endl;
		case 3:
			cout << "---------------------------" << endl;
			tr.print_Tree(tr.getRoot());
			cout << "----------------------------------------------------------" << endl;
			break;
		case 4:
			cout << "Середнє значенняномерів: " << tr.getAv() << endl;
			cout << "---------------------------" << endl;
			tr.print_Tree(tr.getRoot());
			cout << "----------------------------------------------------------" << endl;
			break;
		case 5:
			tr.preOrder(tr.getRoot());
			cout << "\n---------------------------" << endl;
			tr.print_Tree(tr.getRoot());
			cout << "----------------------------------------------------------" << endl;
			break;
		case 6:
			tr.postOrder(tr.getRoot());
			cout << "\n---------------------------" << endl;
			tr.print_Tree(tr.getRoot());
			cout << "----------------------------------------------------------" << endl;
			break;
		case 7:
			tr.symmetricOrder(tr.getRoot());
			cout << "\n---------------------------" << endl;
			tr.print_Tree(tr.getRoot());
			cout << "----------------------------------------------------------" << endl;
			break;
		case 8:
			tr.delR();
			cout << "---------------------------" << endl;
			tr.print_Tree(tr.getRoot());
			cout << "----------------------------------------------------------" << endl;
			break;
		case 9:
			tr.delL();
			cout << "---------------------------" << endl;
			tr.print_Tree(tr.getRoot());
			cout << "----------------------------------------------------------" << endl;
			break;

		case 10:
			cout << "Введіть назву: ";
			cin >> st;
			tr.Remove(st);
			cout << "---------------------------" << endl;
			tr.print_Tree(tr.getRoot());
			cout << "----------------------------------------------------------" << endl;
			break;

		case 11:
			tr.newTree(tr.getRoot(), trRB);
			tr.delBT(tr.getRoot());
			tr = trRB;
			cout << "---------------------------" << endl;
			tr.print_Tree(tr.getRoot());
			cout << "----------------------------------------------------------" << endl;
			break;

		default:
			cout << "Введено невірний номер" << endl;
			cout << "----------------------------------------------------------" << endl;
			break;

		}




	}
}