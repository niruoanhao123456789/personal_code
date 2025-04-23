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
	int user_id;
}Userdata;
typedef Userdata SLDataType;

typedef struct SeqList
{
	SLDataType* data;
	int count;
	int capacity;
}SeqList;
typedef SeqList Users;

//初始化顺序表
void SeqlistInit(SeqList* ps, const char* filename);

//添加用户信息
void SeqListPushBack(SeqList* ps, const char* filename);

//删除用户信息
void SeqListPopBack(SeqList* ps, const char* filename);

//用学号来找用户，找到返回下标，找不到则返回-1
int SeqListFind_ByID(const SeqList* ps, int user_id);

//针对对应下标的添加用户信息
void SeqListModify(SeqList* ps, int pos);

//针对对应下标的删除用户信息
void SeqListErase(SeqList* ps, int pos);

//将顺序表里的用户数据储存到相应文件
void save_user_data(SeqList* ps, const char* filename);

void SeqListPrint(const SeqList* ps);

//释放申请内存
void SeqListDestory(SeqList* ps);