#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<errno.h>
#include<ctype.h>
#include<stddef.h>
#include<limits.h>

//函数
//int Add(int x, int y)//Add函数的创建   Add为函数名，()内为该函数的参数 {}内为函数体  int 为该函数的返回值
//{
//	int Z = 0;
//	Z = x + y;
//	return Z;
//}
//上方函数亦可写成如下形式
// int Add(int x, int y)
// {
// return x + y;
// }
// 
//int main()//计算中函数的运用
//{
//	int n1 = 0;
//	int n2 = 0;
//	printf("请输入一个数字，在enter后再输一个数字，即可求和\n");
//	scanf_s("%d %d", &n1, &n2);
//	int sum = Add(n1, n2);//()是Add函数的操作符，Add,n1,n2是其操作数
//	printf("%d\n",sum);
//	int t1 = 250;  //Add函数可反复运用 如下
//	int t2 = 270;
//	int sum1 = Add(t1, t2);
//	printf("%d\n", sum1);
//	return 0;
//}

//系统自带函数如库函数等
//int main()
//{
//	char arr1[20] = { 0 };
//	char arr2[] = "hello,word!";
//	char arr3[] = { 0 };
//	strcpy_s(arr1,20,arr2);//strcpy函数将arr2里的内容拷贝到arr1中 正常来说格式为strcpy( , ) 而vs为中strcpy_s（ ，目标长度的数字， ）
//	printf("%s\n", arr1);
//	long long n;
//	scanf_s("%d", &n);
//	printf("%d\n", n);
//	return 0;
//}

//自定义函数
//ret_type fun_name(paral参数可0个或多个)
//{
//	statement(语句项)函数体;
//}
//int Max(int x, int y)
//{
//	return(x > y ? x : y);
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf_s("%d %d", &a,&b);
//	int t = Max(a,b);
//	printf("%d\n",t);
//	return 0;
//}

//函数的嵌套与链式访问
//函数内部调用其他函数为函数的嵌套（嵌套调用而不是嵌套定义）（函数间地位平等）
//函数内部调用自己为函数式的递归
//链式访问依赖于函数的返回值
//int main()
//{
//	int len = strlen("abcdef");
//	printf("%d\n", len);
//	printf("%d\n", strlen("abcdef"));//链式访问
//
//	printf("%d\n", printf("%d", printf("%d", 43)));//printf的返回值为打印字符的个数 故是4321
//
//	return 0;
//}
//
//void test(void)//在函数中()内填void，来表明该函数不接受参数
//{
//	printf("hehe");
//}
//
//int main()
//{
//	test();
//
//	return 0;
//}

//main函数的参数
//int main(int agrc,char* argv[], char *envp[])
//{
//	return 0;
//}

//函数的声明与定义
//
////int Add(int x, int y);//函数的声明(函数类型 函数名称 参数类型) 如果函数定义写在main函数后面需要声明才能使用
////函数的声明通常放在头文件中.h
//// 
////#include "Add.h" //需新建
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf_s("%d %d", &a,&b);
//	int sum = Add(a, b);
//	printf("%d\n", sum);
//
//	return 0;
//}
//
////int Add(int x, int y)//函数的定义
////{
////	int z = x + y;
////	return z;
////}

//函数的递归:函数调用自身
//接受一个整型（无符号），并按顺序打印其每一位  例如：输入1234，输出1 2 3 4
//void print(unsigned int n)
//{
//	if (n > 9)
//	{
//		print(n / 10);
//	}
//	printf("%d ", n % 10);
//}
//
//int main()
//{
//	unsigned int num = 0;//无符号整型
//	// %d是有符号的整数(会有正负数)
//	// %u是无符号的整数（无负号）
//	scanf_s("%u", &num);
//	print(num);
//	//while (num)
//	//{
//	//	printf("%d ", num % 10);
//	//	num = num / 10;
//	//}		//4 3 2 1
//
//	return 0;
//}
//函数递归需要有停下来的条件，每次递归逐步接近该条件
//栈溢出	《函数栈帧的创建于销毁》
//
//编写函数不创建临时变量，求字符串的长度
//int my_strlen(char* str)	//使用临时变量的函数
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;//找下一个字符
//	}
//	return count;
//}
//
//递归求解
//int my_strlen(char* str)
//{
//	if (*str != '\0')
//	{
//		return 1 + my_strlen(str + 1);
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int	main()
//{
//	char arr[] = "abcde";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}

