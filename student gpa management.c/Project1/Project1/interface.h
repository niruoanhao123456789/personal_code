#pragma once
#include<stdbool.h>
#include"userdata.h"
#include"score.h"

//登录函数，登录成功返回true，失败返回false
bool login(Users* user, int *user_id, int identity);

//下面是用户交互函数
//teacher的identity为1
//student的identity为2
void user_interface(Users* user, int identity);

void tea_interface(int user_id);

void stu_interface(int user_id);