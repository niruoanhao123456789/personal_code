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


// 力扣 P611
// 
//class Solution {
//public:
//    int triangleNumber(vector<int>& nums) {
//        int sum = 0;
//		  
//		// 先对vector进行优化，再利用双指针
//        sort(nums.begin(), nums.end());
//        int max = nums.size() - 1;
//        while (max >= 2)
//        {
//            int left = 0;
//            int right = max - 1;
//            while (left < right)
//            {
//                if (nums[left] + nums[right] > nums[max])
//                {
//                    sum += right - left;
//                    right--;
//                }
//                else
//                    left++;
//
//            }
//            max--;
//        }
//        return sum;
//    }
//};