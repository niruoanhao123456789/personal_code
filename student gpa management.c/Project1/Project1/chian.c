#include "chain.h"

course_node *course_head = NULL;
course_node *course_tail = NULL;

course_node *get_course_by_id(int course_id) 
{
    course_node *now_course = course_head;
    while (now_course != NULL) 
    {
        if (now_course->course_id == course_id) 
        {
            return now_course;
        }
        now_course = now_course->next;
    }
    return NULL;
}

score_node *get_score_by_id(int course_id, int student_id) 
{
    course_node *course = get_course_by_id(course_id);
    if (course == NULL) 
    {
        return NULL;
    }
    score_node *now_score = course->score_head;
    while (now_score != NULL) 
    {
        if (now_score->student_id == student_id)
        {
            return now_score;
        }
        now_score = now_score->next;
    }
    return NULL;
}

score_node *get_score_by_course(struct course_node *course, int student_id) 
{
    if (course == NULL) 
    {
        return NULL;
    }
    score_node *now_score = course->score_head;
    while (now_score != NULL) 
    {
        if (now_score->student_id == student_id) 
        {
            return now_score;
        }
        now_score = now_score->next;
    }
    return NULL;
}

int insert_score(int course_id,const char* student_name, int student_id, int score)
{
    assert(student_name);
    course_node *course = get_course_by_id(course_id);
    if (course == NULL) 
    {
        return -1;
    }
    score_node *tmp = (struct score_node *)malloc(sizeof(struct score_node));
    if (tmp == NULL)
    {
        printf("%s\n", strerror(errno));
        exit(-1);
    }
    tmp->student_id = student_id;
    tmp->score = score;
    strcpy(tmp->student_name, student_name);
    tmp->next = NULL;
    tmp->prev = NULL;
    if (course->score_head == NULL) 
    {
        course->score_head = tmp;
        course->score_tail = tmp;
    } 
    else 
    {
        course->score_tail->next = tmp;
        tmp->prev = course->score_tail;
        course->score_tail = tmp;
    }
    return 0;
}

int update_score(int course_id, int student_id, int score) 
{
    struct score_node *now_score = get_score_by_id(course_id, student_id);
    if (now_score == NULL) 
    {
        return -1;
    }
    now_score->score = score;
    return 0;
}

void new_course(const char *course_name, int course_id, int teacher_id) 
{
    assert(course_name);
    course_node *tmp = (struct course_node *)malloc(sizeof(struct course_node));
    if (tmp == NULL)
    {
        printf("%s\n", strerror(errno));
        exit(-1);
    }
    strcpy(tmp->course_name, course_name);
    tmp->course_id = course_id;
    tmp->teacher_id = teacher_id;
    tmp->score_head = NULL;
    tmp->score_tail = NULL;
    tmp->next = NULL;
    tmp->prev = NULL;
    if (course_head == NULL) 
    {
        course_head = tmp;
        course_tail = tmp;
    }
    else
    {
        course_tail->next = tmp;
        tmp->prev = course_tail;
        course_tail = tmp;
    }
}

void delete_course(int course_id) 
{
    struct course_node *course = get_course_by_id(course_id);
    if (course == NULL) 
    {
        return;
    }
    if (course == course_head && course == course_tail)
    {
        course_head = NULL;
        course_tail = NULL;
    } 
    else if (course == course_head)
    {
        course_head = course_head->next;
        course_head->prev = NULL;
    } 
    else if (course == course_tail) 
    {
        course_tail = course_tail->prev;
        course_tail->next = NULL;
    } else 
    {
        course->next->prev = course->prev;
        course->prev->next = course->next;
    }
    struct score_node *score = course->score_head;
    struct score_node *next_score;
    while (score != NULL) 
    {
        next_score = score->next;
        free(score);
        score = next_score;
    }
    free(course);
}

void delete_score(int course_id, int student_id) 
{
    struct course_node *course = get_course_by_id(course_id);
    if (course == NULL) 
    {
        return;
    }
    struct score_node *score = get_score_by_course(course, student_id);
    if (score == NULL) 
    {
        return;
    }
    if (score == course->score_head && score == course->score_tail)
    {
        course->score_head = NULL;
        course->score_tail = NULL;
    }
    else if (score == course->score_head) 
    {
        course->score_head = course->score_head->next;
        course->score_head->prev = NULL;
    } 
    else if (score == course->score_tail) 
    {
        course->score_tail = course->score_tail->prev;
        course->score_tail->next = NULL;
    }
    else 
    {
        score->prev->next = score->next;
        score->next->prev = score->prev;
    }
    free(score);
    score = NULL;
}

