#include"SearchBinaryTree.h"

// ⼆叉搜索树⼜称⼆叉排序树
// 若它的左⼦树不为空，则左⼦树上所有结点的值都⼩于等于根结点的值
// 若它的右⼦树不为空，则右⼦树上所有结点的值都⼤于等于根结点的值
// 它的左右⼦树也分别为⼆叉搜索树
// ⼆叉搜索树中可以⽀持插⼊相等的值，也可以不⽀持插⼊相等的值，具体看使⽤场景定义
// ⼆叉搜索树增删查改时间复杂度为： O(N)  

void test1()
{
	int arr[] = { 8, 3, 1, 10, 1, 6, 4, 7, 14, 13 };
	BSTree<int> t;

	for (auto e : arr)
	{
		t.Insert(e);
	}
	t.InOder();

	t.Erase(8);
	t.InOder();
}

int main()
{
	test1();

	return 0;
}