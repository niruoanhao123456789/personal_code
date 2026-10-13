#include<iostream>
#include<queue>
#include<vector>
#include<list>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

// 贪心算法的策略：
// 从局部最优 -> 全局最优
// 整体思路为：
// 1、将解决问题的过程分为若干过程
// 2、每解决一个过程时，采取当前“最优”的策略
// 3、从而希望得到全局“最优”的策略

// 贪心算法的特点：
// 贪心策略的提出是没有标准与模板的，每一题的贪心策略都不同

// 如何真正意义上确定贪心策略的正确，需要数学证明

// https://leetcode.cn/problems/lexicographically-smallest-permutation-greater-than-target/description/
//class Solution {
//public:
//    string lexGreaterPermutation(string s, string target) {
//        int n = s.size();
//        int left[26] = { 0 };
//        for (int i = 0; i < n; i++)
//        {
//            left[s[i] - 'a']++;
//            left[target[i] - 'a']--;
//        }
//
//        for (int i = n - 1; i >= 0; i--)
//        {
//            int t = target[i] - 'a';
//            left[t]++;
//
//            bool flag = true;
//            for (auto& e : left)
//            {
//                if (e < 0)
//                {
//                    flag = false;
//                    break;
//                }
//            }
//            if (!flag)
//                continue;
//
//            for (int j = t + 1; j < 26; j++)
//            {
//                if (left[j] == 0)
//                    continue;
//
//                left[j]--;
//                target[i] = 'a' + j;
//                target.resize(i + 1);
//
//                for (int k = 0; k < 26; k++)
//                {
//                    target += string(left[k], 'a' + k);
//                }
//
//                return target;
//            }
//        }
//        return "";
//    }
//};


// 