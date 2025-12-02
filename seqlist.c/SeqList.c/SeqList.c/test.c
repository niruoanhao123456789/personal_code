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

	// 删除数据3，但不知道数据3的具体位置
	int pos = SeqListFind(ps, 3);
	if (pos != -1)
	{
		SeqListErase(ps, pos);
	}
	SeqListPrint(ps);
}

void test4(SeqList* ps)
{
	int i = 0;
	for (i = 0; i < 6; i++)
	{
		SeqListPushBack(ps, i);
	}
	SeqListPrint(ps);

	// 在元素0后面插入元素4
	int pos = SeqListFind(ps, 0);
	if (pos != -1)
	{
		SeqListInsertAfter(ps, pos, 4);
	}
	SeqListPrint(ps);
}

int main()
{
	SeqList ps;
	SeqListInit(&ps);
	
	// 写很长的代码和函数模块时，建议这样边写边测试，避免问题过多又不知从何找起
	test1(&ps);
	//test2(&ps);
	//test3(&ps);
	//test4(&ps);

	SeqListDestory(&ps);
	return 0;
}