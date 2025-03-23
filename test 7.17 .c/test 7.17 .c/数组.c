#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<errno.h>
#include<ctype.h>
#include<stddef.h>

//数组 arr [ 字符大小 ]={ 数组的内容 }
//数组的定义：一组相同类型的数的集合 
//数组的下标：数组里的数从0开始编号排序  用下标方便从数组中访问所需的数
//随着数组下标的增长，元素的地址也在规律地递增，可知数组在内存中是连续存放的
//数组的越界：若果使用的下标小于0，或大于[]限定，就造成数组的越界
//数组本身就是一个地址，故在scanf()中可不用&
//int main ()
//{
//	int arr1[10] = { 10,11,12,13,14,15,16,17,18,19, };
//	int arr2[14] = { 10,11,12,13,14,15,16,17,18,19, }; //不完全初始化，剩余部分默认是0
//	printf("数组arr1中第6号元素\n%d\n", arr[6]);
//	int i = 0;
//	while (i < 10)
//	{
//		printf("%d  ", arr[i]);
//		i++; //亦可写成i=i+1;
//	}
//	return 0;
//}

//一维数组
//数组的创建
//创建方式：type_t	arr_name	[const_n]
//			 类型	 名称	 常量表达式，规定数组大小
//int main()
//{
//	////下面代码需在支持C99标准的编译器上
//	//int n = 0;
//	//scanf_s("%d", &n);
//	//int arr[n];//这种数组不能初始化
//
//	//不完全初始化，剩余元素默认设为0
//	int arr1[10] = { 1,2,3 };
//	char ch1[10] = { 'a','b','c' };
//	// a b c 0 0 0 0 0 0 0
//	char ch2[10] = "abc";
//	// a b c \0 0 0 0 0 0 0
//	char ch3[] = { 'a','b','c' };
//	// a b c
//	char ch4[] = "abc";
//	// a b c \0
//
//	return 0;
//}

//二维数组
//可将二维数组理解为一维数组的数组
//二维数组在内存中也是连续存放的
//int main()
//{
//	// type_t arr_name[const_n][const_n];
//	//				 行([]内可省)  列
//	//以此类推三维数组也只能省第一个[]内的数
//	//下标一样从0数起
//	int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};//三行四列的数组的创建,这样填入，会按顺序将元素填入数组
//	int arr2[3][4] = { {1,2},{3,4},{5,6} };//大括号中加大括号来分行
//	//				  第一行 第二行 第三行
//	int arr3[][4] = { {1,2,3},{2,3,4,5} };
//	//	此处就会默认为两行
//	char ch[5][10];//五行十个字符的数组
//	int arr1[4][4] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
//	int i = 0;
//	//for (i = 0; i < 4; i++)
//	//{
//	//	int j = 0;
//	//	for (j = 0; j < 4; j++)
//	//	{
//	//		scanf_s("%d", &arr1[i][j]);
//	//	}
//	//}
//	// 
//	//访问打印整个数组
//	for (i = 0; i < 4; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 4; j++)
//		{
//			printf("%2d ", arr1[i][j]);
//			printf("&arr1[%d][%d] = %p", i, j, &arr1[i][j]);
//		}
//		printf("\n");
//	}
//	//访问打印单个元素
//	//printf("%d\n", arr2[1][0]);
//
//	return 0;
//}

//数组作为函数参数
//数组传参时,形参有两种写法：1、数组 2、指针
// 1、错误写法
//void bubble_sort(int arr[]) //地址是由指针来接受
//{
//	//确定趟数
//	int sz = sizeof(arr)/sizeof(arr[0]);//1
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] < arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//正确写法：
//void bubble_sort(int arr[], int sz)//接收数组地址时一定要写成arr[],不能漏了[]
//{
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if(arr[j]<arr[j+1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//2、
//void bubble_sort(int* arr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int j = 0;
//		for (j = sz - 2; j >= i; j--)
//		{
//			if (arr[j] < arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//
//int main()
//{
//	//把下列数组元素按升序排列，冒泡排序
//	//冒泡排序核心：两个相邻元素进行比较
//	int arr[] = { 8,9,7,3,5,4,6,0,1,2 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	bubble_sort(arr,sz);//数组名本质上是数组首元素的地址
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

//数组名：本质上是数组首元素的地址
//但有两个例外：
//1、sizeof(arr)中数组名表示整个数组，计算整个数组的大小，单位为比特
//2、&数组名，这里数组名表示整个数组，取出整个数组的地址
//int main()
//{
//	int arr[10] = { 0 };
//	printf("%p\n", arr);
//	printf("%p\n", arr[0]);
//	printf("%p\n", &arr);
//
//	return 0;
//}
//
//二维数组数组名的理解
//二维数组arr[0]表示其一行数组的地址
//int main()
//{
//	int arr[3][4] = { 0 };
//	//计算行数 整个数组的大小除以一行数组的大小
//	int sz1 = sizeof(arr) / sizeof(arr[0]);
//	printf("%d\n", sz1);
//	//计算列数 一行数组的大小除以单个元素的大小
//	int sz2 = sizeof(arr[0]) / sizeof(arr[0][0]);
//	printf("%d\n", sz2);
//
//	return 0;
//}