//函数的递归与迭代
//计算n！
//int fac(int n)//递归实现
//{
//	if (n <= 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return n * fac(n-1);
//	}
//}
//
//int fac(int n)//迭代实现
//{
//	int i = 0;
//	int ret = 1;
//	for (i = 1; i <= n; i++)
//	{
//		ret *= i;
//	}
//	return ret;
//}
//
//int main()
//{
//	int n = 0;
//	scanf_s("%d", &n);
//	int
// ret = fac(n);
//	printf("ret = %d\n", ret);
//
//	return 0;
//}

//函数栈帧的创建与销毁
//该过程的实现在每个编译器下会有差别，但大体逻辑相同
//
//寄存器:
//eax ebx ecx edx
//ebp esp 其中这两个寄存器存放的是地址，而这两个地址是用来维护函数栈帧的
//
//每一个函数的调用都要在栈区创建一块空间
//而栈区的使用习惯是先用高地址再到地址
//ebp存的是栈底指针，esp存的是栈顶指针，每一次函数的调用，esp、ebp两个指针都会指向函数栈帧在栈区的首尾，
//两者中间便是函数在栈区的内存
//


//字符函数与字符串函数
//尝试自己模拟实现这些字符串库函数
// 
//strlen()求字符串长度，计算\0之前的字符个数，返回值是个无符号整型
//size_t my_strlen(const char* str)
//{
//	assert(str);
//	char* cur = str;
//	size_t count = 0;
//	while (*cur != '\0')
//	{
//		count++;
//		cur++;
//	}
//	return count;
// }
//
//strcpy()拷贝字符串到另外一个数组，拷贝内容包括\0，字符数组不能直接赋值，因数组名是个地址，是个常量不能被修改
//strcpy()返回值是目标空间的地址
//int main()
//{
//	char name[6] = "xxxxx";
//	//printf("%zu\n", my_strlen(name));
//
//	char arr[] = { 'a','b','c' };
//	//strcpy_s(name, 5, arr);
//	//用strcpy拷贝字符是不行的，strcpy()需要\0来停止以明确拷贝内容，要求源字符串必须以\0结束
//
//	char arr1[] = "abcdef";
//	//strcpy_s(name, 5, arr1);
//	//arr1的内存要大于name，会造成越界访问，导致strcpy()函数的崩溃，要求目标空间要足够大
//
//	const char* p = "abcdef";
//	char arr2[] = "bit";
//	//strcpy_s(p, 8, arr2);
//	//p指向的是一个常量字符串，strcpy()也会崩溃，要求目标内容要可改变
//	return 0;
//}
//
//模拟实现
//char* my_strcpy(char* destination, const char* source)
//{
//	assert(source);
//	assert(destination);
//	char* ret = destination;
//	while (*destination++ = *source++)
//	{
//		;
//	}
//	*destination = '\0';
//	return ret;
//}
//
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[20] = { 0 };
//	my_strcpy(arr2, arr1);
//	printf("%s\n", my_strcpy(arr2, arr1));
//	return 0;
//}

//strcat()字符串追加
//要求目标空间要足够大，且内容可修改，源字符串要有\0
//返回值也是目标空间的起始地址
//char* my_strcat(char* dest, const char* source)
//{
//	assert(dest && source);
//	char* ret = dest;
//	//先找到目标空间末尾的\0
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//	//拷贝要追加的内容
//	while (*dest++ = *source++)
//	{
//		;
//	}
//	return ret;
//}
//
//int main()
//{
//	char arr1[20] = "hi";
//	//strcat_s(arr1,20," world");//但不能字符串自己追加自己
//	//因在拷贝时其自身的\0被覆盖，导致拷贝过程没有\0来终止过程
//	my_strcat(arr1, " world");
//	printf("%s\n", arr1);
//	return 0;
//}

