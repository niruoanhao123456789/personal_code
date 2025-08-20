#include"Sort.h"

void SelectSort(int* arr, int sizeNum)
{
	int i = 0;
	for (i = 0; i < sizeNum - 1; i++)
	{
		int max = i;
		int j = 0;
		for (j = i + 1; j < sizeNum; j++)
		{
			if (arr[i] < arr[j])
			{
				max = j;
			}
		}
		if (max != i)
		{
			int tmp = arr[i];
			arr[i] = arr[max];
			arr[max] = tmp;
		}
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