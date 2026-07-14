#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<list>
using namespace std;

// 快排
// 
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


//  https://leetcode.cn/problems/longest-palindromic-substring/description/
//class Solution {
//public:
//    string longestPalindrome(string s)
//    {
//        int n = s.size();
//        int begin = 0, len = 1;
//        vector<vector<int>> dp(n, vector<int>(n));
//        for (int i = n - 1; i >= 0; i--)
//        {
//            for (int j = i; j < n; j++)
//            {
//                if (s[i] == s[j])
//                {
//                    dp[i][j] = i + 1 < j ? dp[i + 1][j - 1] : true;
//                }
//                if (dp[i][j] && j - i + 1 > len)
//                {
//                    len = j - i + 1;
//                    begin = i;
//                }
//            }
//        }
//        return s.substr(begin, len);
//    }
//};


// 归并
//
// https://leetcode.cn/problems/sort-an-array/description/
//class Solution {
//public:
//
//    vector<int> sortArray(vector<int>& nums)
//    {
//        int n = nums.size();
//        vector<int> tmp(n);
//        mergeSort(nums, 0, n - 1, tmp);
//        return nums;
//    }
//
//    void mergeSort(vector<int>& nums, int left, int right, vector<int>& tmp)
//    {
//        if (left >= right)
//            return;
//
//        // 选择中间结点进行划分
//        int mid = (right + left) >> 1;
//
//        // 把左右区间进行划分排序
//        mergeSort(nums, left, mid, tmp);
//        mergeSort(nums, mid + 1, right, tmp);
//
//        int begin1 = left, end1 = mid;
//        int begin2 = mid + 1, end2 = right;
//        int index = left;
//
//        // 合并两个数组
//        while (begin1 <= end1 && begin2 <= end2)
//        {
//            tmp[index++] = nums[begin1] <= nums[begin2] ? nums[begin1++] : nums[begin2++];
//        }
//        // 处理未遍历完的数组
//        while (begin1 <= end1)
//        {
//            tmp[index++] = nums[begin1++];
//        }
//        while (begin2 <= end2)
//        {
//            tmp[index++] = nums[begin2++];
//        }
//
//        // 将原数组复原
//        for (int i = left; i <= right; i++)
//        {
//            nums[i] = tmp[i];
//        }
//    }
//};


// https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/description/
//class Solution {
//public:
//    int reversePairs(vector<int>& record)
//    {
//        int n = record.size();
//        vector<int> tmp(n);
//        return mergeSort(record, 0, n - 1, tmp);
//    }
//
//    int mergeSort(vector<int>& record, int left, int right, vector<int>& tmp)
//    {
//        if (left >= right)
//            return 0;
//
//        int ret = 0;
//        int mid = (right - left) / 2 + left;
//        ret += mergeSort(record, left, mid, tmp);
//        ret += mergeSort(record, mid + 1, right, tmp);
//
//        int begin1 = left, end1 = mid;
//        int begin2 = mid + 1, end2 = right;
//        int index = left;
//        while (begin1 <= end1 && begin2 <= end2)
//        {
//            if (record[begin1] <= record[begin2])
//                tmp[index++] = record[begin1++];
//            else
//            {
//                ret += mid - begin1 + 1;
//                tmp[index++] = record[begin2++];
//            }
//        }
//
//        while (begin1 <= end1)
//        {
//            tmp[index++] = record[begin1++];
//        }
//        while (begin2 <= end2)
//        {
//            tmp[index++] = record[begin2++];
//        }
//
//        for (int i = left; i <= right; i++)
//        {
//            record[i] = tmp[i];
//        }
//
//        return ret;
//    }
//};


// https://leetcode.cn/problems/count-of-smaller-numbers-after-self/description/
//class Solution {
//public:
//    int ntmp[100010], itmp[100010], index[100010];
//    vector<int> countSmaller(vector<int>& nums)
//    {
//        int n = nums.size();
//        vector<int> ret(n);
//        for (int i = 0; i < n; i++)
//            index[i] = i;
//        mergeSort(nums, 0, n - 1, ret);
//        return ret;
//    }
//
//    void mergeSort(vector<int>& nums, int left, int right, vector<int>& ret)
//    {
//        if (left >= right)
//            return;
//
//        int mid = (right + left) >> 1;
//        mergeSort(nums, left, mid, ret);
//        mergeSort(nums, mid + 1, right, ret);
//
//        int begin1 = left, end1 = mid;
//        int begin2 = mid + 1, end2 = right;
//        int cur = left;
//        while (begin1 <= end1 && begin2 <= end2)
//        {
//            if (nums[begin1] <= nums[begin2])
//            {
//                ntmp[cur] = nums[begin2];
//                itmp[cur++] = index[begin2++];
//            }
//            else
//            {
//                ret[index[begin1]] += end2 - begin2 + 1;
//                ntmp[cur] = nums[begin1];
//                itmp[cur++] = index[begin1++];
//            }
//        }
//        while (begin1 <= end1)
//        {
//            ntmp[cur] = nums[begin1];
//            itmp[cur++] = index[begin1++];
//        }
//        while (begin2 <= end2)
//        {
//            ntmp[cur] = nums[begin2];
//            itmp[cur++] = index[begin2++];
//        }
//
//        for (int i = left; i <= right; i++)
//        {
//            nums[i] = ntmp[i];
//            index[i] = itmp[i];
//        }
//    }
//};


// https://leetcode.cn/problems/reverse-pairs/description/
//class Solution {
//public:
//    int reversePairs(vector<int>& nums)
//    {
//        vector<int> tmp(nums.size());
//        return mergeSort(nums, 0, nums.size() - 1, tmp);
//    }
//
//    int mergeSort(vector<int>& nums, int left, int right, vector<int>& tmp)
//    {
//        if (left >= right)
//            return 0;
//
//        int ret = 0;
//        int mid = (left + right) >> 1;
//        ret += mergeSort(nums, left, mid, tmp);
//        ret += mergeSort(nums, mid + 1, right, tmp);
//
//        int begin1 = left, end1 = mid;
//        int begin2 = mid + 1, end2 = right;
//
//        while (begin1 <= end1) // 降序的情况
//        {
//            while (begin2 <= right && nums[begin2] >= nums[begin1] / 2.0)
//                begin2++;
//            if (begin2 > right)
//                break;
//            ret += right - begin2 + 1;
//            begin1++;
//        }
//
//        int index = left;
//        begin1 = left, begin2 = mid + 1;
//        while (begin1 <= end1 && begin2 <= end2)
//        {
//            tmp[index++] = nums[begin1] > nums[begin2] ? nums[begin1++] : nums[begin2++];
//        }
//        while (begin1 <= end1)
//        {
//            tmp[index++] = nums[begin1++];
//        }
//        while (begin2 <= end2)
//        {
//            tmp[index++] = nums[begin2++];
//        }
//
//        for (int i = left; i <= right; i++)
//        {
//            nums[i] = tmp[i];
//        }
//
//        return ret;
//    }
//};


//
