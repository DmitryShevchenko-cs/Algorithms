#include "tree.h"

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	bTree tr;

	tr.create("50", 2012, 200);
	tr.add("30", 2014, 300);
	tr.add("55", 2014, 300);

	tr.add("27", 2014, 300);
	tr.add("51", 2014, 300);

	tr.add("37", 2014, 300);
	tr.add("56", 2014, 300);
	tr.add("40", 2014, 300);
	
	cout << tr.getAv() << endl;
	cout << "------------------------------------" << endl;
	tr.preOrder(tr.getRoot());
	cout << "------------------------------------" << endl;
	tr.postOrder(tr.getRoot());
	cout << "------------------------------------" << endl;
	tr.symmetricOrder(tr.getRoot());
	cout << "------------------------------------" << endl;

	tr.print_Tree(tr.getRoot());

}