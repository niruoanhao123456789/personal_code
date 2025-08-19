#include"Sort.h"

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