#include "tree.h"

void bTree::create(string Name, int Year, int Num)
{
	if (isEpty()) {
		obj* temp = new obj;
		temp->name = Name;
		temp->year = Year;
		temp->num = Num;
		root = temp;
		root->l = root->r = NULL;
		count++;
	}
	else
		cout << "Дерево вже створено" << endl;
}

void bTree::add(string Name, int Year, int Num)
{
	if (!isEpty()) {
		obj* temp = root;
		obj* ob = new obj;
		ob->name = Name;
		ob->year = Year;
		ob->num = Num;
		ob->r = ob->l = NULL;
		while (true) {
			if (Name < temp->name) {
				if (temp->l == NULL) {
					temp->l = ob; 
					count++;
					break;
				}
				else
					temp = temp->l;
			}
			else if (Name > temp->name) {
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
}

void bTree::show(obj* temp)
{
	if (temp != NULL)               
	{
		show(temp->l);               
		cout << temp->name << endl;
		show(temp->r);               
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
		cout << temp->name << endl;
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
		cout << temp->name << endl;
	}
}

void bTree::symmetricOrder(obj* temp)
{
	if (temp != NULL)
	{
		symmetricOrder(temp->l);
		cout << temp->name << endl;
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

void bTree::print_Tree(obj* p, int level)
{
	if (p)
	{
		print_Tree(p->l, level + 1);
		for (int i = 0; i < level; i++) cout << "   ";
		cout << p->name << endl;
		print_Tree(p->r, level + 1);
	}
}

bool bTree::isEpty()
{
	if (root != NULL)
		return false;
	else return true;
}