//strcmp()字符串比较
//比较的是内容，而不是大小
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//		{
//			return 0;
//			break;
//		}
//		str1++;
//		str2++;
//	}
//	return (*str1 - *str2);	
//}
//int main()
//{
//	char arr1[20] = "zhangsan";
//	char arr2[20] = "zhangs";
//	int ret = 0;
//	//arr1与arr2都是数组名，是首元素的地址，所以arr1 == arr2 这个是在比较地址而不是字符串
//	//arr1与arr2在内存中所分配的位置是不同
//	//if (arr1 == arr2)
//	//{
//	//	printf("ok\n");
//	//}
//	//else
//	//{
//	//	printf("err\n");
//	//}
//
//	//if (strcmp(arr1, arr2)==0)
//	//{
//	//	printf("=\n");
//	//}
//	//else if (strcmp(arr1, arr2) > 0)
//	//{
//	//	printf("0>\n");
//	//}
//	//else
//	//{
//	//	printf("<0\n");
//	//}
//
//	ret = my_strcmp(arr1, arr2);
//	if (ret > 0)
//	{
//		printf(">0\n");
//	}
//	else if (ret == 0)
//	{
//		printf("==0\n");
//	}
//	else
//	{
//		printf("<0\n");
//	}
//
//	return 0;
//}

//长度受限制的字符串函数
//strncpy
//strncat
//strncmp
//char* my_strncpy(char* dest, const char* source, size_t num)
//{
//	assert(source);
//	assert(dest);
//	char* str1 = dest;
//	char* str2 = source;
//	while (num)
//	{
//		*str1 = *str2;
//		if (*str2 == '\0')
//		{
//			str1++;
//			num--;
//			continue;
//		}
//		str1++;
//		str2++;
//		num--;
//	}
//	*str1 = '\0';
//
//	return dest;
//}
//
//char* my_strncat(char* dest, const char* source, size_t num)
//{
//	assert(dest);
//	assert(source);
//	char* str1 = dest;
//	char* str2 = source;
//	while (*str1 != '\0')
//	{
//		str1++;
//	}
//	while (num)
//	{
//		*str1 = *str2;
//		if (*str2 == '\0')
//		{
//			str1++;
//			num--;
//			continue;
//		}
//		str1++;
//		str2++;
//		num--;
//	}
//	*str1 = '\0';
//
//	return dest;
//}
//
//int main()
//{
//	//char arr1[10] = "abcdef";
//	//char arr2[10] = "hello bit";
//	////strncpy_s(arr1,10, arr2, 5);
//	////5是要拷贝的字符个数，如果arr2里元素不够则在拷贝时将缺少的部分设为\0
//	//my_strncpy(arr1, arr2, 5);
//	//printf("%s\n", arr1);
//
//	char arr1[20] = "abc";
//	char arr2[20] = "world";
//	//strncat_s(arr1, 20, arr2, 3);
//	//3是要追加的字符个数，在追加完后还会追加上一个\0
//	/*my_strncat(arr1, arr2, 3);
//	printf("%s\n", arr1);*/
//
//	//char arr1[20] = "abcde";
//	//char arr2[20] = "acbde";
//	//int ret = strncmp(arr1, arr2, 3);
//	//if (ret > 0)
//	//{
//	//	printf(">0\n");
//	//}
//	//else if (ret == 0)
//	//{
//	//	printf("=0\n");
//	//}
//	//else
//	//{
//	//	printf("<0\n");
//	//}
//
//	return 0;
//}

