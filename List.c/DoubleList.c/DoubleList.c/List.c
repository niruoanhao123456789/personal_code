#include"List.h"

//法一：
//void ListInit(LTNode** phead)
//{
//	*phead = (LTNode*)malloc(sizeof(LTNode));
//	if (*phead == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		exit(-1);
//	}
//	(*phead)->next = phead;
//	(*phead)->prev = phead;
//}

//法二：
LTNode* ListInit()
{
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	if (phead == NULL)
	{
		printf("%s\n", strerror(errno));
		exit(-1);
	}
	phead->next = phead;
	phead->prev = phead;
}

void ListPrint(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void ListPushBack(LTNode* phead,LTDataType val)
{
	assert(phead);

	LTNode* tail = phead->prev;
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		printf("%s\n", strerror(errno));
		exit(-1);
	}
	newnode->data = val;

	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;

	//ListInsert(phead, val);
}

void ListPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);//要保留头结点
	LTNode* tail = phead->prev;
	tail->prev->next = phead;
	phead->prev = tail->prev;
	free(tail);
	tail = NULL;
}

void ListPushFront(LTNode* phead, LTDataType val)
{
	assert(phead);
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		printf("%s\n", strerror(errno));
		exit(-1);
	}
	newnode->data = val;
	newnode->prev = phead;
	newnode->next = phead->next;

	phead->next->prev = newnode;
	phead->next = newnode;

	//可用ListInsert实现头插和尾插的全部功能
	//ListInsert(phead->next, val);
}

void ListPopFront(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	LTNode* next = phead->next;
	phead->next = next->next;
	next->next->prev = phead;
	free(next);
	next = NULL;
}

LTNode* ListFind(LTNode* phead, LTDataType val)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == val)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void ListInsert(LTNode* pos, LTDataType val)
{
	assert(pos);
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		printf("%s\n", strerror(errno));
		exit(-1);
	}
	newnode->data = val;
	LTNode* posprev = pos->prev;
	posprev->next = newnode;
	newnode->prev = posprev;
	newnode->next = pos;
	pos->prev = newnode;
}

void ListErase(LTNode* pos)//该函数跟ListInsert类似能实现头删与尾删的功能
{
	assert(pos);
	LTNode* posprev = pos->prev;
	LTNode* posnext = pos->next;
	posprev->next = posnext;
	posnext->prev = posprev;
	free(pos);
	pos = NULL;
}

//为保持接口的一致性传一级指针，但导致要在函数外将哨兵位头结点置空
void ListDestroy(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur!=phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
	phead = NULL;
}