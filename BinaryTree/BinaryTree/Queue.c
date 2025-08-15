#include"Queue.h"


void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->head;
	while (cur)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = NULL;
	pq->tail = NULL;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		exit(-1);
	}
	newnode->val = x;
	newnode->next = NULL;
	if (pq->head == NULL)
	{
		pq->head = newnode;
	}
	else
	{
		pq->tail->next = newnode;
	}
	pq->tail = newnode;
}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	QueueNode* next = pq->head->next;
	if (pq->head == pq->tail)
	{
		pq->tail = NULL;
	}
	free(pq->head);
	pq->head = next;
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->head->val;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq && pq->tail);
	return pq->tail->val;
}

int QueueSize(Queue* pq)
{
	assert(pq);
	int count = 0;
	if (pq->head == NULL)
	{
		count = 0;
	}
	else
	{
		QueueNode* cur = pq->head;
		while (cur != NULL)
		{
			QueueNode* next = cur->next;
			count++;
			cur = next;
		}
	}
	return count;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);
	if (pq->head)
	{
		return false;
	}
	else
	{
		return true;
	}
}