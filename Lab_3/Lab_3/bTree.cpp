#include "bTree.h"

void menu_b() {

	cout << "----------------------------------------------------------" << endl;
	cout << "1 - Створити дерево" << endl;
	cout << "2 - Додати елемент" << endl;
	cout << "3 - Вивести у вигляді дерева" << endl;
	cout << "4 - Вивести середнє значення номерів" << endl;
	cout << "5 - Прямий обхід" << endl;
	cout << "6 - Зворотній обхід" << endl;
	cout << "7 - Симетричний обхід" << endl;
	cout << "8 - Видалити праве піддерево" << endl;
	cout << "9 - Видалити ліве піддерево" << endl;
	cout << "10 - Видалити вузол" << endl;
	cout << "11 - Переписати по новому ключу" << endl;
	cout << "12 - Розфарбувати у червоно-чорне" << endl;
	cout << "13 - Вихід" << endl;
	cout << "---------------------------" << endl;

}

void menu_rb() {
	cout << "----------------------------------------------------------" << endl;
	cout << "1 - Додати елемент" << endl;
	cout << "2 - Видалити вузол" << endl;
	cout << "3 - Вивести у вигляді дерева" << endl;
	cout << "4 - Вихід" << endl;
	cout << "---------------------------" << endl;
}

void bTree::add(string Name, int Year, int Num)
{
	if (!isEmpty()) {
		node* temp = root;
		node* ob = new node;
		ob->name = Name;
		ob->year = Year;
		ob->num = Num;
		while (true) {
			if (Name > temp->name) {
				if (temp->left == NULL) {
					temp->left = ob;
					count++;
					break;
				}
				else
					temp = temp->left;
			}
			else if (Name <= temp->name) {
				if (temp->right == NULL) {
					temp->right = ob;
					count++;
					break;
				}
				else
					temp = temp->right;
			}
		}
	}
	else
	{
		node* temp = new node;
		temp->name = Name;
		temp->year = Year;
		temp->num = Num;
		root = temp;
		root->left = root->right = NULL;
		count++;
	}
}
void bTree::print_Tree(node* temp, int level)
{
	if (temp)
	{
		print_Tree(temp->right, level + 1);

		for (int i = 0; i < level; i++) cout << "\t\t";
		cout << "Назва: " << temp->name << endl;

		for (int i = 0; i < level; i++) cout << "\t\t";
		cout << "Рік: " << temp->year << endl;

		for (int i = 0; i < level; i++) cout << "\t\t";
		cout << "Кіль-сть: " << temp->num << endl;

		print_Tree(temp->left, level + 1);
	}
}

void bTree::avarageNum(node* temp)
{
	if (temp != NULL)
	{
		avarageNum(temp->left);
		avarage += temp->num;
		avarageNum(temp->right);
	}

}
int bTree::getAv()
{
	avarageNum(root);
	return avarage / count;
}

void bTree::preOrder(node* temp)
{
	if (temp != NULL)
	{
		cout << temp->name << ' ';
		preOrder(temp->left);
		preOrder(temp->right);
	}
}
void bTree::postOrder(node* temp)
{
	if (temp != NULL)
	{
		postOrder(temp->left);
		postOrder(temp->right);
		cout << temp->name << ' ';
	}
}
void bTree::symmetricOrder(node* temp)
{
	if (temp != NULL)
	{
		symmetricOrder(temp->left);
		cout << temp->name << ' ';
		symmetricOrder(temp->right);
	}
}

void bTree::delBT(node* temp)
{
	if (temp != NULL)
	{
		delBT(temp->left);
		delBT(temp->right);
		delete temp;
	}
}

void bTree::delL()
{
	delBT(root->left);
	root->left = NULL;
}
void bTree::delR()
{
	delBT(root->right);
	root->right = NULL;
}

void bTree::add4num(string Name, int Year, int Num)
{
	if (!isEmpty()) {
		node* temp = root;
		node* ob = new node;
		ob->name = Name;
		ob->year = Year;
		ob->num = Num;
		while (true) {
			if (Num > temp->num) {
				if (temp->left == NULL) {
					temp->left = ob;
					count++;
					break;
				}
				else
					temp = temp->left;
			}
			else if (Num <= temp->num) {
				if (temp->right == NULL) {
					temp->right = ob;
					count++;
					break;
				}
				else
					temp = temp->right;
			}
		}
	}
	else
	{
	node* temp = new node;
	temp->name = Name;
	temp->year = Year;
	temp->num = Num;
	root = temp;
	root->left = root->right = NULL;
	count++;
	}
}

