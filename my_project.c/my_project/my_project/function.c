#include"function.h"

 struct firm
{
	char name[50];
	char ID_Number[len];
	char account[len];
	char password[len];
	char phone[len];
	char date[len];
}f;

 typedef struct goods
 {
	 char name[len];
	 double price;
	 int num;
	 struct goods* next;

 }goods;
 typedef struct goods* Linklist;

 //初始化链表
 void Initlist(Linklist* l)
 {
	 again:
	 *l = (Linklist)malloc(sizeof(goods));
	 if (!(*l))
	 {
		 goto again;
	 }
	 else
	 {
		 (*l)->next = NULL;
	 }
 }

 //找到链表第i个元素
 void seekgoods(Linklist l)
 {
	 int i = 0;
	 int j = 1;
	 printf("请输入所要找的商品编号：");
	 scanf_s("%d", &i);
	 Linklist p = l->next;
	 while(p && j<i)
	 {
		 p = p ->next;
		 j++;
	 }
	 if (!p || j>i)
	 {
		 printf("无该商品信息\n");
	 }
	 else
	 {
		 printf("查询结果如下：\n");
		 printf("商品名称：%s	商品价格：%.2f	货存：%d\n", p->name, p->price, p->num);
	 }
 }

 //对链表的每个商品名称依次输出
 void printLinklist(Linklist l)
 {	
	 int i = 1;
	 Linklist p = l->next;
	 while (p)
	 {
		 printf("%d.%s ", i, p->name);
		 p = p->next;
		 i++;
	 }
	 printf("\n");
 }

 void firm_board(Linklist l)
{
	printf("\n———————————————————— Firm ————————————————————————\n");
	printf("用户：%s\n", f.account);
	printf("商品：\n");
	printLinklist(l);
}

 void LinklistInsert(Linklist *l)
 {
	 Linklist p = *l;
	 Linklist s ;
	 s = (Linklist)malloc(sizeof(goods));
	 printf("请输入新加商品名称：");
	 scanf_s("%s", s->name, len);
	 printf("请输入该商品价格：");
	 scanf_s("%lf", &(s->price));
	 printf("请输入该商品数量：");
	 scanf_s("%d", &(s->num));
	 s->next = p->next;
	 p->next = s;
 }

 void LinklistDelete(Linklist *l)
 {
	 int i = 0;
	 int j = 1;
	 Linklist p = *l;
	 Linklist s;
	 printf("在要输入时输入0,可退出下架\n");
	 again:
	 printf("请输入要下架的商品编号：");
	 scanf_s("%d", &i);
	 if (i)
	 {
		 for (j = 1; j < i && p != NULL; j++)
		 {
			 p = p->next;
		 }
		 if (p == NULL)
		 {
			 printf("该编号商品不存在，请重新输入\n");
			 goto again;
		 }
		 s = p->next;
		 p->next = s->next;
		 free(s);
	 }
	 else
	 {
		 printf("退出下架\n");
	 }
 }

 void operate(Linklist l)
 {
	 int input = 1;
	 int i = 0;
	 int j = 1;
	 Linklist p = l->next;
	 char name[len] = { 0 };
	 double price = 0;
	 int num = 0;
	 firm_board(l);
	 printf("请输入所要操作的商品编号,中途“请输入”处输入0可退出操作\n");
	 again:
	 printf("请输入：");
	 scanf_s("%d", &i);
	 if (i)
	 {
		 for (j = 1; j < i && p != NULL; j++)
		 {
			 p = p->next;
		 }

		 if (p == NULL)
		 {
			 printf("该编号商品不存在，请重新输入\n");
			 goto again;
		 }
		 printf("请输入所要改变的商品信息：\n");
		 printf("***** 1.商品名称 2.价格 3.数量 *****\n");
	 here:
		 printf("请输入：");
		 scanf_s("%d", &input);
		 switch (input)
		 {
		 case 1:
			 printf("请输入商品新名称：");
			 scanf_s("%s", name, len);
			 strcpy_s(p->name, len, name);
			 break;
		 case 2:
			 printf("请输入商品新价格：");
			 scanf_s("%lf", &price);
			 p->price = price;
			 break;
		 case 3:
			 printf("请输入商品新数量：");
			 scanf_s("%d", &num);
			 p->num = num;
			 break;
		 case 0:
			 i = 0;
			 break;
		 default:
			 printf("输入错误，请重新输入\n");
			 goto here;
			 break;
		 }
		 if (i)
		 {
			 printf("修改成功!\n");
		 }
		 else
		 {
			 printf("操作退出\n");
		 }
	 }
	 else
	 {
		 printf("操作退出\n");
	 }
 }

 void change_password(struct firm* f)
 {
	 char password[len] = { 0 };
	 char password1[len] = { 0 };
	 again:
	 printf("请输入新密码：");
	 scanf_s("%s", password, len);
	 printf("请再输入一遍密码：");
	 scanf_s("%s", password1, len);
	 if (strcmp(password, password1)==0)
	 {
		 strcpy_s(f->password, len, password);
		 printf("密码修改成功，请重新登录\n");
	 }
	 else
	 {
		 printf("两次密码不一致，请重新输入\n");
		 goto again;
	 }
 }