//strstr 查找字串的函数
//返回值是字串的首元素地址，如果没有找到字串返回的是NULL
//char* my_strstr(const char* str1, const char* str2)
//{
//	assert(str1, str2);
////	存在一次匹配和多次匹配的情况
////	为了防止str1,str2这两个起始指针发生改变，所以创建s1,s2两个指针变量
//	const char* s1 = str1;
//	const char* s2 = str2;
//	const char* p = str1;//p用来记录找到字串的起始地址
//	while (*p)
//	{
//		s1 = p;
//		s2 = str2;
//		while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return (char*)p;
//		}
//		p++;
//	}
//	return NULL;
//}
//
//int main()
//{
//	char arr1[5] = "abcd";
//	char arr2[20] = "aderabcdefg";
//	//char* ret = strstr(arr2, arr1);
//	char* ret = my_strstr(arr2, arr1);
//	if (ret == NULL)
//	{
//		printf("字串不存在\n");
//	}
//	else
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}

//strtok 切割字符串
//当第一个参数不为NULL时，strtok会找到分隔符并将其改为\0，并保存该位置的地址
//如果第一个参数为NULL时，将从同一个字符串被保存的位置开始，查找下一个分隔符
//如果字符串不存在更多的分隔符时，则会返回NULL
//int main()
//{
//	const char* sep = "@.";//sep是strtok的参数之一，是定义用作于分隔符的字符的集合
//	char arr[20] = "1234567@qq.com";
//	char cp[20] = { 0 };
//	strcpy_s(cp, 20, arr);
//	//由于strtok会改变被分割的字符串，所以给strtok的参数通常是一个字符串的临时拷贝且可被改变
//	char* ptr = NULL;//&ptr是vs的strtok_s用来判断从哪里开始处理字符串的
//
//	/*char* ret = strtok_s(cp, sep,&ptr);
//	printf("%s\n", ret);
//	ret = strtok_s(NULL, sep, &ptr);
//	printf("%s\n", ret);
//	ret = strtok_s(NULL, sep, &ptr);
//	printf("%s\n", ret);*/
//	//因为实际里是不知道cp里有多少个分隔符，且为避免NULL打印，所以有以下写法
//	char* ret = NULL;
//	for (ret = strtok_s(cp, sep, &ptr); ret != NULL; ret = strtok_s(NULL, sep, &ptr))
//	{
//		printf("%s\n", ret);
//	}
//
//	return 0;
//}

//strerror(int num) 字符串错误报告函数
//返回错误码所对应的的错误信息
//C语言的库函数在执行失败时都会设置错误码
//int main()
//{
//	printf("%s\n", strerror(0));
//	//printf("%s\n", strerror_s());
//	printf("%s\n", strerror(1));
//	printf("%s\n", strerror(2));
//	printf("%s\n", strerror(3));
//
//	//errno  C语言设置的一个存放错误码的全局变量
//	//使用需要<errno.h>的头文件
//	FILE* pf = fopen("test.txt", "r");
//	//文件查找的文件得在同一个工程文件里，或者用绝对路径来查找
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;//C语言中main函数返回值为非零时，表示异常退出程序
//	}
//	return 0;
//}

//字符分类函数
//需要头文件<ctype.h>
//int main()
//{
//	//int a = isspace(' ');
//	//printf("%d\n", a);
//
//	//int b = isdigit('0');//是数字字符则返回非零的值，相反的话返回0
//	//printf("%d\n", b);
//
//	//是否是大小写
//	//isupper();
//	//islower();
//
//	//是否是字母
//	//isalpha();
//
//	//是否是字母或数字
//	//isalnum();
//
//	//是否是标点符号
//	//ispunct();
//
//	//图形字符
//	//isgraph();
//
//	//可打印字符
//	//isprint();
//
//	//转化为大小写，如果不是大小写字母则会保留而不会转换
//	//toupper();
//	//tolower();
//	return 0;
//}

