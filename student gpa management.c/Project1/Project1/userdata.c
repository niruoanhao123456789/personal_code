#include "userdata.h"

//检查顺序表是否扩容
static void SLCeckcapacity(SeqList* ps)
{
	assert(ps);
	if (ps->count == ps->capacity)
	{
		int newcapacity = (ps->capacity == 0 ? 4 : 2 * ps->capacity);
		SLDataType* tmp = (SLDataType*)realloc(ps->data, newcapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			printf("%s\n", strerror(errno));//用来反馈错误信息的函数
			exit(-1);
		}
		ps->data = tmp;
		ps->capacity = newcapacity;
	}
}

//将用户文件加载到顺序表里
static void LoadUserData(SeqList* ps,const char* filename)
{
	assert(ps);
	FILE* pfread = fopen(filename, "r");
	if (pfread == NULL)
	{
		perror(pfread);//用来反馈错误信息的函数
		return;
	}
	char line_buffer[LINE_BUFFER_SIZE] = { 0 };
	SLDataType tmp = { 0 };
    while (fgets(line_buffer, LINE_BUFFER_SIZE, pfread) != NULL) //读文件一行数据
	{
		SLCeckcapacity(ps);
        sscanf(line_buffer, "%s %s %lld %lld", &tmp.password, &tmp.name, &tmp.phone_num, &tmp.user_id);
        ps->data[ps->count] = tmp;
		ps->count++;
    }
	fclose(pfread);
	pfread = NULL;
}

void save_user_data(SeqList* ps, const char* filename)
{
	assert(ps && filename);
	FILE* f = fopen(filename, "w");
	if (f == NULL)
	{
		perror(fopen);
		return;
	}
	int i = 0;
	for (i = 0; i < ps->count; i++)
	{
		fprintf(f, "%s %s %lld %lld\n", ps->data[i].password,
										ps->data[i].name,
										ps->data[i].phone_num,
										ps->data[i].user_id);
	}
	fclose(f);
	f = NULL;
}

void SeqlistInit(SeqList* ps, const char* filename)
{
	assert(ps && filename);
	ps->data = NULL;
	ps->count = 0;
	ps->capacity = 0;

	LoadUserData(ps, filename);
}

void SeqListPushBack(SeqList* ps, const char* filename)
{
	assert(ps && filename);
	SLCeckcapacity(ps);

	printf("用户添加\n请输入姓名：");
	scanf("%s", &ps->data[ps->count].name);
	printf("请输入工号或学号：");
	scanf("%lld", &ps->data[ps->count].user_id);
	printf("请输入电话号码：");
	scanf("%lld", &ps->data[ps->count].phone_num);
	printf("请输入登陆密码：");
	scanf("%s", &ps->data[ps->count].password);
	printf("添加成功\n");

	FILE* pfwrite = fopen(filename, "a");
	if (pfwrite == NULL)
	{
		perror(pfwrite);
		return;
	}
    fprintf(pfwrite, "%s %s %lld %lld", ps->data[ps->count].password, 
									    ps->data[ps->count].name, 
									    ps->data[ps->count].phone_num,
									    ps->data[ps->count].user_id);
	//fwrite(ps->data, sizeof(SLDataType), 1, pfwrite);
	fclose(pfwrite);
	pfwrite = NULL;

	ps->count++;
}


void SeqListPopBack(SeqList* ps, const char* filename)
{
	assert(ps->count > 0 && ps && filename);
	ps->count--;
}

int SeqListFind_ByID(const SeqList* ps, int user_id)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->count; i++)
	{
		if (ps->data[i].user_id == user_id)
		{
			return i;
		}
	}
	return -1;
}

void SeqListModify(SeqList* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->count);

	printf("用户修改\n请输入姓名：");
	scanf("%s", &ps->data[pos].name);
	printf("请输入工号或学号：");
	scanf("%lld", &ps->data[pos].user_id);
	printf("请输入电话号码：");
	scanf("%lld", &ps->data[pos].phone_num);
	printf("请输入登陆密码：");
	scanf("%s", &ps->data[pos].password);
	printf("修改成功\n");
}

void SeqListErase(SeqList* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->count);
	int begin = pos;
	while (begin < ps->count - 1)
	{
		ps->data[begin] = ps->data[begin + 1];
		begin++;
	}
	ps->count--;
}

void SeqListPrint(const SeqList* ps)
{
	assert(ps);
	int i = 0;
	printf("name  ID  password  phone\n");
	for (i = 0; i < ps->count; i++)
	{
		printf("%s %lld %s %lld\n", ps->data[i].name, 
								    ps->data[i].user_id,
								    ps->data[i].password,
								    ps->data[i].phone_num);
	}
}

void SeqListDestory(SeqList* ps)
{
	assert(ps);
	free(ps->data);
	ps->data = NULL;
	ps->capacity = 0;
	ps->count = 0;
}