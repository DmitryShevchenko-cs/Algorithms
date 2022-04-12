#include "stack.h"

int main() {

	stack st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	st.push(6);
	st.show();//ok

	st.swapTopTail();//ok
	st.show();

	st.reverse();//ok
	st.show();

	return 1;
}