//#include<iostream>
//using namespace std;
//
//int main()
//{
//	cout << "hello world\n" << endl;
//
//	return 0;
//}


//命名空间
//C中存在着在定义全局变量时如果变量名同某个库函数重名，运行时会报错的情况
//#include<stdio.h>
//#include<stdlib.h>
//
//int rand = 0;
//
//int main()
//{
//	
//	printf("%d\n", rand);
//	return 0;
//}
// 
//C++中命名空间得存在得以解决这个变量名命名的问题
#include<stdio.h>
#include<stdlib.h>
//命名空间中可以定义变量、函数、类型、甚至命名空间的嵌套定义，但命名空间只能定义在全局
namespace cl
{
	int rand = 1;

	int Add(int x, int y)
	{
		return (x + y);
	}
	
	struct Node
	{
		int val;
		struct Node* next;
	};

	namespace clt
	{
		int rand = 3;
	}
}

int a = 1;

int main()
{
	//编译器语法查找确认，默认先局部再全局，不会主动查找命名空间里的
	//如果指定了作用域，就直接去该域里进行查找

	int a = 0;
	printf("%d\n", a);
	//::域作用限定符
	printf("%d\n", ::a);//全局

	printf("%p\n", rand);
	printf("%d\n", cl::rand);

	//printf("%p\n", Add);//err
	printf("%p\n", cl::Add);

	/*struct Node s;*/
	struct cl:: Node s;
	printf("%d\n", cl::clt::rand);

	return 0;
}