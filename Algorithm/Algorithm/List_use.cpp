#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<list>
using namespace std;
using ll = long long;

// 常用技巧：
// 1、画图
// 2、哨兵位头结点的引入可以减少对边界情况的特殊处理
// 3、不要吝啬定义变量，要让自己看得懂逻辑
// 4、快慢双指针

// 常用操作：
// 1、new一个新结点
// 2、头插尾插

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

};

// https://leetcode.cn/problems/add-two-numbers/description/
//class Solution {
//public:
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//        ListNode* cur1 = l1, * cur2 = l2;
//        ListNode* phead = new ListNode();
//        ListNode* cur = phead;
//        int tmp = 0;
//        while (cur1 && cur2)
//        {
//            tmp += cur1->val + cur2->val;
//            cur->next = new ListNode(tmp % 10);
//            cur = cur->next;
//            tmp /= 10;
//            cur1 = cur1->next;
//            cur2 = cur2->next;
//        }
//        while (cur1)
//        {
//            tmp += cur1->val;
//            cur->next = new ListNode(tmp % 10);
//            tmp /= 10;
//            cur = cur->next;
//            cur1 = cur1->next;
//        }
//        while (cur2)
//        {
//            tmp += cur2->val;
//            cur->next = new ListNode(tmp % 10);
//            tmp /= 10;
//            cur = cur->next;
//            cur2 = cur2->next;
//        }
//        if (tmp)
//        {
//            cur->next = new ListNode(tmp % 10);
//        }
//        cur = phead->next;
//        delete phead;
//        return cur;
//    }
//};


// https://leetcode.cn/problems/reorder-list/description/
//class Solution {
//public:
//    void reorderList(ListNode* head)
//    {
//        if (!head->next || !head || !head->next->next)
//            return;
//        ListNode* cur = head;
//        ListNode* cur1 = head->next;
//        ListNode* tail = getmidNode(head);
//        ListNode* next = tail->next;
//        tail->next = nullptr;
//        ListNode* cur2 = ListReverse(next);
//        while (cur1 && cur2)
//        {
//
//            cur->next = cur2;
//            cur = cur->next;
//            cur2 = cur2->next;
//            cur->next = cur1;
//            cur = cur->next;
//            cur1 = cur1->next;
//        }
//        if (cur2)
//            cur->next = cur2;
//        else if (cur1)
//            cur->next = cur1;
//    }
//
//    ListNode* getmidNode(ListNode* phead)
//    {
//        if (!phead)
//            return nullptr;
//        ListNode* fast = phead, * slow = phead;
//        while (fast && fast->next)
//        {
//            slow = slow->next;
//            fast = fast->next->next;
//        }
//        return slow;
//    }
//
//    ListNode* ListReverse(ListNode* phead)
//    {
//        if (!phead)
//            return nullptr;
//        ListNode* newhead = nullptr, * cur = phead;
//        while (cur)
//        {
//            ListNode* next = cur->next;
//            cur->next = newhead;
//            newhead = cur;
//            cur = next;
//        }
//        return newhead;
//    }
//};


// https://leetcode.cn/problems/merge-k-sorted-lists/description/
//class Solution {
//public:
//    struct cmp
//    {
//        bool operator()(const ListNode* l1, const ListNode* l2)
//        {
//            return l1->val > l2->val;
//        }
//    };
//
//    ListNode* mergeKLists(vector<ListNode*>& lists)
//    {
//        priority_queue<ListNode*, vector<ListNode*>, cmp> heap;
//        // 让所有头结点进入小根堆
//        for (auto& e : lists)
//        {
//            if (e)
//                heap.push(e);
//        }
//
//        // 合并k个有序链表
//        ListNode* ret = new ListNode();
//        ListNode* cur = ret;
//        while (!heap.empty())
//        {
//            ListNode* tmp = heap.top();
//            heap.pop();
//            cur->next = tmp;
//            cur = tmp;
//            if (tmp->next)
//            {
//                heap.push(tmp->next);
//            }
//        }
//
//        cur = ret->next;
//        delete ret;
//        return cur;
//    }
//};
//
// 法二
//class Solution {
//public:
//    ListNode* mergeKLists(vector<ListNode*>& lists)
//    {
//        return mergeLists(lists, 0, lists.size() - 1);
//    }
//
//    ListNode* mergeLists(vector<ListNode*>& lists, int left, int right)
//    {
//        if (left > right)
//            return nullptr;
//        if (left == right)
//            return lists[left];
//
//        int mid = (left + right) >> 1;
//        ListNode* l1 = mergeLists(lists, left, mid);
//        ListNode* l2 = mergeLists(lists, mid + 1, right);
//
//
//        return mergeTwoLists(l1, l2);
//    }
//
//    ListNode* mergeTwoLists(ListNode* phead1, ListNode* phead2)
//    {
//        ListNode* guard = new ListNode(0), * cur1 = phead1, * cur2 = phead2;
//        ListNode* ret = guard;
//        while (cur1 && cur2)
//        {
//            if (cur1->val > cur2->val)
//            {
//                ret->next = cur2;
//                cur2 = cur2->next;
//            }
//            else
//            {
//                ret->next = cur1;
//                cur1 = cur1->next;
//            }
//            ret = ret->next;
//        }
//        if (cur1)
//            ret->next = cur1;
//        if (cur2)
//            ret->next = cur2;
//        ret = guard->next;
//        delete guard;
//        return ret;
//    }
//};


// https://leetcode.cn/problems/reverse-nodes-in-k-group/description/
//class Solution {
//public:
//    ListNode* reverseKGroup(ListNode* head, int k)
//    {
//
//        int cnt = 0;
//        ListNode* cur = head;
//        ListNode* guard = new ListNode(0);
//        while (cur)
//        {
//            cnt++;
//            cur = cur->next;
//        }
//        cnt /= k;
//        cur = head;
//        ListNode* prev = guard;
//        while (cnt--)
//        {
//            int count = k;
//            ListNode* tail = cur;
//            while (count--)
//            {
//                ListNode* next = cur->next;
//                cur->next = prev->next;
//                prev->next = cur;
//                cur = next;
//            }
//            prev = tail;
//        }
//        prev->next = cur;
//        cur = guard->next;
//        delete guard;
//        return cur;
//    }
//};


// https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/
// 方法一：
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//class Solution {
//public:
//    ListNode* removeNthFromEnd(ListNode* head, int n) {
//        int len = getLen(head);
//        if (len == 1)
//            return nullptr;
//        ListNode* cur = head;
//        ListNode* prev = head;
//        for (int i = 1;i < len - n + 1;i++)
//        {
//            prev = cur;
//            cur = cur->next;
//        }
//        ListNode* next = cur->next;
//        prev->next = next;
//        if (cur == head)
//            return head->next;
//
//        return head;
//    }
//
//    int getLen(ListNode* head)
//    {
//        int cnt = 0;
//        ListNode* cur = head;
//        while (cur)
//        {
//            cnt++;
//            cur = cur->next;
//        }
//        return cnt;
//    }
//};
//
// 方法二：利用栈
//class Solution {
//public:
//    ListNode* removeNthFromEnd(ListNode* head, int n) {
//        stack<ListNode*> st;
//        ListNode* cur = head;
//        while (cur) {
//            st.push(cur);
//            cur = cur->next;
//        }
//        for (int i = 0;i < n;i++)
//        {
//            st.pop();
//        }
//        if (st.empty())
//            return head->next;
//        ListNode* prev = st.top();
//        prev->next = prev->next->next;
//
//        return head;
//    }
//};