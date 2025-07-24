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
//ÒÔ´ó¶ÑÎªÀý
void HeapPush(Heap* php, HPDataType x);