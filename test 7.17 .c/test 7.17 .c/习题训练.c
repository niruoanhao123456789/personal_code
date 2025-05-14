//输出1-100的奇数（if的使用）
//#include <stdio.h>
//
//int main()
//{
//	int a = 1;
//	while ( a <= 100 )
//	{
//		if (a % 2 == 1)
//		{
//			printf("%d\n", a);
//		}
//		a++;
//	}
//	return 0;
//}


//只打印数字字符跳过其他字符(while使用)
//#include <stdio.h>
//
//int main()
//{
//	char ch = '\0';
//	while ((ch = getchar()) != EOF)
//	{
//		if (ch < '0' || ch>'9')
//			continue;
//		 putchar(ch);
//	}
//	return 0;
//}


//计算n!的阶乘(for循环与递归实现)
//#include<stdio.h>
// 
// //n! = n * (n-1)!
// * …… * 2 * 1
//int factorial(int n)
//{
//	int ret = 1;
//	if (n > 2)
//	{
//		ret = n * factorial(n - 1);
//	}
//	else
//	{
//		ret *= n;
//	}
//	return ret;
//}
// 
//int main()
//{
//	int i = 1;
//	int n = 0;
//	int ret = 1;
//	scanf_s("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		ret = ret * i;
//	}
//		printf("%d\n", ret);
//	return 0;
//}
// 
//计算1!+2!+……+t!
//#include<stdio.h>
// 
//int main()
//{
//	int i = 1;
//	int n = 0; 
//	int ret = 1;
//	int sum = 0;
//	int t = 0;
//	scanf_s("%d", &t);
//	//for (n = 1; n <=t; n++)
//	//{
//	//	ret = 1;
//	//	for (i = 1; i <= n; i++)
//
//	//	{
//	//		ret = ret * i;
//	//		
//	//	}
//	//	sum += ret;
//	//}
//	for (n = 1; n <= t; n++)
//	{
//		ret *= n;
//		sum += ret;
//	}
//	printf("%d\n", sum);
//	return 0;
//}


//在有序数组中找某个数字n
//#include<stdio.h>  //一个个找
// 
//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,8,9,10};
//	int k = 7;
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		if (arr[i] == k)
//		{
//			printf("下标为:%d\n", i);
//			break;
//		}
//	}
//	if (i == sz)
//	{
//		printf("找不到\n");
//	}
//	return 0;
//}
// 
//二分查找（要求数据要明确且有序）
//#include<stdio.h>
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int right = sz - 1;
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;	//或int mid = left +(left - right)/2;
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			printf("找到了，下标为：%d\n", mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("找不到\n");
//	}
//	return 0;
//}


//演示多个字符从两端移动向中间靠拢
//#include<stdio.h>
//#include<string.h>
//#include<windows.h>
//#include<stdlib.h>
//
//int main()
//{
//	char arr1[] = "welcome here !!!";
//	char arr2[] = "################";
//
//	int left = 0;
//	int right = strlen(arr2) - 1;  //int right = sizeof(arr2)/sizeof(arr2[0])-2;
//
//	while (left <= right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s", arr2);
//		Sleep(1000);
//		system("cls");
//
//		left++;
//		right--;
//	}
//	return 0;
//}


//用户登录输入密码，只能输入三次，如果密码正确则提示登录成功，三次都错误则退出程序
//假设密码为“abcdef”
//#include<stdio.h>
//#include<string.h>
// 
//int main()
//{
//	int i = 0;
//	char password[20] = { 0 };
//	for (i = 1; i <= 3; i++)
//	{
//		printf("请输入密码：");
//		scanf_s("%s", password,20);
// //vs的scanf_s在输入字符串时要像一行这样加上字符串的大小
// //scanf读取到空格时也会停下
//		if (strcmp(password,"abcdef") == 0)	//比较两个字符串是否相等应该用strcmp这个库函数,如果返回值为0则两字符串相等
//		{
//			printf("登录成功!\n");
//			break;
//		}
//		else
//		{
//			printf("密码错误\n");
//		}
//	}
//
//	if (i = 4)
//	{
//		printf("三次密码均输入错误，退出程序\n");
//	}
//
//	return 0;
//}  


//猜数字游戏初始界面
//时间戳
//#include<stdio.h>
//#include<stdlib.h>	//rand的头文件
//#include<time.h>	//time函数生成时间戳的头文件
//
//void menu()
//{
//	printf("									\n");
//	printf("			 PLAY输入1		        \n");
//	printf("			 EXIT输入0				\n");
//	printf("									\n");
//} 
//
//void game()
//{
//	int guess = 0;
//	//srand((unsigned int)time(NULL));//将时间戳传给srand确保随机数不同  time(指针)是一个整数，time函数使用时间戳
//	int ret = rand()%100+1;//此处生成1~100的数 rand生成随机数的函数 其范围为0~RAND_MAX(32767)
//	while (1)
//	{
//		printf("请猜一个数字：");
//		scanf_s("%d", &guess);
//		if (guess == ret)
//		{
//			printf("猜对了！\n");
//			break;
//		}
//		else if (guess < ret)
//		{
//			printf("猜小了\n");
//		}
//		else
//		{
//			printf("猜大了\n");
//		}
//	}
//	printf("正确答案为：");
//	printf("%d\n", ret);
//}
//
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));//也可以把这个放在这里会更有随机性 NULL为空指针值为0 srand()内得为整型  srand函数设置随机值生成节点
//	do
//	{
//		menu();
//		printf("请选择数字:\n");
//		scanf_s("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("猜数字\n");
//			game();
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("输入错误，请重新选择\n");
//			continue;
//		}
//	} while (input);
//	return 0;
//}


//一分钟关机程序
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//int main()
//{
//	char input[20] = { 0 };
//	system("shutdowm -s -t 60"); //shutdown这存在问题
//again:
//	printf("请注意电脑将60秒内关机，要停止关机请输入：haha\n");
//	printf("请输入：");
//	scanf_s("%s",input);
//	if (strcmp(input, "haha") == 0)
//	{
//		system("shutdown -a");
//		printf("成功停止关机");
//	}
//	else
//	{
//		printf("请重新输入: 否者继续关机");
//		goto again;
//	}
//	return 0;
//}


//交换两个整型变量的函数 函数的理解
//#include<stdio.h>
//
////void Swap(int x, int y)//此处x y为形式参数
////{
////	int z = 0;
////	z = x;
////	x = y;
////	y = z;
////} //函数中要改变a、b的值时错误案例
//
//void Swap(int* px, int* py)//此处x y为形式参数
//{
//	int z = *px;//a
//	*px = *py;//a=b
//	*py = z;//b=a
//} //用指针的方式在相同的地址实现遥控改变形参与实参  传址调用
//
//int Add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//} //因用Add将a、b相加过程中不用改变实参，所以其不用传址调用而用形参
//
////当实参传递给形参时，形参是实参的临时拷贝（两者的地址不一样） 传值调用
////形参的改变不会影响实参，故下面主函数前后输出的a b一样
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf_s("%d %d", &a, &b);//此处a b为实参
//	printf("交换前 a=%d,b=%d\n", a, b);
//	int z = Add(a, b);
//	printf("交换前的a、b相加的和为：%d\n", z);
//	//Swap(a, b);//这个错误案例
//	Swap(&a, &b);
//	printf("交换后 a=%d,b=%d\n", a, b);
//
//	return 0;
//}
//
////int main()
////{
////	int a = 0;
////	int* p = &a;
////	a = 20;//(直接改)
////	*p = 30;//（间接改）
////	return 0;
////}


/*//打印100-200的素数/质数
#include<stdio.h>
#include<math.h>

int main()
{
	int i = 0;
	int count = 0;
	//因素数不会是偶数，故缩小数据范围从奇数里检索
	//for (i = 101; i<=200; i+=2)	 法三

	for (i = 100; i <= 200; i++) //判断100 - 200的数是否为素数，先生成100到200的数
	{
		//拿2 - i-1的数字去试除i 来判断i是否为素数
		int j = 0;
		int flag = 1;//用这个1来表示真，是素数  flag意义为 记：

		//非素数的因式小于其本身-1，可用此判断是否为素数
		//for (j = 2; j <= i - 1; j++)	//法一
		// 
		//一个非素数的其中一个因式（非1）小于等于其开平方后的数 故用此方法改进
		for(j = 2;j <= sqrt(i);j++) //sqrt()开平方 需要用头文件<math.h>	 法二
		{
			if (i % j == 0)
			{
				flag = 0;// 记0时为假，即不是素数
				break;
			}
		}
		if (flag == 1)
		{
			count++;
			printf("%d ", i);
		}
	}
  printf("\n素数的个数count = %d\n", count);
	return 0;
}

//函数版
#include<stdio.h>
#include<math.h>

int is_it(int a)
{
	int z = 0;
	int j = 0;
	int flag = 1;
	for (j = 2; j <= sqrt(a); j++)
	{
		if (a % j == 0)
		{
			flag = 0;
			break;
		}
		else
		{
			flag = 1;
		}
	}
	return flag;
}
//或
int is_it(int a)
{
	int j = 0;
	for (j = 2; j <= sqrt(a); j++)
	{
		if (a % j == 0)
		{
			return 0;//return 一当被执行即结束该函数，所以不用break
		}
	}
	return 1;
}

int main()
{
	int i = 0;
	int count = 0;
	for (i = 101; i <= 200; i += 2)
	{
		if (is_it(i) == 1)
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\n素数个数是：%d\n", count);
	return 0;
}*/


//打印1000 - 2000之间的闰年
//能被4整除，但不能被100整除的年份
//能被400整除的年份
//#include<stdio.h>
//
//int is_leap_year(int x)
//{
//	if ((x % 4 == 0) && (x % 100 != 0) || (x % 400 == 0))
//	{
//		return 1;
//	}
//	return 0;
//}
//
//int main()
//{
//	int year = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		//判断是不是闰年
//		//if (year % 4 == 0)
//		//{
//		//	if (year % 100 != 0)
//		//	{
//		//		printf("%d ", year);
//		//	}
//
//		//}
//		//if (year % 400 == 0)
//		//{
//		//	printf("%d ", year);
//		//}
//		////or
//		//if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
//		//{
//		//	printf("%d ", year);
//		//}
//
//		if (is_leap_year(year))
//		{
//			printf("%d ", year);
//		}
//	}
//	return 0;
//}


////实现整型有序数组二分查找的函数
////注：写函数之前先想其怎么用，再去写函数
//#include<stdio.h>
//
// 注：数组传参实际上传递的是数组元素的地址，而不是整个数组
//	   因此在函数中计算数组元素个数是不可行的
//int binary_search(int arr[], int k, int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	int mid = left + (right - left) / 2;
//	while (left <= right)
//	{
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 0;
//	printf("请输入1-10的数\n");
//	scanf_s("%d", &k);
//	//函数中如果找到，则返回下标，找不到则返回-1
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = binary_search(arr, k, sz);
//	if (ret == -1)
//	{
//		printf("找不到\n");
//	}
//	else
//	{
//		printf("找到了，下表为:%d\n", ret);
//	}
//
//	return 0;
//}


