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
		scanf("%d", &arr[i]);
	}

	//InsertSort(arr, n);
	ShellSort(arr, n);

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
	test1();

	return 0;
}