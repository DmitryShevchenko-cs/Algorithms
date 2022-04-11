#include "stack.h"

void stackWork::push(short d)
{
	obj* temp = new obj;
	temp->data = d;
	temp->next = top;

	top = temp;
}

void stackWork::popTop()
{
	if (!top) return;

	obj* temp = top->next;
	delete top;
	top = temp;
}
