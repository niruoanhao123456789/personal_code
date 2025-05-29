#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<errno.h>
#include<ctype.h>
#include<stddef.h>

//程序文件、数据文件

//文本文件、二进制文件
//文本文件将文本内容拆为字符，并用ASCII形式来存储
//二进制文件则将文本内容用二进制形式来存储
//字符一律以ASCII码存储，数值型数据可用ASCII码存储，也可以用二进制存储
//二进制文件可从源文件添加现有项，将相应二进制文件用二进制编译器来打开，可观察里面的内容
//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("test.txt", "wb");
//	fwrite(&a, 4, 1, pf);
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//流
//任何一个C程序，只要运行就会默认打开三个流
//FILE* stdin  标准输入流（键盘）
//FILE* stdout 标准输出流（屏幕）
//FILE* stderr 标准错误流（屏幕）
//这三个流的类型为FILE*也就是文件指针

//文件的使用
//文件的打开
//当打开硬盘里的一个文件时，该文件会在内存中创建一个FILE结构体类型的文件信息区，并可通过相应的文件指针进行维护
//并用文件指针FILE*来进行管理
// "r"只读，前提是文件存在
// "w"只写，文件不存在会自动创建一个文件
// "a"追加，文件不存在会自动创建一个文件
//int main()
//{
//	//FILE* pf = fopen("C:\\Users\\你若安好\\Desktop\\text.txt", "r");//用绝对路径打开文件
//	FILE* pf = fopen("learn.txt", "r");//此处pf就是一个文件指针		用相对路径打开文件
// 
//  //文件名处 . 表示当前路径  .. 表示上一级路径（在相对路径中） 
//  //FILE* pf = fopen("./../../learn.txt", "r");
//	
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//
//	//读文件
//	
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//文件的读写
//字符输入函数fgetc()	读取失败返回EOF
//字符输出函数fputc()
//文本行输入fgets()     一直读到\n并在末尾加\0
//文本行输出fputs()		遇到\0就会停止
//格式化输入fscanf()
//格式化输出fprintf()
//二进制输入fread()
//二进制输出fwrite()
//
//int main()
//{
//	fputc('a', stdout);//写到标准输出流里
//	//相当于putchar()
//
//	int ch = fgetc(stdin);
//	fputc(ch, stdout);
//
//	return 0;
//}
//
//int main()
//{
//	//打开文件
//	FILE* pf = fopen("test.txt", "r");
//	//FILE* pf = fopen("test.txt", "w");//写文件时，如果该文件上有内容时，会先将原有内容清空再写文件
//	//FILE* pf = fopen("test.txt", "a");
//	if (pf == NULL)
//	{
//		//printf("fopen: %s\n", strerror(errno));
//		perror("fopen");//这个和上一行代码作用一样
//		return 1;
//	}
//
//	//字符
//	//写文件
//	/*int i = 0;
//	for (i = 'a'; i <= 'f'; i++)
//	{
//		fputc(i, pf);
//	}*/
//	//读文件
//	//int ch = 0;
//	////printf("%c\n", ch);
//	//while ((ch = fgetc(pf)) != EOF)
//	//{
//	//	printf("%c ", ch);
//	//}
//
//	//字符串
//	//写文件
//	/*fputs("hello world ", pf);
//	fputs("hello world\n", pf);
//	fputs("hello world\n", pf);*/
//	//fputs("hello \0 xxx");//fputs遇到\0会停止写入到文件
//
//	//读文件
//	//char arr[12] = { 0 };
//	//fgets(arr, 12, pf);
//	////	这里的数字参数12是字符个数+'\0'的总和
//	//printf("%s\n", arr);
//
//	//关闭
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}
//
//struct S
//{
//	char name[20];
//	int age;
//	double score;
//};
//int main()
//{
//	//struct S s = { "zhangshan",18,90.5f };
//	//FILE* pf = fopen("test.txt", "w");
//
//	struct S s = {0};
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	//fprintf(pf, "%s %d %lf", s.name, s.age, s.score);//将内容写在文件里
//
//	fscanf(pf, "%s %d %lf", s.name, &s.age, &s.score);
//	//printf("%s %d %lf\n", s.name, s.age, s.score);
//	fprintf(stdout, "%s %d %lf\n", s.name, s.age, s.score);//将内容写到屏幕上
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//
//struct S
//{
//	char name[20];
//	int age;
//	double score;
//};
//
////int main()
////{
////	struct S s = { "zhangshan",18,90.5f };
////	//以二进制写到文件中
////	FILE* pf = fopen("test.txt", "wb");
////	if (pf == NULL)
////	{
////		perror("fopen");
////		return 1;
////	}
////
////	//二进制的方式写
////	fwrite(&s, sizeof(struct S), 1, pf);//以s的起始地址，大小为sizeof(struct S)，每次写一个到pf这个流里
////	
////	fclose(pf);
////	pf = NULL;
////	return 0;
////}
////
//int main()
//{
//	struct S s = {0};
//	FILE* pf = fopen("test.txt", "rb");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	
//	fread(&s, sizeof(struct S), 1, pf);
//	printf("%s %d %lf", s.name, s.age, s.score);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//比较scanf printf、fscanf fprintf、sscanf sprintf
//scanf   是针对标准输入的格式化输入语句
//printf  是针对标准输出的格式化输出语句
// 
//fscanf  是针对所有输入流的格式化输入语句
//fprintf 是针对所有输出流的格式话输出语句
// 
//sscanf  从字符串中获取格式化数据到变量中
//sprintf 将格式化的数据写到字符串中，但不会在末尾填上\0

