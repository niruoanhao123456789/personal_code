#include"Sort.h"

//void SelectSort(int* arr, int sizeNum)
//{
//	int i = 0;
//	for (i = 0; i < sizeNum - 1; i++)
//	{
//		int max = i;
//		int j = 0;
//		for (j = i + 1; j < sizeNum; j++)
//		{
//			if (arr[i] < arr[j])
//			{
//				max = j;
//			}
//		}
//		if (max != i)
//		{
//			int tmp = arr[i];
//			arr[i] = arr[max];
//			arr[max] = tmp;
//		}
//	}
//}

//升序
void SelectSort(int* arr, int sizeNum)
{
	assert(arr);
	int begin = 0, end = sizeNum - 1;
	while (begin < end)
	{
		int max = end;
		int min = begin;
		int i = 0;
		for (i = begin+1; i <= end; i++)
		{
			if (arr[i] < arr[min])
				min = i;
			if (arr[i] > arr[max])
				max = i;
		}

		int tmp = arr[min];
		arr[min] = arr[begin];
		arr[begin] = tmp;
		
		if (max == begin)
			max = min;

		tmp = arr[max];
		arr[max] = arr[end]; 
		arr[end] = tmp;

		begin++;
		end--;
	}
}

//时间复杂度为O（n^2）
void InsertSort(int* arr, int sizeNum)
{
	assert(arr);
	int i = 0;
	for (i = 0; i < sizeNum-1; i++)
	{
		int end = i;
		int tmp = arr[end + 1];
		while (end > -1)
		{
			if (arr[end] > tmp)
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else
			{
				break;
			}
		}
		arr[end + 1] = tmp;
	}
}

//时间复杂度为O(n^1.3)
//外层循环时间复杂度为O(log n)
//内层
//n/gap个数据下，最坏情况下移动次数为：1+2+3+……+(n/gap-1)
//最后一趟经过前面的调整，直接插入排序的复杂度可达O(n)
void ShellSort(int* arr, int sizeNum)
{
	assert(arr);
	int gap = sizeNum;
	int i = 0;
	while(gap>1)//gap==1时执行直接插入排序
	{
		gap = gap / 3 + 1;//通常情况下/3能使循环次数适当少
		for (i = 0; i < sizeNum - gap; i ++)
		{
			int end = i;
			int tmp = arr[gap + end];
			while (end > -1)
			{
				if (arr[end] > tmp)
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = tmp;
		}
	}
}

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void AdjustDown(int* arr, int parent, int n)
{
	assert(arr);
	int child = parent * 2 + 1;
	while (child < n)
	{
		//找最大子节点
		if ((arr[child] < arr[child + 1]) && (child + 1 < n))
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

void HeapSort(int* arr, int n)
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