//一个每次调用函数就使num +1的函数
//写函数时不建议用全局变量
//#include<stdio.h>
//
//要用函数使函数外变量的值发生改变要传值调用
//void Add(int* p)
//{
//	(*p)++;
//}
//
//int main()
//{
//	int num = 0;
//	Add(&num);
//	printf("%d\n",num);//1
//	return 0;
//}
////or
//int Add(int n)
//{
//	return n = n+1;
//}
//
//int main()
//{
//	int num = 0;
//	num = Add(num);
//	printf("%d\n", num);
//	return 0;
//}


//求斐波那契数列第n项
//#include<stdio.h>
//
//int Fib(int n)
//{
//	if (n <= 2)
//	{
//		return 1;
//	}
//	else
//	{
//		return Fib(n - 1) + Fib(n - 2);
//	}
//}
//
//int Fib1(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	while (n >= 3)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//
//int main()
//{
//	int n = 0;
//	scanf_s("%d", &n);
//	int ret = Fib(n);
//	printf("%d\n", ret);
//	ret = Fib1(n);
//	printf("%d\n", ret);
//
//	return 0;
//}
//汉诺塔,青蛙跳台


//将三个数从大到小输出
//#include<stdio.h>
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	//输入
//	scanf_s("%d %d %d", &a, &b, &c);
//	//调整
//	int tmp = 0;
//	if (a < b)
//	{
//		tmp = a;
//		a = b;
//		b = tmp;
//	}
//	if (a < c)
//	{
//		tmp = a;
//		a = c;
//		c = tmp;
//	}
//	if (b < c)
//	{
//		tmp = b;
//		b = c;
//		c = tmp;
//	}
//	//输出
//	printf("%d %d %d\n", a,b,c);
//	
//	return 0;
//}
//还可采用函数


//打印1-100中3的倍数
//#include<stdio.h>
//
//int main()
//{
//	int i = 0;
//	//for (i = 1; i <= 100; i++)
//	//{
//	//	if (i % 3 == 0)
//	//	{
//	//		printf("%d ", i);
//	//	}
//	//}
//
//	for (i = 3; i <= 100; i += 3)
//	{
//		printf("%d ", i);
//	}
//	return 0;
//}


//给定两个整数，求二者的最大公因数
//#include<stdio.h>
//
//最大公因数不会大于两个数的最小值
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf_s("%d %d", &a, &b);
//	int min = (a < b ? a : b);
//	while (1)
//	{
//		if (a % min == 0 && b % min == 0)
//		{
//			break;
//		}
//		min--;
//	}
//	printf("%d\n", min);
//
//	return 0;
//}
//
//辗转相除法
// a % b = c,if c != 0,那就b % c = d（这样持续直到两个数取模结果为0）if d == 0,那么c就是a与b的最大公因数
//若要求a,b最小公倍数i，可用到其最大公因数c，i = a * b / c
//#include<stdio.h>
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	scanf_s("%d %d", &a, &b);
//	while (c = a % b)
//	{
//		a = b;
//		b = c;
//	}
//	printf("%d\n", b);
//
//	return 0;
//}


//数一下1-100的整数中有多少个数字9
//分别判断个位与十位是否有9
//#include<stdio.h>
//
//int main()
//{
//	int count = 0;
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		//个位
//		if (i % 10 == 9)
//		{
//			count++;
//		}
//		//十位
//		if (i / 10 == 9)
//		{
//			count++;
//		}
//	}
//	printf("count = %d\n", count);
//
//	return 0;
//}


//计算1/1 - 1/2 + 1/3 - 1/4 + …… - 1/100的值 （1/n） //注意小数的写法
//#include<stdio.h>
//
//int main()
//{
//	int n = 0;
//	double sum = 0;
//	int flag = 1;
//
//	for (n = 1; n <= 4; n++)
//	{
//		sum += flag * (1.0 / n);
//		flag *= -1;
//	}
//
//	printf("%lf\n", sum);
//
//	return 0;
//}


//求十个整数中最大的数
//#include<stdio.h>
//
//int main()
//{
//	int arr[10] = {0};
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		scanf_s("%d", &arr[i]);
//	}
//	int max = arr[0];
//	for (i = 1; i < 10; i++)
//	{
//		if (max < arr[i])
//		{
//			max = arr[i];
//		}
//	}
//	printf("%d\n", max);
//
//	return 0;
//}


//打印乘法口诀表（循环）
//1*1 = 1
//1*2 = 2  2*2 = 4
//#include<stdio.h>
//
//int main()
//{
//	int i = 0;
//	//打印行
//	for (i = 1; i <= 9; i++)
//	{
//		int j = 0;
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%2d ", j, i, i * j);//%2d(右对齐) 打印两位数，输入的是一位数的话就打印空格加数字；而%d打印一位数；%-2d（左对齐）
//		}
//		printf("\n");
//	}
//
//	return 0;
//}


//用函数的递归实现n的k次方
 //n*n (k-1)
 //n*n*n (k-2)
//#include <stdio.h>
//
//double Power_of(double n, int k, int i)
//{
//	if (k > 0)
//	{
//		if (i <= k - 1)
//		{
//			i++;
//			n = n * Power_of(n, k, i);
//		}
//		return n;
//	}
//	else if (k == 0)
//		return 1;
//	else
//	{
//		n = 1.0 / Power_of(n, -k, i);
//		return n;
//	}
//}
//
//int main()
//{
//	double n = 0;
//	int k = 0;
//	int i = 1;
//	scanf_s("%lf %d", &n, &k);
//	double ret = Power_of(n, k,i);
//	printf("%lf\n", ret);
//
//	return 0;
//}


//小乐乐走台阶(青蛙跳桥)	变种《剑指offer》 - 50道
//共有n(1<= n <= 30)个台阶，乐乐可一次走一阶或两阶，请问他有几种走法
//#include<stdio.h>
//
//int Fib(int n)
//{
//	if (n <= 2)
//	{
//		return n;
//	}
//	else
//	{
//		return Fib(n - 1) + Fib(n - 2);
//	}
//}
//
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	again:
//	scanf_s("%d", &n);
//	if (n >= 1 && n <= 30)
//	{
//		ret = Fib(n);
//	}
//	else
//	{
//		goto again;
//	}
//	printf("%d\n", ret);
//
//	return 0;
//}


//#include<stdio.h>
//
//int main()
//{
//	int arr[4];
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		scanf_s("%d", &arr[i]);
//	}
//
//	for (i = 0; i < 4; i++)
//	{
//		printf("%d", arr[i]);
//	}
//
//	return 0;
//}


//字符串逆序(改变数组本身)
//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//	char arr[] = "abcedfg";
//	int left = 0;
//	int right = strlen(arr) - 1;
//	while (left < right)
//	{
//		char tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//	printf("%s\n", arr);
//	return 0;
//}
//
//指针版
//void reverse(char* str)
//{
//	char tmp = *str;//把a从数组中拿出
//	int len = strlen(str);
//	*str = *(str + len - 1);//将末尾的g放到首位去
//	*(str + len - 1) = '\0';//在末尾上放置\0，实质上改变了数组的长度
//	if (strlen(str + 1) >= 2)//要求数组里有两个元素来交换位置
//	{
//		reverse(str + 1);
//	}
//	*(str + len - 1) = tmp;
//}
//
//void reverse(char arr[], int left, int right)
//{
//	char tmp = arr[left];
//	arr[left] = arr[right];
//	arr[right] = tmp;
//	if ((int)left < (int)right)
//	{
//		reverse(arr, left + 1, right - 1);
//	}
//}
//
//int main()
//{
//	char arr[] = "abcedfg";
//	int left = 0;
//	int right = strlen(arr) - 1;
//	reverse(arr, left, right);
//	printf("%s\n", arr);
//	return 0;
//}


//输入一个值，返回组成它的数字之和
//(1234)
//4+(123)
//4+3+(12)
//#include<stdio.h>
//
//int Digitsum(unsigned int n)
//{
//	int i = 0;
//	i += n % 10;
//	if (n%10)
//	{
//		i += Digitsum(n / 10);
//	}
//	return i;
//
//	//或
//	//if (n > 9)
//	//{
//	//	return Digitsum(n / 10) + n % 10;
//	//}
//	//else
//	//{
//	//	return n;
//	//}
//}
//
//int main()
//{
//	unsigned int n = 0;
//	scanf_s("%u", &n);
//	int sum = Digitsum(n);
//	printf("%d\n", sum);
//	return 0;
//}


//两个数组内容交换（两数组一样大）
//#include<stdio.h>
//
//int main()
//{
//	int arr1[] = { 1,3,5,7,9 };
//	int arr2[] = { 2,4,6,8,10 };
//	int i = 0;
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	for (i = 0; i < sz; i++)
//	{
//		int tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	printf("\n");
//
//	return 0;
//}


//不创建临时变量，实现两个数的交换
//int main()
//{
//	int a = 3;
//	int b = 5;
//	//printf("交换前a = %d, b =%d\n", a, b);
//	//a = a + b;//8
//	//b = a - b;//3
//	//a = a - b;//5
//	//printf("交换后a = %d, b = %d\n", a, b);
//	//以上存在溢出问题
//	// 0 ^ a = a	a ^ a = 0
//	printf("打印前a = %d b = %d\n",a,b);
//	a = a ^ b;//6
//	b = a ^ b;//3
//	a = a ^ b;
// //0011
// //0101
// //0110  6
// //0101  
// //0011  3
// //0110
// //0101  5
// 
//	printf("打印前a = %d b = %d\n",a,b);
//
//	return 0;
//}


//求一个整数在内存中二进制中1的个数(求补码中1的个数)
//a & 1 为a补码末位的数
//#include<stdio.h>
//
// int NumberOf1(int n ) 
//{
//	int num = 0;
//	while (n)
//	{
//		n = n & (n - 1);
//		num++;
//	}
//	return num;
//}
// 
//int main()
//{
//	int a = 0;
//	int num = 0;
//	int sz = 0;
//	int i = 0;
//	scanf_s("%d", &a);
//	sz = sizeof(a);
//	for (i = 1; i <= sz; i++)
//	{
//		if (a & 1)
//		{
//			num++;
//		}
//		a >>= 1;
//	}
//	printf("%d\n", num);
//	return 0;
//}


//判断下列所打印的sizeof的大小
//#include<stdio.h>
//
//void test1(int arr[])
//{
//	printf("(3): %d\n", sizeof(arr));
//}
//
//void test2(char ch[])
//{
//	printf("(4): %d\n", sizeof(ch));
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	char ch[10] = { 0 };
//	printf("(1): %d\n", sizeof(arr));
//	printf("(2): %d\n", sizeof(ch));
//	test1(arr);//由于数组传参时给的是首元素的地址，其本质是指针，无论是数字还是字符，其大小都是固定的 4/8比特
//	test2(ch);
//
//	return 0;
//}


//序列中删除指定的数字
//输入序列长度n(1<= n <= 50),再分别输入n个数字，最后输入要删除的数字，对删除后的序列每个数用空格隔开进行打印
//#include<stdio.h>
//
//int main()
//{
//	int n = 0;
//	scanf_s("%d", &n);
//	int arr[50];
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf_s("%d ", &arr[i]);
//	}
//	int k = 0;
//	scanf_s("%d", &k);
//	//法一：创建另一个数组来接受不用删除的
//	//int arr1[50];
//	//int j = 0;
//	//for (i = 0; i < n; i++)
//	//{
//	//	if (arr[i] != k)
//	//	{
//	//		arr1[j] = arr[i];
//	//		j++;
//	//	}
//	//}
//	//for (i = 0; i < j; i++)
//	//{
//	//	printf("%d ", arr1[i]);
//	//}
//
//	//法二：更改数组内部
//	int j = 0;
//	for (i = 0; i < n; i++)
//	{
//		if (arr[i] != k)
//		{
//			arr[j++] = arr[i];
//		}
//	}
//	for (i = 0; i < j; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}


