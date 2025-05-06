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
	while (cur != (pq->tail))
	{
		free(cur);
		cur = cur->next;
	}
	cur = NULL;
	pq->head = NULL;
	pq->tail = NULL;
}