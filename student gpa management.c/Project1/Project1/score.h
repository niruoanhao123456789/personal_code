#pragma once
#include<math.h>
#include"chain.h"

//返回课程ID，无该课程则返回-1
int input_course_id(long long teacher_id);

//输入成绩，输入失败返回-1
int teacher_input_score(int course_id);

//通过学生ID找所要课程ID，寻找失败返回-1
int input_course_id_student(long long student_id);