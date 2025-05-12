#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<errno.h>
#include<stdbool.h>
#include<math.h>

typedef struct SingleListNode
{
	int data;
	struct SingleListNode* next;
}SLTNode;

void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void SListPushBack(SLTNode** pphead, int x)
{
	assert(pphead);
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

void SListDestoey(SLTNode** pphead)
{
	assert(pphead);
	SLTNode* cur = *pphead;
	while (cur)
	{
		SLTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}

//数据结构与算法的学习再写代码前尽量要画图分析

//时间复杂度  计算的是程序执行次数
//空间复杂度  计算的是变量的个数(额外空间的大小)

//顺序表
//优点：支持随机访问，有些算法（二分查找、快速排序等）需要结构支持随机访问
//缺陷：空间不足要扩容，扩容要付出一定代价；为了避免频繁扩容，表满了基本扩2倍，可能导致内存浪费
//顺序表要求数据从起始位置开始连续存储，如果头插或者中间插入数据要挪动数据，效率不高

//链表
//优点：按需申请空间，不用时就释放，头插和中间插时不用挪动数据
//缺点：每个节点都要存一个指针去链接下一个节点；不支持 随机访问（用下标访问相应的数据）


//消失的数字
//数组包括0到n的全部整数，但其中缺失了一个，请找出那个缺失的整数，并在 O(n)时间内完成
//int cmp_num(const void* e1, const void* e2)
//{
//	return (*((int*)e1) - *((int*)e2));
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int* parr = (int*)calloc(n+1, sizeof(int));
//	if (parr == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &parr[i]);
//	}
//	//思路一：先排序，再历遍
//	//qsort(parr, n, sizeof(int), cmp_num);//快速排序算法，时间复杂度为O(N*log2N)，不符题意
//	//i = 0;
//	//while (1)
//	//{
//	//	if(i == *(parr + i))
//	//		i++;
//	//	else
//	//	{
//	//		printf("%d\n", i);
//	//		break;
//	//	}
//	//}
//
//	//思路二：先求0到n个整数之和，再减去目前数组里的数之和，结果就是所求	时间复杂度为O(N)
//	/*int sum1 = 0;
//	int sum2 = 0;
//	for (i = 0; i < n; i++)
//	{
//		sum1 += i;
//		sum2 += *(parr + i);
//	}
//	sum1 += n;
//	printf("%d\n", sum1 - sum2);*/
//
//	//思路三：创建一个n+1长的数组，将之前数组的数按照对应下标填入，没填的就是所求
//	//int* parr1 = (int*)calloc(n + 1, sizeof(int));
//	//if (parr1 == NULL)
//	//{
//	//	printf("%s\n", strerror(errno));
//	//	return 1;
//	//}
//	//for(i=0;i<n+1;i++)
//	//{
//	//	*(parr1 + *(parr + i)) = *(parr + i);
//	//	if (i == n)
//	//	{
//	//		*(parr1 + *(parr + i)) = -1;
//	//	}
//	//}
//	//for (i = 0; i < n + 1; i++)
//	//{
//	//	if (*(parr1 + i) != i)
//	//	{
//	//		printf("%d\n", i);
//	//		break;
//	//	}
//	//}
//	//free(parr1);
//	//parr1 = NULL;
//
//	//思路四：给一个数x=0，先跟0-n按位异或，再跟数组中每个值按位异或，最后x就是所求
//	// ^ 按（二进制）位异或  补码中对应二进制为相同为0，相异为1	 (同则0，异则1)
//	// 0 ^ a = a	a ^ a = 0	^ 的运算可适用交换律
//	/*int x = 0;
//	for (i = 1; i <= n; i++)
//	{
//		x ^= i;
//	}
//	for (i = 0; i < n; i++)
//	{
//		x ^= *(parr + i);
//	}
//	printf("%d\n", x);*/
//
//
//	free(parr);
//	parr = NULL;
// 
//	return 0;
//}


//旋转数组
//将数组里的元素向右移k个位置，k为非负数，要求空间复杂度为O(1)
//思路一：额外开辟空间，空间复杂度为O(n)
//int main()
//{
//	int n = 0;
//	int k = 0;
//	int i = 0;
//	scanf("%d", &n);
//	int* arr = (int*)calloc(n, sizeof(int));
//	if (arr == NULL)
//	{
//		perror("arr");
//		return 1;
//	}
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", arr + i);
//	}
//	scanf("%d", &k);
//	k %= n;
//	int* arr1 = (int*)calloc(n, sizeof(int));
//	if (arr1 == NULL)
//	{
//		perror("arr1");
//		return 1;
//	}
//	int j = 0;
//	for (i = n - k ; i < n; i++)
//	{
//		*(arr1 + j) = *(arr + i);
//		j++;
//	}
//	for (i = 0; i < n - k; i++)
//	{
//		*(arr1 + j) = *(arr + i);
//		j++;
//	}
//	for (i = 0; i < n; i++)
//	{
//		*(arr + i) = *(arr1 + i);
//		printf("%d ", *(arr + i));
//	}
//	printf("\n");
//	free(arr1);
//	arr1 = NULL;
//
//	free(arr);
//	arr = NULL;
//
//	return 0;
//}
//
//思路二：先对字符串前n-k个元素进行逆置，再后k个元素进行逆置，最后整体逆置
//void Reverse(int* arr, int left, int right)
//{
//	while (left < right)
//	{
//		int tmp = *(arr + left);
//		*(arr + left) = *(arr + right);
//		*(arr + right) = tmp;
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int* arr = (int*)calloc(n, sizeof(int));
//	if (arr == NULL)
//	{
//		printf("%s\n",strerror(errno));
//		return 1;
//	}
//	int k = 0;
//	scanf("%d", &k);
//	k %= n;//对于k>=n时避免重复或无效的逆置
//	//前面部分逆置
//	Reverse(arr, 0, n - k - 1);
//	//后面部分逆置
//	Reverse(arr, n - k, n - 1);
//	//整体逆置
//	Reverse(arr, 0, n - 1);
//
//	free(arr);
//	arr = NULL;
//
//	return 0;
//}


//移除元素
//给定数组arr和一个数k，要求原地移除数组里数值等于k的元素，并返回移除后数组的新长度
//只能使用O(1)的额外空间并原地修改数组
//法一：时间复杂度为O(n^2)
//int main()
//{
//	int n = 0;
//	int k = 0;
//	int i = 0;
//	scanf("%d", &n);
//	int* arr = (int*)calloc(n, sizeof(int));
//	if (arr == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", arr + i);
//	}
//	scanf("%d", &k);
//
	//int newsize = n;
	//i = 0;
	//while(i<newsize)
	//{
	//	 if (k == *(arr + i))
	//	 {
	//		int j = i;
	//		while (j < newsize-1)
	//		{
	//			*(arr + j) = *(arr + j+1);
	//			j++;
	//		}
	//		newsize--;
	//	 }
	//	 else
	//	 {
	//		i++;
	//	 }
	//}
//	for (i = 0; i < newsize; i++)
//	{
//		printf("%d ", *(arr + i));
//	}
//	printf("\nnewsize:%d\n", newsize);
//
//	free(arr);
//	arr = NULL;
//  return 0;
//}
//法二：时间复杂度O(n) 空间复杂度O(n)
//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d", &n);
//	int* arr = (int*)calloc(n, sizeof(int));
//	if (arr == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	int i = 0;
//	for (i = 0; i < n; i++) 
//	{
//		scanf("%d", arr + i);
//	}
//	scanf("%d", &k);
//	int* tmp = (int*)calloc(n, sizeof(int));
//	if (tmp == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	int j = 0;
//	for (i = 0; i < n; i++)
//	{
//		if (k != *(arr + i))
//		{
//			*(tmp + j) = *(arr + i);
//			j++;
//		}
//	}
//	for (i = 0; i < j; i++)
//	{
//		*(arr + i) = *(tmp + i);
//		printf("%d ", *(arr + i));
//	}
//	printf("\nnewsize:%d\n", j);
//
//	free(tmp);
//	tmp = NULL;
//	free(arr);
//	arr = NULL;
//	return 0;
//}
//法三:双指针 时间复杂度O(n) 空间复杂度O(1)
//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d", &n);
//	int* arr = (int*)calloc(n, sizeof(int));
//	if (arr == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	int i = 0;
//	for (i = 0; i < n; i++) 
//	{
//		scanf("%d", arr + i);
//	}
//	scanf("%d", &k);
//	int src = 0;
//	int dest = 0;
//	while (src < n)
//	{
//		if (k != *(arr + src))
//		{
//			*(arr + dest) = *(arr + src);
//			dest++;
//		}
//		src++;
//	}
//	for (i = 0; i < dest; i++)
//	{
//		printf("%d ", *(arr + i));
//	}
//	printf("\nnewsize:%d\n", dest);
//
//	free(arr);
//	arr = NULL;
//	return 0;
//}


//删除有序数组中的重复项
//给定数组arr，要求原地删除重复出现的元素，使每个元素中出现一次，并返回删除后的数组新长度
//只能使用O(1)的额外空间并原地修改数组
//法一：
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int newlen = n;
//	int* arr = (int*)calloc(n, sizeof(int));
//	if (arr == NULL)
//	{
//		perror("calloc");
//		return EXIT_FAILURE;
//	}
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", arr + i);
//	}
//	for (i = 0; i < newlen - 1; i++)
//	{
//		int j = 0;
//		for (j = i + 1; j < newlen; j++)
//		{
//			while (*(arr + i) == *(arr + j))
//			{
//				if (j == newlen - 1)
//				{
//					newlen--;
//					break;
//				}
//				else
//				{
//					int begin = 0;
//					for (begin = j; begin < newlen - 1; begin++)
//					{
//						*(arr + begin) = *(arr + begin + 1);
//					}
//					newlen--;
//				}
//			}
//		}
//	}
//	for (i = 0; i < newlen; i++)
//	{
//		printf("%d ", *(arr + i));
//	}
//	printf("\nnewlen:%d\n", newlen);
//
//	free(arr);
//	arr = NULL;
//	
//	return 0;
//}
//法二：
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int* arr = (int*)calloc(n, sizeof(int));
//	if (arr == NULL)
//	{
//		perror("calloc");
//		return EXIT_FAILURE;
//	}
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", arr + i);
//	}
//
//	int j = 0;
//	int dest = 0;
//	i = 0;
//	while (j < n)
//	{
//		if (*(arr + i) == *(arr + j))
//		{
//			j++;
//		}
//		else
//		{
//			*(arr + dest) = *(arr + i);
//			dest++;
//			i = j++;
//		}
//	}
//	*(arr + dest) = *(arr + i);
//	dest++;
//
//	for (i = 0; i < dest; i++)
//	{
//		printf("%d ", *(arr + i));
//	}
//	printf("\nnewlen:%d\n", dest);
//
//	free(arr);
//	arr = NULL;
//
//	return 0;
//}


//合并有序数组
//给定一个长m+n的升序数组arr1，其中arr1前m个元素为应合并的数据，后n个元素为0，应忽略；
//以及长为n、元素都应被合并的升序数组arr2
//请将arr2合并到arr1中，合并后的数组也按升序排列
//归并排序：
//从前开始进行历遍比较，较小的元素放在前面，比较完后剩余元素拷贝到后面
//从后开始进行历遍比较，较大的元素放在后面，比较完后剩余元素拷贝到前面
//int main()
//{
//	int m = 0;
//	int n = 0;
//	int i = 0;
//	scanf("%d", &n);
//	scanf("%d", &m);
//	int* arr2 = (int*)calloc(n, sizeof(int));
//	if (arr2 == NULL)
//	{
//		return 1;
//	}
//	int* arr1 = (int*)calloc(m + n, sizeof(int));
//	if (arr1 == NULL)
//	{
//		return 1;
//	}
//	for (i = 0; i < m; i++)
//	{
//		scanf("%d", arr1 + i);
//	}
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", arr2 + i);
//	}
//
//	int end1 = m - 1, end2 = n - 1, end = m + n - 1;
//	while (end1 >= 0 && end2 >= 0)
//	{
//		if (*(arr1 + end1) > *(arr2 + end2))
//		{
//			*(arr1 + end) = *(arr1 + end1);
//			end--;
//			end1--;
//		}
//		else
//		{
//			*(arr1 + end) = *(arr2 + end2);
//			end--;
//			end2--;
//		}
//	}
//	while (end2 >= 0)
//	{
//		*(arr1+end--) = *(arr2 + end2--);
//	}
//	
//	for (i = 0; i < n + m; i++)
//	{
//		printf("%d ", *(arr1 + i));
//	}
//
//	free(arr1);
//	arr1 = NULL;
//	free(arr2);
//	arr2 = NULL;
//
//	return 0;
//}


//给定一个链表的头节点和数据k，要求删除链表里和数据n一样的元素的节点，并返回新的头节点
//
//SLTNode* test(SLTNode* phead, int k)
//{
//	SLTNode* prev = NULL;
//	SLTNode* cur = phead;
//	while (cur)
//	{
//		if (cur->data == k)
//		{
//			if (cur == phead)
//			{
//				phead = cur->next;
//				free(cur);
//				cur = phead;
//			}
//			else
//			{
//				prev->next = cur->next;
//				free(cur);
//				cur = prev->next;
//			}
//		}
//		else
//		{
//			prev = cur;
//			cur = cur->next;
//		}
//	}
//	return phead;
//}
//
//int main()
//{
//	SLTNode* plist = NULL;
//	int n = 0;
//	int i = 0;
//	int k = 0;
//	int x = 0;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &x);
//		SListPushBack(&plist, x);
//	}
//	scanf("%d", &k);
//
//	plist = test(plist,k);
//	SListPrint(plist);
//
//	return 0;
//}


//给你单链表的头节点，将链表反转，并返回反转后的头节点
//
//SLTNode* reverselist(SLTNode* phead)
//{
//	//思路一：翻转指针
//	// if (phead == NULL)
//	//{
//	//	return NULL;
//	//}
//	//SLTNode* n2 = phead;
//	//SLTNode* n1 = NULL;
//	//SLTNode* n3 = phead->next;
//	//while (n2 != NULL)
//	//{
//	//	//翻转
//	//	n2->next = n1;
//	//	//迭代
//	//	n1 = n2;
//	//	n2 = n3;
//	//	if (n3 != NULL)
//	//	{
//	//		n3 = n3->next;
//	//	}
//	//}
//	//return n1;
//
//	//思路二：将原链表中的节点取下来头插到新链表
//	SLTNode* cur = phead;
//	SLTNode* newhead = NULL;
//	while (cur != NULL)
//	{
//		SLTNode* next = cur->next;
//		cur->next = newhead;
//		newhead = cur;
//		cur = next;
//	}
//	return newhead;
//}
//
//int main()
//{
//	SLTNode* plist = NULL;
//	int n = 0;
//	int i = 0;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		SListPushBack(&plist, i);
//	}
//	SListPrint(plist);
//	SLTNode* newplist = reverselist(plist);
//	SListPrint(newplist);
//
//	SListDestory(&plist);
//	return 0;
//}


//链表的中间节点
//给定头节点head的非空链表，返回链表的中间节点，如果有两个中间节点则返回第二个中间节点
//
//SLTNode* middlenode(SLTNode* phead)
//{
//	assert(phead);
//	//思路：快慢指针 快指针的速度是慢指针的两倍，当快指针走完后，满指针正好在中间
//	SLTNode* slow = phead;
//	SLTNode* fast = phead;
//	while (fast && fast->next)
//	{
//		slow = slow->next;
//		fast = (fast->next)->next;
//	}
//
//	return slow;
//}
//
//int main()
//{
//	int len = 0;
//	scanf("%d", &len);
//	SLTNode* plist = NULL;
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		SListPushBack(&plist, i);
//	}
//	SListPrint(plist);
//
//	SLTNode* newnode = middlenode(plist);
//	printf("%d\n", newnode->data);
//
//	SListDestory(&plist);
//
//	return 0;
//}


//求单链表倒数第k个节点，k为非负数
//
//SLTNode* Findkthtotail(SLTNode* phead, int k)
//{
//	//思路：快指针先走k步，满指针再和快指针一起走
//	SLTNode* fast = phead;
//	SLTNode* slow = phead;
//	while (k--)
//	{
//		if (fast==NULL)//针对越界情况
//		{
//			return NULL;
//		}
//		fast = fast->next;
//	}
//	while (fast)
//	{
//		fast = fast->next;
//		slow = slow->next;
//	}
//	return slow;
//}
//
//int main()
//{
//	int len = 0;
//	scanf("%d", &len);
//	int i = 0;
//	SLTNode* plist = NULL;
//	for (i = 0; i < len; i++)
//	{
//		SListPushBack(&plist, i);
//	}
//	SListPrint(plist);
//	int k = 0;
//	scanf("%d", &k);
//	SLTNode* newnode = Findkthtotail(plist, k);
//	if (newnode == NULL)
//	{
//		printf("NULL\n");
//	}
//	else
//	{
//		printf("%d\n", newnode->data);
//	}
//
//	SListDestory(&plist);
//
//	return 0;
//}


//将两个升序链表合并为一个新的升序链表，该新链表是由给定的两个链表的所有节点拼接而成
//typedef struct SingleListNode
//{
//	int data;
//	struct SingleListNode* next;
//}SLTNode;
//
//void SListPrint(SLTNode* phead)
//{
//	SLTNode* cur = phead;
//	while (cur)
//	{
//		printf("%d ", cur->data);
//		cur = cur->next;
//	}
//	printf("\n");
//}
//
//void SListPushBack(SLTNode** pphead, int x)
//{
//	assert(pphead);
//	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
//	if (newnode == NULL)
//	{
//		perror("malloc");
//		exit(-1);
//	}
//	newnode->data = x;
//	newnode->next = NULL;
//	if (*pphead == NULL)
//	{
//		*pphead = newnode;
//	}
//	else
//	{
//		SLTNode* tail = *pphead;
//		while (tail->next != NULL)
//		{
//			tail = tail->next;
//		}
//		tail->next = newnode;
//	}
//}
//
//void SListDestoey(SLTNode** pphead)
//{
//	assert(pphead);
//	SLTNode* cur = *pphead;
//	while (cur)
//	{
//		SLTNode* next = cur->next;
//		free(cur);
//		cur = next;
//	}
//	*pphead = NULL;
//}
//
//SLTNode* Merge_two_list(SLTNode* pl1, SLTNode* pl2)
//{
//	//思路一：归并排序，并尾插
//	//如果有一个链表为空，则返回另一个，二者都为空就返回空
//	if (pl1 == NULL)
//	{
//		return pl2;
//	}
//	if (pl2 == NULL)
//	{
//		return pl1;
//	}
//	SLTNode* head = NULL, * tail = NULL;
//	if (pl1->data < pl2->data)//针对头结点为空
//	{
//		head = pl1;
//		tail = pl1;
//		pl1 = pl1->next;
//	}
//	else
//	{
//		head = pl2;
//		tail = pl2;
//		pl2 = pl2->next;
//	}
//	while (pl1 && pl2)
//	{
//		if (pl1->data < pl2->data)
//		{
//			tail->next = pl1;
//			tail = pl1;
//			pl1 = pl1->next;
//		}
//		else
//		{
//			tail->next = pl2;
//			tail = pl2;
//			pl2 = pl2->next;
//		}
//	}
//	if (pl1)
//	{
//		tail->next = pl1;
//	}
//	if (pl2)
//	{
//		tail->next = pl2;
//	}
//	return head;
//}
//
//int main()
//{
//	int len1 = 0;
//	int len2 = 0;
//	int i = 0;
//	SLTNode* plist1 = NULL;
//	SLTNode* plist2 = NULL;
//	scanf("%d %d", &len1, &len2);
//	for (i = 0; i < len1; i++)
//	{
//		SListPushBack(&plist1, i);
//	}
//	SListPrint(plist1);
//	for (i = 0; i < len2; i++)
//	{
//		SListPushBack(&plist2, i);
//	}
//	SListPrint(plist2);
//	SLTNode* newlist = Merge_two_list(plist1, plist2);
//	SListPrint(newlist);
//
//	return 0;
//}


//链表分割
//给定链表头结点和一个数 x 使小于x的结点排在其余结点之前，且不能改变原来的数据顺序(相对链表本身而言)，
//返回重新排列后的头指针
//思路：将大于x和小于x的结点分别放在两个链表中，最后将这两个链表链接起来
//SLTNode* Partition(SLTNode* phead, int x)
//{
//	if (phead == NULL)
//	{
//		return NULL;
//	}
//	SLTNode* lesshead, * lesstail, * greaterhead, * greatertail;
//	//设置哨兵位头结点，方便尾插
//	lesshead = lesstail = (SLTNode*)malloc(sizeof(SLTNode));
//	if ((lesshead == NULL) || (lesstail == NULL))
//	{
//		exit(-1);
//	}
//	lesstail->next = NULL;
//	greaterhead = greatertail = (SLTNode*)malloc(sizeof(SLTNode));
//	if ((greaterhead == NULL) || (greatertail == NULL))
//	{
//		exit(-1);
//	}
//	greaterhead->next = NULL;
//	greatertail->next = NULL;
//
//	SLTNode* cur = phead;
//	while (cur)
//	{
//		if (cur->data < x)
//		{
//			lesstail->next = cur;
//			lesstail = cur;
//		}
//		else
//		{
//			greatertail->next = cur;
//			greatertail = cur;
//			if (greaterhead->next == NULL)
//			{
//				greaterhead->next = greatertail;
//			}
//		}
//		cur = cur->next;
//	}
//	greatertail->next = NULL;
//	lesstail->next = greaterhead->next;
//	phead = lesshead->next;
//	//释放哨兵结点
//	free(greaterhead);
//	free(lesshead);
//
//	return phead;
//}
//
//int main()
//{
//	int len = 0;
//	scanf("%d", &len);
//	int x = 0;
//	int i = 0;
//	SLTNode* plist = NULL;
//	for (i = 0; i < len; i++)
//	{
//		SListPushBack(&plist, len-i);
//	}
//	SListPrint(plist);
//	scanf("%d", &x);
//	SLTNode* newlist = Partition(plist, x);
//	SListPrint(newlist);
//
//	return 0;
//}


//给定一个链表的头指针，返回bool值，判断该链表是否为回文结构，要求时间复杂度为O(n)，空间复杂度为O(1)
//思路：将先找到中间节点，将后半部分逆置，再让前半部分和后半部分相比是否相同
//bool IsPalindrome(SLTNode* phead)
//{
//	if (phead == NULL)
//		return false;
//
//	SLTNode* slow = phead, * fast = phead;
//	while (fast && fast->next)
//	{
//		slow = slow->next;
//		fast = (fast->next)->next;
//	}
//
//	SLTNode* cur = slow;
//	SLTNode* newhead = NULL;
//	while (cur != NULL)
//	{
//		SLTNode* next = cur->next;
//		cur->next = newhead;
//		newhead = cur;
//		cur = next;
//	}
//
//	SLTNode* head = phead;
//	while (head && newhead)
//	{
//		if (head->data != newhead->data)
//			return false;
//		head = head->next;
//		newhead = newhead->next;
//	}
//	return true;
//}
//
//int main()
//{
//	int len = 0;
//	scanf("%d", &len);
//	int i = 0;
//	int x = 0;
//	SLTNode* plist = NULL;
//	for (i = 0; i < len; i++)
//	{
//		scanf("%d", &x);
//		SListPushBack(&plist, x);
//	}
//	
//	if (IsPalindrome(plist))
//	{
//		printf("yes\n");
//	}
//	else
//	{
//		printf("no\n");
//	}
//
//	return 0;
//}


//相交链表
//给定两个不存在环结构的链表头结点phead1、phead2，找出并返回两个链表相交的起始结点，如果两个链表没有相交则返回NULL
//返回后链表要保持其原始结构
//思路1：将链表list1每个结点和链表list2的所有结点依次进行比较，有地址相同则相交
//思路2：尾结点相同就是相交，长的链表先走长度差，再两个链表一起走，第一个相同的结点就是所求
//SLTNode* get_intersection_node(SLTNode* phead1, SLTNode* phead2)
//{
	//if (!(phead1 && phead2))
	//	return NULL;
	//SLTNode* cur1 = phead1, * cur2 = phead2;
	//int len1 = 1,len2 = 1;
	//while (cur1->next)
	//{
	//	len1++;
	//	cur1 = cur1->next;
	//}
	//while (cur2->next)
	//{
	//	len2++;
	//	cur2 = cur2->next;
	//}
	//if (cur1 != cur2)
	//	return NULL;
	//int gap = len1 > len2 ? len1 - len2 : len2 - len1;
	//SLTNode* longlist = phead1;
	//SLTNode* shortlist = phead2;
	//if (len1 < len2)
	//{
	//	longlist = phead2;
	//	shortlist = phead1;
	//}
	//while (gap--)
	//{
	//	longlist = longlist->next;
	//}
	//while (longlist!=shortlist)
	//{
	//	longlist = longlist->next;
	//	shortlist = shortlist->next;
	//}
	//return longlist;
//}


//环形链表
//如果链表中某个结点可以通过连续追踪next指针找到，则链表中存在环。
//判断链表中是否有环，返回一个布尔类型
//思路：因无法正常遍历，所以采取快慢指针。如果链表没有环，那么fast最终会为空；有环的话，fast会与slow相遇
//bool hasCycle(SLTNode* head)
//{
//	SLTNode* slow = head, * fast = head;
//	while (fast && fast->next)//针对链表长度的奇偶来确定是否到尾
//	{
//		slow = slow->next;
//		fast = (fast->next)->next;
//		if (slow == fast)
//		{
//			return true;
//		}
//	}
//	return false;
//}
//
//延伸问题：
// 1、为什么slow和fast一定会在环中相遇？中间会不会错过，或者不相遇？请证明
// 一定会相遇。
// fast一定先入环，fast入环时，slow走了入环前的一半，
// 随着slow进环，fast已经在环中走了一段，走了多少和环的大小有关，假设slow进环时，slow和fast的距离是n,
// fast开始追slow，slow每次往前走1步，fast往前走2步，每追1次，判断是否相遇，
// 每追一次，fast和slow的距离变化：
// N
// N-1
// N-1-1
// ……
// 1
// 0
// 每追一次，fast和slow的距离就减1，最后距离减到0的时候，就是相遇的点
// 
// 2、为什么slow走一步，fast走两步？fast能不能走三步或更多步呢？请证明
// fast一次走n步(n>2)的话不一定会相遇。
// 假设slow走1步，fast走3步
// 距离变化：
// N 为偶数     N为奇数
// N-2			N-2
// N-4			N-4
// ……			……
// 2			1
// 0			-1
// n为奇数时就会出现slow和fast错过的情况，若每次都错过就会永远不会相遇
// 这种情况下fast和slow错过后之间的距离就变为了c-1(c为环的长度)，如果c-1是奇数，那就永远追不上；c-1是偶数才会追上
// 扩展到更多步数，有如果n是slow和fast的步数差的倍数就可以追上，不是则可能追不上

//给定头结点head，如果链表有环，则返回入环的第一个节点，无环则返回NULL
//结论：一个指针从相遇点开始走，另一个指针从链表头开始走，他们会在环的入口点相遇
// 
//方法一证明：公式法  
// 追上相遇过程中
// slow与fast相遇时走了L+X，fast走L+X+n*C距离 
// (X为slow和fast之间的间距，n(n>=1)为此时fast指针在环里走了的圈数，L为入环时走的距离)
// 让fast的步频是slow的两倍，且slow每次只走一步，所以fast走的路程是slow的两倍,有：
// 2*(L+X) = L+X + n*C
// L = n*C - X
// L = (n-1)*C + C - X
// 其中(n-1)*C 为fast从相遇点再走回相遇点的过程，C - X 为fast在最后一圈从相遇点到入口点的距离
//
//SLTNode** detectCycle(SLTNode* head)
//{
//	SLTNode* slow = head, * fast = head;
//	SLTNode* meetnode = NULL;
//	while (fast && fast->next)
//	{
//		slow = slow->next;
//		fast = (fast->next)->next;
//		if (fast == slow)
//		{
//			meetnode = fast;
//			while (meetnode != head)
//			{
//				meetnode = meetnode->next;
//				head = head->next;
//			}
//			return head;
//		}
//	}
//	return NULL;
//}
//
//方法二：将相遇点的next置空或者将相遇点视为尾节点，从头结点和原本相遇点的下一个结点到入口点，就变成两个链表的相交问题


//力扣138  复制带随机指针的链表
// 思路：
// 1、复制结点，插入到原结点和下一个结点之间
// 2、根据原结点的random，处理复制结点的random
// 3、将复制结点解下来链接成一个新的链表，并将原链表的链接关系恢复
//一定要画图分析
//typedef struct RandomListNode
//{
//	int data;
//	struct RandomListNode* next;
//	struct RandomListNode* random;
//}RLNode;
//
//RLNode* copyRandomList(RLNode* head)
//{
//	RLNode* cur = head;
//	//、复制结点，插入到原结点和下一个结点之间
//	while (cur)
//	{
//		RLNode* copynode = (RLNode*)malloc(sizeof(RLNode));
//		if (copynode == NULL)
//		{
//			exit(-1);
//		}
//		copynode->data = cur->data;
//
//		copynode->next = cur->next;
//		cur->next = copynode;
//		cur = copynode->next;
//	}
//	//2、根据原结点的random，处理复制结点的random
//	cur = head;
//	while (cur)
//	{
//		RLNode* copynode = cur->next;
//		if (cur->random == NULL)
//		{
//			copynode->random = cur->random;
//		}
//		else
//		{
//			copynode->random = cur->random->next;
//		}
//		cur = copynode->next;
//	}
//	//3、将复制结点解下来链接成一个新的链表，并将原链表的链接关系恢复
//	cur = head;
//	RLNode* copyhead = NULL, *copytail = NULL;
//	while (cur)
//	{
//		RLNode* copy = cur->next;
//		RLNode* next = copy->next;
//		if (copytail == NULL)
//		{
//			copyhead = copy;
//			copytail = copy;
//		}
//		else
//		{
//			copytail->next = copy;
//			copytail = copy;
//		}
//		cur->next = next;
//		cur = next;
//	}
//	return copyhead;
//}


//双向链表
//链表的结构可分为以下形式的排列组合：
//   单向	   双向
// 有哨兵位  无哨兵位
//   循环      非循环
//


//顺序表和链表
//
//顺序表
//优点：1、支持随机访问
//		2、cpu高速缓存命中率更高
//缺点：1、头部与中间部分插入删除效率低，O(N)
//		2、空间不足时要增容，而增容有一定消耗；为了避免频繁增容，通常是*2去增容，可能出现空间浪费
//
//链表（以双向带头循环链表为例）
//优点：1、任意位置插入与删除效率高，O(1)
//		2、按需申请与释放空间
//缺点：1、不支持随机访问（用下标访问）意味着一些排序算法不适用如：快速排序、二分查找等
//		2、在存储有效值的同时，也存储连接指针，也有一定损耗
//		3cpu高速缓存命中率更低
//
//cpu高速缓存命中率
//在访问存储1数据的内存位置时，先看这个地址在不在缓存中
//在就直接访问，不在就加载到缓存，在访问。假设不命中，一次性加载多少bite到缓存中取决于硬件体系
//顺序表因其内存在物理空间上的连续性，使其在第一次性命中后继续命中的可能性更大
//而链表因其内存空间不具有连续性，导致经常要加载缓存，而缓存中不一定都是所要访问的数据，导致一定的缓存污染


//栈
//先进后出
// 
//数组栈	头做栈底，尾做栈头
// 
//链式栈	如果用尾做栈顶，尾插尾删，要设计成双向链表，否则效率低
//			如果用头做栈顶，头插头删，设计成单链表
//
//考虑缓存等因素，栈设计成数组栈会更好


//队列
//先进先出
//队头出队 队尾进队
//链式队列会更优
//常用于要排队的程序设计


//力扣20	有效括号
//typedef char STDataType;
//typedef struct Stack
//{
//	STDataType* data;
//	int top;
//	int capacity;
//}Stack;
//
//bool StackEmpty(Stack* ps)
//{
//	assert(ps);
//	if (ps->top > 0)
//	{
//		return false;
//	}
//	return true;
//}
//
//void StackInit(Stack* ps)
//{
//	assert(ps);
//	ps->data = NULL;
//	ps->capacity = 0;
//	ps->top = 0;//这里如果top = 0，意味着top指向栈顶的下一个；top = -1,top指向栈顶
//}
//
//void StackDestroy(Stack* ps)
//{
//	assert(ps);
//	free(ps->data);
//	ps->data = NULL;
//	ps->top = 0;
//	ps->capacity = 0;
//}
//
//static void CheckCapacity(Stack** ps)
//{
//	assert(ps);
//	if ((*ps)->capacity == (*ps)->top)
//	{
//		int newcapacity = (*ps)->capacity == 0 ? 4 : (*ps)->capacity * 2;
//		STDataType* tmp = (STDataType*)realloc((*ps)->data, newcapacity * sizeof(STDataType));
//		if (tmp == NULL)
//		{
//			exit(-1);
//		}
//		(*ps)->data = tmp;
//		(*ps)->capacity = newcapacity;
//		tmp = NULL;
//	}
//}
//
//void StackPush(Stack* ps, STDataType x)
//{
//	assert(ps);
//	CheckCapacity(&ps);
//	ps->data[ps->top] = x;
//	ps->top++;
//}
//
//void StackPop(Stack* ps)
//{
//	assert(ps);
//	assert(!StackEmpty(ps));
//	(ps->top)--;
//}
//
//STDataType StackTop(Stack* ps)
//{
//	assert(ps);
//	assert(!StackEmpty(ps));
//	return (ps->data[ps->top - 1]);
//
//}
//
//bool isValid(char* s)
//{
//	Stack st;
//	StackInit(&st);
//	while (*s)
//	{
//		if ((*s == '(') || (*s == '{') || (*s == '['))
//		{
//			StackPush(&st, *s);
//			s++;
//		}
//		else
//		{
//			if (StackEmpty(&st))
//			{
//				StackDestroy(&st);
//				return false;
//			}
//			STDataType top = StackTop(&st);
//			StackPop(&st);
//			if ((top != '(' && *s == ')')
//				|| (top != '{' && *s == '}')
//				|| (top != '[' && *s == ']'))
//			{
//				StackDestroy(&st);
//				return false;
//			}
//			else
//			{
//				s++;
//			}
//		}
//	}
//	bool ret = StackEmpty(&st);
//	StackDestroy(&st);
//	return ret;
//}


//力扣 P225
//请用两个队列实现栈，并支持普通栈的push、pop、top、empty四种操作
//不能改变队列的结构
// 
//核心思路：
//永远保持一个队列为空
//往非空队列入数据
//出数据时，依次出队头数据，将其转移到另一个队列中，剩最后一个数据时把它pop或将其结点返回

typedef int QDataType;

typedef struct QueueNode
{
	QDataType val;
	struct QueueNode* next;
}QueueNode;

typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->head;
	while (cur)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = NULL;
	pq->tail = NULL;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		exit(-1);
	}
	newnode->val = x;
	newnode->next = NULL;
	if (pq->head == NULL)
	{
		pq->head = newnode;
	}
	else
	{
		pq->tail->next = newnode;
	}
	pq->tail = newnode;
}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	QueueNode* next = pq->head->next;
	if (pq->head == pq->tail)
	{
		pq->tail = NULL;
	}
	free(pq->head);
	pq->head = next;
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->head->val;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq && pq->tail && pq->head);
	return pq->tail->val;
}

