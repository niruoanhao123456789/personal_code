#include"stack.h"

void test1()
{
	Stack st;
	StackInit(&st);
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		StackPush(&st, i);
	}
	StackPrint(&st);
	StackDestroy(&st);
}

int main()
{
	test1();
	return 0;
}