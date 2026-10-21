#include<iostream>
#include<string>
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

// 如何真正意义上确定贪心策略的正确，需要数学证明（交换、数学归纳、反证法）

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


// https://leetcode.cn/problems/lemonade-change/description/
//class Solution {
//public:
//    bool lemonadeChange(vector<int>& bills) {
//        int five = 0, ten = 0;
//        for (auto& e : bills)
//        {
//            if (e == 5)
//                five++;
//            else if (e == 10)
//            {
//                if (!five)
//                    return false;
//                ten++;
//                five--;
//            }
//            else
//            {
//                if (ten && five)
//                {
//                    ten--;
//                    five--;
//                }
//                else if (!ten && five >= 3)
//                {
//                    five -= 3;
//                }
//                else
//                    return false;
//            }
//        }
//        return true;
//    }
//};


// https://leetcode.cn/problems/minimum-operations-to-halve-array-sum/description/
//class Solution {
//public:
//    int halveArray(vector<int>& nums) {
//        int count = 0;
//        double sum = 0;
//        priority_queue<double> heap;
//        for (auto& n : nums)
//        {
//            sum += n;
//            heap.push(n);
//        }
//        double aim = sum / 2;
//        while (sum > aim)
//        {
//            double tmp = heap.top() / 2;
//            heap.pop();
//            heap.push(tmp);
//            sum -= (tmp);
//            count++;
//        }
//        return count;
//    }
//};


// https://leetcode.cn/problems/largest-number/description/
//class Solution {
//public:
//    string largestNumber(vector<int>& nums) {
//        sort(nums.begin(), nums.end(), [](int left, int right) {
//            return to_string(left) + to_string(right) > to_string(right) + to_string(left);
//            });
//        if (nums[0] == 0)
//            return "0";
//        string ret;
//        for (auto& e : nums)
//        {
//            ret += to_string(e);
//        }
//        return ret;
//    }
//};


// https://leetcode.cn/problems/wiggle-subsequence/description/
//class Solution {
//public:
//    int wiggleMaxLength(vector<int>& nums) {
//        int n = nums.size();
//        if (n < 2)
//            return n;
//        int ret = 0, left = 0;
//        for (int i = 0;i < n - 1;i++)
//        {
//            // 计算接下来的趋势
//            int right = nums[i + 1] - nums[i];
//            // 水平段直接跳过
//            if (!right)
//                continue;
//            // 出现拐点，累加波峰与波谷
//            if (right * left <= 0)
//                ret++;
//            left = right;
//        }
//        return ret + 1;
//    }
//};