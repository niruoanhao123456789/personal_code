#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#include<math.h>
#include<assert.h>
#include<stdbool.h>

typedef int HPDataType;
struct Heap
{
	HPDataType* data;
	int size;
	int capacity;
};
typedef struct Heap Heap;

bool HPEmpty(Heap* php);
void HeapInit(Heap* php);
void HeapDestory(Heap* php);
void HPPrint(Heap php);

void Swap(HPDataType* x, HPDataType* y);
void AdjustUp(HPDataType* arr, int child);
void AdjustDown(HPDataType* arr, int parent, int n);

//以大堆为例，改写为小堆的话将数据比较的不等号改变方向
void HeapPush(Heap* php, HPDataType x);
void HPPop(Heap* php);
HPDataType HPTop(Heap* php);