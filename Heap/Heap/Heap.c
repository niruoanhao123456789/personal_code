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

void HPPrint(Heap hp)
{
	int i = 0;
	for (i = 0; i < hp.size; i++)
	{
		printf("%d ", hp.data[i]);
	}
	printf("\n");
}

static void Checkcapacity(Heap* php)
{
	assert(php);
	if (php->capacity <= php->size)
	{
		int newcapacity = php->capacity == 0 ? 4 : 2 * php->capacity;
		HPDataType* tmp = (HPDataType*)realloc(php->data, newcapacity * sizeof(HPDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		php->data = tmp;
		php->capacity = newcapacity;
	}
}

static void Swap(HPDataType* x, HPDataType* y)
{
	HPDataType tmp = *x;
	*x = *y;
	*y = tmp;
}

//向上调整算法，比较大小调整次序，父节点下标是字节点的(n-1)/2
static void AdjustUp(HPDataType* arr, int child)
{
	assert(arr);
	int parent = (child - 1) / 2;
	while (child>0)
	{
		if (arr[parent] < arr[child])
		{
			Swap(&arr[parent], &arr[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}

void HeapPush(Heap* php, HPDataType x)
{
	assert(php);
	Checkcapacity(php);
	php->data[php->size] = x;
	php->size++;

	AdjustUp(php->data, php->size-1);
}

bool HPEmpty(Heap* php)
{
	assert(php);
	return (php->size == 0);
}

//向下调整算法，先比较两个子节点，将大的与父节点（第一个结点）交换后再与下标(n*2+1)子节点比较，直至子节点越界
static void AdjustDown(HPDataType* arr)
{
	assert(arr);
	
}

void HPPop(Heap* php)
{
	assert(php && !HPEmpty(php));
	//出根节点，先将根节点和下标最后的结点交换后出掉后结点，再让堆顶进行向下调整

}