int QueueSize(Queue* pq)
{
	assert(pq);
	int count = 0;
	if (pq->head == NULL)
	{
		count = 0;
	}
	else
	{
		QueueNode* cur = pq->head;
		while (cur != NULL)
		{
			QueueNode* next = cur->next;
			count++;
			cur = next;
		}
	}
	return count;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);
	if (pq->head)
	{
		return false;
	}
	else
	{
		return true;
	}
}

//匿名结构体
//struct 
//{
//
//} MyStack;//此时MyStack为变量

typedef struct
{
	Queue q1;
	Queue q2;
} MyStack;

MyStack* myStackCreate() 
{
	MyStack* st = (MyStack*)malloc(sizeof(MyStack));//为避免返回个野指针，需将为其申请空间，并初始化队列
	if (st == NULL)
	{
		exit(-1);
	}
	QueueInit(&st->q1);
	QueueInit(&st->q2);
	return st;
}

void myStackPush(MyStack* obj, int x)
{
	if (QueueEmpty(&obj->q1))
	{
		QueuePush(&obj->q2, x);
	}
	else
	{
		QueuePush(&obj->q1,x);
	}
}

int myStackPop(MyStack* obj) 
{
	Queue* emptyqueue = &obj->q1;
	Queue* nonemptyqueue = &obj->q2;
	//借鉴相交链表的思路
	//先默认q1为空，q2非空
	if (!QueueEmpty(emptyqueue))
	{
		emptyqueue = &obj->q2;
		nonemptyqueue = &obj->q1;
	}
	//确保emptyqueue为空，nonemptyqueue为非空

	while (QueueSize(nonemptyqueue) > 1)
	{
		QueuePush(emptyqueue, QueueFront(nonemptyqueue));

	}
}

int myStackTop(MyStack* obj) 
{

}

bool myStackEmpty(MyStack* obj)
{

}


void myStackFree(MyStack* obj) 
{

}