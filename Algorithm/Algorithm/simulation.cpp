#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;


// https://leetcode.cn/problems/replace-all-s-to-avoid-consecutive-repeating-characters/
//class Solution {
//public:
//    string modifyString(string s) {
//        int size = s.size();
//        for (int i = 0; i < size; i++)
//        {
//            if (s[i] == '?')
//            {
//                char ch = 'a';
//                if (i == 0)
//                {
//                    if (ch == s[1])
//                        ch++;
//                }
//                else if (i == size - 1)
//                {
//                    if (ch == s[i - 1])
//                        ch++;
//                }
//                else
//                {
//                    while (ch == s[i - 1] || ch == s[i + 1])
//                    {
//                        ch++;
//                    }
//                }
//                ch = (ch - 'a') % 26;
//                ch += 'a';
//                s[i] = ch;
//            }
//
//        }
//        return s;
//    }
//};


// https://leetcode.cn/problems/teemo-attacking/description/
//class Solution {
//public:
//    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
//        int ret = 0;
//        for (int i = 0; i < timeSeries.size() - 1; i++)
//        {
//            int x = timeSeries[i + 1] - timeSeries[i];
//            if (x >= duration)
//            {
//                ret += duration;
//            }
//            else
//            {
//                ret += x;
//            }
//        }
//        ret += duration;
//        return ret;
//    }
//};