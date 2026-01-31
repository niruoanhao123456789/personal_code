#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// 滑动窗口，即同向双指针
// 1、判断什么时候数据入窗口
// 2、根据题目决定在哪里更新结果
// 3、判断什么时候出窗口
// 
// https://leetcode.cn/problems/minimum-size-subarray-sum/description/
//class Solution {
//public:
//    int minSubArrayLen(int target, vector<int>& nums) {
//        int left = 0, right = 0, sum = 0, len = 0;
//        while (right < nums.size())
//        {
//            sum += nums[right]; //入窗口
//            if (sum < target)
//            {
//                right++;
//            }
//            else
//            {
//				  // 更新结果
//                if (len)
//                    len = (len < right - left + 1 ? len : right - left + 1);
//                else
//                    len = right - left + 1;
//                sum -= nums[left++]; //出窗口
//                sum -= nums[right];
//            }
//        }
//        return len;
//    }
//};


// https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/
//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//        int hash[256] = { 0 };
//        int left = 0, right = 0;
//        int n = s.size();
//        int len = 0;
//        while (right < n)
//        {
//            hash[s[right++]]++;
//            while (hash[s[right - 1]] > 1)
//            {
//                hash[s[left++]]--;
//            }
//            len = len > right - left ? len : right - left;
//        }
//        return len;
//    }
//};


//
//class Solution {
//public:
//    int longestOnes(vector<int>& nums, int k) {
//        int left = 0, right = 0, ret = 0, count = 0;
//        int n = nums.size();
//        while (right < n)
//        {
//            if (nums[right] == 0)
//                count++;
//            while (count > k)
//            {
//                if (nums[left++] == 0)
//                    count--;
//            }
//            ret = max(ret, right - left + 1);
//            right++;
//        }
//        return ret;
//    }
//};
//
//int main()
//{
//    vector<int> v = { 1,1,1,0,0,0,1,1,1,1,0 };
//    int k = 0;
//    Solution s;
//    cout << s.longestOnes(v, k) << endl;
//
//    return 0;
//}


//https://leetcode.cn/problems/minimum-operations-to-reduce-x-to-zero/description/
//class Solution {
//public:
//    int minOperations(vector<int>& nums, int x) {
//        int sum = 0;
//        for (auto e : nums)
//        {
//            sum += e;
//        }
//        int ret = -1;
//        int target = sum - x;
//        if (target < 0)
//            return -1;
//        int left = 0, right = 0;
//        int size = nums.size();
//        int tmpSum = 0;
//        int len = -1;
//        while (right < size)
//        {
//            tmpSum += nums[right++];
//            while (left <= right && tmpSum > target)
//            {
//                tmpSum -= nums[left++];
//            }
//            if (tmpSum == target)
//            {
//                len = len > (right - left) ? len : (right - left);
//            }
//        }
//        if (len == -1)
//        {
//            return len;
//        }
//        else
//        {
//            ret = size - len;
//        }
//        return ret;
//    }
//};
//
//int main()
//{
//    vector<int> v = { 3,2,20,1,1,3 };
//    Solution s;
//    int ret = s.minOperations(v, 10);
//    cout << ret << endl;
//
//    return 0;
//}


// 
//class Solution {
//public:
//    int totalFruit(vector<int>& fruits) {
//        vector<int> hash = { 0 };
//        hash.reserve(100001);
//        int left = 0, right = 0, kinds = 0;
//        int ret = 0;
//        while (right < fruits.size())
//        {
//            if (hash[fruits[right]] == 0)
//                kinds++;
//            hash[fruits[right]]++;
//            while (kinds > 2)
//            {
//                hash[fruits[left]]--;
//                if (hash[fruits[left]] == 0)
//                {
//                    kinds--;
//                }
//                left++;
//            }
//            ret = max(ret, right - left + 1);
//            right++;
//        }
//        return ret;
//    }
//};