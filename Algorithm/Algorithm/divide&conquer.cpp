#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<list>
using namespace std;

// https://leetcode.cn/problems/sort-colors/description/
//class Solution {
//public:
//    void sortColors(vector<int>& nums)
//    {
//        int left = -1, i = 0, right = nums.size();
//        while (i < right)
//        {
//            if (nums[i] == 0)
//                swap(nums[++left], nums[i++]);
//            else if (nums[i] == 2)
//                swap(nums[--right], nums[i]);
//            else
//                i++;
//        }
//    }
//};


// https://leetcode.cn/problems/sort-an-array/description/
//class Solution {
//public:
//    vector<int> sortArray(vector<int>& nums)
//    {
//        srand(time(nullptr));
//        myqsort(nums, 0, nums.size() - 1);
//        return nums;
//    }
//
//    void myqsort(vector<int>& nums, int l, int r)
//    {
//        if (l >= r) return;
//        // 数组分三块
//        int key = nums[rand() % (r - l + 1) + l];
//        int i = l, left = l - 1, right = r + 1;
//        while (i < right)
//        {
//            if (nums[i] < key) swap(nums[++left], nums[i++]);
//            else if (nums[i] == key) i++;
//            else swap(nums[--right], nums[i]);
//        }
//        // [l, left] [left + 1, right - 1] [right, r]
//        myqsort(nums, l, left);
//        myqsort(nums, right, r);
//    }
//};


// https://leetcode.cn/problems/kth-largest-element-in-an-array/description/
//class Solution {
//public:
//    int findKthLargest(vector<int>& nums, int k) {
//        srand(time(nullptr));
//        return myqsort(nums, 0, nums.size() - 1, k);
//    }
//
//    int myqsort(vector<int>& nums, int l, int r, int k)
//    {
//        if (l == r)
//            return nums[l];
//        int key = nums[rand() % (r - l + 1) + l];
//        int i = l, left = l - 1, right = r + 1;
//        while (i < right)
//        {
//            if (nums[i] < key)
//                swap(nums[++left], nums[i++]);
//            else if (nums[i] > key)
//                swap(nums[--right], nums[i]);
//            else
//                i++;
//        }
//        int c = r - right + 1, b = right - left - 1;
//        if (c >= k)
//            return myqsort(nums, right, r, k);
//        else if (c + b >= k)
//            return key;
//        else
//            return myqsort(nums, l, left, k - c - b);
//    }
//};


// https://leetcode.cn/problems/zui-xiao-de-kge-shu-lcof/description/
//class Solution {
//public:
//    vector<int> inventoryManagement(vector<int>& stock, int cnt)
//    {
//        srand(time(nullptr));
//        myqsort(stock, 0, stock.size() - 1, cnt);
//        return { stock.begin(),stock.begin() + cnt };
//    }
//
//    void myqsort(vector<int>& stock, int l, int r, int cnt)
//    {
//        if (l >= r)
//            return;
//        int key = stock[rand() % (r - l + 1) + l];
//        int left = l - 1, right = r + 1, cur = l;
//        while (cur < right)
//        {
//            if (stock[cur] < key)
//                swap(stock[++left], stock[cur++]);
//            else if (stock[cur] > key)
//                swap(stock[--right], stock[cur]);
//            else
//                cur++;
//        }
//
//        int a = left - l + 1, b = right - left - 1;
//        if (a > cnt)
//            myqsort(stock, l, left, cnt);
//        else if (a + b > cnt)
//            return;
//        else
//            myqsort(stock, right, r, cnt - a - b);
//    }
//};