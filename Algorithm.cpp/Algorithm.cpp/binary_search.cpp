#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//
//class Solution {
//public:
//    int search(vector<int>& nums, int target) {
//        int left = 0, right = nums.size() - 1;
//        while (left <= right)
//        {
//            int mid = left + (right - left + 1) / 2; // 防溢出写法
//            if (nums[mid] < target)
//                left = mid + 1;
//            else if (nums[mid] > target)
//                right = mid - 1;
//            else
//                return mid;
//        }
//        return -1;
//    }
//};


// https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/
//class Solution {
//public:
//    vector<int> searchRange(vector<int>& nums, int target) {
//        if (!nums.size())
//            return { -1,-1 };
//
//        int left = 0, right = nums.size() - 1, lindex = 0, rindex = 0;
//        // 二分左端点
//        while (left < right)
//        {
//            int mid = left + (right - left) / 2;
//            if (nums[mid] >= target)
//            {
//                right = mid;
//            }
//            else
//            {
//                left = mid + 1;
//            }
//        }
//        if (nums[left] != target)
//            return{ -1,-1 };
//        lindex = left;
//        // 二分右端点
//        left = 0;
//        right = nums.size() - 1;
//        while (left < right)
//        {
//            int mid = left + (right - left + 1) / 2;
//            if (nums[mid] <= target)
//            {
//                left = mid;
//            }
//            else
//            {
//                right = mid - 1;
//            }
//        }
//        rindex = right;
//
//        return { lindex,rindex };
//    }
//};