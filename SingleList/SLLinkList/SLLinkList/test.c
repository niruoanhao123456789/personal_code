#include"SList.h"

void test1(SLTNode* phead)
{
	SListPushBack(&phead,1);
	SListPushBack(&phead, 2);
	SListPushBack(&phead, 3);
	SListPrint(phead);

	SListPushFront(&phead, 1);
	SListPushFront(&phead, 2);
	SListPushFront(&phead, 3);
	SListPrint(phead);

	SListPopFront(&phead);
	SListPopBack(&phead);
	SListPrint(phead);
}

void test2(SLTNode* phead)
{
	SListPushBack(&phead, 1);
	SListPushBack(&phead, 2);
	SListPushBack(&phead, 3);
	SListPushBack(&phead, 2);
	SListPushBack(&phead, 4);
	SListPushBack(&phead, 5);
	SListPushBack(&phead, 2);

	//SLTNode* pos = SListFind(phead,2);
	////对于要查找的数据存在多个的情况
	//int count = 1;
	//while (pos)
	//{
	//	printf("第%d个要查找的节点：%p %d\n", count++, pos, pos->data);
	//	pos = SListFind(pos->next, 2);
	//}

	//修改要找的数据
	SLTNode* pos = SListFind(phead, 3);
	if (pos)
	{
		pos->data = 2;
	}
	SListPrint(phead);

	pos = SListFind(phead, 4);
	if (pos)
	{
		SListInsert(&phead, pos, 3);
	}
	SListPrint(phead);

	pos = SListFind(phead, 1);
	if (pos)
	{
		SListInsert(&phead, pos, 1);
	}
	SListPrint(phead);
}


int main()
{
	SLTNode* plist = NULL;
	//test1(plist);
	//test2(plist);

	SListDestory(&plist);
	return 0;
}