//广工新生训练营Day1
//#include<stdio.h>
//
//int main()
//{
//	int n = 0;
//	scanf_s("%d", &n);
//	int arr[200000] = { 0 };
//	int i = 0;
//	for (i = 0; i < n-1; i++)
//	{
//	again:
//		scanf_s("%d ", &arr[i]);
//		if (arr[i] != 1 && arr[i] != 0)
//			goto again;
//	}
//	for (i = (n - 2); i >= 0; i--)
//	{
//		if (arr[i] != arr[n - 1])
//			break;
//	}
//	printf("%d\n", i + 1);
//
//	return 0;
//}


//输入n（n<10000）,再分别输入n个成绩（0 - 100），最后输出其中成绩最高和最低之间的差
//#include<stdio.h>
//
//int main()
//{
//	int n = 0;
//	scanf_s("%d", &n);
//	int arr[10000] = { 0 };
//	int i = 0;
//	int max = 0;
//	int min = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf_s("%d ", &arr[i]);//对与这种题目的启示是在写代码时想一下如何在一些步骤中能完成的东西先完成，来简化代码
//		if (max < arr[i])
//		{
//			max = arr[i];
//		}
//		if (min > arr[i])
//		{
//			min = arr[i];
//		}
//	}
//	printf("%d\n", max - min);
//
//	return 0;
//}


//大小写字母转换，多组输入，每行输入一个字母 (考察ASCII值)
//大写字母的ASCII值 + 32 = 小写字母的ASCII值
// scanf("%c",&a) 读取成功会返回1，读取失败会返回EOF
//因scanf如果读取成功会返回其读取数据的个数
// islower()是判断字符是否为小写字母的函数
// isupper()是判断字符是否为大写字母的函数
// tolower()将大写字母转化为小写字母的函数
// toupper()将小写字母转化为大写字母的函数
//以上四个函数需要用到库函数<ctype.h>
//#include<stdio.h>
//#include<ctype.h>
//
//int main()
//{
//	char ch = 0;
//	while (scanf_s("%c", &ch) == 1)
//	{
//		//if (ch >= 'a' && ch <= 'z')
//		//{
//		//	printf("%c\n", ch - 32);
//		//}
//		//else
//		//{
//		//	printf("%c\n", ch + 32);
//		//}
//		//getchar();//scanf读取字母后还留有/n 这个不是字母，得用getchar()拿掉，否则会进到else的部分打印出*
//
//		//or
//		//if (ch >= 'a' && ch <= 'z')
//		//{
//		//	printf("%c\n", ch - 32);
//		//}
//		//else if(ch >= 'A' && ch <= 'Z')//这样当读取到/n时，就可以不进入运算部分
//		//{
//		//	printf("%c\n", ch + 32);
//		//}
//
//		//or
//		if (islower(ch))
//		{
//			printf("%c\n", toupper(ch));
//		}
//		else if (isupper(ch))
//		{
//			printf("%c\n", tolower(ch));
//		}
//	}
//
//	return 0;
//}


//多组输入，每行输入一个字符，判断其是否为字母
//isalpha()判断字符是否为字母的函数，一样要用到库函数<ctype.h>
//#include<stdio.h>
//#include<ctype.h>
//
//int main()
//{
//	char ch = 0;
//	//在%c前加空格，意味着跳过下一个字符前的空白字符
//	while (scanf_s(" %c", &ch) == 1)
//	{
//		if (isalpha(ch)) 
//		{
//			printf("%c is an alphabet.\n", ch);
//		}
//		else
//		{
//			printf("%c is not an alphabet.\n", ch);
//		}
//	}
//
//	//while (scanf_s("%c", &ch) == 1)
//	//{
//	//	if (isupper(ch) || islower(ch))
//	//	{
//	//		printf("%c is an alphabet.\n", ch);
//	//	}
//	//	else
//	//	{
//	//		printf("%c is not an alphabet.\n", ch);
//	//	}
//	//	getchar();
//	//}
//
//	return 0;
//}


//变种水仙花数 Lily Number :把任意数从中间拆分为两个数，如果拆分后的两个数的乘积之和等于本身，那么这个数就是Lily Number
// e.g: 655 = 6 * 55 + 65 * 5
//求出5位数中所有的Lily Number
//#include<stdio.h>
//#include<math.h>
//
//int main()
//{
//	int i = 0;
//	for (i = 10000; i <= 99999; i++)
//	{
//		int j = 0;
//		int sum = 0;
//		for (j = 1; j <= 4; j++)
//		{
//			int k = (int)pow(10, j);// pow(n1 ,n2)是计算n1的n2次方的函数，其返回值为double类型，需要用到<math.h>库函数
//			sum += (i / k) * (i % k);
//			if (sum == i)
//			{
//				printf("%d ", sum);
//			}
//		}
//	}
//
//	return 0;
//}


//求字符串中除了' '与'\n'的元素个数
//#include<stdio.h>
//
//int main()
//{
//	char ch[5] = { 0 };
//	int i = 0;
//	int num = 0;
//	gets(ch);
//	for (i = 0;ch[i] != '\0'; i++)
//	{
//		if (ch[i] != ' ' && ch[i] != '\n')
//			num++;
//	}
//	printf("%d\n", num);
//
//	return 0;
//}


//求以下程序运行结果
//#include<stdio.h>
//
//int main()
//{
//	int a, b, c;
//	a = 5;
//	c = ++a;//c=6=a
//	b = ++c, c++, ++a, a++;//此处b = ++c是一个表达式	b = 7,c=8=a
//	b += a++ + c;//a=9,c=8,b=23		此处是先使用a=8计算，再a+1
//	printf("a = %d b = %d c = %d", a, b, c);
//
//	return 0;
//}


//一个能统计参数的二进制中1的个数的函数
//类比取十进制的数的每一位 /10 %10,二进制可以 /2 %2
//e.g: 11的二进制1011 11%2=1(最后的那位) 11/2=5(5的二进制:101)  5%2=1 5/2=2(10) 2%2=0 2/2=1
//#include<stdio.h>
//
////法一
////只适合正数
////int count_num1(int n)
////{
////	int count = 0;
////	while (n)
////	{
////		if ((n % 2) == 1)
////		{
////			count++;
////		}
////		n /= 2;
////	}
////	return count;
////}
//
////但如果将将负数用无符号整型传参时，接首的n会将其视为很大的数(它的补码)
////int count_num1(unsigned int n)
////{
////	int count = 0;
////	while (n)
////	{
////		if ((n % 2) == 1)
////		{
////			count++;
////		}
////		n /= 2;
////	}
////	return count;
////}
//
////法二
////也可利用操作符的方法
////某个数&1 可得到其二进制最低位的数字，再用移位操作符
////int count_num1(int n)
////{
////	int i = 0;
////	int count = 0;
////	for (i = 0; i < 32; i++)
////	{
////		if (((n >> i) & 1) == 1)
////			count++;
////	}
////	return count;
////}
//
////法三
////若n=15
////n = n&(n-1)
////1111		n
////1110		n-1
////1110		重新赋值为n,这样反复运行
////1101		n-1
////1100		n	这样每执行一次就能让n二进制序列最右边的1去掉，从而得知该数的二进制序列有多少个1
//int count_num1(int n)
//{
//	int count = 0;
//	while(n)
//	{
//		n = n & (n - 1);
//		count++;
//	}
//	return count;
//}
//
//int main()
//{
//	int n = 0;
//	scanf_s("%d", &n);
//	int num = count_num1(n);
//	printf("%d\n", num);
// 
//	return 0;
//}


//用上一题的法三中的n = n & (n-1)来判断一个数是否是2的n次方
//2^1
//10
//2^2
//100
//2^3
//1000
//其最左边一定是1，右边是0
//#include<stdio.h>
//
//int is_two_power(int n)
//{
//		if (n & (n - 1) == 0)
//		{
//			return 1;
//		}
//		return 0;
//}
//
//int main()
//{
//	int n = 0;
//	scanf_s("%d", &n);
//	is_two_power(n);//是返回1，不是返回0
//
//	return 0;
//}


//两个32位的整数二进制位中，有多少个位（bit）不同
//#include<stdio.h>
//
//int count_different(int m, int n)
//{
//	//法一：拿到二进制中的每一位进行比较
//	//int i = 0;
//	//int num = 0;
//	//for (i = 0; i < 32; i++)
//	//{
//	//	if (((m >> i) & 1) != ((n >> i) & 1))
//	//	{
//	//		num++;
//	//	}
//	//}
//	//return num;
//
//	//法二：
//	//因 ^ 按位异或同则0异则1，所以可统计m^n中1的个数
//	int num = 0;
//	int ret = m ^ n;
//	while (ret)
//	{
//		ret = ret & (ret - 1);
//		num++;
//	}
//
//	return num;
//}
//
//int main()
//{
//	int m = 0;
//	int n = 0;
//	int ret = 0;
//	scanf_s("%d %d", &m, &n);
//	ret = count_different(m, n);
//	printf("%d\n", ret);
//
//	return 0;
//}


//获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列(b本题将二进制最低位视为第一位)
//#include<stdio.h>
//
//int main()
//{
//	int i = 0;
//	int n = 0;
//	scanf_s("%d", &n);
//	//获取奇数位的数字
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf("%d ", (n >> i) & 1);
//	}
//	printf("\n");
//	//获取偶数位
//	for (i = 31; i >= 0; i -= 2)
//	{
//		printf("%d ", (n >> i) & 1);
//	}
//	printf("\n");
//
//	return 0;
//}


//多组输入，输入一个整数，表示输出的行数和组成X的正斜线和反斜线的长度，并输出由*组成的X图案
//#include<stdio.h>
//
//int main()
//{
//	int n = 0;
//	int i = 0;
//	int j = 0;
//	while (scanf_s("%d", &n) == 1)
//	{
//		for (i = 0; i < n; i++)
//		{
//			for (j = 0; j < n; j++)
//			{
//				if (i == j)
//					printf("*");
//				else if (i + j == n - 1)
//					printf("*");
//				else
//					printf(" ");
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}


//多组输入，输入两个整数分别表示年和月，输出该年该月的天数
//#include<stdio.h>
//
//int is_leapyear(int y)
//{
//	if ((y % 4 == 0) && (y % 100 != 0) || (y % 400 == 0))
//	{
//		return 1;
//	}
//	return 0;
//}
//
//int main()
//{
//	int y = 0;
//	int m = 0;
//	int d = 0;
//	while (scanf_s("%d %d", &y, &m) == 2)
//	{
//		int ret = is_leapyear(y);
//		switch (m)
//		{
//		case 1:
//		case 3:
//		case 5:
//		case 7:
//		case 8:
//		case 10:
//		case 12:
//			d = 31;
//			printf("%d\n", d);
//			break;
//		case 4:
//		case 6:
//		case 9:
//		case 11:
//			d = 30;
//			printf("%d\n", d);
//			break;
//		case 2:
//			if (ret)
//			{
//				d = 29;
//				printf("%d\n", d);
//			}
//			else
//			{
//				d = 28;
//				printf("%d\n", d);
//			}
//			break;
//		default:
//			break;
//		}
//	}
//	return 0;
//}


