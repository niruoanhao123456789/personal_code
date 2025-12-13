#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//力扣P202
//class Solution {
//public:
//    int powSum(int n)
//    {
//        int i = 0;
//        int sum = 0;
//        while (n)
//        {
//            i = n % 10;
//            sum += i * i;
//            n /= 10;
//        }
//        return sum;
//    }
//    bool isHappy(int n) {
//        int slow = n;
//        int fast = n;
//        slow = powSum(slow);
//        fast = powSum(fast);
//        fast = powSum(fast);
//        while (slow != fast)
//        {
//            slow = powSum(slow);
//            fast = powSum(fast);
//            fast = powSum(fast);
//        }
//        if (slow == 1)
//            return true;
//        else
//            return false;
//    }
//};
//
//int main()
//{
//    Solution s;
//    int n = 2;
//    cout << s.isHappy(n) << endl;
//
//	return 0;
//}


// 力扣 P11
// 利用向内遍历时存在的单调性，结合双指针
// 
//class Solution {
//public:
//    int maxArea(vector<int>& height) {
//        int left = 0;
//        int right = height.size() - 1;
//        int maxVolume = 0;
//        while (left < right)
//        {
//            int width = right - left;
//            int minHeight = min(height[left], height[right]);
//            int tmp = width * minHeight;
//            maxVolume = max(maxVolume, tmp);
//            if (height[left] > height[right])
//                right--;
//            else
//                left++;
//        }
//        return maxVolume;
//    }
//};