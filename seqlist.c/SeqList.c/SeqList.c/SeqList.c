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
		// 扩容 
		// 扩少了不够用，扩大了又浪费
		// *2比较适中
		int newcapacity = (ps->capacity == 0 ? 4 : 2 * ps->capacity);
		SLDataType* tmp = (SLDataType*)realloc(ps->data, newcapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			printf("%s\n", strerror(errno));	// 根据错误码，打印错误信息，反馈扩容失败
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
	//将每个数据往后挪一位，将第一个位置空出来
	int end = ps->count - 1;
	while (end >= 0)
	{
		ps->data[end+1] = ps->data[end];
		end--;
	}

	ps->data[0] = x;
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
	if (ps->count > 0)		// 确保不对空表进行删除数据
	{
		// 将除第一个数据外的每个元素从后往前挪，将第一数据进行覆盖
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
	// 再确定某严格要求下，断言assert会比if更常用，且断言会返回错误信息
	assert(ps);
	assert(pos >= 0 && pos <= ps->count);
	//or
	//if (pos<0 || pos>ps->count)
	//{
	//	printf("err\n");
	//	return;
	//}
	SLCeckcapacity(ps);
	int end = ps->count - 1;
	while (end >= pos)
	{
		ps->data[end + 1] = ps->data[end];
		end--;
	}
	ps->data[pos] = x;
	ps->count++;
}

void SeqListInsertAfter(SeqList* ps, int pos, SLDataType x)
{
	assert(ps && pos >= 0 && pos < ps->count);
	SLCeckcapacity(ps);
	int end = ps->count - 1;
	while (end > pos)
	{
		ps->data[end + 1] = ps->data[end];
		end--;
	}
	ps->data[pos + 1] = x;
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