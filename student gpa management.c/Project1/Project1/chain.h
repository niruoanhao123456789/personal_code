#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<errno.h>
#include<assert.h>

#define STR_BUFFER_SIZE 50
#define LINE_BUFFER_SIZE 1000

typedef struct score_node {
    int student_id;
    int score;
    char student_name[10];
    struct score_node* next;
    struct score_node* prev;
}score_node;

typedef struct course_node {
    char course_name[STR_BUFFER_SIZE];
    int course_id;
    int teacher_id;
    struct score_node* score_head;
    struct score_node* score_tail;
    struct course_node* next;
    struct course_node* prev;
}course_node;

extern course_node *course_head;
extern course_node *course_tail;

//通过课程ID找课程结点，无该课程则返回NULL
course_node *get_course_by_id(int course_id);

//通过学生ID和课程ID找学生的课程成绩结点，无成绩则返回NULL
score_node *get_score_by_id(int course_id, int student_id);

//通过课程结点和学生ID找学生的课程成绩结点，无成绩则返回NULL
score_node *get_score_by_course(struct course_node *course, int student_id);

//输入成绩，成功返回0，失败返回-1
int insert_score(int course_id, const char* student_name,int student_id, int score);

//更改成绩，成功返回0，失败返回-1
int update_score(int course_id, int student_id, int score);

//添加课程
void new_course(const char *course_name, int course_id, int teacher_id);

//删除课程
void delete_course(int course_id);

//删除成绩
void delete_score(int course_id, int student_id);

//加载文件数据到双向链表
void load_course_list(const char *filename);

void load_score_list(const char *filename);

//保存双向链表数据到文件
void save_course_list(const char *filename);

void save_score_list(const char *filename);

////释放申请内存
void CourseListDestory(course_node **pphead);