#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>

#define STR_BUFFER_SIZE 50
#define LINE_BUFFER_SIZE 1000

typedef struct Userdata
{
	char password[STR_BUFFER_SIZE];
	char name[STR_BUFFER_SIZE];
	long long phone_num;
	long long user_id;
}Userdata;
typedef Userdata SLDataType;

typedef struct SeqList
{
	SLDataType* data;
	int count;
	int capacity;
}SeqList;
typedef SeqList Users;

void SeqlistInit(SeqList* ps, const char* filename);

void SeqListPushBack(SeqList* ps, const char* filename);

void SeqListPopBack(SeqList* ps, const char* filename);


int SeqListFind_ByID(const SeqList* ps, int user_id);

void SeqListModify(SeqList* ps, int pos);

void SeqListErase(SeqList* ps, int pos);

void save_user_data(SeqList* ps, const char* filename);

void SeqListPrint(const SeqList* ps);

void SeqListDestory(SeqList* ps);