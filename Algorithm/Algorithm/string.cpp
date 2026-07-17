#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// https://leetcode.cn/problems/longest-common-prefix/
//class Solution {
//public:
//    string longestCommonPrefix(vector<string>& strs)
//    {
//        int n = strs.size();
//        string ret;
//        int pos = 0;
//        int flag = 1;
//        while (pos < strs[0].size())
//        {
//            char tmp = strs[0][pos];
//            for (int i = 0; i < n; i++)
//            {
//                if (pos >= strs[i].size() || strs[i][pos] != tmp)
//                {
//                    flag = 0;
//                    break;
//                }
//            }
//            if (!flag)
//                break;
//            ret += tmp;
//            pos++;
//        }
//        return ret;
//    }
//};


// https://leetcode.cn/problems/longest-palindromic-substring/description/
//class Solution {
//public:
//    string longestPalindrome(string s)
//    {
//        // 中心拓展
//        int n = s.size();
//        int left = 0, right = 0, len = 0, pos = 0;
//        for (int i = 0; i < n; i++)
//        {
//            left = right = i;
//            while (left >= 0 && right < n && s[left] == s[right])
//            {
//                left--;
//                right++;
//            }
//            if (right - left - 1 > len)
//            {
//                len = right - left - 1;
//                pos = left + 1;
//            }
//            left = i;
//            right = i + 1;
//            while (left >= 0 && right < n && s[left] == s[right])
//            {
//                left--;
//                right++;
//            }
//            if (right - left - 1 > len)
//            {
//                len = right - left - 1;
//                pos = left + 1;
//            }
//        }
//        return s.substr(pos, len);
//    }
//};


// https://leetcode.cn/problems/add-binary/description/
//class Solution {
//public:
//    string addBinary(string a, string b) {
//        string ret;
//        int cur1 = a.size() - 1, cur2 = b.size() - 1, t = 0;
//        while (cur1 >= 0 || cur2 >= 0 || t) {
//            if (cur1 >= 0)
//                t += a[cur1--] - '0';
//            if (cur2 >= 0)
//                t += b[cur2--] - '0';
//            ret += t % 2 + '0';
//            t /= 2;
//        }
//        reverse(ret.begin(), ret.end());
//        return ret;
//    }
//};


// https://leetcode.cn/problems/multiply-strings/description/
//class Solution {
//public:
//    string multiply(string num1, string num2) {
//        int n = num1.size(), m = num2.size();
//        vector<int> tmp(m + n - 1);
//        reverse(num1.begin(), num1.end());
//        reverse(num2.begin(), num2.end());
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < m; j++)
//            {
//                tmp[i + j] += (num1[i] - '0') * (num2[j] - '0');
//            }
//        }
//        string ret;
//        int carry = 0;
//        for (int i = 0; i < m + n - 1; i++)
//        {
//            ret += ((tmp[i] + carry) % 10 + '0');
//            carry = (tmp[i] + carry) / 10;
//        }
//        if (carry)
//        {
//            ret += carry + '0';
//        }
//
//        reverse(ret.begin(), ret.end());
//        int pos = 0;
//        while (ret[pos] == '0')
//        {
//            pos++;
//        }
//        ret.erase(0, pos);
//        if (ret.size() == 0)
//            ret += '0';
//        return ret;
//    }
//};