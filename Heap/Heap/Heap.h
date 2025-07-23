#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#include<math.h>
#include<assert.h>

typedef int HPDataType;
struct Heap
{
	HPDataType* data;
	int size;
	int capacity;
};
typedef struct Heap Heap;

void HeapInit(Heap* php);

void HeapDestory(Heap* php);