//求下列运行结果
//#include<stdio.h>
//
//int main()
//{
//	int arr[] = { 1,2,3,4 ,5};//在32位下int存储4个字节
//	short* p = (short*)arr;
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		*(p + i) = 0;//short指针每次只移动2个字节
//	}
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}


//输出部分要求保留小数点后几位
//#include<stdio.h>
//#include<math.h>
//
//int main()
//{
//	float t = 0;
//	int n = 0;
//	int num = 0;
//	float a = 0;
//	scanf_s("%f %d", &t, &n);
//	num = n * 2;
//	a = t / n;
//	printf("%.3f\n", a);// 注意.xf
//	printf("%d\n", num);
//
//	return 0;
//}


//求三角形面积
//#include<stdio.h>
//#include<math.h>
//
//int main()
//{
//	double a = 0;
//	double b = 0;
//	double c = 0;
//	double p = 0;
//	double s2 = 0;
//	double s = 0;
//	scanf_s("%lf %lf %lf", &a, &b, &c);
//	p = (a + b + c) / 2.0;
//	s2 = p * (p - a) * (p - b) * (p - c);
//	s = sqrt(s2);
//	printf("%.1f\n", s);
//	return 0;
//}


//求下列结果
//#include<stdio.h>
//
//int main()
//{
//	int a = 0x11223344;
//	char* pc = (char*)&a;
//	//数据储存是从高地址到低地址来存储
//	// 44 33 22 11
//	// pc初始指向44的位置
//	*pc = 0;
//	// 00 33 22 11
//	printf("%x\n", a);//11223300
//
//	return 0;
//}


//输入三个勾股数，求最小锐角的正弦值并用分数形式来表达
//#include<stdio.h>
//#include<math.h>
//
//int main()
//{
//	long long a, b, c;
//	scanf_s("%lld %lld %lld", &a, &b, &c);
//	long long tmp = 0;
//	long long num = 0;
//	long long den = 0;
//	if (a < b)
//	{
//		tmp = a;
//		a = b;
//		b = tmp;
//	}
//	if (a < c)
//	{
//		tmp = a;
//		a = c;
//		c = tmp;
//	}
//	if (b < c)
//	{
//		tmp = b;
//		b = c;
//		c = tmp;
//	}
//	long long min = c;
//	while (1)
//	{
//		if (a % min == 0 && c % min == 0)
//		{
//			break;
//		}
//		min--;
//	}
//	num = c / min;
//	den = a / min;
//	printf("%lld/%lld\n", num, den);
//
//	return 0;
//}


//写一个函数打印数组内容，使用指针
//#include<stdio.h>
//
//void print(int* p, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr, sz);
//	return 0;
//}


//写一个函数将字符串(长度为1-10000)颠倒过来输出
//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//	char ch[10001] = { 0 };
//	gets(ch);
//	int left = 0;
//	int right = strlen(ch) - 1;
//	while (left < right)
//	{
//		char tmp = 0;
//		tmp = ch[left];
//		ch[left] = ch[right];
//		ch[right] = tmp;
//		left++;
//		right--;
//	}
//	printf("%s\n", ch);
//
//	return 0;
//}


//求Sn = a+aa+aaa+aaaa+……的前n项之和，其中a是一个数字
//1
//11 1*10+1
//111 11*10+1
//#include<stdio.h>
//
//int main()
//{
//	int a = 0;
//	int n = 0;
//	scanf_s("%d %d", &a, &n);
//	int sum = 0;
//	int k = 0;
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		k = k * 10 + a;
//		sum += k;
//	}
//	printf("%d\n", sum);
//
//	return 0;
//}


//求0-100000之间的"水仙花数"，并输出
//"水仙花数"：指一个n位数，其各个数字的n次方之和等于该数本身，如:153 1的3次方+5的3次方+3的3次方
//真正的水仙花数只有三位数
//#include<stdio.h>
//#include<math.h>
//
//int main()
//{
//	int i = 0;
//	//生成0-100000
//	for (i = 0; i < 100000; i++)
//	{
//		//判断
//		//1、计算i是几位数
//		int n = 1;//默认任何数最少是一位数
//		int tmp = i;
//		int sum = 0;
//		while (tmp / 10)
//		{
//			n++;
//			tmp /= 10;
//		}
//		//2、得到i的每一位，计算它的n次方之和
//		tmp = i;
//		while (tmp)
//		{
//			sum += pow(tmp % 10, n);
//			tmp /= 10;
//		}
//		//3、判断是否与原数相等
//		if (sum == i)
//		{
//			printf("%d ", sum);
//		}
//	}
//	printf("\n");
//
//	return 0;
//}


//打印n行n列的菱形(n = (2 * line - 1) 为奇数)
//#include<stdio.h>
//
//int main()
//{
//	int line = 0;
//	scanf_s("%d", &line);
//	int i = 0;
//	int j = 0;
//	//上面部分
//	for (i = 0; i < line; i++)
//	{
//		//打印一行
//		//空格
//		for (j = 0; j < line - 1-i; j++)
//		{
//			printf(" ");
//		}
//		//*
//		for (j = 0; j < i * 2 + 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	//下面部分
//	for (i = 0; i < line - 1; i++)
//	{
//		//打印一行
//		//空格
//		for (j = 0; j < i+1 ; j++)
//		{
//			printf(" ");
//		}
//		//*
//		for (j = 0; j < 2*(line - 1 - i) - 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//
//	return 0;
//}


//买汽水，一元一瓶，两个空瓶能再换一瓶汽水，现有money,问能喝多少瓶汽水
//#include<stdio.h>
//
//int main()
//{
//	int money = 0;
//	scanf_s("%d", &money);
//	int total = money;
//	int empty = money;
//
//	//置换
//	while (empty >= 2)
//	{
//		total += empty / 2;
//		empty = empty / 2 + empty % 2;
//	}
//	printf("%d\n", total);
//
//	return 0;
//}


//求两个数的最小公倍数
//#include<stdio.h>
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int i = 1;
//	scanf_s("%d %d", &a, &b);
////法一：
////	int m = (a > b ? a:b);
////	while (1)
////	{
////		if (m % a == 0 && m % b == 0)
////		{
////			printf("%d\n", m);
////			break;
////		}
////		m++;
////	}
////法二：
//	while (a * i % b)
//	{
//		i++;
//	}
//	printf("%d\n", a * i);
//
//	return 0;
//}


//倒置字符串，将一句话的单词倒置，标点不倒置
//e.g: I like Beijing. -> Beijing. like I 
//#include<stdio.h>
//#include<string.h>
//#include<assert.h>
//
//void reserve(char* left, char* right)
//{
//	assert(left != NULL);
//	assert(right != NULL);
//	char tmp = 0;
//	while (left < right)
//	{
//		tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	char arr[100] = { 0 };
//	gets(arr);
//	//1、对字符串整体进行逆序
//	int len = strlen(arr);
//	reserve(arr, arr + len - 1);
//	//2、查找每一个单词，对其进行逆序
//	char* start = arr;
//	while (*start != '\0')
//	{
//		char* end = start;
//		while (*end != ' ' && *end != '\0')
//		{
//			end++;
//		}
//		reserve(start, end-1);
//		if (*end != '\0')
//		{
//			end++;
//		}
//		start = end;
//	}
//	printf("%s\n", arr);
//
//	return 0;
//}


//已知Sn = 1 + 1/2 + 1/3 + …… +1/n，对于一个数k，求最小的n,使得Sn > k
//#include<stdio.h>
//
//int main()
//{
//	int k = 0;
//	int n = 0;
//	double sum = 0;
//	scanf_s("%d", &k);
//	for (n = 1; sum <= k; n++)
//	{
//		sum += 1.0 / n;
//		if (sum > k)
//		{
//			printf("%d\n", n);
//			break;
//		}
//	}
//
//	return 0;
//}


//#include<stdio.h>
//
//int main()
//{
//	int k = 0;
//	int day = 0;
//	int sum = 0;
//	int i = 1;
//	int j = 1;
//	scanf_s("%d", &k);
//	while (day+1 <= k)
//	{
//		int count = 0;
//		for (i = 1; i <= j; i++)
//		{
//			sum += j;
//			count++;
//			if (count == k - day)
//			{
//				break;
//			}
//		}
//		day += j;
//		j++;
//	}
//	printf("%d\n", sum);
//
//	return 0;
//}


//按顺序输入n个数，每一个数与其之前的数比较大小，并分别输出在其之前有数少个数比自己小
//#include<stdio.h>
//
//int main()
//{
//	int n = 0;
//	int arr[100] = { 0 };
//	scanf_s("%d", &n);
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf_s("%d", &arr[i]);
//	}
//	int* str1 = arr;
//	int* str2 = str1 + 1;
//	printf("0 ");
//	for (i = 1; i < n; i++)
//	{
//		int num = 0;
//		while (str1 < str2)
//		{
//			if (*str1 < *str2)
//			{
//				num++;
//			}
//			str1++;
//		}
//		str1 = arr;
//		str2++;
//		printf("%d ", num);
//	}
//	printf("\n");
//
//	return 0;
//}


//数字反转，正负号保留，若反转后是0开头，则不打印这些0
//#include<stdio.h>
//
//int main()
//{
//	long long n = 0;
//	scanf_s("%lld", &n);
//	if (n == 0)
//	{
//		printf("%lld\n", n);
//	}
//	else
//	{
//		if (n < 0)
//		{
//			n = 0 - n;
//			printf("-");
//			while (n % 10 == 0)
//			{
//				n /= 10;
//			}
//			while (n)
//			{
//				printf("%lld", n % 10);
//				n /= 10;
//			}
//			printf("\n");
//		}
//		else if (n > 0)
//		{
//			while (n % 10 == 0)
//			{
//				n /= 10;
//			}
//			while (n)
//			{
//				printf("%lld", n % 10);
//					n /= 10;
//			}
//			printf("\n");
//		}
//	}
//
//	return 0;
//}


//斐波那契数列
//#include<stdio.h>
//#include<math.h>
//
//int main()
//{
//	int n = 0;
//	double n1 = 0;
//	double n2 = 0;
//	double f = 0;
//	scanf_s("%d", &n);
//	n1 = pow((sqrt(5) + 1) / 2.0, n);
//	n2 = pow((sqrt(5) - 1) / 2.0, n);
//	f = (n1 - n2) / sqrt(5);
//	printf("%.2f\n", f);
//
//	return 0;
//}


//冰雹猜想
//#include<stdio.h>
//
//int main()
//{
//	int n = 0;
//	scanf_s("%d", &n);
//	int arr[200] = { 0 };
//	int i = 1;
//	int j = 0;
//	arr[0] = n;
//	while (n != 1)
//	{
//		if (n % 2)
//		{
//			n = n * 3 + 1;
//			arr[i] = n;
//		}
//		else
//		{
//			n /= 2;
//			arr[i] = n;
//		}
//		i++;
//	}
//	int left = 0;
//	int right = i - 1;
//	while (left < right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//	for (j = 0; j < i; j++)
//	{
//		printf("%d ", arr[j]);
//	}
//	printf("\n");
//
//	return 0;
//}


