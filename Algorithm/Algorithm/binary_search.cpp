#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

// 在数据存在二段性下使用
// 注意mid 循环条件等细节问题

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


// https://leetcode.cn/problems/sqrtx/description/
//class Solution {
//public:
//    int mySqrt(int x) {
//        if (x < 1)
//            return 0;
//        int left = 1, right = x;
//        while (left < right)
//        {
//            long long mid = left + (right - left + 1) / 2;
//            if (mid * mid <= x)
//                left = mid;
//            else
//                right = mid - 1;
//        }
//
//        return left;
//    }
//};


// https://leetcode.cn/problems/search-insert-position/description/
//class Solution {
//public:
//    int searchInsert(vector<int>& nums, int target) {
//        int left = 0, right = nums.size() - 1;
//        while (left < right)
//        {
//            int mid = left + (right - left + 1) / 2;
//            if (nums[mid] <= target)
//                left = mid;
//            else
//                right = mid - 1;
//        }
//        if (nums[left] < target)
//            return left + 1;
//        return left;
//    }
//};


// https://leetcode.cn/problems/peak-index-in-a-mountain-array/description/
//class Solution {
//public:
//    int peakIndexInMountainArray(vector<int>& arr) {
//        int left = 1, right = arr.size() - 2;
//        while (left < right)
//        {
//            int mid = left + (right - left + 1) / 2;
//            if (arr[mid] > arr[mid - 1])
//                left = mid;
//            else
//                right = mid - 1;
//        }
//        return left;
//    }
//};


// https://leetcode.cn/problems/find-peak-element/submissions/701480732/
//class Solution {
//public:
//    int findPeakElement(vector<int>& nums) {
//        int left = 0, right = nums.size() - 1;
//        while (left < right)
//        {
//            int mid = left + (right - left) / 2;
//            if (nums[mid] > nums[mid + 1])
//            {
//                right = mid;
//            }
//            else
//            {
//                left = mid + 1;
//            }
//        }
//        return left;
//    }
//};


// https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/submissions/701806092/
//class Solution {
//public:
//    int findMin(vector<int>& nums) {
//        int size = nums.size();
//        int left = 0, right = size - 1;
//        while (left < right)
//        {
//            int mid = left + (right - left) / 2;
//            if (nums[mid] > nums[size - 1])
//            {
//                left = mid + 1;
//            }
//            else
//            {
//                right = mid;
//            }
//        }
//        return nums[left];
//    }
//};


// https://leetcode.cn/problems/que-shi-de-shu-zi-lcof/description/
// 
// 解法一：hash
// 解法二：历遍
// 解法三：数学（高斯求和）
// 解法四：^按位异或
// 解法五：二分查找
// 
//class Solution {
//public:
//    int takeAttendance(vector<int>& records) {
//        int left = 0, right = records.size() - 1;
//        while (left < right)
//        {
//            int mid = left + (right - left) / 2;
//            if (records[mid] == mid)
//            {
//                left = mid + 1;
//            }
//            else
//            {
//                right = mid;
//            }
//        }
//        if (records[left] == left)
//        {
//            return left + 1;
//        }
//        return left;
//    }
// 
// 
//};