void load_course_list(const char *filename)
{
    assert(filename);
    FILE *f = fopen(filename, "r");
    if (f == NULL) 
    {
        perror(fopen);
        return;
    }
    char line_buffer[LINE_BUFFER_SIZE];
    struct course_node *tmp;
    char course_name[STR_BUFFER_SIZE];
    int course_id;
    int teacher_id;
    while (fgets(line_buffer, LINE_BUFFER_SIZE, f) != NULL) 
    {
        sscanf(line_buffer, "%s %d %d", &course_name, &course_id, &teacher_id);
        //printf("%s\n%d\n%d\n", course_name, course_id, teacher_id);
        tmp = (struct course_node *)malloc(sizeof(struct course_node));
        strcpy(tmp->course_name, course_name);
        tmp->course_id = course_id;
        tmp->teacher_id = teacher_id;
        tmp->score_head = NULL;
        tmp->score_tail = NULL;
        tmp->next = NULL;
        tmp->prev = NULL;
        if (course_head == NULL) 
        {
            course_head = tmp;
            course_tail = tmp;
        }
        else 
        {
            course_tail->next = tmp;
            tmp->prev = course_tail;
            course_tail = tmp;
        }
    }
    fclose(f);
    f = NULL;
}

void load_score_list(const char *filename)
{
    assert(filename);
    FILE *f = fopen(filename, "r");
    if (f == NULL) 
    {
        perror(fopen);
        return;
    }
    char line_buffer[LINE_BUFFER_SIZE];
    struct score_node *tmp;
    struct course_node *course;
    int course_id;
    int student_id;
    int score;
    char name[10] = { 0 };
    while (fgets(line_buffer, LINE_BUFFER_SIZE, f) != NULL)
    {
        sscanf(line_buffer, "%s %d %d %d", name, &course_id, &student_id, &score);
        printf("%s %d %d %d\n", name, course_id, student_id, score);
        tmp = (struct score_node *)malloc(sizeof(struct score_node));
        if (tmp == NULL)
        {
            printf("%s\n", strerror(errno));
            exit(-1);
        }
        strcpy(tmp->student_name, name);
        tmp->student_id = student_id;
        tmp->score = score;
        tmp->next = NULL;
        tmp->prev = NULL;
        course = get_course_by_id(course_id);
        if (course == NULL)
        {
            continue;
        }
        if (course->score_head == NULL)
        {
            course->score_head = tmp;
            course->score_tail = tmp;
        }
        else 
        {
            course->score_tail->next = tmp;
            tmp->prev = course->score_tail;
            course->score_tail = tmp;
        }
    }
    fclose(f);
    f = NULL;
}

void save_course_list(const char *filename)
{
    assert(filename);
    FILE *f = fopen(filename, "w");
    if (f == NULL)
    {
        perror(fopen);
        return;
    }
    struct course_node *now_corse = course_head;
    while (now_corse != NULL) 
    {
        fprintf(f, "%s %d %d\n", now_corse->course_name, now_corse->course_id, now_corse->teacher_id);
        now_corse = now_corse->next;
    }
    fclose(f);
    f = NULL;
}

void save_score_list(const char *filename)
{
    assert(filename);
    FILE *f = fopen(filename, "w");
    if (f == NULL)
    {
        perror(fopen);
        return;
    }
    struct course_node *now_corse = course_head;
    struct score_node *now_score;
    while (now_corse != NULL) 
    { 
        now_score = course_head->score_head;
        while (now_score != NULL) 
        {
            fprintf(f, "%s %d %d %d\n",now_score->student_name, now_corse->course_id, now_score->student_id, now_score->score);
            now_score = now_score->next;
        }
        now_corse = now_corse->next;
    }
    fclose(f);
    f = NULL;
}

void CourseListDestory(course_node** pphead)
{
    assert(pphead);
    course_node* cur = *pphead;
    course_node* next = NULL;
    while (cur)
    {
        next = cur->next;
        free(cur);
        cur = next;
    }
    *pphead = NULL;
}