void bTree::newTree(node* temp, bTree& tr)
{
	if (temp != NULL)
	{
		tr.add4num(temp->name, temp->year, temp->num);
		newTree(temp->left, tr);
		newTree(temp->right, tr);
	}
}

void bTree::RemoveNode(node* parent, node* curr, string Name) {
	if (curr == nullptr) { return; }
	if (curr->name == Name) {
		//CASE -- 1
		if (curr->left == nullptr && curr->right == nullptr) {
			if (parent->name == curr->name) { root = nullptr; }
			else if (parent->right == curr) { parent->right = nullptr; }
			else { parent->left = nullptr; }
		}
		//CASE -- 2
		else if (curr->left != nullptr && curr->right == nullptr) {
			auto n = curr->name;
			auto ye = curr->year;
			auto nu = curr->num;

			curr->name = curr->left->name;
			curr->year = curr->left->year;
			curr->num = curr->left->num;

			curr->left->name = n;
			curr->left->year = ye;
			curr->left->num = nu;
			RemoveNode(curr, curr->left, Name);
		}
		else if (curr->left == nullptr && curr->right != nullptr) {
			auto n = curr->name;
			auto ye = curr->year;
			auto nu = curr->num;
			curr->name = curr->right->name;
			curr->year = curr->right->year;
			curr->num = curr->right->num;
			curr->right->name = n;
			curr->right->year = ye;
			curr->right->num = nu;
			RemoveNode(curr, curr->right, Name);
		}
		//CASE -- 3
		else {
			bool flag = false;
			node* temp = curr->right;
			while (temp->left) { flag = true; parent = temp; temp = temp->left; }
			if (!flag) { parent = curr; }
			auto n = curr->name;
			auto ye = curr->year;
			auto nu = curr->num;
			curr->name = temp->name;
			curr->year = temp->year;
			curr->num = temp->num;
			temp->name = n;
			temp->year = ye;
			temp->num = nu;
			RemoveNode(parent, temp, Name);
		}
	}
}
void bTree::Remove(string Name) {
	node* temp = root;
	node* parent = temp;
	bool flag = false;
	if (temp == nullptr) { RemoveNode(nullptr, nullptr, Name); }

	while (temp) {
		if (Name == temp->name) {
			flag = true;
			RemoveNode(parent, temp, Name);
			break;
		}
		else if (Name < temp->name) {
			parent = temp;
			temp = temp->right;
		}
		else {
			parent = temp;
			temp = temp->left;
		}
	}

	if (!flag) { cout << "\nElement doesn't exist in the table"; }
}
void bTree::delete_tree(node* temp) {
	if (temp != NULL)
	{
		delete_tree(temp->left);
		delete_tree(temp->right);
		delete(temp);
		if (temp->left != NULL)
			temp->left = NULL;
		if (temp->right != NULL)
			temp->right = NULL;
		root = NULL;
	}
}

void bTree::RB(node* temp, rbTree& rb)
{

	if (temp != NULL)
	{
		rb.addRB(temp->name, temp->year, temp->num);
		RB(temp->left, rb);
		RB(temp->right, rb);
	}

}

