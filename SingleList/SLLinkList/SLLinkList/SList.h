#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<errno.h>

typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

void SListPrint(SLTNode* phead);

void SListPushBack(SLTNode** pphead, SLTDataType x);

void SListPushFront(SLTNode** pphead, SLTDataType x);

void SListPopBack(SLTNode** pphead);

void SListPopFront(SLTNode** pphead);

SLTNode* SListFind(SLTNode* phead, SLTDataType x);

//在pos位置后面插入一个节点
void SListInsertAfter(SLTNode* pos, SLTDataType x);

//思路一：在pos位置之前插入一个节点
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
//思路二：
//void SListInsert(SLTNode** pphead, int pos, SLTDataType x);

void SListEase(SLTNode** pphead, SLTNode* pos);

void SListEaseAfter(SLTNode* pos);

void SListDestroy(SLTNode** pphead);