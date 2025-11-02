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

void Swap(HPDataType* x, HPDataType* y)
{
	HPDataType tmp = *x;
	*x = *y;
	*y = tmp;
}

//向上调整算法，比较大小调整次序，父节点下标是字节点的(n-1)/2
//分析该算法的时间复杂度：
//while循环次数是根据二叉树的层次来决定，在最坏情况下的满二叉树节点个数 n = 2^k-1
//可知层数为k = log2(n+1)，即为本算法的时间复杂度
//因向上移动h层需要步数为：
// F(h) = 2 + 2^2*2 + 2^3*3 + 2^4*4 + …… + 2^(h-1)*(h-1)
//2*F(h) =    2^2*1 + 2^3*2 + 2^4*3 + …… + 2^(h-1)*(h-2) + 2^h*(h-1)
//错位相减得 F(h) = 2^h * (h-2) + 2
//由上面的结论可得F(h) = (n+1)*(log2(n+1)-2)+2
//所以向上调整算法建堆的时间复杂度为O(n*log2(n))
//其越往下结点越多，调整次数也相应增多
void AdjustUp(HPDataType* arr, int child)
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
//与向上调整思路一样，得出其复杂度O(n)
//该算法随着越往下节点数增多，但调整次数减少
void AdjustDown(HPDataType* arr,int parent,int n)
{
	assert(arr);
	int child = parent * 2 + 1;
	while (child < n)
	{
		//找最大子节点
		if ((arr[child] < arr[child + 1])&&(child+1<n))
		{
			child++;
		}
		//字节点与父节点比较
		if (arr[child] > arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

void HPPop(Heap* php)
{
	assert(php && !HPEmpty(php));
	//出堆顶节点，先将根节点和下标最后的结点交换后出掉后结点，再让堆顶进行向下调整
	Swap(&php->data[0], &php->data[php->size - 1]);
	php->size--;
	AdjustDown(php->data, 0, php->size);
}

HPDataType HPTop(Heap* php)
{
	assert(php && !HPEmpty(php));
	return (php->data[0]);
}
