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


// https://leetcode.cn/problems/zigzag-conversion/description/
// 
// 模拟以外还可以试着找规律
//class Solution {
//public:
//    string convert(string s, int numRows) {
//        int size = s.size();
//        if (numRows == 1)
//            return s;
//        string ret;
//        // 计算公差
//        int d = 2 * numRows - 2;
//        // 处理第一行
//        for (int i = 0; i < size; i += d)
//        {
//            ret += s[i];
//        }
//        // 处理第k行
//        for (int k = 1; k < numRows - 1; k++)
//        {
//            for (int i = k, j = d - k; i < size || j < size; i += d, j += d)
//            {
//                if (i < size)
//                    ret += s[i];
//                if (j < size)
//                    ret += s[j];
//            }
//        }
//        //处理最后一行
//        for (int i = numRows - 1; i < size; i += d)
//        {
//            ret += s[i];
//        }
//
//        return ret;
//    }
//};


// https://leetcode.cn/problems/count-and-say/description/
//class Solution {
//public:
//    string countAndSay(int n) {
//        string ret = "1";
//        while (--n)
//        {
//            int left = 0, right = 0;
//            int count = 0;
//            string tmp;
//            tmp.reserve(2 * ret.size());
//            while (right < ret.size())
//            {
//                while (ret[left] == ret[right])
//                {
//                    right++;
//                }
//                count = right - left;
//                tmp += count + '0';
//                tmp += ret[left];
//                left = right;
//
//            }
//            ret = tmp;
//        }
//        return ret;
//    }
//};


// https://leetcode.cn/problems/minimum-number-of-frogs-croaking/description/
//class Solution {
//public:
//    int minNumberOfFrogs(string croakOfFrogs) {
//        string s = "croak";
//        int size = s.size();
//        vector<int> countHash(size); // 用数组模拟hash表
//        unordered_map<char, int> indexHash; // 映射字符下标
//        for (int i = 0; i < size; i++)
//        {
//            indexHash[s[i]] = i;
//        }
//
//        for (auto e : croakOfFrogs)
//        {
//            countHash[indexHash[e]]++;
//            if (e == 'c' && countHash[size - 1] > 0)
//            {
//                countHash[size - 1]--;
//            }
//            else
//            {
//                if (e != 'c')
//                    countHash[indexHash[e] - 1]--;
//            }
//            if (e != 'c' && countHash[indexHash[e] - 1] < 0)
//                return -1;
//        }
//
//        for (int i = 0; i < size - 1; i++)
//        {
//            if (countHash[i] > 0)
//                return -1;
//        }
//
//        return countHash[size - 1];
//    }
//};


