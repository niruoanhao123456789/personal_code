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