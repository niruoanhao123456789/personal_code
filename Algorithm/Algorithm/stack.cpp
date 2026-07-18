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


// https://leetcode.cn/problems/basic-calculator-ii/description/
//class Solution {
//public:
//    int calculate(string s)
//    {
//        int n = s.size();
//        int i = 0;
//        vector<int> nums;
//        char oper = '+';
//        while (i < n)
//        {
//            if (s[i] == ' ')
//                i++;
//            else if (s[i] >= '0' && s[i] <= '9')
//            {
//                int tmp = 0;
//                while (i < n && s[i] >= '0' && s[i] <= '9')
//                {
//                    tmp *= 10;
//                    tmp += s[i] - '0';
//                    i++;
//                }
//                if (oper == '+')
//                    nums.push_back(tmp);
//                else if (oper == '-')
//                    nums.push_back(-tmp);
//                else if (oper == '*')
//                    nums.back() *= tmp;
//                else if (oper == '/')
//                    nums.back() /= tmp;
//            }
//            else
//            {
//                oper = s[i];
//                i++;
//            }
//        }
//        int ret = 0;
//        for (auto& e : nums)
//        {
//            ret += e;
//        }
//        return ret;
//    }
//};


// https://leetcode.cn/problems/decode-string/description/
//class Solution {
//public:
//    string decodeString(string s)
//    {
//        int n = s.size();
//        stack<string> st;
//        st.push("");
//        stack<int> num;
//        int i = 0;
//        while (i < n)
//        {
//            if (s[i] >= '0' && s[i] <= '9')
//            {
//                int tmp = 0;
//                while (i < n && s[i] >= '0' && s[i] <= '9')
//                {
//                    tmp *= 10;
//                    tmp += s[i] - '0';
//                    i++;
//                }
//                num.push(tmp);
//            }
//            else if (s[i] == '[')
//            {
//                i++;
//                string tmp1 = "";
//                while (i < n && s[i] >= 'a' && s[i] <= 'z')
//                {
//                    tmp1 += s[i++];
//                }
//                st.push(tmp1);
//            }
//            else if (s[i] == ']')
//            {
//                i++;
//                int cnt = num.top();
//                num.pop();
//                string t = st.top();
//                st.pop();
//                while (cnt--)
//                {
//                    st.top() += t;
//                }
//            }
//            else
//            {
//                string tmp2 = "";
//                while (i < n && s[i] >= 'a' && s[i] <= 'z')
//                {
//                    tmp2 += s[i++];
//                }
//                st.top() += tmp2;
//            }
//        }
//        return st.top();
//    }
//};


// https://leetcode.cn/problems/validate-stack-sequences/description/
//class Solution {
//public:
//    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
//    {
//        int n = pushed.size(), m = popped.size();
//        stack<int> st;
//        int j = 0;
//        for (int i = 0; i < n; i++)
//        {
//            st.push(pushed[i]);
//            while (!st.empty() && st.top() == popped[j])
//            {
//                st.pop();
//                j++;
//            }
//        }
//        if (st.empty())
//            return true;
//        else
//            return false;
//    }
//};