//内存函数
//memcpy(void*,const void*,unsigned int num)内存拷贝
//memcpy是负责拷贝两块独立空间里的数据
//要实现重叠内存的拷贝，要用memmove()
//void* my_memcpy(void* dest, const void* src, unsigned int num)
//{
//	assert(dest && src);
//	void* ret = dest;
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//	return ret;
//}
//
//void* my_memmove(void* dest, const void* src, unsigned int num)
//{
//	assert(dest && src);
//	void* ret = dest;
//	if (dest < src)
//	{
//		//从前向后拷贝
//		while (num--)
//		{
//			*(char*)dest = *(char*)src;
//			dest = (char*)dest + 1;
//			src = (char*)src + 1;
//		}
//	}
//	else
//	{
//		//从后向前拷贝
//		while (num--)
//		{
//			*((char*)dest + num) = *((char*)src + num);
//		}
//	}
//	return ret;
//}
//
//int main()
//{
//	int i = 0;
//	int arr1[] = { 1,2,3,4,5,6,7,8,9 };
//	int arr2[10] = { 0 };
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	//memcpy(arr2, arr1, 36);//36为要拷贝的字节数(9*4)
//	//my_memcpy(arr2, arr1, 36);
//
//	//memmove(arr1 + 2, arr1, 20);
//	my_memmove(arr1 + 2, arr1, 20);
//
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//	return 0;
//}

//memcmp()内存比较
//int my_memcmp(const void* ptr1, const void* ptr2, unsigned int num)
//{
//	assert(ptr1 && ptr2);
//	while (num--)
//	{
//		if (*(char*)ptr1 == *(char*)ptr2)
//		{
//			ptr1 = (char*)ptr1 + 1;
//			ptr2 = (char*)ptr2 + 1;
//		}
//		else
//		{
//			return (*(char*)ptr1 - *(char*)ptr2);
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6 };
//	int arr2[] = { 1,3,2 };
//	//int ret = memcmp(arr1, arr2, 12);
//	int ret = my_memcmp(arr1, arr2, 12);
//	printf("%d\n", ret);
//	return 0;
//}

//memset()内存设置
//int main()
//{
//	char arr[] = "Hello bit";
//	memset(arr, 'x', 5);
//	memset(arr + 6, 'y', 3);
//	printf("%s\n", arr);
//
//	int arr1[10] = { 0 };
//	memset(arr1,1, 40);//这里并不能让arr1数组全部初始化为1，因memset()是按一个字节进行操作的
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d\n", arr1[i]);
//	}
//
//	return 0;
//}

//atoi() 将数字字符串转化为整型  需要用到<stdlib.h>的头文件
//int main()
//{
//	char arr[] = "    -1234 5abc6";
//	char arr1[] = "    -a1234 5abc6";
//	//可以转换负数，遇到非数字字符会停止转换，但最前面是空格会自动跳过,负号后面是非数字字符则会视为空字符串返回0
//	int ret = atoi(arr);
//	int ret1 = atoi(arr1);
//
//	printf("%d\n", ret);
//	printf("%d\n", ret1);
//
//	return 0;
//}
//
//atoi()模拟实现
//要考虑的问题：
//1、空指针 2、空字符串 3、空格 4、+- 5、越界 6、非数字字符
//enum Status
//{
//	VAULE,
//	INVAULE
//}sta = INVAULE;//可设这样的全局变量来判断返回0是因为字符0还是空字符
//
//int my_atoi(const char* str)
//{
//	assert(str);
//	sta = INVAULE;
//	long long ret = 0;
//	int flag = 1;
//	if (*str == '\0')
//	{
//		return 0;
//	}
//	while (isspace(*str))
//	{
//		str++;
//	}
//	if (*str == '+')
//	{
//		flag = 1;
//		str++;
//	}
//	else if(*str == '-')
//	{
//		flag = -1;
//		str++;
//	}
//	while (*str)
//	{
//		if (*str < '0' || *str>'9')
//		{
//			break;
//		}
//		ret = ret * 10 + flag*(*str - '0');
//		//考虑是否越界
//		if (ret > INT_MAX || ret < INT_MIN)//要用这两个宏定义需要<limits.h>头文件
//		{
//			return 0;
//		}
//		str++;
//	}
//	sta = VAULE;
//	return (int)ret;
//}
//
//int main()
//{
//	char arr[] = "  -123456 12";
//	int ret = my_atoi(arr);
//	if (sta)
//	{
//		printf("非法返回 %d\n", ret);
//	}
//	else
//	{
//		printf("%d\n", ret);
//	}
//
//	return 0;
//}