void rbTree::RB_Insert_Fixup(node* z)
{
	while (z->parent->color == "RED") {
		node* grandparent = z->parent->parent;
		node* uncle = root;
		if (z->parent == grandparent->left) {
			if (grandparent->right) { uncle = grandparent->right; }
			if (uncle->color == "RED") {
				z->parent->color = "BLACK";
				uncle->color = "BLACK";
				grandparent->color = "RED";
				if (grandparent->num != root->num) { z = grandparent; }
				else { break; }
			}
			else if (z == grandparent->left->right) {
				LeftRotate(z->parent);
			}
			else {
				z->parent->color = "BLACK";
				grandparent->color = "RED";
				RightRotate(grandparent);
				if (grandparent->num != root->num) { z = grandparent; }
				else { break; }
			}
		}
		else {
			if (grandparent->left) { uncle = grandparent->left; }
			if (uncle->color == "RED") {
				z->parent->color = "BLACK";
				uncle->color = "BLACK";
				grandparent->color = "RED";
				if (grandparent->num != root->num) { z = grandparent; }
				else { break; }
			}
			else if (z == grandparent->right->left) {
				RightRotate(z->parent);
			}
			else {
				z->parent->color = "BLACK";
				grandparent->color = "RED";
				LeftRotate(grandparent);
				if (grandparent->num != root->num) { z = grandparent; }
				else { break; }
			}
		}
	}
	root->color = "BLACK";
}
void rbTree::LeftRotate(node* x) {
	node* nw_node = new node();
	if (x->right->left) { nw_node->right = x->right->left; }
	nw_node->left = x->left;
	nw_node->name = x->name;
	nw_node->year = x->year;
	nw_node->num = x->num;
	nw_node->color = x->color;

	x->name = x->right->name;
	x->year = x->right->year;
	x->num = x->right->num;

	x->left = nw_node;
	if (nw_node->left) { nw_node->left->parent = nw_node; }
	if (nw_node->right) { nw_node->right->parent = nw_node; }
	nw_node->parent = x;

	if (x->right->right) { x->right = x->right->right; }
	else { x->right = nullptr; }

	if (x->right) { x->right->parent = x; }
}
void rbTree::RightRotate(node* x) {
	node* nw_node = new node();
	if (x->left->right) { nw_node->left = x->left->right; }
	nw_node->right = x->right;
	nw_node->name = x->name;
	nw_node->year = x->year;
	nw_node->num = x->num;
	nw_node->color = x->color;

	x->name = x->left->name;
	x->year = x->left->year;
	x->num = x->left->num;
	x->color = x->left->color;

	x->right = nw_node;
	if (nw_node->left) { nw_node->left->parent = nw_node; }
	if (nw_node->right) { nw_node->right->parent = nw_node; }
	nw_node->parent = x;

	if (x->left->left) { x->left = x->left->left; }
	else { x->left = nullptr; }

	if (x->left) { x->left->parent = x; }
}
void rbTree::addRB(string Name, int Year, int Num)
{
	if (!isEmpty()) {
		node* temp = root;
		node* newnode = new node;
		newnode->name = Name;
		newnode->year = Year;
		newnode->num = Num;

		while (true) {
			if (Num > temp->num) {
				if (temp->left == NULL) {
					temp->left = newnode;
					newnode->color = "RED";
					newnode->parent = temp;
					break;
				}
				else
					temp = temp->left;
			}
			else if (Num <= temp->num) {
				if (temp->right == NULL) {
					temp->right = newnode;
					newnode->color = "RED";
					newnode->parent = temp;
					break;
				}
				else
					temp = temp->right;
			}
		}
		RB_Insert_Fixup(newnode);
	}
	else
	{
		root = new node();
		root->name = Name;
		root->year = Year;
		root->num = Num;
		root->parent = nullptr;
		root->color = "BLACK";
	}
}
void rbTree::RemoveNodeRB(node* parent, node* curr, int Num) {
	if (curr == nullptr) { return; }
	if (curr->num == Num) {
		//CASE -- 1
		if (curr->left == nullptr && curr->right == nullptr) {
			if (parent->num == curr->num) { root = nullptr; }
			else if (parent->right == curr) {
				RB_Delete_Fixup(curr);
				parent->right = nullptr;
			}
			else {
				RB_Delete_Fixup(curr);
				parent->left = nullptr;
			}
		}
		//CASE -- 2
		else if (curr->left != nullptr && curr->right == nullptr) {
			auto n = curr->name;
			auto ye = curr->year;
			auto nu = curr->num;
			curr->name = curr->left->name;
			curr->year = curr->left->year;
			curr->num = curr->left->num;
			curr->left->name = n;
			curr->left->year = ye;
			curr->left->num = nu;
			RemoveNodeRB(curr, curr->left, Num);
		}
		else if (curr->left == nullptr && curr->right != nullptr) {
			auto n = curr->name;
			auto ye = curr->year;
			auto nu = curr->num;
			curr->name = curr->right->name;
			curr->year = curr->right->year;
			curr->num = curr->right->num;
			curr->right->name = n;
			curr->right->year = ye;
			curr->right->num = nu;
			RemoveNodeRB(curr, curr->right, Num);
		}
		//CASE -- 3
		else {
			bool flag = false;
			node* temp = curr->right;
			while (temp->left) { flag = true; parent = temp; temp = temp->left; }
			if (!flag) { parent = curr; }
			auto n = curr->name;
			auto ye = curr->year;
			auto nu = curr->num;
			curr->name = temp->name;
			curr->year = temp->year;
			curr->num = temp->num;
			temp->name = n;
			temp->year = ye;
			temp->num = nu;
			RemoveNodeRB(parent, temp, nu);
		}
	}
}