void sign_up()
{
	printf("\n———————————————————注册——————————————————-\n");
	printf("请输入商家真实姓名：");
	scanf_s("%s", f.name, 50);
	printf("请输入身份证号：");
	scanf_s("%s", f.ID_Number, len);
again:
	printf("出生日期 输入样例如“19190504”\n请输入：");
	scanf_s("%s", f.date, 9);
	if (strlen(f.date) < 5)
	{
		printf("输入内容不实，请重新输入\n");
		goto again;
	}
	printf("请输入用户名：");
	scanf_s("%s", f.account,len);
	printf("请输入密码：");
	scanf_s("%s", f.password,len);
	printf("请输入手机号：");
	scanf_s("%s", f.phone,len);
	printf("注册成功！\n");
}

void forget()
{
	char fname[len] = { 0 };
	char fidnumber[len] = { 0 };
	char fphone[len] = { 0 };
	char fpassword[len] = { 0 };
	char fpassword1[len] = { 0 };
	again:
	printf("请输入商家真实姓名：");
	scanf_s("%s", fname, len);
	printf("请输入身份证号：");
	scanf_s("%s", fidnumber, len);
	printf("请输入手机号：");
	scanf_s("%s", fphone, len);
	if ((strcmp(f.name, fname)==0) && (strcmp(f.ID_Number, fidnumber)==0) && (strcmp(f.phone, fphone)==0))
	{
		here:
		printf("请输入新密码：");
		scanf_s("%s", fpassword, len);
		printf("请再输入一遍密码："); 
		scanf_s("%s", fpassword1, len);
		if (strcmp(fpassword, fpassword1)==0)
		{
			strcpy_s(f.password, len, fpassword);
			printf("密码修改成功，请重新登录\n");
		}
		else
		{
			printf("两次密码不一致，请重新输入\n");
			goto here;
		}
	}
	else
	{
		printf("输入信息错误，请重新输入\n");
		goto again;
	}
}

int logn_in()
{
	int i = 1;
	int input = 0;
	char faccount[len] = { 0 };
	char fpassword[len] = { 0 };
	printf("\n————————————————————————登录———————————————————————-\n");
	do
	{
	here:
	again:
	there:
	it1:
		printf("\n******* 1.登录 2.忘记密码 3.修改密码 0.退出 *******\n");
		printf("请输入：");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("请输入用户名：");
			scanf_s("%s", faccount, len);
			printf("请输入密码：");
			scanf_s("%s", fpassword, len);
			if ((strcmp(f.account, faccount) == 0) && (strcmp(f.password, fpassword) == 0))
			{
				printf("登陆成功！\n欢迎用户：%s\n", f.account);
				i = 1;
				input = 0;
			}
			else
			{
				printf("用户名或密码错误\n");
				goto here;
			}
			break;
		case 2:
			forget();
			goto there;
			break;
		case 3:
		it:
			printf("请输入用户名：");
			scanf_s("%s", faccount, len);
			printf("请输入密码：");
			scanf_s("%s", fpassword, len);
			if ((strcmp(f.account, faccount) == 0) && (strcmp(f.password, fpassword) == 0))
			{
				change_password(&f);
				goto it1;
			}
			else
			{
				printf("用户名或密码错误,请重新输入\n");
				goto it;
			}
			break;
		case 0:
			printf("退出\n");
			i = 0;
			break;
		default:
			printf("输入错误，请重新输入\n");
			goto again;
			break;
		}
	} while (input);
	return i;
}

void operation()
{
	int input = 0;
	Linklist l;
	Initlist(&l);
	do
	{
		firm_board(l);
		printf("\n————————————————————————————————————————————————————");
		printf("\n******** 1.查询 2.上架 3.下架 4.操作 0.退出 ********\n");
	again:
		printf("请输入：");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			seekgoods(l);
			break;
		case 2:
			LinklistInsert(&l);
			firm_board(l);
			break;
		case 3:
			firm_board(l);
			LinklistDelete(&l);
			firm_board(l);
			break;
		case 4:
			operate(l);
			firm_board(l);
			break;
		case 0:
			printf("程序退出\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			goto again;
		}
	} while (input);

}