#include"contact.h"

//增容
//static void Check_capacity(Contact* pc)
//{
//	assert(pc);
//	//扩容
//	if (pc->count == pc->capacity)
//	{
//		PeoInfo* ptr = (PeoInfo*)realloc(pc->data, pc->capacity + INC_SZ * sizeof(PeoInfo));
//		if (ptr = NULL)
//		{
//			printf("Check_capacity: %s\n", strerror(errno));
//			return;
//		}
//		else
//		{
//			pc->data = ptr;
//			pc->capacity = pc->capacity + INC_SZ;
//		}
//	}
//}

void LoadContact(Contact* pc)
{
	assert(pc);
	FILE* pfread = fopen("Contact.txt", "rb");
	if (pfread == NULL)
	{
		return;
	}

	PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(PeoInfo), 1, pfread)==1)
	{
		//动态版要检查是否要扩容
		//Check_capacity(pc);

		pc->data[pc->count] = tmp;
		pc->count++;
	}

	fclose(pfread);
	pfread = NULL;
}

//静态版
void Initcontact(Contact* pc)
{
	assert(pc);
	pc->count = 0;
	memset(pc->data, 0, sizeof(pc->data));

	//加载文件信息到通讯录中
	LoadContact(pc);
}

//动态版
//int Initcontact(Contact* pc)
//{
//	assert(pc);
//	pc->count = 0;
//	pc->data = (PeoInfo*)calloc(DEFAULT_SZ, sizeof(PeoInfo));//初始化三个人容量的通讯录
//	if (pc->data = NULL)
//	{
//		printf("Initcontact: %s\n", strerror(errno));
//		return 1;
//	}
//	pc->capacity = DEFAULT_SZ;
//    LoadContact(pc);
//	return 0;
//}

//void DestoryContact(Contact* pc)
//{
//	assert(pc);
//	free(pc->data);
//	pc->data = NULL;
//}

//静态版
void AddContact(Contact* pc)
{
	assert(pc);
	if (pc->count == 100)
	{
		printf("通讯录已满，无法添加\n");
		return;
	}
	printf("请输入姓名：");
	scanf("%s", pc->data[pc->count].name);
	printf("请输入年龄：");
	scanf("%d", &(pc->data[pc->count].age));
	printf("请输入性别：");
	scanf("%s", pc->data[pc->count].sex);
	printf("请输入电话：");
	scanf("%s", pc->data[pc->count].tele);
	printf("请输入地址：");
	scanf("%s", pc->data[pc->count].adder);
	pc->count++;
	printf("添加成功\n");
}

//动态版
//void AddContact(Contact* pc)
//{
//	assert(pc);
//	//增容
//	Check_capacity(pc);
//
//	printf("请输入姓名：");
//	scanf("%s", pc->data[pc->count].name);
//	printf("请输入年龄：");
//	scanf("%d", &(pc->data[pc->count].age));
//	printf("请输入性别：");
//	scanf("%s", pc->data[pc->count].sex);
//	printf("请输入电话：");
//	scanf("%s", pc->data[pc->count].tele);
//	printf("请输入地址：");
//	scanf("%s", pc->data[pc->count].adder);
//	pc->count++;
//	printf("添加成功\n");
//}

void ShowContact(const Contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%20s\t%5s\t%5s\t%12s\t%20s\n", "名字", "年龄", "性别", "电话", "地址");
	for (i = 0; i < pc->count; i++)
	{
		printf("%20s\t%5d\t%5s\t%12s\t%20s\n", 
			pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].tele,
			pc->data[i].adder);
	}
}

//返回要查找的对应下标
static int Findbyname(const Contact* pc, char name[])//static 修饰后只能在本源文件里才能看到该函数
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

void DelContact(Contact* pc)
{
	assert(pc);
	//判断是否为空表
	if (pc->count == 0)
	{
		printf("通讯录为空，无法删除\n");
		return;
	}
	//查找
	char name[20] = { 0 };
	printf("请输入要删除的人的姓名\n请输入：");
	scanf("%s", name);
	int pos = Findbyname(pc, name);
	if (pos == -1)
	{
		printf("通讯录中不存在此人，无法删除\n");
		return;
	}
	//删除
	int i = 0;
	for (i = pos; i < pc->count - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
	printf("删除成功\n");
}

void SearchContact(const Contact* pc)
{
	assert(pc);
	char name[20] = { 0 };
	printf("请输入要查找的人的姓名\n请输入：");
	scanf("%s", name);
	int pos = Findbyname(pc, name);
	if (pos == -1)
	{
		printf("通讯录中不存在此人\n");
		return;
	}
	printf("%20s\t%5s\t%5s\t%12s\t%20s\n", "名字", "年龄", "性别", "电话", "地址");
	printf("%20s\t%5d\t%5s\t%12s\t%20s\n",
		pc->data[pos].name,
		pc->data[pos].age,
		pc->data[pos].sex,
		pc->data[pos].tele,
		pc->data[pos].adder);

}

void ModifyContact(Contact* pc)
{
	assert(pc);
	char name[20] = { 0 };
	printf("请输入要修改的人的姓名\n请输入：");
	scanf("%s", name);
	int pos = Findbyname(pc, name);
	if (pos == -1)
	{
		printf("通讯录中不存在此人\n");
		return;
	}
	printf("开始修改\n");
	printf("请输入姓名：");
	scanf("%s", pc->data[pc->count].name);
	printf("请输入年龄：");
	scanf("%d", &(pc->data[pc->count].age));
	printf("请输入性别：");
	scanf("%s", pc->data[pc->count].sex);
	printf("请输入电话：");
	scanf("%s", pc->data[pc->count].tele);
	printf("请输入地址：");
	scanf("%s", pc->data[pc->count].adder);
	printf("修改成功\n");
}

//按名字来排序
int cmp_by_name(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}

//按年龄来排序
int cmp_by_age(const void* e1, const void* e2)
{
	return (((PeoInfo*)e1)->age - ((PeoInfo*)e2)->age);
}

void SortContact(Contact* pc)
{
	assert(pc);
	int input = 0;
	do
	{
		printf("1、按名字来排序  2、按年龄来排序  0、退出排序\n请输入：");
		scanf("%d",&input);
		switch (input)
		{
		case 0:
			printf("退出排序\n");
			break;
		case 1:
			qsort(pc->data, pc->count, sizeof(PeoInfo), cmp_by_name);
			printf("排序成功\n");
			break;
		case 2:
			qsort(pc->data, pc->count, sizeof(PeoInfo), cmp_by_age);
			printf("排序成功\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
}

void SaveContact(const Contact* pc)
{
	assert(pc);
	FILE* pfwrite = fopen("Contact.txt", "wb");
	if (pfwrite == NULL)
	{
		perror("SaveContact");
		return;
	}
	//以二进制写到文件
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		fwrite(pc->data + i, sizeof(PeoInfo), 1, pfwrite);
	}

	fclose(pfwrite);
	pfwrite = NULL;
}