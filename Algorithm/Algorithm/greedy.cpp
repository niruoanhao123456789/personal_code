#include<iostream>
#include<queue>
#include<vector>
#include<list>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

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