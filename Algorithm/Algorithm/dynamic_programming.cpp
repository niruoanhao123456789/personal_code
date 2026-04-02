#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

// 1、状态表示
//	  简单来说是dp表里的数值所表示的含义
//	  如何来？题目要求、经验总结、分析问题中发现重复子问题
// 2、状态转移方程
//	  即dp[i]= ？
//	  根据最近一步，来划分问题
// 3、初始化
//    保证填表时不越界
// 4、填表顺序
//    在填写当前状态时，所需的状态已经计算过了
// 5、返回值
//    题目要求 + 状态表示
// 6、空间优化
//	  滚动数组


// https://leetcode.cn/problems/n-th-tribonacci-number/
//class Solution {
//public:
//    int tribonacci(int n) {
//        if (n == 0)
//            return 0;
//        if (n == 1 || n == 2)
//            return 1;
//
//        // 创建dp表
//        vector<int> dp(n + 1);
//        // 初始化
//        dp[0] = 0, dp[1] = dp[2] = 1;
//        // 填表
//        for (int i = 3; i <= n; i++)
//        {
//            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
//        }
//
//        return dp[n];
//    }
//};
// 空间优化版
//class Solution {
//public:
//    int tribonacci(int n) {
//        if (n == 0)
//            return 0;
//        if (n == 1 || n == 2)
//            return 1;
//
//        int a = 0, b = 1, c = 1, d = 0;
//        for (int i = 3; i <= n; i++)
//        {
//            d = a + b + c;
//            a = b;
//            b = c;
//            c = d;
//        }
//        return d;
//    }
//};


// https://leetcode.cn/problems/three-steps-problem-lcci/description/
//class Solution {
//public:
//    int waysToStep(int n) {
//        if (n < 3)
//        {
//            return n;
//        }
//        // 1、创建dp表
//        vector<long long> dp(n + 1);
//        // 2、初始化
//        dp[1] = 1, dp[2] = 2, dp[3] = 4;
//        // 3、填表
//        for (int i = 4; i < n + 1; i++)
//        {
//            dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000007;
//        }
//        // 4、返回值
//        return dp[n];
//    }
//};


// https://leetcode.cn/problems/min-cost-climbing-stairs/description/
// 法一：dp[i]为到i位置的最小花费
//class Solution {
//public:
//    int minCostClimbingStairs(vector<int>& cost) {
//        int n = cost.size();
//        vector<int> dp(n + 1);
//        for (int i = 2; i < n + 1; i++)
//        {
//            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
//        }
//        return dp[n];
//    }
//};
//
// 法二：dp[i]为从i位置到楼顶的最小花费
//class Solution {
//public:
//    int minCostClimbingStairs(vector<int>& cost) {
//        int n = cost.size();
//        vector<int> dp(n);
//        dp[n - 1] = cost[n - 1], dp[n - 2] = cost[n - 2];
//        for (int i = n - 3; i >= 0; i--)
//        {
//            dp[i] = min(dp[i + 1], dp[i + 2]) + cost[i];
//        }
//        return min(dp[0], dp[1]);
//    }
//};


// https://leetcode.cn/problems/decode-ways/description/
//class Solution {
//public:
//    int numDecodings(string s) {
//        int n = s.size();
//        vector<int> dp(n);
//        dp[0] = s[0] != '0';
//        if (n < 2)
//            return dp[0];
//        int tmp = (s[0] - '0') * 10 + s[1] - '0';
//        if (s[0] != '0' && ((s[1] - '0') > 0 && (s[1] - '0') <= 9))
//            dp[1] += 1;
//        if (tmp >= 10 && tmp <= 26)
//            dp[1] += 1;
//
//        int i = 0;
//        for (i = 2; i < n; i++)
//        {
//            tmp = (s[i - 1] - '0') * 10 + s[i] - '0';
//            if (s[i] != '0')
//                dp[i] += dp[i - 1];
//            if (tmp >= 10 && tmp <= 26)
//                dp[i] += dp[i - 2];
//        }
//        return dp[i - 1];
//    }
//};
//
// 写法二
//class Solution {
//public:
//    int numDecodings(string s) {
//        int n = s.size();
//        vector<int> dp(n + 1);
//        dp[0] = 1; // 虚拟结点要保证后面填表是要正确的
//        dp[1] = s[0] != '0';
//
//        int i = 0;
//        for (i = 2; i <= n; i++)
//        {
//            int tmp = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
//            if (s[i - 1] != '0')
//                dp[i] += dp[i - 1]; // 处理单编码的情况
//            if (tmp >= 10 && tmp <= 26)
//                dp[i] += dp[i - 2];
//        }
//        return dp[i - 1];
//    }
//};


