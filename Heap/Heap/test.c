#include"Heap.h"

void test1()
{
	Heap hp;
	HeapInit(&hp);
	HeapPush(&hp, 1);
	HPPrint(hp);
	HeapPush(&hp, 2);
	HPPrint(hp);
	HeapPush(&hp, 3);
	HPPrint(hp);
	HeapPush(&hp, 0);
	HPPrint(hp);

	HeapDestory(&hp);
}

int main()
{
	test1();

	return 0;
}