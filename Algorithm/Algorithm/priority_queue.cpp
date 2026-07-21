#include<iostream>
#include<queue>
#include<vector>
#include<list>
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