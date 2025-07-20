#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<errno.h>

#define MAX 100

typedef int SLDataType;

//静态顺序表
//typedef struct SeqList
//{
//	SLDataType data[MAX];
//	int count;
//}SeqList;

//动态顺序表
typedef struct SeqList
{
	SLDataType* data;
	int count;//表示当前顺序表线长，即实际有效储存的数据个数
	int capaicty;//表示顺序表目前最大长度
}SeqList;

void SeqListPrint(const SeqList* ps);

//增删查改
void SeqListInit(SeqList* ps);

void SeqListPushFront(SeqList* ps, SLDataType x);

void SeqListPushBack(SeqList* ps, SLDataType x);

void SeqListPopBack(SeqList* ps);

void SeqListPopFront(SeqList* ps);

void SeqListInsert(SeqList* ps, int pos, SLDataType x);

void SeqListInsertAfter(SeqList* ps, int pos, SLDataType x);

void SeqListErase(SeqList* ps, int pos);

//找到返回下标，找不到则返回-1
int SeqListFind(const SeqList* ps, SLDataType x);

//销毁顺序表
void SeqListDestory(SeqList* ps);