void rbTree::RB_Delete_Fixup(node* z) {
	while (z->name != root->name && z->color == "BLACK") {
		auto sibling = root;
		if (z->parent->left == z) {
			if (z->parent->right) { sibling = z->parent->right; }
			if (sibling) {
				//CASE -- 1
				if (sibling->color == "RED") {
					sibling->color = "BLACK";
					z->parent->color = "RED";
					LeftRotate(z->parent);
					sibling = z->parent->right;
				}
				//CASE -- 2
				if (sibling->left == nullptr && sibling->right == nullptr) {
					sibling->color = "RED";
					z = z->parent;
				}
				else if (sibling->left->color == "BLACK" && sibling->right->color == "BLACK") {
					sibling->color = "RED";
					z = z->parent;
				}
				//CASE -- 3
				else if (sibling->right->color == "BLACK") {
					sibling->left->color = "BLACK";
					sibling->color = "RED";
					RightRotate(sibling);
					sibling = z->parent->right;
				}
				else {
					sibling->color = z->parent->color;
					z->parent->color = "BLACK";
					if (sibling->right) { sibling->right->color = "BLACK"; }
					LeftRotate(z->parent);
					z = root;
				}
			}
		}
		else {
			if (z->parent->right == z) {
				if (z->parent->left) { sibling = z->parent->left; }
				if (sibling) {
					//CASE -- 1
					if (sibling->color == "RED") {
						sibling->color = "BLACK";
						z->parent->color = "RED";
						RightRotate(z->parent);
						sibling = z->parent->left;
					}
					//CASE -- 2
					if (sibling->left == nullptr && sibling->right == nullptr) {
						sibling->color = "RED";
						z = z->parent;
					}
					else if (sibling->left->color == "BLACK" && sibling->right->color == "BLACK") {
						sibling->color = "RED";
						z = z->parent;
					}
					//CASE -- 3 
					else if (sibling->left->color == "BLACK") {
						sibling->right->color = "BLACK";
						sibling->color = "RED";
						RightRotate(sibling);
						sibling = z->parent->left;
					}
					else {
						sibling->color = z->parent->color;
						z->parent->color = "BLACK";
						if (sibling->left) { sibling->left->color = "BLACK"; }
						LeftRotate(z->parent);
						z = root;
					}
				}
			}

		}
	}
	z->color = "BLACK";
}

void rbTree::RemoveRBNode(int Num) {
	auto temp = root;
	auto parent = temp;
	bool flag = false;
	if (!temp) { RemoveNodeRB(nullptr, nullptr, Num); }

	while (temp) {
		if (Num == temp->num) { flag = true; RemoveNodeRB(parent, temp, Num); break; }
		else if (Num < temp->num) { parent = temp; temp = temp->right; }
		else { parent = temp; temp = temp->left; }
	}

	if (!flag) { cout << "\nElement doesn't exist in the table"; }
}

void rbTree::print_RBTree(node* temp, int level)
{
	if (temp)
	{
		print_RBTree(temp->right, level + 1);

		for (int i = 0; i < level; i++) cout << "\t\t";
		cout << "Колір: " << temp->color << endl;

		for (int i = 0; i < level; i++) cout << "\t\t";
		cout << "Назва: " << temp->name << endl;

		for (int i = 0; i < level; i++) cout << "\t\t";
		cout << "Рік: " << temp->year << endl;

		for (int i = 0; i < level; i++) cout << "\t\t";
		cout << "Кіль-сть: " << temp->num << endl;

		print_RBTree(temp->left, level + 1);
	}
}
