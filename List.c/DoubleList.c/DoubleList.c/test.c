#include"List.h"

void listtest1()
{
	LTNode* plist = ListInit();
	//int i = 0;
	//for (i = 0; i < 5; i++)
	//{
	//	ListPushBack(plist, i);
	//}
	//ListPrint(plist);

	//ListPopBack(plist);
	//ListPopBack(plist);
	//ListPrint(plist);

	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPushFront(plist, 4);
	ListPopFront(plist);
	ListPrint(plist);

	ListDestroy(plist);
	plist = NULL;
}

//双向带头循环链表的实现

int main()
{
	//LTNode* plist = ListInit();
	//ListInit(&plist);

	listtest1();

	return 0;
}