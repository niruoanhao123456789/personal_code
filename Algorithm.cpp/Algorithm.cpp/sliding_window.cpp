#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
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


// 438. 找到字符串中所有字⺟异位词 
// https://leetcode.cn/problems/find-all-anagrams-in-a-string/description/
//class Solution {
//public:
//    vector<int> findAnagrams(string s, string p) {
//        size_t hash1[26] = { 0 };
//        size_t hash2[26] = { 0 };
//        vector<int> ret;
//        for (auto e : p)
//        {
//            hash1[e - 'a']++;
//        }
//        int left = 0, right = 0;
//        int count = 0;
//        while (right < s.size())
//        {
//            hash2[s[right] - 'a']++;
//            if (hash2[s[right] - 'a'] <= hash1[s[right] - 'a'])
//            {
//                count++;
//            }
//            if (right - left + 1 > p.size())
//            {
//                if (hash2[s[left] - 'a'] <= hash1[s[left] - 'a'])
//                {
//                    count--;
//                }
//                hash2[s[left] - 'a']--;
//                left++;
//            }
//            if (right - left + 1 == p.size() && count == p.size())
//            {
//                ret.push_back(left);
//            }
//            right++;
//        }
//        return ret;
//    }
//};

// https://leetcode.cn/problems/substring-with-concatenation-of-all-words/description/
//class Solution {
//public:
//    vector<int> findSubstring(string s, vector<string>& words) {
//        unordered_map<string, int> hash1;
//        vector<int> ret;
//        for (auto e : words)
//        {
//            hash1[e]++;
//        }
//        int len = words[0].size();
//        for (int i = 0; i < len; i++)
//        {
//            int count = 0;
//            int left = i;
//            int right = left;
//            unordered_map<string, int> hash2;
//            while (right+len <= s.size())
//            {
//                // 进窗口
//                string in(s, right, len);
//                hash2[in]++;
//                if (hash2[in] <= hash1[in])
//                {
//                    count++;
//                }
//
//                // 出窗口
//                if (right - left+1> len * words.size())
//                {
//                    string out(s, left, len);
//                    if (hash2[out] <= hash1[out])
//                    {
//                        count--;
//                    }
//                    hash2[out]--;
//                    left += len;
//                }
//
//                // 判断
//                if (count == words.size())
//                {
//                    ret.push_back(left);
//                }
//
//                right += len;
//            }
//        }
//        return ret;
//    }
//};
//
//int main()
//{
//    string str = "barfoothefoobarman";
//    vector<string> words = { "foo","bar" };
//    Solution s;
//    for (auto e : s.findSubstring(str, words))
//    {
//        cout << e << " ";
//    }
//    cout << endl;
//
// 
// 
//    return 0;
//}