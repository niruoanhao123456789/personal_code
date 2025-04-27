#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#include<errno.h>

//À≥–Ú’ª
typedef int STDataType;
typedef struct Stack
{
	STDataType* data;
	int top;
	int capacity;
}Stack;

void StackInit(Stack* ps);

void StackDestroy(Stack* ps);

void StackPush(Stack* ps, STDataType x);

void StackPop(Stack* ps);

STDataType StackTop(Stack* ps);

int StackSize(Stack* ps);

bool StackEmpty(Stack* ps);

void StackPrint(Stack* ps);