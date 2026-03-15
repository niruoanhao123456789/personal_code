#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

// 1、状态表示
//	  简单来说是dp表里的数值所表示的含义
//	  如何来？题目要求、经验总结、分析问题中发现重复子问题
// 2、状态转移方程
//	  即dp[i]= ？
// 3、初始化
//    保证填表时不越界
// 4、填表顺序
//    在填写当前状态时，所需的状态已经计算过了
// 5、返回值
//    题目要求 + 状态表示
// 6、空间优化
//	  滚动数组


// https://leetcode.cn/problems/n-th-tribonacci-number/
//class Solution {
//public:
//    int tribonacci(int n) {
//        if (n == 0)
//            return 0;
//        if (n == 1 || n == 2)
//            return 1;
//
//        // 创建dp表
//        vector<int> dp(n + 1);
//        // 初始化
//        dp[0] = 0, dp[1] = dp[2] = 1;
//        // 填表
//        for (int i = 3; i <= n; i++)
//        {
//            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
//        }
//
//        return dp[n];
//    }
//};
// 空间优化版
//class Solution {
//public:
//    int tribonacci(int n) {
//        if (n == 0)
//            return 0;
//        if (n == 1 || n == 2)
//            return 1;
//
//        int a = 0, b = 1, c = 1, d = 0;
//        for (int i = 3; i <= n; i++)
//        {
//            d = a + b + c;
//            a = b;
//            b = c;
//            c = d;
//        }
//        return d;
//    }
//};


// https://leetcode.cn/problems/three-steps-problem-lcci/description/
//class Solution {
//public:
//    int waysToStep(int n) {
//        if (n < 3)
//        {
//            return n;
//        }
//        // 1、创建dp表
//        vector<long long> dp(n + 1);
//        // 2、初始化
//        dp[1] = 1, dp[2] = 2, dp[3] = 4;
//        // 3、填表
//        for (int i = 4; i < n + 1; i++)
//        {
//            dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000007;
//        }
//        // 4、返回值
//        return dp[n];
//    }
//};


// https://leetcode.cn/problems/min-cost-climbing-stairs/description/
// 法一：dp[i]为到i位置的最小花费
//class Solution {
//public:
//    int minCostClimbingStairs(vector<int>& cost) {
//        int n = cost.size();
//        vector<int> dp(n + 1);
//        for (int i = 2; i < n + 1; i++)
//        {
//            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
//        }
//        return dp[n];
//    }
//};
//
// 法二：dp[i]为从i位置到楼顶的最小花费
//class Solution {
//public:
//    int minCostClimbingStairs(vector<int>& cost) {
//        int n = cost.size();
//        vector<int> dp(n);
//        dp[n - 1] = cost[n - 1], dp[n - 2] = cost[n - 2];
//        for (int i = n - 3; i >= 0; i--)
//        {
//            dp[i] = min(dp[i + 1], dp[i + 2]) + cost[i];
//        }
//        return min(dp[0], dp[1]);
//    }
//};