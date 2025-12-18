#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// 滑动窗口，即同向双指针
// https://leetcode.cn/problems/minimum-size-subarray-sum/description/
//
// 1、判断什么时候数据入窗口
// 2、根据题目决定在哪里更新结果
// 3、判断什么时候出窗口
// 
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