#include"SList.h"

void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

static SLTNode* SLTBuyMemory(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void SListPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	//该函数用二级指针的原因是针对头节点没有创建的情况
	//增加新节点
	SLTNode* newnode = SLTBuyMemory(x);

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//找到尾节点
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = SLTBuyMemory(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

void SListPopBack(SLTNode** pphead)
{
	assert(pphead);
	//普通情况下可不用传二级指针，但针对链表删到空的情况要传二级指针
	//SLTNode* tail = *pphead;
	//SLTNode* prev = NULL;
	//while (tail->next)
	//{
	//	prev = tail;
	//	tail = tail->next;
	//}

	//free(tail);
	//tail = NULL;
	//prev->next = NULL;//在释放最后一个节点后，将上一个节点的指向后续的置空
	//但这种方法只适用于两个及以上节点的情况

	//因此可对单节点或无节点特殊处理
	assert(*pphead);
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* tail = *pphead;
		SLTNode* prev = NULL;
		while (tail->next)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;
	}
}

void SListPopFront(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

SLTNode* SListFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}

void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead);
	assert(pos);
	SLTNode* newnode = SLTBuyMemory(x);

	if (*pphead == pos)
	{
		newnode->next = *pphead;
		*pphead = newnode;
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = newnode;
		newnode->next = pos;
	}
}

void SListInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = SLTBuyMemory(x);

	newnode->next = pos->next;
	pos->next = newnode;
}

void SListEase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead);
	assert(pos);
	if (pos == *pphead)
	{
		*pphead = pos->next;
		free(pos);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
	}
	pos = NULL;
}

void SListEaseAfter(SLTNode* pos)
{
	assert(pos->next && pos);
	SLTNode* next = pos->next;
	pos->next = next->next;
	free(next);
	next = NULL;
}

void SListDestory(SLTNode** pphead)
{
	assert(pphead);
	SLTNode* cur = *pphead;
	SLTNode* next = NULL;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}