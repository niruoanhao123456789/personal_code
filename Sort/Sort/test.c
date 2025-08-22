#include"Sort.h"

void test1()
{
	int n = 0;
	scanf("%d", &n);
	int* arr = (int*)calloc(n, sizeof(int));
	if (arr == NULL)
		exit(-1);
	int i = 0;
	for (i = 0; i < n; i++)
	{
		arr[i] = rand() % n + 1;
	}
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	//InsertSort(arr, n);
	//ShellSort(arr, n);
	//SelectSort(arr, n);
	//BubbleSort(arr, n);
	//QuickSort(arr, 0, n - 1);
	QuickSortNorR(arr, 0, n - 1);

	for(i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	free(arr);
	arr = NULL;
}

int main()
{
	srand((unsigned int)time(NULL));
	test1();

	return 0;
}