//struct S
//{
//	char name[20];
//	int age;
//	double score;
//};
//
//int main()
//{
//	struct S s = { "zhangshan",18,90.5f };
//	struct S tmp = { 0 };
//	char buf[100] = { 0 };
//
//	//将格式化的数据写到字符串中
//	sprintf(buf, "%s %d %lf", s.name, s.age, s.score);
//	printf("%s\n", buf);
//
//	//从字符串中获取格式化数据到变量中
//	sscanf(buf, "%s %d %lf", tmp.name, &tmp.age, &tmp.score);
//	printf("%s %d %lf\n", tmp.name, tmp.age, tmp.score);
//
//	return 0;
//}

//文件的随机读写
//fseek() 根据文件指针的位置和偏移量来定位文件指针
//ftell() 返回文件指针相对于起始位置的偏移量
//rewind() 让文件指针的位置回到文件的起始位置
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("pf");
//		return 1;
//	}
//
//	int ch = fgetc(pf);
//	printf("%c\n", ch);
//
//	//定位文件指针
//	fseek(pf, 2, SEEK_SET);
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//	printf("%d\n", ftell(pf));
//
//	//fseek(pf, 2, SEEK_CUR);
//	//ch = fgetc(pf);
//	//printf("%c\n", ch);
//
//	fseek(pf, -1, SEEK_END);
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//	printf("%d\n", ftell(pf));
//
//	rewind(pf);
//	ch = fgetc(pf);
//	printf("%c", ch);
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//文件读取结束的判定
// 
//读文件时，如果遇到文件末尾就会在对应的流上设置一个文件结束指示符
//feof就检测该文件结束指示符是否被设置，被设置返回非0，未设置返回0
//同时函数feof可用于当文件读取结束时，判断是因读取失败结束，还是遇到文件末结束
//而不是用feof的返回值来判断文件是否结束，其返回值为真就是遇到文件末结束
// 
//函数ferror()返回值为真就是遇到错误读取失败
//相对应的ferror()也有个文件错误指示符
// 
//文本文件读取是否结束，判断返回值是否EOF(fgetc)或者NULL(fgets)
//二进制文本读取是否结束，判断返回值是否小于实际要读的个数

//  文件缓冲区
// 缓冲：
// 完全缓冲 、换行缓冲、无缓冲
// 文件和程序正常结束时会刷新
// fflush()可以强制刷新缓冲区  仅对输入流与更新流有明确刷新行为

//更新文件
//w+ r+ a+
//