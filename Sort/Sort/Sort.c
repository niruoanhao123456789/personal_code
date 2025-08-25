#include"Sort.h"
#include"stack.h"

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

void BubbleSort(int* arr, int sizeNum)
{
	int i = 0;
	int exchange = 0;
	for (i = 0; i < sizeNum-1; i++)
	{
		int j = 0;
		for (j = i + 1; j < sizeNum; j++)
		{
			if (arr[i] > arr[j])
			{
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
				exchange = 1;
			}
		}
		if (!exchange)
			break;
	}
}

//hoare版本，时间复杂度为O(n*log n)
//如果基准值找的不好/数组有序 O(n^2)
int _QuickSort(int* arr, int left, int right)
{
	int key = left;
	left++;
	while (left <= right)
	{
		//下面两个循环的顺序不能交换，
		//right从右往左找比基准值小的
		while (left <= right && arr[right] > arr[key])//这里不用等号是为了防止数据多次重复出现导致的O(n^2)
		{
			right--;
		}
		//left从左往右找比基准值大的
		while (left <= right && arr[left] < arr[key])
		{
			left++;
		}
		if (left <= right)
		{
			Swap(&arr[left], &arr[right]);
			//left、right如果不移动的话，在相遇值和基准值相等时会进入死循环
			left++;
			right--;
		}
	}
	//此时right的位置就是基准值的位置
	//
	Swap(&arr[key], &arr[right]);

	return right;
}

//挖坑法找基准值
//现将最左边的值作为基准值并保存下来，同时该位置作为坑位
//让right先从右往左比较，比基准值小就把该值放到坑位，此时right变为坑位，再走left执行一样的操作，
//直到left和right相遇将基准值放入坑位，此时坑位就是基准值的位置
int _QuickSorthole(int* arr, int left, int right)
{
	int hole = left;
	int key = arr[hole];
	while (left < right)
	{
		while (left < right && arr[right] >= key)
		{
			right--;
		}
		arr[hole] = arr[right];
		hole = right;
		while (left < right && arr[left] <= key)
		{
			left++;
		}
		arr[hole] = arr[left];
		hole = left;
	}
	arr[hole] = key;
	return hole;
}

//lumoto双指针法
//创建前后指针，从左往右找比基准值小的进行交换，使小的都在基准值左边
_QuickSortlumoto(int* arr, int left, int right)
{
	int prev = left, cur = left + 1, keyi = left;
	while (cur <= right)
	{
		if(arr[cur] < arr[keyi] && ++prev != cur)
		{
			Swap(&arr[prev], &arr[cur]);
		}
		cur++;
	}
	Swap(&arr[keyi], &arr[prev]);
	return prev;
}

void QuickSort(int* arr, int left, int right)
{
	if (left >= right)
		return;

	//找基准值，并将其放在合适的位置
	//先假定基准值在最左侧
	//left找比基准值大的，right找比基准值小的

	//int key = _QuicSort(arr, left, right);
	//int key = _QuickSorthole(arr, left, right);
	int key = _QuickSortlumoto(arr, left, right);
	//将序列一分为二
	QuickSort(arr, left, key - 1);
	QuickSort(arr, key + 1, right);
}

//根据基准值分开的子序列用栈来存起来
//每次对栈顶的序列进行序列划分
void QuickSortNorR(int* arr, int left, int right)
{
	Stack st;
	StackInit(&st);
	StackPush(&st, right);
	StackPush(&st, left);
	while (!StackEmpty(&st))
	{
		//取栈顶两次
		int begin = StackTop(&st);
		StackPop(&st);
		int end = StackTop(&st);
		StackPop(&st);
		//找基准值
		int keyi = begin, prev = begin, cur = begin + 1;
		while (cur <= end)
		{
			if (arr[cur] < arr[keyi] && ++prev != cur)
			{
				Swap(&arr[cur], &arr[prev]);
			}
			cur++;
		}
		Swap(&arr[prev], &arr[keyi]);
		keyi = prev;
		//分左右序列，右序列优先入栈
		if (end > keyi + 1)
		{
			StackPush(&st, end);
			StackPush(&st, keyi + 1);
		}
		if (begin < keyi - 1)
		{
			StackPush(&st, keyi-1);
			StackPush(&st, begin);
		}
	}
	
	StackDestroy(&st);
}

//分治法：
//先将待排数据不断二分，直至每组一个数据（此时相当于每组都是有序数列），再通过合并有序序列的方式不断将这些反路劲合并成一个有序序列
void _MergeSort(int* arr, int left, int right, int* tmp)
{
	if (left >= right)
	{
		return;
	}
	int mid = (left + right) / 2;
	//根据mid划分两个序列
	_MergeSort(arr, left, mid, tmp);
	_MergeSort(arr, mid + 1, right, tmp);

	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] < arr[begin2])
		{
			tmp[index++] = arr[begin1++];
		}
		else
		{
			tmp[index++] = arr[begin2++];
		}
	}
	//上一个while循环退出要么begin1序列中数据没放完，要么begin2序列中数据没放完
	//将序列剩下数据放入临时数组中
	while (begin1 <= end1)
	{
		tmp[index++] = arr[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = arr[begin2++];
	}
	//将临时数组的有序数据放回原数组
	int i = left;
	for (i = left; i <= right; i++)
	{
		arr[i] = tmp[i];
	}
}

//时间复杂度为O(n*log n)
void MergeSort(int* arr, int sizeNum)
{
	int* tmp = (int*)calloc(sizeNum, sizeof(int));
	if (!tmp)
		exit(-1);
	_MergeSort(arr, 0, sizeNum - 1, tmp);
	free(tmp);
	tmp = NULL;
}

//计数排序又称鸽巢原理，是对哈希直接定址法的变形应用
//先统计相同元素出现的次数，根据统计结果将序列放回原序列中
//统计数组count大小如何确定，如果申请原数组中最大值+1大小的空间，面对[10001,10009]这样的数组必然造成空格间的浪费
//所以统计数组的大小应该申请max - min + 1空间大小，同时通过数据映射（data->data-min）的方式将数据存储再count数组中
//时间复杂度为O(n+range)、空间复杂度为O(range)
//因此计数排序适合数据较为集中的限定场景
void CountSort(int* arr, int sizeNum)
{
	//找min、max
	int min = arr[0], max = arr[0];
	int i = 0;
	for (i = 1; i < sizeNum; i++)
	{
		if (min > arr[i])
		{
			min = arr[i];
		}
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	//确定count数组大小
	int range = max - min + 1;
	int* count = (int*)calloc(range ,sizeof(int));
	if (!count)
		exit(-1);
	for (i = 0; i < sizeNum; i++)
	{
		int j = arr[i] - min;
		count[j]++;
	}
	//将count还原到原数组中
	int index = 0;
	for (i = 0; i < range; i++)
	{
		while (count[i]--)
		{
			arr[index++] = i + min;
		}
	}
	free(count);
	count = NULL;
}