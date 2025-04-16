#include"SeqList.h"

void test1(SeqList* ps)
{
	int i = 0;
	for (i = 0; i <= 5; i++)
	{
		SeqListPushBack(ps, i);
	}
	SeqListPrint(ps);
	for (i = 0; i <= 5; i++)
	{
		SeqListPopBack(ps);
	}
	SeqListPrint(ps);
}

void test2(SeqList* ps)
{
	int i = 0;
	for (i = 0; i <= 5; i++)
	{
		SeqListPushFront(ps, i);
	}
	SeqListPrint(ps);
	for (i = 0; i <= 5; i++)
	{
		SeqListPopFront(ps);
	}
	SeqListPrint(ps);
}

void test3(SeqList* ps)
{
	int i = 0;
	for (i = 0; i < 6; i++)
	{
		SeqListPushBack(ps, i);
	}
	int pos = SeqListFind(ps, 3);
	if (pos != -1)
	{
		SeqListErase(ps, pos);
	}
	SeqListPrint(ps);
}

int main()
{
	SeqList ps;
	SeqListInit(&ps);

	//test1(&ps);
	//test2(&ps);
	test3(&ps);

	SeqListDestory(&ps);
	return 0;
}