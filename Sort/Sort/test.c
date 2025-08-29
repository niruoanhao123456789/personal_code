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
		//scanf("%d", &arr[i]);
	}
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	//HeapSort(arr, n);
	//InsertSort(arr, n);
	//ShellSort(arr, n);
	//SelectSort(arr, n);
	//BubbleSort(arr, n);
	//QuickSort(arr, 0, n - 1);
	//QuickSortNorR(arr, 0, n - 1);
	//MergeSort(arr, n);
	//CountSort(arr, n);
	//QuickSort_byIntro(arr, 0, n - 1);

	for(i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	free(arr);
	arr = NULL;
}

void CreateNData()
{
	int n = 10000;
	const char* filename = "NData.txt";
	FILE* fin = fopen(filename, "w");
	if (!fin)
		return;
	for (int i = 0; i < n; i++)
	{
		int x = rand() + i;
		fprintf(fin, "%d\n", x);
	}

	fclose(fin);
	fin = NULL;
}

void test2()
{
	//CreateNData();
	const char* file1 = "file1.txt";
	const char* file2 = "file2.txt";
	const char* mfile = "mfile.txt";

	FILE* fout = fopen("NData.txt", "r");
	if (fout == NULL)
		return;
	ReadNDataToFile(fout, 100, file1);
	ReadNDataToFile(fout, 100, file2);

	while (1)
	{
		MergeFileSort(file1, file2, mfile);
		//删除file1、file2数据
		remove(file1);
		remove(file2);
		//将mfile重命名为file1
		rename(mfile, file1);
		//当读取不到数据时结束循环
		if (ReadNDataToFile(fout, 100, file2) == 0)
			break;
	}

	fclose(fout);
	fout = NULL;
}

int main()
{
	srand((unsigned int)time(NULL));
	//test1();
	test2();

	return 0;
}