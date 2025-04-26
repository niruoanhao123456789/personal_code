#pragma once
#include<stdbool.h>
#include<math.h>
#include"userdata.h"
#include"score.h"

//身份为teacher，identity为1
//身份为student，identity为2
//登录函数，成功则返回true，失败返回false
bool login(Users* user, int* user_id, int identity);

void user_interface(Users* user, int identity);

void tea_interface(int user_id);

void stu_interface(int user_id);