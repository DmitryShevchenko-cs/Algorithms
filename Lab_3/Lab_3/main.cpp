#include "bTree.h"

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	bTree tr, tr2;
	rbTree rb;
	string name;
	int year, num;

	int choice = -1;

	while (choice != 12) {
		menu_b();

		cin >> choice;
		switch (choice) {
		case 0:
			tr.delete_tree(tr.getRoot());
			break;

		case 1:
			cout << "¬вед≥ть назву, р≥к так к≥льк≥сть номер≥в журналу> ";
			cin >> name >> year >> num;
			tr.add(name, year, num);
			cout << "---------------------------" << endl;
			tr.print_Tree(tr.getRoot());
			cout << "----------------------------------------------------------" << endl;
			break;

		case 2:
			cout << "¬вед≥ть назву, р≥к так к≥льк≥сть номер≥в журналу> ";
			cin >> name >> year >> num;
			tr.add(name, year, num);
			cout << "---------------------------" << endl;
			tr.print_Tree(tr.getRoot());
			cout << "----------------------------------------------------------" << endl;
			break;

		case 3:
			cout << "---------------------------" << endl;
			tr.print_Tree(tr.getRoot());
			cout << "----------------------------------------------------------" << endl;
			break;

		case 4:
			cout << "—ереднЇ значенн€ номер≥в: " << tr.getAv() << endl;
			cout << "---------------------------" << endl;
			tr.print_Tree(tr.getRoot());
			cout << "----------------------------------------------------------" << endl;
			break;

		case 5:
			cout << "ѕр€мий обх≥д" << endl;
			tr.preOrder(tr.getRoot());
			cout << "\n---------------------------" << endl;
			tr.print_Tree(tr.getRoot());
			cout << "----------------------------------------------------------" << endl;
			break;
		case 6:
			cout << "«воротн≥й обх≥д" << endl;
			tr.postOrder(tr.getRoot());
			cout << "\n---------------------------" << endl;
			tr.print_Tree(tr.getRoot());
			cout << "----------------------------------------------------------" << endl;
			break;
		case 7:
			cout << "—иметричний обх≥д" << endl;
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
			cout << "¬вед≥ть назву: ";
			cin >> name;
			tr.Remove(name);
			cout << "---------------------------" << endl;
			tr.print_Tree(tr.getRoot());
			cout << "----------------------------------------------------------" << endl;
			break;

		case 11:
			tr.newTree(tr.getRoot(), tr2);
			tr.delete_tree(tr.getRoot());
			tr2.newTree(tr2.getRoot(), tr);
			tr2.delete_tree(tr2.getRoot());

			cout << "---------------------------" << endl;
			tr.print_Tree(tr.getRoot());
			cout << "----------------------------------------------------------" << endl;
			break;

		case 12:
			tr.RB(tr.getRoot(), rb);
			tr.delete_tree(tr.getRoot());

			cout << "---------------------------" << endl;
			rb.print_RBTree(rb.getRoot());
			cout << "----------------------------------------------------------" << endl;
			break;
		case 13:
			tr.delete_tree(tr.getRoot());
			return 1;
		default:
			cout << "¬ведено нев≥рний номер" << endl;
			cout << "----------------------------------------------------------" << endl;
			break;
		}
	}

	while (true) {
		menu_rb();

		cin >> choice;
		switch (choice) {
		case 1:
			cout << "¬вед≥ть назву, р≥к так к≥льк≥сть номер≥в журналу> ";
			cin >> name >> year >> num;
			rb.addRB(name, year, num);
			cout << "---------------------------" << endl;
			rb.print_RBTree(rb.getRoot());
			cout << "----------------------------------------------------------" << endl;
			break;
		case 2:
			cout << "¬вед≥ть к≥льк≥сть номер≥в: " << endl;
			cin >> num;
			rb.RemoveRBNode(num);
			break;
			cout << "---------------------------" << endl;
			rb.print_RBTree(rb.getRoot());
			cout << "----------------------------------------------------------" << endl;
			break;
		case 3:
			cout << "---------------------------" << endl;
			rb.print_RBTree(rb.getRoot());
			cout << "----------------------------------------------------------" << endl;
			break;
		case 4:
			save(rb.getRoot());
			break;
		case 5:
			cout << "¬их≥д..."<<endl;
			exit(1);
			break;
		default:
			cout << "¬ведено нев≥рний номер" << endl;
			cout << "----------------------------------------------------------" << endl;
			break;
		}

	}
}