//长度为l的数轴上，每个正整数点与0上都有一棵树，现有m个区域的树要移除，请在
//输入l、m之后的m行分别输入移除区域的首尾坐标，求移除后剩下树的棵树
//#include<stdio.h>
//
//int main()
//{
//	int l = 0;
//	int m = 0;
//	int i = 0;
//	int j = 0;
//	int arr[100][2] = { 0 };
//	int arr1[10001] = { 0 };
//	scanf_s("%d%d", &l, &m);
//	int sum = 0;
//	int left = 0;
//	for (i = 0; i < m; i++)
//	{
//		for (j = 0; j < 2; j++)
//		{
//			scanf_s("%d", &arr[i][j]);
//		}
//	}
//	for (i = 0; i < m; i++)
//	{
//		for (j = arr[i][0]; j <= arr[i][1]; j++)
//		{
//			arr1[j] = 1;
//		}
//	}
//	for (i = 0; i <= l; i++)
//	{
//		sum += arr1[i];
//	}
//	left = l + 1 - sum;
//	printf("%d\n", left);
//
//	return 0;
//}


//
//#include<stdio.h>
//
//int main()
//{
//	char arr[20] = { 0 };
//	int n = 0;
//	scanf_s("%d", &n);
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf_s("%s", &arr, 20);
//		printf("Welcome to GDUT %s\n",arr);
//	}
//
//	return 0;
//}


//在n个数字中，求连续m个数的和的最小值
//#include<stdio.h>
//
//int main()
//{
//	int n = 0;
//	int m = 0;
//	int i = 0;
//	int min = 0;
//	int arr[3000] = { 0 };
//	scanf_s("%d%d", &n, &m);
//	for (i = 0; i < n; i++)
//	{
//		scanf_s("%d", &arr[i]);
//	}
//	for (i = 0; i < m; i++)
//	{
//		min += arr[i];
//	}
//	for (i = 1; i <= n-m; i++)
//	{
//		int j = 0;
//		int sum = 0;
//		for (j = i; j <= m+i-1; j++)
//		{
//			sum += arr[j];
//		}
//		if (sum < min)
//		{
//			min = sum;
//		}
//	}
//	printf("%d\n", min);
//
//	return 0;
//}


//看以下代码结果
//#include<stdio.h>
//#include<Windows.h>
//
//int main()
//{
//	unsigned int i = 0;
// //unsigned int 类型取值范围是大于0的,所以下面是个死循环
//	for (i = 9; i >= 0; i--)
//	{
//		printf("%u\n", i);
//		Sleep(1000);//休眠1000ms
//	}
//
//	return 0;
//}


//求下列结果
//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//	char a[1000] ;
//	int i = 0;
//	for (i = 0; i < 1000; i++)
//	{
//		a[i] = -1 - i;
//	}
//	printf("%d\n", strlen(a));
//	//strlen 关注\0之前出现了多少字符，而'\0'的ACISS码是0
//	//因char类型取值范围为-128 - 127
//	// -1 -2 …… -128 127 126 125 …… 3 2 1 0 -1 -2 ……   //strlen到0停，所以结果为128 + 127 = 255
//	//10000000		-128的补码
//	//01111111		 127的补码
//	return 0;
//}

//
//#include<stdio.h>
//
//int main()
//{
//	unsigned char i = 0;
//	//unsigned char 类型取值范围为0 - 255
//	for (i = 0; i <= 255; i++)//因此i<=255的条件恒成立
//	{
//		printf("Hello world\n");
//	}
//	//这是个死循环
//
//	return 0;
//}

//
//#include<stdio.h>
//#include<string.h>
//#include<assert.h>
//
//int my_strlen(const char* str)
//{
//	assert(str != NULL);
//	int count = 0;
//	while (*str)
//	{
//		str++;
//		count++;
//	}
//	return count;
//}
//
//int main()
//{
//	if (strlen("abc") - strlen("abcdef") > 0)
//	{
//		printf(">\n");
//	}
//	else
//	{
//		printf("<\n");
//	}
//	//strlen的返回值是unsigned int类型
//	//无符号整数 减去 无符号整数 仍是一个无符号整数，其始终>=0
//	if (my_strlen("abc") - my_strlen("abcdef") > 0)
//	{
//		printf(">\n");
//	}
//	else
//	{
//		printf("<\n");
//	}
//
//	//这题想要规避可如下
//	if (strlen("abc") > strlen("abcdef"))
//	{
//		printf(">\n");
//	}
//	else
//	{
//		printf("<\n");
//	}
//	//or
//	if ((int)strlen("abc") - (int)strlen("abcdef") > 0)
//	{
//		printf(">\n");
//	}
//	else
//	{
//		printf("<\n");
//	}
//
//	return 0;
//}


//杨辉三角形
//#include<stdio.h>
//
//int main()
//{
//	int n = 0;
//	int i = 0;
//	int j = 0;
//	scanf_s("%d", &n);
//	int arr[20][20] = { 0 };
//	for (i = 0; i < n; i++)
//	{
//		arr[i][0] = 1;
//		arr[i][i] = 1;
//		for (j = 1; j < i; j++)
//		{
//			if (i >= 2)
//			{
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//			}
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}


//输入一个整数数组，实现一个函数进行顺序调整将数组里的奇数位于前半部分，偶数位于后半部分
//#include<stdio.h>
//
//void move_odd_even(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left < right)
//	{
//		//从左往右找一个偶数停下来，但如果存在数组都是奇数的话会造成越界访问
//		//while (arr[left] % 2)
//		while ((left < right) && (arr[left] % 2))//为避免越界，需这样调整
//		{
//			left++;
//		}
//		while ((left < right) && (arr[right] % 2 == 0))
//		{
//			right--;
//		}
//		if (left < right)
//		{
//			int tmp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = tmp;
//			left++;
//			right--;
//		}
//	}//这种写法虽有三个循环，但只对数组历遍了一遍
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		//scanf_s("%d", &arr[i]);//或者写成下面形式
//		scanf_s("%d", arr + i);
//	}
//	move_odd_even(arr,sz);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(arr+i));
//	}
//	printf("\n");
//	return 0;
//}


//升序序列排列
//输入n m，n m分别表示两个序列的长度，并输入这两个序列，将两个序列合并为一个长度为m+n并重新排序的升序序列
//#include<stdio.h>
//
//int main()
//{
//	int n = 0;
//	int m = 0;
//	scanf_s("%d %d",&n,&m);
//	int arr1[1000] = { 0 };
//	int arr2[1000] = { 0 };
//	int i = 0;
//	int j = 0;
//	int k = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf_s("%d", arr1 + i);
//	}
//	for (i = 0; i < m; i++)
//	{
//		scanf_s("%d", arr2 + i);
//	}
//	while (j < n && k < m)
//	{
//		if (arr1[j] < arr2[k])
//		{
//			printf("%d ", arr1[j]);
//			j++;
//		}
//		else
//		{
//			printf("%d ", arr2[k]);
//			k++;
//		}
//	}
//	if (j < n)
//	{
//		for (; j < n; j++)
//		{
//			printf("%d ",arr1[j]);
//		}
//	}
//	else
//	{
//		for (; k < m; k++)
//		{
//			printf("%d ", arr2[k]);
//		}
//	}
//	printf("\n");
//
//	return 0;
//}


//洛谷P1161
//注： 0 ^ a = a	a ^ a = 0
//#include<stdio.h>  
//#include<math.h>  
//
//int main()
//{
//	int n, t;
//	double a;
//	int ans = 0;
//	scanf_s("%d", &n);
//	while (n--)
//	{
//		scanf_s("%lf", &a);
//		scanf_s("%d", &t);
//		for (int i = 1; i <= t; i++)
//		{
//			int x = (int)floor(a * i);
//			ans ^= x;
//		}
//	}
//	printf("%d\n", ans);
//	return 0;
//}


//汉诺塔
//#include<stdio.h>
//
//int move(char departure, char destination)
//{
//	//printf("%c -> %c\n", departure, destination);
//	return 1;
//}
//
//int hanoi(int n, char one, char two, char three)
//{
//	int num = 0;
//	if (n == 1)
//	{
//		return move(one, three);
//	}
//	else
//	{
//		num += hanoi(n - 1, one, three, two);
//		num += move(one, three);
//		num += hanoi(n - 1, two, one, three);
//	}
//	return num;
//}
//
//int main()
//{
//	int n = 0;
//	scanf_s("%d",&n);
//	printf("%d\n", hanoi(n, 'A', 'B', 'C'));
//	return 0;
//}


//指针面试题
//分析以下代码时可以画一个“打横放的栈”(或者关于数组内容内存存放的图)和指针箭头的图来辅助分析
//#include<stdio.h>
//1、
//int main()
//{
//	int a[5] = { 1,2,3,4,5 };
//	int* ptr = (int*)(&a + 1);
//	printf("%d %d\n", *(a + 1), *(ptr - 1));//2 5
//	return 0;
//}
//2、
//struct test
//{
//	int num;
//	char* pcname;
//	short date;
//	char ch[2];
//	short ba[4];
//}* p=(struct test*)0x100000;
////已知该结构体在32位下大小为20
////以下结果是在32位下的情况
//int main()
//{
//	printf("%p\n", p + 0x1);
//	//0x100000+20 --> 0x100014  
//	printf("%p\n", (unsigned long)p + 0x1);
//	//1 048 576 +1 --> 1 048 577
//	//0x100001
//	printf("%p\n", (unsigned int*)p + 0x1);
//	//0x100000 +4 --> 0x100004
//	return 0;
//}
//3、
//int main()
//{
//	int a[4] = { 1,2,3,4 };
//	int* p1 = (int*)(&a + 1);
//	int* p2 = (int*)((int)a + 1);
//	//数组a内存里存储为：01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00
//	//在调试中找到a的内存，假设a首元素地址为0x000000305219FBC8，从01 00 00 00开始读取
//	//那么(int)a + 1 就是0x000000305219FBC9，所以p2为0x000000305219FBC9，即p2指向这个地址
//	//p2访问内存时就从00 00 00 02开始读取
//	//又因为vs内存是小端存储方式，所以导致下行printf运行到*p2时编译系统会报访问错误
//	printf("%x %x\n", p1[-1],*p2);
//	return 0;
//}
//4、
//int main()
//{
//	int a[3][2] = { (0,1),(2,3),(4,5) };//此处()内是个逗号表达式
//	//相当于int a[3][2] = {1,3,5};
//	int* p = NULL;
//	p = a[0];
//	printf("%d\n", p[0]);
//	return 0;
//}
//5、
//int main()
//{
//	int a[5][5];
//	int (*p)[4];
//	p = a;
//	printf("%p %d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//	//p[4][2] --> *(*(p+4)+2)
//	//因( &p[4][2] - &a[4][2] ) == -4 ，其原码反码补码如下：
//	// 10000000000000000000000000000100
//	// 11111111111111111111111111111011
//	// 11111111111111111111111111111100
//	//以%p打印时将会将 -4 的补码视为个地址
//	//将 -4 的补码直接由二进制转换为十六进制
//	// 1111 1111 1111 1111 1111 1111 1111 1100
//	//   F    F    F    F    F    F    F    C
//	return 0;
//}
//6、
//int main()
//{
//	int arr[2][5] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p1 = (int*)(&arr + 1);
//	int* p2 = (int*)(*(arr + 1));//*(arr + 1)指向第二行的首地址，相当于arr[1]
//	printf("%d %d\n", *(p1 - 1), *(p2 - 1));//10	5
//	return 0;
//}
//7、
//int main()
//{
//	char* a[] = { "work","at","alibaba" };
//	char** pa = a;
//	pa++;
//	printf("%s\n", *pa);
//	return 0;
//}
//8、
//void test(char** p)
//{
//	*p += 2;
//}
//
//int main()
//{
//	char* a[] = { "123","abc","456" };
//	char** p = a;
//	test(a);
//	printf("%s\r\n", *p);
//	return 0;
//}
//9、
//int main()
//{
//	char* c[] = { "ENTER","NEW","POINT","FIRST" };
//	char** cp[] = { c + 3,c + 2,c + 1,c };
//	char*** cpp = cp;
//	printf("%s\n", **++cpp);//POINT
//	printf("%s\n", *-- * ++cpp + 3);//++cpp指向c+1即"NEW"，* ++cpp + 3指向c[]里的'W'，-- * ++cpp + 3 向左移5个字节到"ENTER"里的'E'
//	printf("%s\n", *cpp[-2] + 3);//*cpp[-2] 指向c + 3并指向"FIRST"的首元素'F'，*cpp[-2] + 3 指向'S'
//	printf("%s\n", cpp[-1][-1] + 1);//cpp[-1][-1]先指向c+2，再指向"NEW"的首元素'N'，cpp[-1][-1] + 1最后指向"NEW"里的'E'
//	//本题一定要画图来理解
//	return 0;
//}
//
//int main()
//{
//	char* c[] = { "ENTVE","NU!","I LO","FIRYO" };
//	char** cp[] = { c + 3,c + 2,c + 1,c };
//	char*** cpp = cp;
//	printf("%s", **++cpp);//
//	printf("%s ", *-- * ++cpp + 3);//
//	printf("%s", *cpp[-2] + 3);//
//	printf("%s\n", cpp[-1][-1] + 1);//
//	return 0;
//}


