#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

// 前缀和算法：
// 用于快速求出数组中某个区间的和
// 创建一个前缀和数组，下标从1开始计数，下标为0处用于辅助处理；
// 若下标从0开始，则需考虑边界情况

// https://www.nowcoder.com/practice/acead2f4c28c401889915da98ecdc6bf?tpId=230&tqId=2021480&ru=/exam/oj&qru=/ta/dynamic-programming/question-ranking&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D196
//#include <iostream>
//#include<vector>
//using namespace std;
//
//int main() {
//    int n, q;
//    while (cin >> n >> q)
//    {
//        int l = 0, r = 0;
//        long long ret = 0;
//        vector<long long> v(n + 1);
//        vector<long long> dq(n + 1);
//        for (int i = 1; i < n + 1; i++)
//        {
//            cin >> v[i];
//            dq[i] = v[i] + dq[i - 1];
//        }
//
//        for (int i = 0; i < q; i++)
//        {
//            cin >> l >> r;
//            ret = dq[r] - dq[l - 1];
//            cout << ret << endl;
//        }
//
//    }
//
//    return 0;
//}

// https://www.nowcoder.com/practice/99eb8040d116414ea3296467ce81cbbc?tpId=230&tqId=2023819&ru=/exam/oj&qru=/ta/dynamic-programming/question-ranking&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D196
//#include <iostream>
//#include<vector>
//#include<cstdio>
//using namespace std;
//
//int main()
//{
//    int n, m, q;
//    while (scanf("%d%d%d", &n, &m, &q) != EOF)
//    {
//        long long ret = 0;
//        vector<vector<long long>> dq(n + 1, vector<long long>(m + 1));
//        vector<vector<long long>> arr(n + 1, vector<long long>(m + 1));
//        for (int i = 1; i < n + 1; i++)
//        {
//            for (int j = 1; j < m + 1; j++)
//            {
//                scanf("%lld", &arr[i][j]);
//                dq[i][j] = arr[i][j] + dq[i - 1][j] + dq[i][j - 1] - dq[i - 1][j - 1];
//            }
//        }
//        for (int i = 0; i < q; i++)
//        {
//            int x1, x2, y1, y2;
//            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
//            ret = dq[x2][y2] - dq[x2][y1 - 1] - dq[x1 - 1][y2] + dq[x1 - 1][y1 - 1];
//            printf("%lld\n", ret);
//        }
//    }
//
//    return 0;
//}

// https://leetcode.cn/problems/find-pivot-index/submissions/705871190/
//class Solution {
//public:
//    int pivotIndex(vector<int>& nums) {
//        size_t size = nums.size();
//        vector<int> front(size), back(size);
//        for (int i = 1; i < size; i++)
//        {
//            front[i] = front[i - 1] + nums[i - 1];					// 前缀和
//            back[size - i - 1] = back[size - i] + nums[size - i];		// 后缀和
//        }
//        for (int i = 0; i < size; i++)
//        {
//            if (front[i] == back[i])
//            {
//                return i;
//            }
//        }
//        return -1;
//    }
//};

// https://leetcode.cn/problems/product-of-array-except-self/description/
//class Solution {
//public:
//    vector<int> productExceptSelf(vector<int>& nums) {
//        int n = nums.size();
//        vector<int> pre(n, 1), suf(n, 1), answer(n, 1);
//        for (int i = 1; i < n; i++)
//        {
//            pre[i] = pre[i - 1] * nums[i - 1];
//            suf[n - 1 - i] = suf[n - i] * nums[n - i];
//        }
//        for (int i = 0; i < n; i++)
//        {
//            answer[i] = pre[i] * suf[i];
//        }
//
//        return answer;
//    }
//};