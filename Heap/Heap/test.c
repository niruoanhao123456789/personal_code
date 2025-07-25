#include"Heap.h"

void test1()
{
	Heap hp;
	HeapInit(&hp);
	HeapPush(&hp, 1);
	HeapPush(&hp, 2);;
	HeapPush(&hp, 3);
	HeapPush(&hp, 6);
	HeapPush(&hp, 5);
	HeapPush(&hp, 4);
	HeapPush(&hp, 0);
	HPPrint(hp);
	while (!HPEmpty(&hp))//发现该输出结果是有序数组
	{
		printf("%d ",HPTop(&hp));
		HPPop(&hp);
	}
	
	HeapDestory(&hp);
}

//利用类似堆排序来实现无序数组变为有序数组，大堆降序，小堆升序
void HeapSort1(HPDataType* arr,int n)
{
	int i = 0;
	Heap hp;
	HeapInit(&hp);
	for (i = 0; i < n; i++)
	{
		HeapPush(&hp, arr[i]);
	}
	i = 0;
	while (!HPEmpty(&hp))
	{
		arr[i++] = HPTop(&hp);
		HPPop(&hp);
	}

	HeapDestory(&hp);
}

//真正的堆排序是通过堆的思想来实现而不是用堆这个结构，小堆降序，大堆升序
void HeapSort(HPDataType* arr, int n)
{
	//乱序数组	建堆
	//向下调整算法建堆，先从最小子树开始调整
	int i = 0;
	for (i = (n - 1 - 1) / 2; i >= 0; i--)//找到最后子节点的父节点
	{
		AdjustDown(arr, i, n);
	}
	int end = n - 1;//拿最后一个和最值进行交换
	while (end > 0)
	{
		Swap(&arr[end], &arr[0]);
		AdjustDown(arr, 0, end);
		end--;
	}
}

int main()
{
	//test1();

	HPDataType arr[] = { 34,36,2,5,7,2,9,8,1 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr,sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	HeapSort1(arr, sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}