//一个数如果恰好等于它的因子之和，这个数就称为“完数，求1-1000以内的完数
//#include<stdio.h>
// 
//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 1000; i++)
//	{
//		int sum = 1;
//		int j = 2;
//		int q = 0;
//		do
//		{
//			q = i / j;
//			if (i % j == 0)
//			{
//				if (j == q)
//				{
//					sum += j;
//				}
//				else
//				{
//					sum += (j + q);
//				}
//			}
//			j++;
//		} while (j < i / j);
//		if (sum == i)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}


//求一个整数，它加上 100 后是一个完全平方数，再加上 168 又是一个完全平方数，请问这些数是多少, 并判断这些数是否为素数。
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int flag = 1;
//	int i = 1;
//	do
//	{
//		int j = pow(i, 2);
//		j -= 168;
//		double k = sqrt(j);
//		if (j > 0 && (int)(k * 10) % 10 == 0)
//		{
//			j -= 100;
//			if (j > 0)
//			{
//				int l = 0;
//				int pflag = 1;
//				for (l = 2; l < sqrt(k); l++)
//				{
//					if (j % l == 0)
//					{
//						pflag = 0;
//					}
//				}
//				if (pflag)
//				{
//					printf("%d就是所求，是素数\n", j);
//				}
//				else
//				{
//					printf("%d就是所求，不是素数\n", j);
//				}
//			}
//		}
//		i++;
//		if (i > pow(10, 6) + 268)//限定数据范围用的
//		{
//			flag = 0;
//		}
//	} while (flag);
//	return 0;
//}


//字母倒金字塔
//#include<stdio.h>
//
//int main()
//{
//	int i = 0;
//	int j = 0;
//	char a = 0;
//	printf("请输入一个大写字母：");
//	a = getchar();
//	char c = a;
//	while (c >= 'A')
//	{
//		char b = 'A';
//		while (b <= c)
//		{
//			printf("%c", b++);
//		}
//		b--;
//		while (b > 'A')
//		{
//			printf("%c", --b);
//		}
//		printf("\n");
//		c--;
//		i++;
//		for (j = 0; j < i; j++)
//		{
//			printf(" ");
//		}
//	}
//
//	return 0;
//}


//假定输入的字符串中只包含字母和*号，除了尾部的*号之外,将字符串中其它*号全部删除,禁用关于字符串的库函数
//#include<stdio.h>
//
//void test(char* a)
//{
//	int i = 0;
//	for (i = 0; *(a + i) != 0; i++)
//	{
//		if (*(a + i) == '*')
//		{
//			int j = i;
//			int n = 0;
//			while (*(a + j) == '*')
//			{
//				n++;
//				j++;
//			}
//			if (*(a + j) != '\0')
//			{
//				*(a + i) = *(a + j);
//				*(a + j) = '*';
//			}
//			else
//			{
//				*(a + i + n) = '\0';
//				break;
//			}
//		}
//	}
//}
//
//int main()
//{
//	char a[81];
//	gets(a);
//	test(a);
//	puts(a);
//	return 0;
//}


//输入一个数，如果某一位的数是奇数将其改为1，是偶数则将其改为1，最后输出改完后的数
//#include<stdio.h>
//#include<math.h>
//
//int main()
//{
//	int n = 0;
//	int sum = 0;
//	int input = 0;
//	scanf_s("%d", &input);
//	while (input)
//	{
//		int a = input % 10;
//		if (a % 2)
//		{
//			a = 1;
//		}
//		else
//		{
//			a = 0;
//		}
//		sum += a * pow(10, n);
//		n++;
//		input /= 10;
//	}
//	printf("%d\n", sum);
//
//	return 0;
//}


//带空格的直角三角形，多组输入，输入一个数表示三角形的直角边边长，用'*'来打印
//#include<stdio.h>
//
//int main()
//{
//	int input = 0;
//	while (scanf("%d", &input) == 1)
//	{
//		int i = 0;
//		int j = 0;
//		for (i = 0; i < input; i++)
//		{
//			for (j = 0; j < input; j++)
//			{
//				if (i + j < input - 1)
//				{
//					printf("  ");
//				}
//				else
//				{
//					printf("* ");
//				}
//			}
//			printf("\n");
//		}
//	}
//	
//	return 0;
//}


//
//#include<stdio.h>
//
//int main()
//{
//	unsigned char a = 200;
//	//00000000000000000000000011001000
//	//11001000  a 内存截断
//	unsigned char b = 100;
//	//00000000000000000000000001100100
//	//01100100  b
//	unsigned char c = 0;
//	c = a + b;
//	//没有整型大小的数据进行运算时会先进行整型提升
//	//00000000000000000000000011001000
//	//00000000000000000000000001100100
//	//00000000000000000000000100101100   300
//	//00101100  c  44
//	printf("%d %d\n", a + b, c);
//	return 0;
//}


//五名选手参加比赛。A说：b第二，我第三  B说：我第二，E第四  C说：我第一，D第二  
//					D说：C最后，我第三  E说：我第四，A第一  
//比赛结果后，每人都说对了一半，请确定比赛的真正名次（已知没有名次重叠的情况）
//#include<stdio.h>
//
//int main()
//{
//	int a = 0, b = 0, c = 0, d = 0, e = 0;
//	//穷举法
//	for (a = 1; a <= 5; a++)
//	{
//		for (b = 1; b <= 5; b++)
//		{
//			for (c = 1; c <= 5; c++)
//			{
//				for (d = 1; d <= 5; d++)
//				{
//					for (e = 1; e <= 5; e++)
//					{
//						if (((a == 3) + (b == 2) == 1) && 
//							((b == 2) + (e == 4) == 1) && 
//							((c == 1) + (d == 2) == 1) && 
//							((c == 5) + (d == 3) == 1) && 
//							((e == 4) + (a == 1) == 1))	//将每个条件作为语句，将其结果加起来或者根据题目已知条件进行判断
//						{
//							if (a * b * c * d * e == 120)
//							{
//								printf("a=%d b=%d c=%d d=%d e=%d\n", a, b, c, d, e);
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}


//一启案件，有四个嫌疑犯，其中一个是正凶
//A：我不是真凶
//B：C是真凶
//C：D是真凶
//D：C在胡说
//已知：一人在说假话
//#include<stdio.h>
//
//int main()
//{
//	int murder = 0;
//	for (murder = 'A'; murder <= 'D'; murder++)
//	{
//		if ((murder != 'A') + (murder == 'C') + (murder == 'D') + (murder != 'D') == 3)
//		{
//			printf("%c\n", murder);
//		}
//	}
//
//	return 0;
//}


//求下列代码结果
//#include<stdio.h>
//
//int main()
//{
//	char str1[] = "hello world";
//	char str2[] = "hello world";
//	char* str3 = "hello world";
//	char* str4 = "hello world";
//	if (str1 == str2)
//	{
//		printf("str1 and str2 are same\n");
//	}
//	else
//	{
//		printf("str1 and str2 are not same.\n");
//	}
//	if (str3 == str4)
//	{
//		printf("str3 and str4 are same.\n");
//	}
//	else
//	{
//		printf("str3 and str4 are not same.\n");
//	}
//
//	return 0;
//}


//实现一个函数，将字符串里的k个字符从开头移到末尾
//#include<stdio.h>
//#include<string.h>
//#include<assert.h>
//
////法一：
//void move(char* str, int n)
//{
//	int i = 0;
//	int len = strlen(str);
//  n %= len;
//	for (i = 0; i < n; i++)//每次移动一个字符，移动后将后面的字符移前，将要移的字符放在最后，执行n次
//	{
//		char tmp = *str;
//		int j = 0;
//		for (j = 0; j < len-1; j++)
//		{
//			*(str + j) = *(str + j + 1);
//		}
//		*(str + len - 1) = tmp;
//	}
//}
//
//法二：
//void reverse(char* left, char* right)
//{
//	assert(left && right);
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//
//void move(char arr[], int n)
//{
//	int len = strlen(arr);
//	n %= len;
//	reverse(arr, arr + n-1);
//	reverse(arr + n, arr + len - 1);
//	reverse(arr, arr + len - 1);
//}
//
//int main()
//{
//	int k = 0;
//	char arr[] = "abcdef";
//	scanf_s("%d", &k);
//	move(arr, k);
//	printf("%s", arr);
//
//	return 0;
//}


//杨氏矩阵
//有一个数字矩阵，矩阵每行从左到右、从上到下是递增的，输入一个数，查找这个数在矩阵里是否存在
//时间复杂度要求小于O(n)
//#include<stdio.h>
//
//法一：
//struct Point
//{
//	int x;
//	int y;
//};
//
//struct Point find_num(int arr[3][3], int row, int col, int n)
//{
//	int i = 0;
//	int j = col - 1;
//	struct Point p = { -1,-1 };
//	while (i < row-1 && j >= 0)
//	{
//		if (n < arr[i][j])
//		{
//			j--;
//		}
//		else if (n > arr[i][j])
//		{
//			i++;
//		}
//		else
//		{
//			p.x = i;
//			p.y = j;
//			return p;
//		}
//	}
//	return p;
//}
//
//法二：
//px py此时为返回型参数
//int find_num(int arr[3][3], int* px, int* py, int n)
//{
//	int i = 0;
//	int j = *py - 1;
//	while (i < *px-1 && j >= 0)
//	{
//		if (n < arr[i][j])
//		{
//			j--;
//		}
//		else if (n > arr[i][j])
//		{
//			i++;
//		}
//		else
//		{
//			*px = i;
//			*py = j;
//			return 1;
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	int k = 0;
//	scanf_s("%d", &k);
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//
//	//struct Point ret = find_num(arr, 3, 3, k);
//	//printf("%d %d\n", ret.x,ret.y);
//	int x = 3;
//	int y = 3;
//	int ret = find_num(arr, &x, &y, k);
//	if (ret)
//	{
//		printf("%d %d\n", x, y);
//	}
//	else
//	{
//		printf("没找到\n");
//	}
//
//	return 0;
//}


