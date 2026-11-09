#include<iostream>
#include<queue>
#include<vector>
#include<list>
#include<numeric>
#include<algorithm>
using namespace std;


// https://leetcode.cn/problems/last-stone-weight/description/
//class Solution {
//public:
//    int lastStoneWeight(vector<int>& stones) {
//        priority_queue<int> heap;
//        for (auto& e : stones)
//        {
//            heap.push(e);
//        }
//        while (heap.size() > 1)
//        {
//            int x = heap.top();
//            heap.pop();
//            int y = heap.top();
//            heap.pop();
//            if (x - y > 0)
//                heap.push(x - y);
//        }
//        if (!heap.empty())
//            return heap.top();
//        return 0;
//    }
//};


// https://leetcode.cn/problems/kth-largest-element-in-a-stream/description/
//class KthLargest {
//public:
//    priority_queue<int, vector<int>, greater<int>> heap;
//    int _k;
//
//    KthLargest(int k, vector<int>& nums) {
//        _k = k;
//        for (auto& e : nums)
//        {
//            heap.push(e);
//            if (heap.size() > _k)
//                heap.pop();
//        }
//    }
//
//    int add(int val) {
//        heap.push(val);
//        if (heap.size() > _k)
//            heap.pop();
//
//        return heap.top();
//    }
//};


// https://leetcode.cn/problems/find-median-from-data-stream/description/
//class MedianFinder {
//public:
//    priority_queue<int> left;
//    priority_queue<int, vector<int>, greater<int>> right;
//    // 规定奇数个数据的话，letf长度要比right大1
//    MedianFinder() {
//
//    }
//
//    void addNum(int num) {
//        if (left.size() == right.size())
//        {
//            if (left.empty() || num <= left.top())
//            {
//                left.push(num);
//            }
//            else
//            {
//                right.push(num);
//                left.push(right.top());
//                right.pop();
//            }
//        }
//        else
//        {
//            if (num > left.top())
//                right.push(num);
//            else
//            {
//                left.push(num);
//                right.push(left.top());
//                left.pop();
//            }
//        }
//    }
//
//    double findMedian() {
//        if (left.size() == right.size())
//            return (left.top() + right.top()) / 2.0;
//        else
//            return (double)left.top();
//    }
//};


// https://leetcode.cn/problems/process-tasks-using-servers/description/
//class Solution {
//public:
//    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
//        int n = servers.size(), m = tasks.size();
//        vector<int> ret;
//
//        // t, id
//        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;
//
//        // weight , id
//        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> idle;
//        for (int i = 0;i < n;i++)
//        {
//            idle.emplace(servers[i], i);
//        }
//
//        long long now = 0;
//        // 把已经完成任务的服务器从 busy 移至 idle的仿函数
//        auto release = [&]() {
//            while (!busy.empty() && busy.top().first <= now)
//            {
//                auto&& [_, i] = busy.top();
//                idle.emplace(servers[i], i);
//                busy.pop();
//            }
//            };
//
//        // 处理任务
//        for (int i = 0;i < m;i++)
//        {
//            now = max(now, static_cast<long long>(i));
//            release();
//            if (idle.empty())
//            {
//                now = busy.top().first;
//                release();
//            }
//            auto&& [_, index] = idle.top();
//            ret.emplace_back(index);
//            busy.emplace(now + tasks[i], index);
//            idle.pop();
//        }
//
//        return ret;
//    }
//};


// 