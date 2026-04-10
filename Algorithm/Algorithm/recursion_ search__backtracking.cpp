#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
#include<stack>
#include<queue>
#include<list>
using namespace std;

// 如何理解递归
// 1、递归展开的细节图
// 2、二叉树中的题目
// 3、宏观看待递归的过程
//		1、不要在意递归细节展开图的细枝末节
//		2、把递归函数当成一个黑盒
//		3、相信这个黑盒一定能完成任务

// 如何写好一个递归
// 1、先找到相同的子问题 -> 函数头的设计
// 2、只关心某个一个子问题是如何解决的 -> 函数体的设计
// 3、注意递归函数的出口


// 搜索
// 深度优先遍历 vs 深度优先搜索
// 宽度优先遍历 vs 宽度优先搜索
// 暴搜：暴力枚举一遍所有情况


// 拓展搜索
// 全排列、利用树状图  -> 决策树


// 回溯与剪枝
// 回溯本质是深搜    迷宫问题


// https://leetcode.cn/problems/hanota-lcci/description/
//class Solution {
//public:
//    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
//        dfs(A, B, C, A.size());
//    }
//
//    void dfs(vector<int>& A, vector<int>& B, vector<int>& C, int size)
//    {
//        if (size == 1)
//        {
//            C.emplace(C.end(), A.back());
//            A.pop_back();
//            return;
//        }
//        dfs(A, C, B, size - 1);
//        C.emplace(C.end(), A.back());
//        A.pop_back();
//        dfs(B, A, C, size - 1);
//
//    }
//};


// https://leetcode.cn/problems/merge-two-sorted-lists/description/
//class Solution {
//public:
//    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//        if (list1 == nullptr)
//        {
//            return list2;
//        }
//        else if (list2 == nullptr)
//        {
//            return list1;
//        }
//
//        ListNode* phead, next1;
//        if (list1->val < list2->val)
//        {
//            phead = list1;
//            phead->next = mergeTwoLists(list1->next, list2);
//        }
//        else
//        {
//            phead = list2;
//            phead->next = mergeTwoLists(list2->next, list1);
//        }
//        return phead;
//    }
//};


// https://leetcode.cn/problems/reverse-linked-list/
//class Solution {
//public:
//    ListNode* reverseList(ListNode* head) {
//        if (head == nullptr || head->next == nullptr)
//            return head;
//
//        ListNode* newhead = reverseList(head->next);
//        head->next->next = head;
//        head->next = nullptr;
//
//        return newhead;
//    }
//};


// https://leetcode.cn/problems/swap-nodes-in-pairs/description/
//class Solution {
//public:
//    ListNode* swapPairs(ListNode* head) {
//        if (head == nullptr || head->next == nullptr)
//            return head;
//        ListNode* next = head->next;
//        ListNode* tmp = swapPairs(next->next);
//        head->next = tmp;
//        next->next = head;
//        return next;
//    }
//};


// https://leetcode.cn/problems/powx-n/description/
//class Solution {
//public:
//    double myPow(double x, int n) {
//        return n < 0 ? 1.0 / Pow(x, -(long long)n) : Pow(x, n);
//    }
//
//    double Pow(double x, int n)
//    {
//        if (n == 0)
//            return 1.0;
//        double tmp = Pow(x, n / 2);
//        return n % 2 == 0 ? tmp * tmp : tmp * tmp * x;
//    }
//
//};


// https://leetcode.cn/problems/evaluate-boolean-binary-tree/description/
//class Solution {
//public:
//    bool evaluateTree(TreeNode* root) {
//        if (root->val == 1 || root->val == 0)
//            return root->val;
//        bool left = evaluateTree(root->left);
//        bool right = evaluateTree(root->right);
//        if (root->val == 2)
//        {
//            return (left || right);
//        }
//        else if (root->val == 3)
//        {
//            return (left && right);
//        }
//
//        return 0;
//    }
//};


// https://leetcode.cn/problems/sum-root-to-leaf-numbers/description/
//class Solution {
//public:
//    int sumNumbers(TreeNode* root)
//    {
//        return dsf(root, 0);
//    }
//
//    int dsf(TreeNode* root, int presum)
//    {
//        if (!root)
//            return 0;
//        int sum = presum * 10 + root->val;
//        if (!root->left && !root->right)
//            return sum;
//        return dsf(root->left, sum) + dsf(root->right, sum);
//    }
//};


// https://leetcode.cn/problems/binary-tree-pruning/description/
//class Solution {
//public:
//    TreeNode* pruneTree(TreeNode* root) {
//        if (!root)
//            return root;
//
//        root->left = pruneTree(root->left);
//        root->right = pruneTree(root->right);
//        if (!root->left && !root->right && root->val == 0)
//        {
//            //delete root;
//            root = nullptr;
//        }
//
//        return root;
//    }
//};


// https://leetcode.cn/problems/validate-binary-search-tree/description/
//class Solution {
//public:
//    long long preval = LONG_MIN; // 每个节点值符合要求，则preval是严格递增的
//    bool isValidBST(TreeNode* root) {
//        if (!root)
//            return true;
//        // 利用中序遍历
//        bool left = isValidBST(root->left);
//
//        // 剪枝
//        if (!left)
//            return false;
//
//        bool cur = false;
//        if (preval < root->val)
//            cur = true;
//        else
//            return cur;
//        preval = root->val;
//        bool right = isValidBST(root->right);
//
//        return left && cur && right;
//    }
//};