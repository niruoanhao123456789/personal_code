#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// https://leetcode.cn/problems/two-sum/description/
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target)
//    {
//        int n = nums.size();
//        unordered_map<int, int> hash;
//        for (int i = 0; i < n; i++)
//        {
//            int t = target - nums[i];
//            if (hash.count(t))
//                return { hash[t],i };
//            hash[nums[i]] = i;
//        }
//        return {};
//    }
//};


// https://leetcode.cn/problems/check-permutation-lcci/description/
//class Solution {
//public:
//    bool CheckPermutation(string s1, string s2)
//    {
//        if (s1.size() != s2.size())
//            return false;
//        int n = s1.size();
//        int hash[26] = { 0 };
//        for (int i = 0; i < n; i++)
//        {
//            hash[s1[i] - 'a']++;
//            hash[s2[i] - 'a']--;
//        }
//        for (int i = 0; i < 26; i++)
//        {
//            if (hash[i] != 0)
//                return false;
//        }
//        return true;
//    }
//};


// https://leetcode.cn/problems/contains-duplicate-ii/description/
//class Solution {
//public:
//    bool containsNearbyDuplicate(vector<int>& nums, int k)
//    {
//        unordered_map<int, int> hash;
//        int n = nums.size();
//        for (int i = 0; i < n; i++)
//        {
//            if (hash.count(nums[i]) && abs(i - hash[nums[i]]) <= k)
//            {
//                return true;
//            }
//            else
//            {
//                hash[nums[i]] = i;
//            }
//        }
//        return false;
//    }
//};


// https://leetcode.cn/problems/group-anagrams/description/
//class Solution {
//public:
//    vector<vector<string>> groupAnagrams(vector<string>& strs)
//    {
//        vector<vector<string>> ret;
//        unordered_map<string, vector<string>> hash;
//        for (int i = 0; i < strs.size(); i++)
//        {
//            string t = strs[i];
//            sort(t.begin(), t.end());
//            hash[t].push_back(strs[i]);
//        }
//        for (auto& strs : hash)
//        {
//            ret.push_back(strs.second);
//        }
//        return ret;
//    }
//};