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

//真正的堆排序是通过堆的思想来实现而不是用堆这个结构，小堆降序，大堆升序.
//堆排序的时间复杂度为O(n+n*logn)即O(n*logn)
void HeapSort(HPDataType* arr, int n)
{
	int i = 0;
	//乱序数组	建堆
	//向下调整算法建堆，先从最小子树开始调整
	for (i = (n - 1 - 1) / 2; i >= 0; i--)//找到最后子节点的父节点
	{
		AdjustDown(arr, i, n);
	}

	//向上调整建堆
	//for (i = 0; i < n; i++)
	//{
	//	AdjustUp(arr, i);
	//}
	
	int end = n - 1;//拿最后一个和最值进行交换
	while (end > 0)
	{
		Swap(&arr[end], &arr[0]);
		AdjustDown(arr, 0, end);
		end--;
	}
}

//top k问题 排行榜 用于处理大量数据排序
//对于n个数据找出最大k个数据
//对n的前k个数据建小堆，从第k+1个从后历遍与堆顶进行比较，谁大谁放堆顶，并进行堆内调整
//找最小k个数据
//对n的前k个数据建大堆，从第k+1个从后历遍与堆顶进行比较，谁小谁放堆顶，并进行堆内调整
void createdata()
{
	int n = 100000;
	srand((unsigned int)time(NULL));
	FILE* pf = fopen("topkdata", "w");
	if (pf == NULL)
	{
		perror("fopen fail");
		exit(-1);
	}
	int i = 0;
	for (i = 0; i < n; i++)
	{
		int x = (rand() + i) % 1000000;
		fprintf(pf, "%d", x);
	}
	fclose(pf);
	pf = NULL;
}

//topk 问题的时间复杂度为O(k+(n-k)logk)
void test2()
{
	int k = 0;
	scanf("%d", &k);
	createdata();
	FILE* pf = fopen("topkdata", "r");
	if (pf == NULL)
	{
		perror("fopen fail");
		exit(-1);
	}
	//创建堆
	HPDataType* minHeap = (HPDataType*)calloc(k, sizeof(HPDataType));
	if (minHeap == NULL)
	{
		perror("calloc fail");
		exit(-1);
	}
	//从文件中读数据放入堆中
	int i = 0;
	for (i = 0; i < k; i++)
	{
		fscanf(pf, "%d", &minHeap[i]);
	}
	//建k个数据的小堆
	for (i = k - 1 - 1; i >= 0; i--)
	{
		AdjustDown(minHeap, k, i);
	}
	
	int x = 0;
	while (fscanf(pf, "%d", &x) != EOF)
	{
		//读取剩余数据，与堆顶进行比较
		minHeap[0] = x;
		AdjustDown(minHeap, k, 0);
	}

	for (i = 0; i < k; i++)
	{
		printf("%d ", minHeap[i]);
	}
	printf("\n");
	free(minHeap);
	minHeap = NULL;
	fclose(pf);
	pf = NULL;
}

int main()
{
	//test1();

	//HPDataType arr[] = { 34,36,2,5,7,2,9,8,1 };
	//int i = 0;
	//int sz = sizeof(arr) / sizeof(arr[0]);
	//HeapSort(arr,sz);
	//for (i = 0; i < sz; i++)
	//{
	//	printf("%d ", arr[i]);
	//}
	//printf("\n");
	//HeapSort1(arr, sz);
	//for (i = 0; i < sz; i++)
	//{
	//	printf("%d ", arr[i]);
	//}
	//printf("\n");

	test2();

	return 0;
}