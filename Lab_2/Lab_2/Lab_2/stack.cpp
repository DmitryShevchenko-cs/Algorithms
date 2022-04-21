#include "stack.h"

stack::~stack()
{	
	if (!isEmpty()) {
		obj* temp = top;
		while (temp->next) {
			temp = temp->next;
			delete top;
			top = temp;
		}
		top = temp;
		delete top;
	}
}

void stack::push(short d)
{
	obj* temp = new obj;
	temp->data = d;
	temp->next = top;

	top = temp;
}

void stack::pop()
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
	cout << "stack: ";
	while (temp) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

void stack::swapTopTail()
{
	if (!top->next)
		return;

	if (!top->next->next) {
		short s1 = pull();
		short s2 = pull();

		push(s1);
		push(s2);
		return;
	}

	else {
		short first = pull();
		obj* temp = top;
		short count = 0;
		while (temp->next) {
			count++;
			temp = temp->next;
		}
		short* arr = new short[count];

		for (short i = 0; i < count; i++) {
			arr[i] = pull();
		}
		short last = pull();
		push(first);

		for (short i = count-1; i >= 0; i--) {
			push(arr[i]);
		}

		push(last);

	}


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
	obj* temp = top;

	stack tempSt;
	while (!isEmpty()) {
		tempSt.push(pull());
		pop();
	}

	while (!tempSt.isEmpty()) 
		push(tempSt.pull());
}

void stack::delMin()
{
	if (!isEmpty()) {
		stack newStack;
		int size = 0, count = 0;
		short min = top->data;
		while (!isEmpty()) {
			if (min > top->data) {
				min = top->data;
				count = size;
			}
			newStack.push(pull());
			size++;
		}
		for (int i = 0; i < size - count; i++) {
			push(newStack.pull());
		}
		pop();
		while (!newStack.isEmpty())
			push(newStack.pull());
	}


}

void stack::delTail()
{

	short temp = pull();
	while (!isEmpty())
		pop();
	push(temp);

}

void stack::delHead()
{
	while (top->next)
		pop();

}

void stack::maxZero()
{

	if (!isEmpty()) {
		stack newStack;
		int size = 0, count = 1;
		short max = top->data;
		while (!isEmpty()) {
			size++;
			if (max < top->data) {
				max = top->data;
				count = size;
			}
			newStack.push(pull());
			
		}
		for (int i = 0; i < size - count; i++) {
			push(newStack.pull());
		}
		push(0);
		push(newStack.pull());
		while (!newStack.isEmpty())
			push(newStack.pull());
	}
	
}

void stack::putStar()
{
	obj* temp = top;
	int count = 0;

	while (temp)
	{
		count++;
		temp = temp->next;
	}
	temp = top;
	if (count % 2 == 0) {
		for (int i = 0; i < count / 2; i++) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << '*' << ' ';

		while (temp) {
			cout << temp->data << " ";
			temp = temp->next;
		}

	}
	else {
		for (int i = 0; i < count / 2 + 1; i++) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << '*' << ' ';

		while (temp) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	cout << endl;

}

bool stack::isEmpty()
{
	if (top)
		return 0;
	else 
		return 1;
}
