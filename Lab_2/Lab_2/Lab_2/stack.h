#include <iostream>

using namespace std;

typedef struct stack{
	short data;
	stack* next;

}obj;

class stackWork {

	obj* top;

public:
	void push(short d);
	void popTop();
};