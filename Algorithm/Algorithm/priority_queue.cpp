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


// https://leetcode.cn/problems/find-servers-that-handled-most-number-of-requests/description/
//class Solution {
//public:
//    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
//        int n = arrival.size();
//        if (n <= k)
//        {
//            vector<int> ret(n);
//            iota(ret.begin(), ret.end(), 0);
//            return ret;
//        }
//
//        // 保存空闲服务器的虚拟编号
//        priority_queue<int, vector<int>, greater<>> idle;
//        for (int i = 0;i < k;i++)
//        {
//            idle.push(i);
//        }
//
//        // 完成的时刻与服务器编号
//        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> busy;
//        // 统计对应服务器处理请求的个数
//        vector<int> cnt(k);
//        int max_cnt = 0;
//        vector<int> ret;
//        for (int i = 0;i < n;i++)
//        {
//            // 服务器闲置
//            while (!busy.empty() && busy.top().first <= arrival[i])
//            {
//                auto [_, j] = busy.top();
//                busy.pop();
//                // 计算此时服务器所处的虚拟编号
//                int virtual_id = i + (j - (i % k) + k) % k;
//                idle.push(virtual_id);
//            }
//
//            // 闲置服务器去处理请求
//            // 无闲置，舍弃请求
//            if (idle.empty())
//                continue;
//
//            // 实际的服务器编号
//            int id = idle.top() % k;
//            idle.pop();
//            busy.push({ arrival[i] + load[i],id });
//            ++cnt[id];
//
//            if (cnt[id] > max_cnt)
//            {
//                max_cnt = cnt[id];
//                ret = { id };
//            }
//            else if (cnt[id] == max_cnt)
//                ret.emplace_back(id);
//
//        }
//
//        return ret;
//    }
//};