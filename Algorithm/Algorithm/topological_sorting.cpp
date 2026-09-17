#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<stack>
#include<list>
using namespace std;

// 有向无环图（DAG图）
// 入度：有多少条边指向它
// 出度：它指出了多少条边

// AOV网：顶点活动图
// 在有向无环图中，用一个顶点来表示一个活动，用边来表示活动的先后顺序的图结构

// 拓扑排序
// 简单来说，就是找到做事情的先后顺序，拓扑排序的结果可能不唯一

// 如何进行排序：
// 1、找出图中入读为0的结点
// 2、删除与该节点相连的边
// 3、重复上述操作直到图中没有点或入度为0的点为止

// 应用：判断有向图中是否存在环
//		 存在入度不为0的结点，但一直没有结点从图中出来

// 如何实现拓扑排序：
// 思路：借助队列来实现bfs
// 1、初始化，将所有入度为0的结点放入到队列中
// 2、当队列不为空时，拿出队头元素，加入到队头结果中；删除与该元素相连的边

// 建图
// 1、看数据稠密选择
//    邻接矩阵
//    邻接表     vector<vector<int>> / unordered_map<int,vector<int>>
// 2、根据题目灵活建表

// https://leetcode.cn/problems/course-schedule/description/
//class Solution {
//public:
//    bool canFinish(int n, vector<vector<int>>& prerequisites) {
//        unordered_map<int, vector<int>> edges; // 邻接表
//        vector<int> in(n); // 存储每⼀个结点的⼊度
//
//        // 建图
//        for (auto& e : prerequisites)
//        {
//            int a = e[0], b = e[1];
//            edges[b].emplace_back(a);
//            in[a]++;
//        }
//
//        // 拓扑排序 - bfs
//        queue<int> q;
//        // 把所有⼊度为 0 的点加⼊到队列中
//        for (int i = 0; i < n; i++)
//        {
//            if (!in[i])
//                q.push(i);
//        }
//
//        // 层序遍历
//        while (!q.empty())
//        {
//            auto tmp = q.front();
//            q.pop();
//            // 删除与该节点相连的边
//            for (auto e : edges[tmp])
//            {
//                in[e]--;
//                if (!in[e])
//                    q.push(e);
//            }
//        }
//
//        // 判断是否有环
//        for (auto e : in)
//        {
//            if (e)
//                return false;
//        }
//
//        return true;
//    }
//};


// https://leetcode.cn/problems/course-schedule-ii/
// 法一：
//class Solution {
//public:
//    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
//        unordered_map<int, vector<int>> edges; // 邻接表
//        vector<int> in(n); // 存储每⼀个结点的⼊度
//        vector<int> ret;
//
//        // 建图
//        for (auto& e : prerequisites)
//        {
//            int a = e[0], b = e[1];
//            edges[b].emplace_back(a);
//            in[a]++;
//        }
//
//        // 拓扑排序 - bfs
//        queue<int> q;
//        // 把所有⼊度为 0 的点加⼊到队列中
//        for (int i = 0; i < n; i++)
//        {
//            if (!in[i])
//                q.push(i);
//        }
//
//        // 层序遍历
//        while (!q.empty())
//        {
//            auto tmp = q.front();
//            q.pop();
//            ret.emplace_back(tmp);
//            // 删除与该节点相连的边
//            for (auto e : edges[tmp])
//            {
//                in[e]--;
//                if (!in[e])
//                    q.push(e);
//            }
//        }
//
//        if (ret.size() == n)   return ret;
//        else return {};
//    }
//};


// https://leetcode.cn/problems/Jf1JuT/description/
//class Solution {
//public:
//    bool flag;
//    unordered_map<char, int> in;
//    unordered_map<char, unordered_set<char>> edges;
//    string alienOrder(vector<string>& words)
//    {
//        // 初始化⼊度哈希表
//        for (auto& w : words)
//        {
//            for (auto& e : w)
//            {
//                in[e] = 0;
//            }
//        }
//        // 建表
//        int n = words.size();
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = i + 1; j < n; j++)
//            {
//                add(words[i], words[j]);
//                if (flag)    return "";
//            }
//        }
//
//        string ret;
//        // 2. 拓扑排序
//        queue<char> q;
//        for (auto& [a, b] : in)
//        {
//            if (!b)
//            {
//                q.push(a);
//            }
//        }
//        while (!q.empty())
//        {
//            char tmp = q.front();
//            q.pop();
//            ret += tmp;
//            for (auto ch : edges[tmp])
//            {
//                if (--in[ch] == 0)
//                    q.push(ch);
//            }
//        }
//        for (auto& [a, b] : in)
//        {
//            if (b)   return "";
//        }
//        return ret;
//    }
//
//    void add(string& s1, string& s2)
//    {
//        int n = min(s1.size(), s2.size());
//        int i = 0;
//        for (i = 0; i < n; i++)
//        {
//            if (s1[i] != s2[i])
//            {
//                char a = s1[i], b = s2[i];
//                if (!edges.count(a) || !edges[a].count(b))
//                {
//                    edges[a].insert(b);
//                    in[b]++;
//                }
//                break;
//            }
//        }
//        if (i == s2.size() && i < s1.size()) flag = true;
//    }
//};