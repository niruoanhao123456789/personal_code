#include"score.h"

int input_course_id(long long teacher_id)
{
    int course_id = 0;
    char arr[10] = { 0 };
    printf("\n课程列表：\n");
    struct course_node* course = course_head;
    printf("课程ID      课程名称\n");
    while (course != NULL) 
    {
        if (course->teacher_id == teacher_id) 
        {
            printf("%-10d  %-10s\n", course->course_id, course->course_name);
        }
        course = course->next;
    }
    //printf("-1: 返回\n");
    printf("请选择课程ID：");
    scanf("%s", arr);
    int len = strlen(arr);
    int sum = 0;
    int i = 0;
    for (i = 0; i < len; i++)
    {
        sum += (arr[i] - '0')*pow(10,len-i-1);//将字符转化为数字
    }
    course_id = sum;
    if (get_course_by_id(course_id) == NULL) 
    {
        return -1;
    }
    return course_id;
}

int teacher_input_score(int course_id) 
{
    if (get_course_by_id(course_id) == NULL) 
    {
        printf("无效课程ID\n");
        return -1;
    }
    int i = 0;
    long long student_id = 0;
    float score = 0.0f;
    char stu_name[10] = { 0 };
    printf("请在下面依次输入学生姓名、id和成绩(例子：xxx 114514 90)，一行一个数据，输入0 -1 -1为结束：\n请输入：\n");
    scanf("%s%lld%f",stu_name, &student_id, &score);
    int len = strlen(stu_name);
    long long sum = 0;
    for (i = 0; i < len; i++)
    {
        sum += (*(stu_name + i) - '0') * pow(10, len - i - 1);
    }
    while (1)
    {
        if (student_id == -1 && score == -1 && sum == 0)
        {
            break;
        }
        if (student_id == -1 && score == -1)
        {
            printf("输入错误\n");
        }
        insert_score(course_id, stu_name, student_id, (int)floor(score * 10));
        scanf("%s%lld%f", stu_name, &student_id, &score);
        len = strlen(stu_name);
        sum = 0;
        for (i = 0; i < len; i++)
        {
            sum += (*(stu_name + i) - '0') * pow(10, len - i - 1);
        }
    }
    printf("录入完成\n");
}

int input_course_id_student(long long student_id)
{
    int course_id;
    printf("\n课程ID      课程名称\n\n");
    struct course_node* course = course_head;
    while (course != NULL) 
    {
        if (get_score_by_course(course, student_id) != NULL) 
        {
            printf("%-10d  %-10s\n", course->course_id, course->course_name);
        }
        course = course->next;
    }
    //printf("-1: 返回\n");
    printf("请选择课程id：");
    scanf("%d", &course_id);
    if (get_course_by_id(course_id) == NULL) 
    {
        return -1;
    }
    return course_id;
}