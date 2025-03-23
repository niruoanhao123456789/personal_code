#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<errno.h>
#include<ctype.h>
#include<stddef.h>

//动态内存管理
//动态内存开辟malloc()		要用头文件<stdlib.h>
//返回申请到的空间的起始地址（类型为void*），申请失败则返回NULL
//参数为申请的字节数
//
// free()释放内存空间
// 
//局部变量和形参在内存里放在栈区，
//而malloc、calloc、realloc、free在堆区
//
//
//int main()
//{
//	int arr[10] = { 0 };
//
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//		printf("%d ", *(p + i));
//	}
//	free(p);
//	p = NULL;//因free(p)后，p指向的内存空间已归还系统，但p仍保留着那部分内存的地址，避免用p再访问那快空间，得将p置空
//
//	return 0;
//	//以上代码如果没有free，但并不意味着申请的内存空间没有回收，只是在程序退出时，系统会自动回收内存空间
//
//	//内存泄露指申请的内存空间不再使用后，没有用free释放空间，导致的内存浪费
//}
//
//int main()
//{
//	while (1)
//	{
//		malloc(1);
//	}
//	return 0;
//}//这个代码很危险

//void* calloc(size_t num,size_t size)
//	 要开辟的元素个数，单个元素的大小
//calloc在开辟内存空间时，还会将这些空间初始化为0
//int main()
//{
//	int arr[10] = { 0 };
//	int* p = (int*)calloc(10, sizeof(int));
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	free(p);
//	p = NULL;
//
//	return 0;
//}

//动态开辟内存大小调整
//void* realloc(void* ptr,size_t size)
//ptr要调整的内存空间的起始地址，size调整后的内存空间新大小
//realloc在申请额外空间时有两种情况（内存申请时可能和其他已使用空间重叠）
//1：在内存里找一整块新空间进行申请,原空间进行释放
//2：在原空间基础上进行扩充申请
//所以返回值有三种：1、NULL（申请失败） 2、新空间起始地址 3、原空间起始地址
//int main()
//{
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//	//p = (int*)realloc(p, 80);//因返回值存在NULL的情况，会使p发生改变而失去原空间的指针，所以不能这样写
//	int* pc = (int*)realloc(p, 80);
//	if (pc != NULL)
//	{
//		p = pc;
//	}
//	free(p);
//	p = NULL;
//	pc = NULL;
//	return 0;
//}
//
//int main()
//{
//	int* p = (int*) realloc(NULL, 40);//某种意义上realloc可实现malloc的功能
//	return 0;
//}

//常见的动态内存错误
//1、对直接NULL解引用操作
//int* p = (int*)malloc(40);
//*p = 20;//未判断p接受到的是否是空指针
// 
//2、对动态开辟空间的越界访问
//int main()
//{
//	int* p = (int*)malloc(40);
//	if (p = NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	int i = 0;
//	for (i = 0; i <= 10; i++)
//	{
//		p[i] = i;//此处存在越界访问
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}
//
//3、对非动态开辟内存使用free
//int main()
//{
//	int a = 10;
//	int* p = &a;
//	free(p);
//	p = NULL;
//	return 0;
//}
//
//4、使用free释放动态开辟内存的一部分
//int main()
//{
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*p = i;
//		p++;
//	}
//	free(p);//因p++使p指向的不是动态开辟的起始地址了，导致free(p)试图释放动态开辟内存的一部分，而错误
//	p = NULL;
//	return 0;
//}
//
//5、对同一动态内存释放多次释放
//
//6、动态开辟内存忘记释放
//void test()
//{
//	int* p = (int*)malloc(40);
//	int n = 0;
//	scanf_s("%d", &n);//如果n被输入了1，return退出了函数，并没有执行到free(p),就会导致内存泄露
//	if (n == 1)
//	{
//		return;
//	}
//	free(p);
//	p = NULL;
//}
//
//int main()
//{
//	test();
//	return 0;
//}
//
//int* test()
//{
//	int* p = (int*)malloc(40);
//	if (NULL == p)
//	{
//		return p;
//	}
//	//……
//	return p;
//}
//int main()
//{
//	int* ret = test();
//	//设计的函数负责申请空间，可函数申请的空间在使用完后不再使用时，却忘记释放了
//	return 0;
//}

//柔性数组
//C99中，结构体最后一个成员允许是未知大小的数组，这就叫做柔性数组
//typedef struct s
//{
//	int i;
//	int a[];//a就是柔性数组，a前面必须有成员
//}s;
//
//int main()
//{
//	//printf("%d\n", sizeof(s));//sizeof()返回的结构体大小是不包括柔性数组的大小
//
//	s* ps = (s*)malloc(sizeof(s )+40);//40是分配给柔性数组的空间大小
//	if (ps == NULL)
//	{
//		return 1;
//	}
//	/*……*/
//	//空间扩容
//	s* ptr = (s*)realloc(ps, sizeof(s) + 80);
//	if (ptr != NULL)
//	{
//		ps = ptr;
//		ptr = NULL;
//	}
//	//……
//	free(ps);
//	ps = NULL;
//
//	return 0;
//}
//
//方案二，非柔性数组
//该方案malloc()次数多，free()也相应增多，容易忘记free导致内存泄露；多次malloc会导致内存空间的碎片化，使内存空间利用率不高
//typedef struct s
//{
//	int i;
//	int* arr;
//}s;
//
//int main()
//{
//	s* ps = (s*)malloc(sizeof(s));
//	if (ps == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	ps->i = 100;
//	ps->arr = (int*)malloc(40);
//	if (ps->arr == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	//使用
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		ps->arr[i] = i;
//		printf("%d ", ps->arr[i]);
//	}
//	//扩容
//	int* ptr = (int*)realloc(ps->arr, 80);
//	if (ptr != NULL)
//	{
//		ps->arr = ptr;
//		ptr = NULL;
//	}
//	//……
//
//	free(ps->arr);
//	free(ps);
//	ps = NULL;
//	return 0;
//}