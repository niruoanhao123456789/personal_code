#include"Heap.h"

void HeapInit(Heap* php)
{
	assert(php);
	php->data = NULL;
	php->capacity = 0;
	php->size = 0;
}

void HeapDestory(Heap* php)
{
	assert(php);
	free(php->data);
	php->capacity = 0;
	php->size = 0;
	free(php);
	php = NULL;
}

void Checkcapacity(Heap* php)
{
	assert(php);
	if (php->capacity <= php->size)
	{
		int newcapacity = php->capacity == 0 ? 4 : 2 * php->capacity;
		php->data = (HPDataType*)realloc(php->data, newcapacity * sizeof(HPDataType));
		php->capacity = newcapacity;
	}
}

//ÒÔ´ó¶ÑÎªÀý
void HeapPush(Heap* php, HPDataType x)
{
	assert(php);
	Checkcapacity(php);
}