//判断一个字符串进行左旋转后能否得到另一个字符串
//#include<stdio.h>
//#include<string.h>
//
//int is_left_move(char arr1[], char arr2[])
//{
//	int len1 = strlen(arr1);
//	int len2 = strlen(arr2);
//	if (len1 != len2)
//	{
//		return 0;
//	}
//	strncat(arr1, arr1, len1);
//	char* ret = strstr(arr1, arr2);
//	if (ret == NULL)
//	{
//		return 0;
//	}
//	else
//	{
//		return 1;
//	}
//}
//
//int main()
//{
//	char arr1[20] = "abcdef";
//	//abcdefabcdef	里包含了左旋转后所有可能
//	//追加后只需要判断arr2是否是其字串,但要保证arr1和arr2长度要相等
//	char arr2[] = "cdefab";
//	int ret = is_left_move(arr1, arr2);
//	if (ret)
//	{
//		printf("OK\n");
//	}
//	else
//	{
//		printf("ERR\n");
//	}
//	return 0;
//}


//矩阵转置
//第一行输入两个数n、m，表示n行m列的矩阵(1<= n,m <=10)
//第2行到n+1行，分别输入m个数，表示矩阵的内容
//输出m行n列，表示矩阵转置后的结果
//#include<stdio.h>
//
//int main()
//{
//	int arr[10][10] = { 0 };
//	int n = 0;
//	int m = 0;
//	int i = 0;
//	int j = 0;
//	scanf_s("%d %d", &n, &m);
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < m; j++)
//		{
//			scanf_s("%d", &arr[i][j]);
//		}
//	}
//	for (i = 0; i < m; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			printf("%d ", arr[j][i]);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}


//上三角矩阵判断
//上三角矩阵即为主对角线（从矩阵左上角到右下角的连线）以下的元素都为0的矩阵
//输入一个数n（1<= n <=10），表示n*n的矩阵，并输入矩阵相的元素，如果是上三角矩阵输出yes，否则输出no
//#include<stdio.h>
// 
//int is_it(int arr[][10], int n)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < i; j++)
//		{
//			if (arr[i][j])
//				return 0;
//		}
//	}
//	return 1;
//}
//
//int main()
//{
//	int arr[10][10] = { 0 };
//	int n = 0;
//	int i = 0;
//	int j = 0;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	int ret = is_it(arr, n);
//	if (ret)
//	{
//		printf("yes\n");
//	}
//	else
//	{
//		printf("no\n");
//	}
//
//	return 0;
//}


//输入一个整数序列(n个数)，判断该序列是否是有序序列，有序指整数从小到大或从大到小排列，数据相同也算
//#include<stdio.h>
//
//int main()
//{
//	int arr[50] = { 0 };
//	int i = 0;
//	int n = 0;
//	int flag1 = 0;
//	int flag2 = 0;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &n);
//		if (i > 0)
//		{
//			if (arr[i] > arr[i - 1])
//			{
//				flag1 = 1;
//			}
//			else if (arr[i] < arr[i - 1])
//			{
//				flag2 = 1;
//			}
//			else
//			{
//				;
//			}
//		}
//	}
//	if (flag1 + flag2 <= 1)
//	{
//		printf("yes\n");
//	}
//	else
//	{
//		printf("no\n");
//	}
//
//	return 0;
//}


//请问下面代码结果
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//void GetMemory(char* p)
//{
//	p = (char*)malloc(100);//p出了函数后就会销毁，而p指向动态开辟空间的地址也无法被找到，存在内存泄漏
//}
//
//void test()
//{
//	char* str = NULL;
//	GetMemory(str);//str仍指向NULL
//	strcpy(str, "hello world");//strcpy(NULL，……)，会对NULL直接解引用，导致程序崩溃
//	printf(str);
//}
//
////修改版
////void GetMemory(char** p)
////{
////	*p = (char*)malloc(100);
////}
////
////void test()
////{
////	char* str = NULL;
////	GetMemory(&str);
////	strcpy(str, "hello world");
////	printf(str);
////	free(str);
////	str = NULL;
////}
//
//int main()
//{
//	test();
//	return 0;
//}

//返回栈空间地址的问题
//#include<stdio.h>
//char* Getmemory(void)
//{
//	char p[] = "hello world";
//	return p;//p的内存出了该函数就被销毁了，返回了一个野指针
//}
//
//void test()
//{
//	char* str = Getmemory();
//	printf(str);
//}
//
//int main()
//{
//	test();
//	return 0;
//}

//
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//void GetMemory(char** p, int num)
//{
//	*p = (char*)malloc(num);
//}
//
//void test()
//{
//	char* str = NULL;
//	GeyMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//	//该代码存在的问题是没有free(),导致内存泄漏
//}
//
//int main()
//{
//	test();
//	return 0;
//}

////
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//void test()
//{
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//	free(str);//free()后str的空间被系统回收，str变成野指针
//	if (str != NULL)
//	{
//		strcpy(str, "hello");
//		printf(str);
//	}
//}
//
//int main()
//{
//	test();
//	return 0;
//}


//多组输入，求n、m两个整数的最大公因数和最小公倍数之和
//#include<stdio.h>
//
//int main()
//{
//	int n = 0;
//	int m = 0;
//	int sum = 0;
//	while (scanf("%d %d", &n, &m) == 2)
//	{
//		int i = 0;
//		int a = n;
//		int b = m;
//		int tmp = 0;
//		while (tmp = a % b)
//		{
//			a = b;
//			b = tmp;
//		}
//		i = n * m / b;
//		sum = b + i;
//		printf("%d\n", sum);
//	}
//	return 0;
//}


//多组输入，用*打印空心正方形，n为边长(3 <= n <= 20)
//#include<stdio.h>
//
//int main()
//{
//	int n = 0;
//	while (scanf("%d", &n) == 1)
//	{
//		int i = 0;
//		int j = 0;
//		for (i = 0; i < n; i++)
//		{
//			for (j = 0; j < n; j++)
//			{
//				if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
//				{
//					printf("* ");
//				}
//				else
//				{
//					printf("  ");
//				}
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}


//用*打印箭形图案，多组输入，输入整数n（2 - 20）
//#include<stdio.h>
//
//int main()
//{
//	int n = 0;
//	while (scanf("%d", &n) == 1)
//	{
//		int i = 0;
//		int j = 0;
//		for (i = 0;i < n + 1; i++)
//		{
//			for (j = 0; j < n -i; j++)
//			{
//				printf("  ");
//			}
//			for (j = 0; j < i+1; j++)
//			{
//				printf("*");
//			}
//			printf("\n");
//		}
//		for (i = 0;i < n; i++)
//		{
//			for (j = 0; j < i + 1; j++)
//			{
//				printf("  ");
//			}
//			for (j = 0; j < n - i; j++)
//			{
//				printf("*");
//			}
//			printf("\n");
//		}
//	}
//
//	return 0;
//}


//打分,多组输入
//输入7个整数（0 - 100），除去最大值和最小值后，求剩下的平均数，并输出该平均数，输出要求保留两位小数
//#include<stdio.h>
//#include<math.h>
//
//int main()
//{
//	int n = 0;
//	int max = 0;
//	int min = 100;
//	int sum = 0;
//	int score = 0;
//	while (scanf("%d", &score)==1)
//	{
//		n++;
//		if (max < score)
//		{
//			max = score;
//		}
//		if (min > score)
//		{
//			min = score;
//		}
//		sum += score;
//		if (n == 7)
//		{
//			printf("%.2lf\n", (sum - max - min) / 5.0);
//			max = 0;
//			min = 100;
//			n = 0;
//			sum = 0;
//		}
//	}
//	return 0;
//}


//求以下结构体的大小
//#include<stdio.h>
//
//struct A
//{
//	int a;//0-3
//	short b;//4-5
//	int c;//8-11
//	char d;//12
//	//13-15
//};//0-15   16
//
//struct B
//{
//	int a;//0-3
//	short b;//4-5
//	char c;//6
//	int d;//8-11
//	//12
//};
//
//int main()
//{
//	printf("%d\n", sizeof(struct A));//16
//	printf("%d\n", sizeof(struct B));//12
//
//	return 0;
//}


//求给pointer分配了几个字节的空间
//#define MAX_SIZE  2+3
//struct Record
//{
//	unsigned char a : 4;//1  - 8bite
//	unsigned char b : 2;
//	unsigned char c;//1  - 8bite
//	unsigned char d : 1;//1  - 8bite
//
//}*Env_Record;
//
//struct Record* pointer = (struct Record*)malloc(sizeof(struct Record) * MAX_SIZE);//3*2+3 == 9


//求以下代码结果
//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//	unsigned char puc[4];
//	struct tagPIM
//	{
//		unsigned char a;
//		unsigned char b : 1;
//		unsigned char c : 2;
//		unsigned char d : 3;
//
//	}*pstPimData;
//	pstPimData = (struct tagPIM*)puc;
//	memset(puc, 0, 4);
//	// 00000000 00000000 00000000 00000000
//	//由于位段，puc只有前两个字节存放数据
//
//	pstPimData->a = 2;
//	//00000010 00000000 00000000 00000000
//	pstPimData->b = 3;
//	//由于只能放一个字节 3->011 只能放一个1
//	//00000010 00000001 00000000 00000000
//	pstPimData->c = 4;
//	//同理 4->100只能放00
//	//00000010 00000001 00000000 00000000
//	pstPimData->d = 5;
//	// 5->101 放101
//	//00000010 00101001 00000000 00000000
//	printf("%02x %02x %02x %02x\n", puc[0], puc[1], puc[2], puc[3]);//%02x 以十六进制打印两位
//	//0000 0010 0010 1001 0000 0000 0000 0000
//	//  0	 2	  2	   9	0	 0	  0	   0
//	// 02 29 00 00
//
//	return 0;
//}


//求以下结果，小端模式下
//#include<stdio.h>
//
//int main()
//{
//	union
//	{
//		short k;
//		char i[2];
//
//	}*s,a;
//	s = &a;
//	s->i[0] = 0x39;
//	s->i[1] = 0x38;
//	// 0x39  0x38
//	//  0     1
//	//低     ->     高
//	printf("%x\n", a.k);//3839
//
//	return 0;
//}


