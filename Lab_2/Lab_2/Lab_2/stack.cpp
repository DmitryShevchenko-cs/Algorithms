#include "stack.h"

stack::~stack()
{
	obj* temp = top;
	
	while (temp->next) {
		temp = temp->next;
		delete top;
		top = temp;
	}
	top = temp;
	delete top;
}

void stack::push(short d)
{
	obj* temp = new obj;
	temp->data = d;
	temp->next = top;

	top = temp;
}

void stack::popTop()
{
	if (!top) return;

	obj* temp = top->next;
	delete top;
	top = temp;
}

short stack::pull()
{
	short data;
	obj* temp = top->next;

	data = top->data;
	delete top;
	top = temp;

	return data;
}

void stack::show()
{
	obj* temp = top;

	while (temp) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

void stack::swapTopTail()
{
	obj* temp = top, * tempT = top, *tempL = top;

	
	while (tempL->next)
		tempL = tempL->next;

	while (temp->next != tempL)
		temp = temp->next;

	tempL->next = tempT->next;
	top = tempL;
	temp->next = tempT;
	tempT->next = NULL;
}

void stack::reverse()
{
	obj* temp = top;
	short count = 0;
	while (temp) {
		count++;
		temp = temp->next;
	}

	short *arr = new short[count];

	for (short i = 0; i < count; i++) {
		arr[i] = pull();
	}

	for (short i = 0; i < count; i++) {
		push(arr[i]);
	}


}

void stack::delEvery2()
{
	obj* temp1 = top;
	obj* temp2 = top->next;

	while (temp2) {
		if (temp2->next) {
			temp1->next = temp2->next;
			temp1 = temp2->next;
		}

		else 
			temp1->next = NULL;
		delete temp2;

		if (temp1->next)
			temp2 = temp1->next;
		else
			temp2 = NULL;
	}

}

void stack::delMin()
{
	obj* temp = top;
	obj* tempMin = top;
	
	short min = top->data;

	while (temp) {
		if (min > temp->data) {
			min = temp->data;
			tempMin = temp;
		}
		temp = temp->next;
	}
	temp = top;

	if(tempMin!=top)
		while (temp->next != tempMin)
			temp = temp->next;

	if (tempMin == top) {
		temp = top->next;
		delete top; 
		top = temp;
		return;
	}

	else if (!tempMin->next) {

		temp->next = NULL;
		delete tempMin;
	}

	else {
		temp->next = tempMin->next;
		delete tempMin;
	}

}
