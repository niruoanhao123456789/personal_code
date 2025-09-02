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
//#include<stdio.h>
//#include<stdlib.h>
////命名空间中可以定义变量、函数、类型、甚至命名空间的嵌套定义，但命名空间只能定义在全局
//namespace cl
//{
//	int rand = 1;
//
//	int Add(int x, int y)
//	{
//		return (x + y);
//	}
//	
//	struct Node
//	{
//		int val;
//		struct Node* next;
//	};
//
//	namespace clt
//	{
//		int rand = 3;
//	}
//}
//
//int a = 1;
//
//int main()
//{
//	//编译器语法查找确认，默认先局部再全局，不会主动查找命名空间里的
//	//如果指定了作用域，就直接去该域里进行查找
//
//	int a = 0;
//	printf("%d\n", a);
//	//::域作用限定符
//	printf("%d\n", ::a);//全局
//
//	printf("%p\n", rand);
//	printf("%d\n", cl::rand);
//
//	//printf("%p\n", Add);//err
//	printf("%p\n", cl::Add);
//
//	/*struct Node s;*/
//	struct cl:: Node s;
//	printf("%d\n", cl::clt::rand);
//
//	return 0;
//}
//
//在多文件中定义同一个命名空间，系统会默认将它们合并来理解，因此命名空间能很好解决大型项目里不同文件命名冲突的情况


//输入输出流
//用于解决C语言单一的输入输出的问题
#include<iostream>
using namespace std;//展开命名空间
//::的建议在项目中使用，防止命名冲突；而展开命名空间可在平时写简易代码时使用

//部分展开
using std::cout;
using std::endl;

int main()
{
	int i = 10;
	i << 1;//<<在C++中和整型在一起时仍是移位操作符
	double d = 1.1;

	//当<< >>和cin cot这两个类在一起时，<<是流插⼊运算符，>>是流提取运算符
	//流插⼊运算符就是将任何变量转换为字符串（窄字符），插入到流中；流提取运算符就是将变量转换为字符串来输出
	std::cout << i<<"\n";
	std::cout << "Hello World\n";
	std::cout << i << " " << d<<std::endl;//endline C++中换行

	std::cin >> i >> d;
	std::cout << i << d << std::endl;

	//展开命名空间后，就不用指明该作用域了,但如果定义了重名的全局或局部变量就会出现命名冲突
	/*int cout = 0;
	cout << i << d << endl;*/

	return 0;
}