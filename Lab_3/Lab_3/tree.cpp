#include "tree.h"

void bTree::create(string Name, int Year, int Num)
{
	if (isEmpty()) {
		obj* temp = new obj;
		temp->name = Name;
		temp->year = Year;
		temp->num = Num;
		root = temp;
		root->l = root->r = NULL;
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
		ob->r = ob->l = NULL;
		while (true) {
			if (Name > temp->name) {
				if (temp->l == NULL) {
					temp->l = ob;
					count++;
					break;
				}
				else
					temp = temp->l;
			}
			else if (Name <= temp->name) {
				if (temp->r == NULL) {
					temp->r = ob;
					count++;
					break;
				}
				else
					temp = temp->r;
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
		ob->r = ob->l = NULL;
		while (true) {
			if (Num > temp->num) {
				if (temp->l == NULL) {
					temp->l = ob;
					count++;
					break;
				}
				else
					temp = temp->l;
			}
			else if (Num <= temp->num) {
				if (temp->r == NULL) {
					temp->r = ob;
					count++;
					break;
				}
				else
					temp = temp->r;
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
		print_Tree(temp->r, level + 1);

		for (int i = 0; i < level; i++) cout << "\t\t";
		cout << "Назва: " << temp->name << endl;

		for (int i = 0; i < level; i++) cout << "\t\t";
		cout << "Рік: " << temp->year << endl;

		for (int i = 0; i < level; i++) cout << "\t\t";
		cout << "Кіль-сть: " << temp->num << endl;

		print_Tree(temp->l, level + 1);
	}
}


void bTree::avarageNum(obj* temp)
{
	if (temp != NULL)
	{
		avarageNum(temp->l);
		avarage += temp->num;
		avarageNum(temp->r);
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
		preOrder(temp->l);
		preOrder(temp->r);
	}
}

void bTree::postOrder(obj* temp)
{
	if (temp != NULL)
	{
		postOrder(temp->l);
		postOrder(temp->r);
		cout << temp->name << ' ';
	}
}

void bTree::symmetricOrder(obj* temp)
{
	if (temp != NULL)
	{
		symmetricOrder(temp->l);
		cout << temp->name << ' ';
		symmetricOrder(temp->r);
	}
}


void bTree::delBT(obj* temp)
{
	if (temp != NULL)
	{
		delBT(temp->l);
		delBT(temp->r);
		delete temp;
	}
}

void bTree::delL()
{
	delBT(root->l);
	root->l = NULL;
}

void bTree::delR()
{
	delBT(root->r);
	root->r = NULL;
}

void bTree::delEl(obj* el, string name)
{
	if (el == NULL)
		return;
	obj* temp = NULL;
	if (name == el->r->name) {
		if (el->r->l != NULL) {
			temp = el->r->l;
		}
		if (el->r->r != NULL) {
			el->r = el->r->r;
			if (temp)
				add(temp->name, temp->year, temp->num);
		}
		
		else el->r = NULL;
	}
	else if (name == el->l->name) {
		if (el->l->r != NULL) {
			temp = el->l->r;
		}
		if (el->l->l != NULL) {
			el->l = el->l->l;
			if (temp)
				add(temp->name, temp->year, temp->num);
		}
		else el->l = NULL;
	}
	else if (name < el->r->name) {
		delEl(el->r, name);
	}
	else if (name > el->l->name)
		delEl(el->l, name);
}
void bTree::delEl(obj* el, int num)
{
	if (el == NULL)
		return;
	obj* temp = NULL;
	if (num == el->r->num) {
		if (el->r->l != NULL) {
			temp = el->r->l;
		}
		if (el->r->r != NULL) {
			el->r = el->r->r;
			if (temp)
				add4num(temp->name, temp->year, temp->num);
		}

		else el->r = NULL;
	}
	else if (num == el->l->num) {
		if (el->l->r != NULL) {
			temp = el->l->r;
		}
		if (el->l->l != NULL) {
			el->l = el->l->l;
			if (temp)
				add4num(temp->name, temp->year, temp->num);
		}
		else el->l = NULL;
	}
	else if (num < el->r->num) {
		delEl(el->r, num);
	}
	else if (num > el->l->num)
		delEl(el->l, num);
}


void bTree::newTree(obj* temp, bTree& tr)
{
	if (temp != NULL)
	{
		
		tr.add4num(temp->name, temp->year, temp->num);
		newTree(temp->l, tr);
		newTree(temp->r, tr);
	}
}





bool bTree::isEmpty()
{
	if (root != NULL)
		return false;
	else return true;
}

