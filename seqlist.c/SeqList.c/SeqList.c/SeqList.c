#include"SeqList.h"

void SeqListInit(SeqList* ps)
{
	assert(ps);
	ps->data = NULL;
	ps->count = 0;
	ps->capacity = 0;
}

static void SLCeckcapacity(SeqList* ps)
{
	assert(ps);
	if (ps->count >= ps->capacity)
	{
		//扩容 *2比较适中
		int newcapacity = (ps->capacity == 0 ? 4 : 2 * ps->capacity);
		SLDataType* tmp = (SLDataType*)realloc(ps->data, newcapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			printf("%s\n", strerror(errno));
			exit(-1);
		}

		ps->data = tmp;
		ps->capacity = newcapacity;
	}
}

void SeqListPushFront(SeqList* ps, SLDataType x)
{
	assert(ps);
	SLCeckcapacity(ps);
	//挪动数据
	int end = ps->count - 1;
	while (end >= 0)
	{
		*(ps->data + end + 1) = *(ps->data + end);
		end--;
	}
	*(ps->data) = 0;
	ps->count++;
}

void SeqListPushBack(SeqList* ps, SLDataType x)
{
	assert(ps);
	SLCeckcapacity(ps);

	ps->data[ps->count] = x;
	ps->count++;
}

void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	if (ps->count > 0)
	{
		ps->count--;
	}
	//or
	//assert(ps->count > 0);
	//ps->count--;
}

void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	int begin = 0;
	if (ps->count > 0)
	{
		while (begin < ps->count - 1)
		{
			ps->data[begin] = ps->data[begin + 1];
			begin++;
		}
		ps->count--;
	}
}

void SeqListInsert(SeqList* ps, int pos, SLDataType x)
{
	assert(ps);
	//if (pos<0 || pos>ps->count)
	//{
	//	printf("err\n");
	//	return;
	//}
	assert(pos >= 0 && pos <= ps->count);
	SLCeckcapacity(ps);
	int end = ps->count - 1;
	while (end >= pos)
	{
		ps->data[end + 1] = ps->data[end];
	}
	ps->data[pos] = x;
	ps->count++;
}

void SeqListErase(SeqList* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->count);
	int begin = pos;
	while (begin < ps->count - 1)
	{
		ps->data[begin] = ps->data[begin + 1];
		begin++;
	}
	ps->count--;
}

int SeqListFind(const SeqList* ps, SLDataType x)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->count; i++)
	{
		if (ps->data[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void SeqListPrint(const SeqList* ps)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->count; i++)
	{
		printf("%d ", ps->data[i]);
	}
	printf("\n");
}

void SeqListDestory(SeqList* ps)
{
	assert(ps);
	free(ps->data);
	ps->data = NULL;
	ps->capacity = 0;
	ps->count = 0;
}