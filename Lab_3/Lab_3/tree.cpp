#include "tree.h"

void bTree::create(string Name, int Year, int Num)
{
	if (isEmpty()) {
		obj* temp = new obj;
		temp->name = Name;
		temp->year = Year;
		temp->num = Num;
		temp->color = "BLACK";
		root = temp;
		root->left = root->right = NULL;
		count++;
	}
	else
		add(Name, Year, Num);
}

void bTree::add(string Name, int Year, int Num)
{
	if (!isEmpty()) {
		obj* temp = root;
		obj* ob = new obj;
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
		create(Name, Year, Num);
}

void bTree::add4num(string Name, int Year, int Num)
{
	if (!isEmpty()) {
		obj* temp = root;
		obj* ob = new obj;
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
			else {
				cout << "Такий елемент вже існує" << endl;
				return;
			}
		}
	}
	else
		create(Name, Year, Num);
}

void bTree::print_Tree(obj* temp, int level)
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


void bTree::avarageNum(obj* temp)
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


void bTree::preOrder(obj* temp)
{
	if (temp != NULL)
	{
		cout << temp->name << ' ';
		preOrder(temp->left);
		preOrder(temp->right);
	}
}

void bTree::postOrder(obj* temp)
{
	if (temp != NULL)
	{
		postOrder(temp->left);
		postOrder(temp->right);
		cout << temp->name << ' ';
	}
}

void bTree::symmetricOrder(obj* temp)
{
	if (temp != NULL)
	{
		symmetricOrder(temp->left);
		cout << temp->name << ' ';
		symmetricOrder(temp->right);
	}
}


void bTree::delBT(obj* temp)
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

void bTree::RemoveNode(obj* parent, obj* curr, string Name) {
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
			auto swap = curr->name;
			curr->name = curr->left->name;
			curr->left->name = swap;
			RemoveNode(curr, curr->right, Name);
		}
		else if (curr->left == nullptr && curr->right != nullptr) {
			auto swap = curr->name;
			curr->name = curr->right->name;
			curr->right->name = swap;
			RemoveNode(curr, curr->right, Name);
		}
		//CASE -- 3
		else {
			bool flag = false;
			obj* temp = curr->right;
			while (temp->left) { flag = true; parent = temp; temp = temp->left; }
			if (!flag) { parent = curr; }
			auto swap = curr->name;
			curr->name = temp->name;
			temp->name = swap;
			RemoveNode(parent, temp, swap);
		}
	}
}

void bTree::Remove(string Name) {
	obj* temp = root;
	obj* parent = temp;
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
void bTree::RemoveNode(obj* parent, obj* curr, int Num)
{
	if (curr == nullptr) { return; }
	if (curr->num == Num) {
		//CASE -- 1
		if (curr->left == nullptr && curr->right == nullptr) {
			if (parent->num == curr->num) { root = nullptr; }
			else if (parent->right == curr) { parent->right = nullptr; }
			else { parent->left = nullptr; }
		}
		//CASE -- 2
		else if (curr->left != nullptr && curr->right == nullptr) {
			auto swap = curr->num;
			curr->num = curr->left->num;
			curr->left->num = swap;
			RemoveNode(curr, curr->right, Num);
		}
		else if (curr->left == nullptr && curr->right != nullptr) {
			auto swap = curr->num;
			curr->num = curr->right->num;
			curr->right->num = swap;
			RemoveNode(curr, curr->right, Num);
		}
		//CASE -- 3
		else {
			bool flag = false;
			obj* temp = curr->right;
			while (temp->left) { flag = true; parent = temp; temp = temp->left; }
			if (!flag) { parent = curr; }
			auto swap = curr->num;
			curr->num = temp->num;
			temp->num = swap;
			RemoveNode(parent, temp, swap);
		}
	}
}
void bTree::Remove(int Num)
{
	obj* temp = root;
	obj* parent = temp;
	bool flag = false;
	if (temp == nullptr) { RemoveNode(nullptr, nullptr, Num); }

	while (temp) {
		if (Num == temp->num) {
			flag = true;
			RemoveNode(parent, temp, Num);
			break;
		}
		else if (Num < temp->num) {
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



void bTree::newTree(obj* temp, bTree& tr)
{
	if (temp != NULL)
	{

		tr.add4num(temp->name, temp->year, temp->num);
		newTree(temp->left, tr);
		newTree(temp->right, tr);
	}
}

void bTree::paint(obj* temp)
{
	
}


bool bTree::isEmpty()
{
	if (root != NULL)
		return false;
	else return true;
}