// https://leetcode.cn/problems/unique-paths/description/
//class Solution {
//public:
//    int uniquePaths(int m, int n) {
//        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
//        dp[0][1] = 1;
//        for (int i = 1; i < m + 1; i++)
//        {
//            for (int j = 1; j < n + 1; j++)
//            {
//                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//            }
//        }
//        return dp[m][n];
//    }
//};


// https://leetcode.cn/problems/unique-paths-ii/description/
//class Solution {
//public:
//    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//        int n = obstacleGrid.size();
//        int m = obstacleGrid[0].size();
//        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
//        dp[0][1] = 1;
//        for (int i = 1; i <= n; i++)
//        {
//            for (int j = 1; j <= m; j++)
//            {
//                if (obstacleGrid[i - 1][j - 1])
//                {
//                    dp[i][j] = 0;
//                }
//                else
//                {
//                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//                }
//            }
//        }
//        return dp[n][m];
//    }
//};


// https://leetcode.cn/problems/li-wu-de-zui-da-jie-zhi-lcof/description/
//class Solution {
//public:
//    int jewelleryValue(vector<vector<int>>& frame) {
//        int n = frame.size();
//        int m = frame[0].size();
//        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
//        for (int i = 1; i < n + 1; i++)
//        {
//            for (int j = 1; j < m + 1; j++)
//            {
//                dp[i][j] = frame[i - 1][j - 1] + max(dp[i - 1][j], dp[i][j - 1]);
//            }
//        }
//        return dp[n][m];
//    }
//};


// https://leetcode.cn/problems/minimum-falling-path-sum/description/
//class Solution {
//public:
//    int minFallingPathSum(vector<vector<int>>& matrix) {
//        int ret = INT_MAX;
//        int n = matrix.size(), m = matrix[0].size();
//        vector<vector<int>> dp(n + 1, vector<int>(m + 2, INT_MAX));
//        for (int i = 0; i < m + 2; i++)
//            dp[0][i] = 0;
//        for (int i = 1; i < n + 1; i++)
//        {
//            for (int j = 1; j < m + 1; j++)
//            {
//                dp[i][j] = matrix[i - 1][j - 1] + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i - 1][j + 1]));
//            }
//        }
//        for (int i = 1; i < m + 1; i++)
//        {
//            ret = min(ret, dp[n][i]);
//        }
//
//        return ret;
//    }
//};


// https://leetcode.cn/problems/minimum-path-sum/description/
//class Solution {
//public:
//    int minPathSum(vector<vector<int>>& grid) {
//        int n = grid.size(), m = grid[0].size();
//        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
//        dp[0][1] = dp[1][0] = 0;
//        for (int i = 1; i < n + 1; i++)
//        {
//            for (int j = 1; j < m + 1; j++)
//            {
//                dp[i][j] = grid[i - 1][j - 1] + min(dp[i - 1][j], dp[i][j - 1]);
//            }
//        }
//        return dp[n][m];
//    }
//};


// https://leetcode.cn/problems/dungeon-game/description/
//class Solution {
//public:
//    int calculateMinimumHP(vector<vector<int>>& dungeon) {
//        int n = dungeon.size(), m = dungeon[0].size();
//        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
//        dp[n - 1][m] = dp[n][m - 1] = 1;
//        for (int i = n - 1; i >= 0; i--)
//        {
//            for (int j = m - 1; j >= 0; j--)
//            {
//                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
//                dp[i][j] = max(1, dp[i][j]);
//            }
//        }
//        return dp[0][0];
//    }
//};


