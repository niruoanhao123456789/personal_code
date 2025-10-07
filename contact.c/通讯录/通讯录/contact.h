#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<errno.h>

#define MAX 100
#define DEFAULT_SZ 3
#define INC_SZ 2
#define _CRT_SECURE_NO_WARNINGS 1

//类型的声明也可放在头文件里
//人的信息
typedef struct PeoInfo
{
	int age;
	char sex[10];
	char tele[12];
	char name[20];
	char adder[30];
} PeoInfo;

//通讯录 (采用顺序表)
typedef struct Contact
{
	PeoInfo data[MAX];//存放人的信息
	int count;//记录通讯录中实际人的个数，即该线性表的长度
} Contact;

//动态版
//typedef struct Contact
//{
//	PeoInfo* data;//存放人的信息
//	int count;//记录通讯录中实际人的个数，即该线性表的长度
//	int capacity;//记录通讯录的容量
//} Contact;

//初始化通讯录
void Initcontact(Contact* pc);
//int Initcontact(Contact* pc);

//销毁通讯录
//void DestoryContact(Contact* pc);

//添加联系人通讯录
void AddContact(Contact* pc);

//显示通讯录信息
void ShowContact(const Contact* pc);

//删除指定联系人
void DelContact(Contact* pc);

//查找指定联系人
void SearchContact(const Contact* pc);

//修改指定联系人信息
void ModifyContact(Contact* pc);

//排序通讯录的内容
void SortContact(Contact* pc);

//保存通讯录内容
void SaveContact(const Contact* pc);

//加载文件
void LoadContact(Contact* pc);
//