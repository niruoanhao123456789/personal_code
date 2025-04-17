#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<errno.h>

typedef int LTDataType;

typedef struct DoubleListNode
{
	LTDataType data;
	struct DoubleListNode* next;
	struct DoubleListNode* prev;
}LTNode;

//无哨兵位头结点
//void ListInit(LTNode** phead);
//创建哨兵位头结点
LTNode* ListInit();

void ListDestroy(LTNode* phead);

void ListPrint(LTNode* phead);

void ListPushBack(LTNode* phead,LTDataType val);

void ListPushFront(LTNode* phead, LTDataType val);

void ListPopBack(LTNode* phead);

void ListPopFront(LTNode* phead);

LTNode* ListFind(LTNode* phead, LTDataType val);

void ListInsert(LTNode* pos, LTDataType val);

void ListErase(LTNode* pos);