//找单身狗
//一个数组中只有两个数字出现一次，其他所有数字都出现了两次，编写一个函数来找出这两个只出现一次的数字
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//
//void FindSingleNum(const int* parr,const int sz, int* p1, int* p2)
//{
//	assert(parr && p1 && p2);
//	//思路分组
//	int i = 0;
//	int ret = 0;
//	//1、所有数字先异或  
//	for (i = 0; i < sz; i++)
//	{
//		ret ^= *(parr + i);
//	}
//	//2、找出异或的结果最右边哪一位为1（假设第n为1）
//	int pos = 0;
//	for (pos = 0; pos < 32; pos++)
//	{
//		if (((ret >> pos) & 1) == 1)
//		{
//			break;
//		}
//	}
//	//3、以第n位分别为1与0来分组
//	for (i = 0; i < sz; i++)
//	{
//		if (((*(parr + i) >> pos) & 1) == 1)
//		{
//			*p1 ^= *(parr + i);
//		}
//		else
//		{
//			*p2 ^= *(parr + i);
//		}
//	}
//}
//
//int main()
//{
//	int i = 0;
//	int n = 0;
//	scanf("%d", &n);
//	int* arr = (int*)calloc(n, sizeof(int));
//	if (arr == NULL)
//	{
//		perror("arr");
//		return EXIT_FAILURE;
//	}
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", arr + i);
//	}
//
//	int n1 = 0, n2 = 0;
//	FindSingleNum(arr,n,&n1,&n2);
//	printf("%d %d\n", n1, n2);
//
//	free(arr);
//	arr = NULL;
//
//	return 0;
//}


//写一个宏，将一个整数的二进制位的奇数位和偶数位交换
//将从右边数起的第一位视为第0位（即偶数位）
//
// n & 0x55555555 能做到偶数位的保留，奇数位置0
// 0101 0101 0101 0101 0101 0101 0101 0101 //0x55555555
// 同理
// n & 0xaaaaaaaa 能做到寄数位的保留，偶数位置0
// 1010 1010 1010 1010 1010 1010 1010 1010 //0xaaaaaaaa
// 这样就实现一个数的二进制位的寄数位和偶数位的提取
// 
//再将(n & 0x55555555)<<1 和 (n & 0xaaaaaaaa)>>1 后相加，便可实现交换
//#include<stdio.h>
//#define SWAP_BIT(N) ((((N) & 0x55555555) << 1) + (((N) & 0xaaaaaaaa) >> 1))
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d\n", SWAP_BIT(n));
//	return 0;
//}


//求以下结果
//#include<stdio.h>
//
//int main()
//{
//	unsigned char i = 7;
//	int j = 0;
//	//unsigned char i始终>=0，唯有i==0时循环才停止
//	for (; i > 0; i -= 3)
//	{
//		j++;
//	}
//	printf("%d\n", j);//173
//	//7 4 1 
//	//-2
//	//10000000000000000000000000000010
//	//11111111111111111111111111111101
//	//11111111111111111111111111111110
//	//11111110	254
//	//254/3 == 84……2
//	//-1
//	//10000000000000000000000000000001
//	//11111111111111111111111111111110
//	//11111111111111111111111111111100
//	//11111100	252
//	//252 /3 == 84
//	//84+84+1+4==173
//	return 0;
//}


//求输入1abcdef2df(回车)后的输出结果
//#include<stdio.h>
//
//int main()
//{
//	char a = 0, ch;
//	while ((ch = getchar()) != '\n')
//	{
//		if ((a % 2 != 0) && (ch > 'a' && ch < 'z'))
//		{
//			ch = ch - 'a' + 'A';
//		}
//		a++;
//		putchar(ch);
//	}
//	printf("\n");
//
//	return 0;
//}


//斐波那契数列 f[i+2]=f[i]+f[i+1]，i从0起
//将斐波那契数列里的数成为斐波那契数，现给你一个数n，将其变为斐波那契数，
//每一步可以把数X变为X+1或X-1，请问将n变为斐波那契数最少需要多少步
// 1 <= n <= 1 000 000
//#include<stdio.h>
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int a = 0;
//	int b = 1;
//	int c = a + b;
//	while (1)
//	{
//		if (n == b)
//		{
//			printf("0\n");
//			break;
//		}
//		else if(n<b)
//		{
//			if ((n - a) > (b - n))
//			{
//				printf("%d\n", b - n);	
//			}
//			else
//			{
//				printf("%d\n", n - a);
//			}
//			break;
//		}
//		c = a + b;
//		a = b;
//		b = c;
//	}
//
//	return 0;
//}


//空格替换
//实现一个函数将字符串中的每个空格替换为“%20”
//#include<stdio.h>
//#include<string.h>
//#include<assert.h>
//#include<ctype.h>
//先知道空格个数，明确字符串要向后移多少格，再把字符串往后移并将空格改为%20
//void space_turn(char* str,int length)
//{
//	assert(str);
//	char* cur = str;
//	int space_count = 0;
//	while (*cur != '\0')
//	{
//		if (isspace(*cur))
//		{
//			space_count++;
//		}
//		cur++;
//	}
//	int end1 = length - 1;
//	int end2 = length + space_count * 2 - 1;
//	while (end1 != end2)
//	{
//		if (*(str + end1) != ' ')
//		{
//			*(str + end2) = *(str + end1);
//			end1--;
//			end2--;
//		}
//		else
//		{
//			end1--;
//			*(str + end2--) = '0';
//			*(str + end2--) = '2';
//			*(str + end2--) = '%';
//		}
//	}
//
//}
//
//int main()
//{
//	char ch[20] = { 0 };
//	gets(ch);
//	int len = strlen(ch);
//	space_turn(ch,len);
//	printf("%s\n", ch);
//
//	return 0;
//}


//蛇形方阵
//#include<stdio.h>
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[9][9] = { 0 };
//	int i = 0, j = 0;
//	int num = 1;
//	while (num <= n * n)
//	{
//		while (j < n && arr[i][j] == 0)
//		{
//			arr[i][j++] = num++;
//		}
//		j--;
//		i++;
//		while (i < n && arr[i][j] == 0)
//		{
//			arr[i++][j] = num++;
//		}
//		i--;
//		j--;
//		while (j >= 0 && arr[i][j] == 0)
//		{
//			arr[i][j--] = num++;
//		}
//		i--;
//		j++;
//		while (i >= 0 && arr[i][j] == 0)
//		{
//			arr[i--][j] = num++;
//		}
//		i++;
//		j++;
//	}
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			printf("%3d", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}


//假设每次键盘输入时，都按到原本要按的按键右边一个，请将输入内容还原为原本内容并输出
//#include<stdio.h>
//
//int main()
//{
//	char ch[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
//	int i = 0, c = 0;
//	while ((c = getchar()) != EOF)
//	{
//		for (i = 1; ch[i] && ch[i] != c; i++)
//		{
//			;
//		}
//		if (ch[i])
//			putchar(ch[i - 1]);
//		else
//			putchar(c);
//	}
//
//	return 0;
//}


////判断一个串是否位回文串或镜像串(输入字符不包括字符0,且如果是字母都为大写)，多组输入
//#include<stdio.h>
//#include<string.h>
//#include<ctype.h>
//
//int main()
//{
//	char mirror[] = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
//	char* answer[] = { "not palindrome","regular palindrome","mirrored string","mirrored palindrome" };
//	char arr[30] = { 0 };
//
//	while (scanf("%s", arr) == 1)
//	{
//		int len = strlen(arr);
//		int i = 0, pal = 1, mir = 1;
//		for (i = 0; i < len / 2; i++)
//		{
//			if (arr[i] != arr[len - i - 1])
//				pal = 0;
//			if (isalpha(arr[i]))
//			{
//				if (arr[len-i-1] != mirror[arr[i] - 'A'])
//					mir = 0;
//			}
//			else
//			{
//				if (arr[len - i - 1] != mirror[arr[i] - '0' + 25])
//					mir = 0;
//			}
//		}
//		printf("%s is %s\n", arr, answer[2 * mir + pal]);
//	}
//	
//	return 0;
//}


//《算法入门》例3-4
//#include<stdio.h>
//
//int main()
//{
//	int n = 0, ansarr[1010] = { 0 }, guestarr[1010] = { 0 };
//	int times = 1;
//	while (scanf("%d", &n) == 1)
//	{
//		if (n == 0)
//			break;
//		int i = 0;
//		for (i = 0; i < n; i++)
//		{
//			scanf("%d", &ansarr[i]);
//		}
//		while (1)
//		{
//			int A = 0, B = 0;
//			//统计正确的个数A
//			for (i = 0; i < n; i++)
//			{
//				scanf("%d", &guestarr[i]);
//				if (guestarr[i] == ansarr[i])
//					A++;
//			}
//			//猜测数组中有0退出
//			if (guestarr[0] == 0)
//				break;
//			//计算B = min(ascount,guestcount) - A
//			//统计数字0-9 各在两个序列中出现几次
//			for (i = 1; i < 10; i++)
//			{
//				int j = 0;
//				int anscount = 0, guestcount = 0;
//				for (j = 0; j < n; j++)
//				{
//					if (i == ansarr[j])
//						anscount++;
//					if (i == guestarr[j])
//						guestcount++;
//				}
//				if (anscount > guestcount)
//				{
//					B += guestcount;
//				}
//				else
//				{
//					B += anscount;
//				}
//			}
//			B -= A;
//
//			printf("game %d:\n", times++);
//			printf("(A = %d,B = %d)\n", A, B);
//		}
//	}
//	return 0;
//}


//将字符串左逆置k个字符
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//
//void left_reverse(char* str,int k)
//{
//	assert(str);
//	while (k--)
//	{
//		char tmp = *str;
//		char* cur = str;
//		while (*(cur+1)!= '\0')
//		{
//			*cur = *(cur + 1);
//			cur++;
//		}
//		*cur = tmp;
//	}
//}
//
//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d", &n);
//	char* ch = (char*)calloc(n, sizeof(char));
//	if (ch == NULL)
//	{
//		exit(-1);
//	}
//	scanf("%s", ch);
//	scanf("%d", &k);
//	left_reverse(ch,k);
//	printf("%s\n", ch);
//
//	free(ch);
//	ch = NULL;
//
//	return 0;
//}


//其他数字都出现两次情况下，找出只出现一次的两个数字
//#include<stdio.h>
//#include<stdlib.h>
//
//cmp_bylarge(const void* e1, const void* e2)
//{
//	return (*(int*)e1 - *(int*)e2);
//}
//
//two_singlenum(int arr[10], int sz, int* n1, int* n2)
//{
//	if (!arr)
//		return NULL;
//	//法一
//	/*qsort(arr, sz, sizeof(int), cmp_bylarge);
//	int i = 0;
//	int found = 0;
//	for (i = 0; i < sz; i++)
//	{
//		if (arr[i] != arr[i + 1] && i == 0)
//		{
//			*n1 = arr[i];
//			found++;
//		}
//		if (arr[i] != arr[i + 1] && arr[i+1] != arr[i + 2])
//		{
//			if (found)
//			{
//				*n2 = arr[i+1];
//			}
//			else
//			{
//				*n1 = arr[i+1];
//				found++;
//			}
//		}
//		if (arr[i] != arr[i + 1] && i < sz - 1)
//		{
//			*n2 = arr[i + 1];
//		}
//	}*/
//
//	//法二
//
//}
//
//int main()
//{
//	int n1 = 0, n2 = 0;
//	int arr[10] = { 1,2,1,2,6,3,5,4,4,3 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	two_singlenum(arr, sz, &n1, &n2);
//	printf("%d %d\n", n1, n2);
//
//	return 0;
//}