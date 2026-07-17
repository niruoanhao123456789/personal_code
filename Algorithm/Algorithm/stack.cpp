#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<unordered_map>
#include<algorithm>
using namespace std;


// https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/description/
//class Solution {
//public:
//    string removeDuplicates(string s)
//    {
//        string ret;
//        for (auto& ch : s)
//        {
//            if (ret.size() && ret.back() == ch)
//                ret.pop_back();
//            else
//                ret += ch;
//        }
//        return ret;
//    }
//};


// https://leetcode.cn/problems/backspace-string-compare/description/
//class Solution {
//public:
//    bool backspaceCompare(string s, string t)
//    {
//        string s1, t1;
//        for (auto& ch : s)
//        {
//            if (s1.size() && ch == '#')
//            {
//                s1.pop_back();
//            }
//            else if (s1.size() == 0 && ch == '#')
//            {
//                continue;
//            }
//            else
//            {
//                s1 += ch;
//            }
//        }
//        for (auto& ch : t)
//        {
//            if (t1.size() && ch == '#')
//            {
//                t1.pop_back();
//            }
//            else if (t1.size() == 0 && ch == '#')
//            {
//                continue;
//            }
//            else
//            {
//                t1 += ch;
//            }
//        }
//        return s1 == t1;
//    }
//};