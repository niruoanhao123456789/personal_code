#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

// 简单位运算
// & |^ ~ << >>

// 给定一个数n，如何确定它的第x位是0还是1？(二进制下标从左往右从0开始)
// 1、将n右移x位，即n>>x，这样n的第x位就被移到了最低位
// 2、将n与1进行按位与运算，即(n>>x) & 1，如果结果为0，则说明n的第x位是0；如果结果为1，则说明n的第x位是1。
//
// 将一个数n的第x位设置为1
// 1、将1左移x位，即1<<x，这样就得到了一个只有第x位为1，其他位为0的数
// 2、将n与这个数进行按位或运算，即n | (1<<x)，这样就将n的第x位设置为1，而其他位保持不变。

// 将一个数n的第x位设置为0
// 1、将1左移x位，即1<<x，这样就得到了一个只有第x位为1，其他位为0的数
// 2、对这个数进行按位取反，即~(1<<x)，这样就得到了一个只有第x位为0，其他位为1的数
// 3、将n与这个数进行按位与运算，即n & ~(1<<x)，这样就将n的第x位设置为0，而其他位保持不变。

// 提取一个数n二进制表示最右侧的1 (lowbit)
// n & (-n) 
// -n 即将lowbit左边的所有位取反，lowbit位不变，lowbit右边的所有位不变

// 干掉lowbit
// n & (n - 1)
// n - 1 即将lowbit位变为0，lowbit左边的所有位不变，lowbit右边的所有位取反

// ^ 异或运算的运算规律
// 1、a ^ 0 = a
// 2、a ^ a = 0
// 3、a ^ b ^ c = b ^ (a ^ c)  既符合交换律与结合律


// 位图

// 下面几题要知道其一题多解的其他解法
// https://leetcode.cn/problems/is-unique-lcci/description/
//class Solution {
//public:
//    bool isUnique(string astr) {
//        if (astr.size() > 26)
//            return false;
//        int n = 0;
//        for (int i = 0; i < astr.size(); i++)
//        {
//            if ((n >> i) & 1)
//                return false;
//            else
//                n | (1 << i);
//        }
//        return true;
//    }
//};
// 
// https://leetcode.cn/problems/missing-number/description/
//class Solution {
//public:
//    int missingNumber(vector<int>& nums) {
//        int ret = 0;
//        for (int i = 0; i < nums.size(); i++)
//            ret ^= nums[i];
//        for (int i = 0; i <= nums.size(); i++)
//            ret ^= i;
//        return ret;
//    }
//};


// https://leetcode.cn/problems/sum-of-two-integers/description/
// 无进位相加与进位相加
//class Solution {
//public:
//    int getSum(int a, int b) {
//        while (b)
//        {
//            int tmp = a ^ b;  // 算出无进位相加结果
//            unsigned int carry = (unsigned int)(a & b) << 1;  // 算出进位相加结果
//            a = tmp;
//            b = carry;
//        }
//        return a;
//    }
//};


// https://leetcode.cn/problems/missing-two-lcci/description/
//class Solution {
//public:
//    vector<int> missingTwo(vector<int>& nums) {
//        int x = 0;
//        for (auto& e : nums)
//            x ^= e;
//        for (int i = 1; i <= nums.size() + 2; i++)
//            x ^= i;
//
//        // 找出两个数中比特位不同的那一位
//        int diff = 0;
//        while (1)
//        {
//            if ((x >> diff) & 1)
//                break;
//            else
//                diff++;
//        }
//
//        // 根据diff位的不同，将所有的数划分为两类来异或
//        vector<int> ret(2);
//        for (auto e : nums)
//        {
//            if ((e >> diff) & 1)
//                ret[1] ^= e;
//            else
//                ret[0] ^= e;
//        }
//        for (int i = 1; i <= nums.size() + 2; i++)
//        {
//            if ((i >> diff) & 1)
//                ret[1] ^= i;
//            else
//                ret[0] ^= i;
//        }
//        return ret;
//    }
//};