// https://leetcode.cn/problems/the-masseuse-lcci/description/
//class Solution {
//public:
//    int massage(vector<int>& nums) {
//        if (!nums.size())
//            return 0;
//        int n = nums.size();
//        vector<int> f(n);   // 表示第i位置选
//        vector<int> g(n);   // 表示第i位置不选
//        f[0] = nums[0], g[0] = 0;
//        for (int i = 1; i < n; i++)
//        {
//            f[i] = nums[i] + g[i - 1];
//            g[i] = max(f[i - 1], g[i - 1]);
//        }
//        return max(f[n - 1], g[n - 1]);
//    }
//};


// https://leetcode.cn/problems/house-robber-ii/description/
//class Solution {
//public:
//    int rob(vector<int>& nums) {
//        int n = nums.size();
//        // 返回两种情况下的最大值
//        return max(nums[0] + rob1(nums, 2, n - 2), rob1(nums, 1, n - 1));
//    }
//
//    int rob1(vector<int>& nums, int left, int right)
//    {
//        if (left > right)
//            return 0;
//        int n = nums.size();
//        vector<int> f(n);
//        vector<int> g(n);
//        f[left] = nums[left];
//        for (int i = left + 1; i <= right; i++)
//        {
//            f[i] = nums[i] + g[i - 1];
//            g[i] = max(f[i - 1], g[i - 1]);
//        }
//        return max(f[right], g[right]);
//    }
//};


// https://leetcode.cn/problems/delete-and-earn/description/
//class Solution {
//public:
//    int deleteAndEarn(vector<int>& nums) {
//        vector<int> arr(10003); // 用arr存放nums中i的总和,再做一遍“打家劫舍”
//        for (auto e : nums)
//        {
//            arr[e] += e;
//        }
//        int n = arr.size();
//        vector<int> f(n);
//        vector<int> g(n);
//        f[0] = arr[0];
//        for (int i = 1; i < n; i++)
//        {
//            f[i] = g[i - 1] + arr[i];
//            g[i] = max(g[i - 1], f[i - 1]);
//        }
//        return max(f[n - 1], g[n - 1]);
//    }
//};


// https://leetcode.cn/problems/JEj789/description/
//class Solution {
//public:
//    int minCost(vector<vector<int>>& costs) {
//        int n = costs.size();
//        // 用dp[i][0]、dp[i][1]、dp[i][2]分别表示第i间房子上red,bule,green的最小花费
//        vector<vector<int>> dp(n + 1, vector<int>(3));
//        for (int i = 1; i < n + 1; i++)
//        {
//            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i - 1][0];
//            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i - 1][1];
//            dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + costs[i - 1][2];
//        }
//        return min(min(dp[n][0], dp[n][1]), dp[n][2]);
//    }
//};


// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/description/
//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        int minCost = INT_MAX;
//        int maxprofit = 0;
//        for (auto e : prices)
//        {
//            maxprofit = max(e - minCost, maxprofit);
//            minCost = min(minCost, e);
//        }
//        return maxprofit;
//    }
//};


// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        int n = prices.size();
//        // dp[0][i]表示买入后的最大利润
//        // dp[1][i]表示冷冻其的最大利润
//        // dp[2][i]表示可交易的最大利润
//        vector<vector<int>> dp(3, vector<int>(n));
//        dp[0][0] = -prices[0];
//
//        // 用状态机思想来分析状态转移方程，并画个图来看
//        for (int i = 1; i < n; i++)
//        {
//            dp[0][i] = max(dp[0][i - 1], dp[2][i - 1] - prices[i]);
//            dp[1][i] = dp[0][i - 1] + prices[i];
//            dp[2][i] = max(dp[2][i - 1], dp[1][i - 1]);
//        }
//
//        return max(dp[1][n - 1], dp[2][n - 1]);
//    }
//};


// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/description/
//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        int n = prices.size();
//        vector<int> f(n);
//        vector<int> g(n);
//        f[0] = -prices[0];
//        for (int i = 1; i < n; i++)
//        {
//            f[i] = max(f[i - 1], g[i - 1] - prices[i]);
//            g[i] = max(g[i - 1], f[i - 1] + prices[i]);
//        }
//
//        return g[n - 1];
//    }
//};


// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
//class Solution {
//public:
//    int maxProfit(vector<int>& prices, int fee) {
//        int n = prices.size();
//        vector<int> purchase(n);
//        vector<int> sell(n);
//        purchase[0] = -prices[0];
//        for (int i = 1; i < n; i++)
//        {
//            purchase[i] = max(purchase[i - 1], sell[i - 1] - prices[i]);
//            sell[i] = max(sell[i - 1], purchase[i - 1] + prices[i] - fee);
//        }
//        return sell[n - 1];
//    }
//};


// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/description/
//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        int ret = -0x3f3f3f3f;
//        int n = prices.size();
//        // dp[i][j]表示第i+1天第j+1次交易获得的最大利润
//        vector<vector<int>>f(n, vector<int>(3, -0x3f3f3f3f));
//        vector<vector<int>> g(n, vector<int>(3, -0x3f3f3f3f));
//        f[0][0] = -prices[0], g[0][0] = 0;
//        for (int i = 1; i < n; i++)
//        {
//            for (int j = 0; j < 3; j++)
//            {
//                f[i][j] = max(f[i - 1][j], g[i - 1][j] - prices[i]);
//                g[i][j] = g[i - 1][j];
//                if (j >= 1)
//                    g[i][j] = max(g[i - 1][j], f[i - 1][j - 1] + prices[i]);
//            }
//        }
//        for (int j = 0; j < 3; j++)
//            ret = max(ret, g[n - 1][j]);
//        return ret;
//    }
//};


// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/description/
//class Solution {
//public:
//    int maxProfit(int k, vector<int>& prices)
//    {
//        int n = prices.size();
//        vector<vector<int>> f(n, vector<int>(k + 1, -0x3f3f3f3f));
//        vector<vector<int>> g = f;
//        f[0][0] = -prices[0], g[0][0] = 0;
//        for (int i = 1; i < n; i++)
//        {
//            for (int j = 0; j < k + 1; j++)
//            {
//                f[i][j] = max(f[i - 1][j], g[i - 1][j] - prices[i]);
//                if (j >= 1)
//                    g[i][j] = max(g[i - 1][j], f[i - 1][j - 1] + prices[i]);
//                else
//                    g[i][j] = g[i - 1][j];
//            }
//        }
//        int ret = 0;
//        for (int j = 0; j < k + 1; j++)
//            ret = max(ret, g[n - 1][j]);
//        return ret;
//    }
//};


// https://leetcode.cn/problems/maximum-subarray/description/
//class Solution {
//public:
//    int maxSubArray(vector<int>& nums) {
//        int n = nums.size();
//        vector<int> dp(n + 1);
//        dp[0] = -0x3f3f3f3f;
//        int ret = -0x3f3f3f3f;
//        for (int i = 1; i < n + 1; i++)
//        {
//            dp[i] = max(nums[i - 1], dp[i - 1] + nums[i - 1]);
//            ret = max(ret, dp[i]);
//        }
//        return ret;
//    }
//};


// https://leetcode.cn/problems/maximum-sum-circular-subarray/description/
//class Solution {
//public:
//    int maxSubarraySumCircular(vector<int>& nums) {
//        int n = nums.size();
//        int sum = 0;
//        int ret1 = INT_MIN, ret2 = INT_MAX;
//        vector<int> f(n + 1); // 最大和数组
//        vector<int> g = f; // 最小和数组
//
//        for (int i = 1; i < n + 1; i++)
//        {
//            f[i] = max(nums[i - 1], f[i - 1] + nums[i - 1]);
//            g[i] = min(nums[i - 1], g[i - 1] + nums[i - 1]);
//            sum += nums[i - 1];
//            ret1 = max(ret1, f[i]);
//            ret2 = min(ret2, g[i]);
//        }
//
//        return sum == ret2 ? ret1 : max(ret1, sum - ret2);
//    }
//};


// https://leetcode.cn/problems/maximum-product-subarray/description/
//class Solution {
//public:
//    int maxProduct(vector<int>& nums)
//    {
//        int n = nums.size();
//        int ret = INT_MIN;
//        vector<int> f(n + 1);
//        auto g = f;
//        f[0] = g[0] = 1;
//        for (int i = 1; i < n + 1; i++)
//        {
//            f[i] = max(max(nums[i - 1], f[i - 1] * nums[i - 1]), g[i - 1] * nums[i - 1]);
//            g[i] = min(min(nums[i - 1], f[i - 1] * nums[i - 1]), g[i - 1] * nums[i - 1]);
//            ret = max(ret, f[i]);
//        }
//        return ret;
//    }
//};