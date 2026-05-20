#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
#include<stack>
#include<queue>
#include<list>
using namespace std;

// 如何理解递归
// 1、递归展开的细节图
// 2、二叉树中的题目
// 3、宏观看待递归的过程
//		1、不要在意递归细节展开图的细枝末节
//		2、把递归函数当成一个黑盒
//		3、相信这个黑盒一定能完成任务

// 如何写好一个递归
// 1、先找到相同的子问题 -> 函数头的设计
// 2、只关心某个一个子问题是如何解决的 -> 函数体的设计
// 3、注意递归函数的出口


// 搜索
// 深度优先遍历 vs 深度优先搜索
// 宽度优先遍历 vs 宽度优先搜索
// 暴搜：暴力枚举一遍所有情况


// 拓展搜索
// 全排列、利用树状图  -> 决策树


// 回溯与剪枝
// 回溯本质是深搜    迷宫问题


// https://leetcode.cn/problems/hanota-lcci/description/
//class Solution {
//public:
//    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
//        dfs(A, B, C, A.size());
//    }
//
//    void dfs(vector<int>& A, vector<int>& B, vector<int>& C, int size)
//    {
//        if (size == 1)
//        {
//            C.emplace(C.end(), A.back());
//            A.pop_back();
//            return;
//        }
//        dfs(A, C, B, size - 1);
//        C.emplace(C.end(), A.back());
//        A.pop_back();
//        dfs(B, A, C, size - 1);
//
//    }
//};


// https://leetcode.cn/problems/merge-two-sorted-lists/description/
//class Solution {
//public:
//    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//        if (list1 == nullptr)
//        {
//            return list2;
//        }
//        else if (list2 == nullptr)
//        {
//            return list1;
//        }
//
//        ListNode* phead, next1;
//        if (list1->val < list2->val)
//        {
//            phead = list1;
//            phead->next = mergeTwoLists(list1->next, list2);
//        }
//        else
//        {
//            phead = list2;
//            phead->next = mergeTwoLists(list2->next, list1);
//        }
//        return phead;
//    }
//};


// https://leetcode.cn/problems/reverse-linked-list/
//class Solution {
//public:
//    ListNode* reverseList(ListNode* head) {
//        if (head == nullptr || head->next == nullptr)
//            return head;
//
//        ListNode* newhead = reverseList(head->next);
//        head->next->next = head;
//        head->next = nullptr;
//
//        return newhead;
//    }
//};


// https://leetcode.cn/problems/swap-nodes-in-pairs/description/
//class Solution {
//public:
//    ListNode* swapPairs(ListNode* head) {
//        if (head == nullptr || head->next == nullptr)
//            return head;
//        ListNode* next = head->next;
//        ListNode* tmp = swapPairs(next->next);
//        head->next = tmp;
//        next->next = head;
//        return next;
//    }
//};


// https://leetcode.cn/problems/powx-n/description/
//class Solution {
//public:
//    double myPow(double x, int n) {
//        return n < 0 ? 1.0 / Pow(x, -(long long)n) : Pow(x, n);
//    }
//
//    double Pow(double x, int n)
//    {
//        if (n == 0)
//            return 1.0;
//        double tmp = Pow(x, n / 2);
//        return n % 2 == 0 ? tmp * tmp : tmp * tmp * x;
//    }
//
//};


// https://leetcode.cn/problems/evaluate-boolean-binary-tree/description/
//class Solution {
//public:
//    bool evaluateTree(TreeNode* root) {
//        if (root->val == 1 || root->val == 0)
//            return root->val;
//        bool left = evaluateTree(root->left);
//        bool right = evaluateTree(root->right);
//        if (root->val == 2)
//        {
//            return (left || right);
//        }
//        else if (root->val == 3)
//        {
//            return (left && right);
//        }
//
//        return 0;
//    }
//};


// https://leetcode.cn/problems/sum-root-to-leaf-numbers/description/
//class Solution {
//public:
//    int sumNumbers(TreeNode* root)
//    {
//        return dsf(root, 0);
//    }
//
//    int dsf(TreeNode* root, int presum)
//    {
//        if (!root)
//            return 0;
//        int sum = presum * 10 + root->val;
//        if (!root->left && !root->right)
//            return sum;
//        return dsf(root->left, sum) + dsf(root->right, sum);
//    }
//};


// https://leetcode.cn/problems/binary-tree-pruning/description/
//class Solution {
//public:
//    TreeNode* pruneTree(TreeNode* root) {
//        if (!root)
//            return root;
//
//        root->left = pruneTree(root->left);
//        root->right = pruneTree(root->right);
//        if (!root->left && !root->right && root->val == 0)
//        {
//            //delete root;
//            root = nullptr;
//        }
//
//        return root;
//    }
//};

// dsf中
// 全局变量
//“恢复现场”
// 剪枝

// https://leetcode.cn/problems/validate-binary-search-tree/description/
//class Solution {
//public:
//    long long preval = LONG_MIN; // 每个节点值符合要求，则preval是严格递增的
//    bool isValidBST(TreeNode* root) {
//        if (!root)
//            return true;
//        // 利用中序遍历
//        bool left = isValidBST(root->left);
//
//        // 剪枝
//        if (!left)
//            return false;
//
//        bool cur = false;
//        if (preval < root->val)
//            cur = true;
//        else
//            return cur;
//        preval = root->val;
//        bool right = isValidBST(root->right);
//
//        return left && cur && right;
//    }
//};


// https://leetcode.cn/problems/kth-smallest-element-in-a-bst/description/
//class Solution {
//public:
//    // 全局变量的使用
//    int ret = 0;
//    int count = 0;
//    int kthSmallest(TreeNode* root, int k) {
//        count = k;
//        dsf(root);
//        return ret;
//    }
//
//    void dsf(TreeNode* root)
//    {
//        if (!root)
//            return;
//        dsf(root->left);
//        count--;
//        if (count < 0)
//            return;
//        if (count == 0)
//            ret = root->val;
//        dsf(root->right);
//    }
//};


// https://leetcode.cn/problems/binary-tree-paths/description/
//class Solution {
//public:
//    // 全局变量的使用，以及其需要实现“恢复现场”的作用
//    vector<string> ret;
//    vector<string> binaryTreePaths(TreeNode* root) {
//        dsf(root, "");
//        return ret;
//    }
//
//    // 本题利用函数形参来实现“恢复现场”
//    void dsf(TreeNode* root, string path)
//    {
//        path += to_string(root->val);
//        if (!root->left && !root->right)
//        {
//            ret.emplace_back(path);
//            return;
//        }
//        else
//        {
//            path += "->";
//        }
//        if (root->left)
//            dsf(root->left, path);
//        if (root->right)
//            dsf(root->right, path);
//    }
//};


// 思考思路
// 1、先画棵决策树（树状图），越详细越好
// 2、深搜、回溯、剪枝
// 
// https://leetcode.cn/problems/permutations/description/
//class Solution {
//public:
//    vector<vector<int>> ret;
//    vector<int> path;
//    bool check[7] = { false };
//
//    vector<vector<int>> permute(vector<int>& nums)
//    {
//        dsf(nums);
//        return ret;
//    }
//
//    void dsf(vector<int>& nums)
//    {
//        if (nums.size() == path.size())
//        {
//            ret.emplace_back(path);
//            return;
//        }
//
//        for (int i = 0; i < nums.size(); i++)
//        {
//            if (!check[i])
//            {
//                path.emplace_back(nums[i]);
//                check[i] = true;
//                dsf(nums);
//                // 回溯 -> 回复现场
//                path.pop_back();
//                check[i] = false;
//            }
//        }
//    }
//
//};


// https://leetcode.cn/problems/subsets/description/
// 解法一：
//class Solution {
//public:
//    vector<vector<int>> ret;
//    vector<int> path;
//
//    vector<vector<int>> subsets(vector<int>& nums)
//    {
//        dsf(nums, 0);
//        return ret;
//    }
//
//    void dsf(vector<int>& nums, int i)
//    {
//        if (i == nums.size())
//        {
//            ret.emplace_back(path);
//            return;
//        }
//
//        // 不选空
//        path.emplace_back(nums[i]);
//        dsf(nums, i + 1);
//        path.pop_back();
//
//        // 选空
//        dsf(nums, i + 1);
//    }
//};
//
// 解法二：
//class Solution {
//public:
//    vector<vector<int>> ret;
//    vector<int> path;
//
//    vector<vector<int>> subsets(vector<int>& nums)
//    {
//        dsf(nums, 0);
//        return ret;
//    }
//
//    void dsf(vector<int>& nums, int pos)
//    {
//        ret.emplace_back(path);
//        for (int i = pos; i < nums.size(); i++)
//        {
//            path.emplace_back(nums[i]);
//            dsf(nums, i + 1);
//            path.pop_back();
//        }
//    }
//};


// https://leetcode.cn/problems/sum-of-all-subset-xor-totals/description/
//class Solution {
//public:
//    int sum = 0;
//    int path = 0;
//    int subsetXORSum(vector<int>& nums)
//    {
//        dsf(nums, 0);
//        return sum;
//    }
//
//    void dsf(vector<int>& nums, int pos)
//    {
//        sum += path;
//        for (int i = pos; i < nums.size(); i++)
//        {
//            path ^= nums[i];
//            dsf(nums, i + 1);
//            path ^= nums[i];
//        }
//    }
//};


// https://leetcode.cn/problems/permutations-ii/description/
//class Solution {
//public:
//    vector<vector<int>> ret;
//    vector<int> path;
//    bool check[9] = { 0 };
//    vector<vector<int>> permuteUnique(vector<int>& nums)
//    {
//        sort(nums.begin(), nums.end());
//        dsf(nums, 0);
//        return ret;
//    }
//
//    void dsf(vector<int>& nums, int pos)
//    {
//        if (pos == nums.size())
//        {
//            ret.emplace_back(path);
//            return;
//        }
//
//        for (int i = 0; i < nums.size(); i++)
//        {
//            if (!check[i] && (i == 0 || nums[i] != nums[i - 1] || check[i - 1]))
//            {
//                path.emplace_back(nums[i]);
//                check[i] = true;
//                dsf(nums, pos + 1);
//                path.pop_back();
//                check[i] = false;
//            }
//        }
//    }
//};


// https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/
//class Solution {
//public:
//    vector<string> hash = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
//    vector<string> ret;
//    string path;
//    vector<string> letterCombinations(string digits)
//    {
//        dfs(digits, 0);
//        return ret;
//    }
//
//    void dfs(string& digits, int pos)
//    {
//        if (pos == digits.size())
//        {
//            ret.push_back(path);
//            return;
//        }
//
//        for (int i = 0; i < hash[digits[pos] - '0'].size(); i++)
//        {
//            path += hash[digits[pos] - '0'][i];
//            dfs(digits, pos + 1);
//            path.pop_back();
//        }
//    }
//};


// https://leetcode.cn/problems/generate-parentheses/description/
//class Solution {
//public:
//    vector<string> ret;
//    string path;
//    int left, right, size;
//    vector<string> generateParenthesis(int n) {
//        size = n;
//        dfs();
//        return ret;
//    }
//
//    void dfs()
//    {
//        if (right == size)
//        {
//            ret.push_back(path);
//            return;
//        }
//
//        if (left < size)
//        {
//            path += "(";
//            left++;
//            dfs();
//            path.pop_back();
//            left--;
//        }
//        if (right < left)
//        {
//            path += ")";
//            right++;
//            dfs();
//            path.pop_back();
//            right--;
//        }
//    }
//};


// https://leetcode.cn/problems/combinations/description/
//class Solution {
//public:
//    vector<vector<int>> ret;
//    vector<int> path;
//    vector<vector<int>> combine(int n, int k) {
//        dfs(n, k, 1);
//        return ret;
//    }
//
//    void dfs(int n, int k, int pos)
//    {
//        if (path.size() == k)
//        {
//            ret.push_back(path);
//            return;
//        }
//
//        for (int i = pos; i <= n; i++)
//        {
//            path.push_back(i);
//            dfs(n, k, i + 1);
//            path.pop_back();
//        }
//    }
//};


// https://leetcode.cn/problems/target-sum/description/
//class Solution {
//public:
//    int ret = 0;
//    int findTargetSumWays(vector<int>& nums, int target) {
//        dfs(nums, target, 0, 0);
//        return ret;
//    }
//
//    void dfs(vector<int>& nums, int t, int pos, int path)
//    {
//        if (pos == nums.size())
//        {
//            if (path == t)
//                ret++;
//            return;
//        }
//        dfs(nums, t, pos + 1, path + nums[pos]);
//        dfs(nums, t, pos + 1, path - nums[pos]);
//    }
//};


// https://leetcode.cn/problems/combination-sum/description/
// 法一
//class Solution {
//public:
//    int t;
//    vector<int> path;
//    vector<vector<int>> ret;
//    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
//    {
//		  int sum = 0;
//        t = target;
//        dfs(candidates, 0,sum);
//        return ret;
//    }
//
//    void dfs(vector<int>& candidates, int pos,int sum)
//    {
//        if (sum == t)
//        {
//            ret.push_back(path);
//            return;
//        }
//        if (sum > t || pos==candidates.size())
//            return;
//
//        for (int i = pos; i < candidates.size(); i++)
//        {
//            path.push_back(candidates[i]);
//            dfs(candidates, i,sum + candidates[i]);
//            path.pop_back();
//        }
//    }
//};
//
// 法二
//class Solution {
//public:
//    int t;
//    vector<int> path;
//    vector<vector<int>> ret;
//    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
//    {
//        t = target;
//        dfs(candidates, 0, 0);
//        return ret;
//    }
//
//    void dfs(vector<int>& candidates, int pos, int sum)
//    {
//        if (sum == t)
//        {
//            ret.push_back(path);
//            return;
//        }
//        if (sum > t || pos == candidates.size())
//            return;
//
//        for (int i = 0; i * candidates[pos] + sum <= t; i++)
//        {
//            if (i)
//                path.push_back(candidates[pos]);
//            dfs(candidates, pos + 1, i * candidates[pos] + sum);
//        }
//
//        for (int i = 1; i * candidates[pos] + sum <= t; i++)
//        {
//            path.pop_back();
//        }
//    }
//};


// https://leetcode.cn/problems/letter-case-permutation/description/
//class Solution {
//public:
//    vector<string> ret;
//    string path;
//    vector<string> letterCasePermutation(string s) {
//        dfs(s, 0);
//        return ret;
//    }
//
//    void dfs(string& s, int pos)
//    {
//        if (pos == s.size())
//        {
//            ret.push_back(path);
//            return;
//        }
//
//        char tmp = s[pos];
//        // 不变
//        path += tmp;
//        dfs(s, pos + 1);
//        path.pop_back();
//
//        if (s[pos] >= 'a' && s[pos] <= 'z')
//        {
//            tmp -= 32;
//        }
//        else if (s[pos] >= 'A' && s[pos] <= 'Z')
//        {
//            tmp += 32;
//        }
//        if (s[pos] > '9' || s[pos] < '0')
//        {
//            path += tmp;
//            dfs(s, pos + 1);
//            path.pop_back();
//        }
//    }
//};


// https://leetcode.cn/problems/beautiful-arrangement/description/
//class Solution {
//public:
//    int ret = 0;
//    bool check[16] = { false };
//    int countArrangement(int n) {
//        dfs(n, 1);
//        return ret;
//    }
//
//    void dfs(int n, int pos)
//    {
//        if (pos == n + 1)
//        {
//            ret++;
//            return;
//        }
//        for (int i = 1; i <= n; i++)
//        {
//            if (!check[i] && (pos % i == 0 || i % pos == 0))
//            {
//                check[i] = true;
//                dfs(n, pos + 1);
//                check[i] = false;
//            }
//        }
//
//    }
//};


// https://leetcode.cn/problems/n-queens/description/
//class Solution {
//public:
//    int size = 0;
//    bool col[10] = { false };
//    bool dig1[2 * 10] = { false };
//    bool dig2[2 * 10] = { false };
//    vector<vector<string>> ret;
//    vector<string> path;
//    vector<vector<string>> solveNQueens(int n) {
//        size = n;
//        dfs(0);
//        return ret;
//    }
//
//    void dfs(int pos)
//    {
//        if (pos == size)
//        {
//            ret.push_back(path);
//            return;
//        }
//        string s(size, '.');
//        for (int j = 0; j < size; j++)
//        {
//            if ((!col[j]) && (!dig1[pos - j + size]) && (!dig2[pos + j]))
//            {
//                s[j] = 'Q';
//                path.push_back(s);
//                col[j] = dig1[pos - j + size] = dig2[pos + j] = true;
//                dfs(pos + 1);
//                path.pop_back();
//                col[j] = dig1[pos - j + size] = dig2[pos + j] = false;
//                s[j] = '.';
//            }
//
//        }
//
//    }
//};


// https://leetcode.cn/problems/valid-sudoku/description/
//class Solution {
//public:
//    bool row[9][10];
//    bool col[9][10];
//    bool grid[3][3][10];
//    bool isValidSudoku(vector<vector<char>>& board)
//    {
//        int n = board.size();
//        int m = board[0].size();
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < m; j++)
//            {
//                if (board[i][j] != '.')
//                {
//                    int num = board[i][j] - '0';
//                    if (row[i][num] || col[j][num] || grid[i / 3][j / 3][num])
//                        return false;
//                    row[i][num] = col[j][num] = grid[i / 3][j / 3][num] = true;
//                }
//            }
//        }
//        return true;
//    }
//};


// https://leetcode.cn/problems/sudoku-solver/description/
//class Solution {
//public:
//    bool row[9][10] = { false };
//    bool col[9][10] = { false };
//    bool grid[3][3][10] = { false };
//    int n, m;
//    void solveSudoku(vector<vector<char>>& board)
//    {
//        n = board.size();
//        m = board[0].size();
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < m; j++)
//            {
//                if (board[i][j] != '.')
//                {
//                    int num = board[i][j] - '0';
//                    row[i][num] = col[j][num] = grid[i / 3][j / 3][num] = true;
//                }
//            }
//        }
//        dfs(board);
//    }
//
//    bool dfs(vector<vector<char>>& board)
//    {
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < m; j++)
//            {
//                
//                if (board[i][j] == '.')
//                {
//                    for (int val = 1; val <= 9; val++)
//                    {
//                        if (!row[i][val] && !col[j][val] && !grid[i][j][val])
//                        {
//                            board[i][j] = val + '0';
//                            row[i][val] = col[j][val] = grid[i / 3][j / 3][val] = true;
//                            if (dfs(board))
//                                return true;
//                            board[i][j] = '.';
//                            row[i][val] = col[j][val] = grid[i / 3][j / 3][val] = false;
//                        }
//                    }
//                    return false;
//                }
//            }
//        }
//        return true;
//    }
//};


// https://leetcode.cn/problems/word-search/description/
//class Solution {
//public:
//    int n, m;
//    bool visit[7][7];
//    bool exist(vector<vector<char>>& board, string word)
//    {
//        n = board.size();
//        m = board[0].size();
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < m; j++)
//            {
//                if (board[i][j] == word[0])
//                {
//                    visit[i][j] = true;
//                    if (dfs(board, i, j, word, 1))
//                        return true;
//                    visit[i][j] = false;
//                }
//            }
//        }
//        return false;
//    }
//
//    // 利用向量的思维来进行表格内的搜索
//    int dx[4] = { 0,0,-1,1 };
//    int dy[4] = { 1,-1,0,0 };
//    bool dfs(vector<vector<char>>& board, int i, int j, string& s, int pos)
//    {
//        if (pos == s.size())
//            return true;
//        for (int k = 0; k < 4; k++)
//        {
//            int x = j + dx[k];
//            int y = i + dy[k];
//            if (x >= 0 && x < m && y >= 0 && y < n && !visit[y][x] && board[y][x] == s[pos])
//            {
//                visit[y][x] = true;
//                if (dfs(board, y, x, s, pos + 1))
//                    return true;
//                visit[y][x] = false;
//            }
//        }
//        return false;
//    }
//};


// https://leetcode.cn/problems/path-with-maximum-gold/description/
//class Solution {
//public:
//    int n, m;
//    bool visit[15][15] = { false };
//    int ret = 0;
//    int getMaximumGold(vector<vector<int>>& grid)
//    {
//        n = grid.size(), m = grid[0].size();
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < m; j++)
//            {
//                if (grid[i][j] != 0)
//                {
//                    visit[i][j] = true;
//                    dfs(grid, i, j, 0);
//                    visit[i][j] = false;
//                }
//            }
//        }
//        return ret;
//    }
//
//    int dx[4] = { 0,0,1,-1 };
//    int dy[4] = { -1,1,0,0 };
//    void dfs(vector<vector<int>>& grid, int i, int j, int sum)
//    {
//        sum += grid[i][j];
//        int flag = 1;
//        for (int k = 0; k < 4; k++)
//        {
//            int x = i + dx[k];
//            int y = j + dy[k];
//            if (x >= 0 && y >= 0 && x < n && y < m && !visit[x][y] && grid[x][y])
//            {
//                flag = 0;
//                visit[x][y] = true;
//                dfs(grid, x, y, sum);
//                visit[x][y] = false;
//            }
//        }
//        if (flag)
//        {
//            ret = max(sum, ret);
//            return;
//        }
//    }
//};


// https://leetcode.cn/problems/unique-paths-iii/description/
//class Solution {
//public:
//    int n, m;
//    int ret = 0, target = 0;
//    bool visit[20][20] = { false };
//    int uniquePathsIII(vector<vector<int>>& grid)
//    {
//        int x, y;
//        n = grid.size(), m = grid[0].size();
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < m; j++)
//            {
//                if (grid[i][j] == 0)
//                    target++;
//                else if (grid[i][j] == 1)
//                {
//                    x = i;
//                    y = j;
//                    visit[i][j] = true;
//                }
//                else if (grid[i][j] == -1)
//                    visit[i][j] = true;
//            }
//        }
//        dfs(grid, x, y, 0);
//        return ret;
//    }
//
//    int dx[4] = { 0,0,1,-1 };
//    int dy[4] = { 1,-1,0,0 };
//    void dfs(vector<vector<int>>& grid, int i, int j, int count)
//    {
//        if (grid[i][j] == 0)
//            count++;
//        if (grid[i][j] == 2 && count == target)
//        {
//            ret++;
//            return;
//        }
//        for (int k = 0; k < 4; k++)
//        {
//            int x = i + dx[k];
//            int y = j + dy[k];
//            if (x >= 0 && x < n && y >= 0 && y < m && !visit[x][y])
//            {
//                visit[x][y] = true;
//                dfs(grid, x, y, count);
//                visit[x][y] = false;
//            }
//        }
//    }
//};


// floodfill算法
// 基本模型在一块区域中寻找有相同性质的连通区
// 思想也是暴力搜索，dfs、bfs
// https://leetcode.cn/problems/flood-fill/description/
//class Solution {
//public:
//    int n, m, pre;
//    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
//    {
//        if (image[sr][sc] == color)
//            return image;
//        n = image.size(), m = image[0].size();
//        pre = image[sr][sc];
//        dfs(image, sr, sc, color);
//        return image;
//    }
//
//    int dx[4] = { 0,0,1,-1 };
//    int dy[4] = { 1,-1,0,0 };
//    void dfs(vector<vector<int>>& image, int i, int j, int color)
//    {
//        image[i][j] = color;
//        for (int k = 0; k < 4; k++)
//        {
//            int x = i + dx[k];
//            int y = j + dy[k];
//            if (x >= 0 && x < n && y >= 0 && y < m && image[x][y] == pre)
//            {
//                dfs(image, x, y, color);
//            }
//        }
//    }
//};


// https://leetcode.cn/problems/number-of-islands/description/
//class Solution 
//{
//public:
//    int n, m, ret = 0;
//    bool visit[301][301] = { false };
//    int numIslands(vector<vector<char>>& grid)
//    {
//        n = grid.size(), m = grid[0].size();
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < m; j++)
//            {
//                if (grid[i][j] == '1' && !visit[i][j])
//                {
//                    ret++;
//                    visit[i][j] = true;
//                    dfs(grid, i, j);
//                }
//            }
//        }
//        return ret;
//    }
//
//    int dx[4] = { 0,0,1,-1 };
//    int dy[4] = { 1,-1,0,0 };
//    void dfs(vector<vector<char>>& grid, int i, int j)
//    {
//        for (int k = 0; k < 4; k++)
//        {
//            int x = i + dx[k];
//            int y = j + dy[k];
//            if (x >= 0 && x < n && y >= 0 && y < m && !visit[x][y] && grid[x][y] == '1')
//            {
//                visit[x][y] = true;
//                dfs(grid, x, y);
//            }
//        }
//    }
//};


// https://leetcode.cn/problems/max-area-of-island/description/
//class Solution {
//public:
//    int count = 0;
//    int n, m, ret = 0;
//    bool visit[50][50] = { false };
//    int maxAreaOfIsland(vector<vector<int>>& grid) {
//        n = grid.size();
//        m = grid[0].size();
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < m; j++)
//            {
//                if (grid[i][j] == 1 && !visit[i][j])
//                {
//                    count = 0;
//                    visit[i][j] = true;
//                    dfs(grid, i, j);
//                    ret = max(ret, count);
//                }
//            }
//        }
//
//        return ret;
//    }
//
//    int dx[4] = { 0,0,1,-1 };
//    int dy[4] = { 1,-1,0,0 };
//    void dfs(vector<vector<int>>& grid, int i, int j)
//    {
//        count++;
//        for (int k = 0; k < 4; k++)
//        {
//            int x = i + dx[k];
//            int y = j + dy[k];
//            if (x >= 0 && x < n && y >= 0 && y < m && !visit[x][y] && grid[x][y] == 1)
//            {
//                visit[x][y] = true;
//                dfs(grid, x, y);
//            }
//        }
//    }
//};


// https://leetcode.cn/problems/surrounded-regions/description/
//class Solution {
//public:
//    int n, m;
//    void solve(vector<vector<char>>& board)
//    {
//        n = board.size(), m = board[0].size();
//        // 1、先将边界的O替换成.
//        for (int i = 0; i < n; i++)
//        {
//            if (board[i][0] == 'O')
//                dfs(board, i, 0);
//            if (board[i][m - 1] == 'O')
//                dfs(board, i, m - 1);
//        }
//
//        for (int j = 0; j < m; j++)
//        {
//            if (board[0][j] == 'O')
//                dfs(board, 0, j);
//            if (board[n - 1][j] == 'O')
//                dfs(board, n - 1, j);
//        }
//
//        // 2、还原并将其他O换成X
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < m; j++)
//            {
//                if (board[i][j] == '.')
//                    board[i][j] = 'O';
//                else if (board[i][j] == 'O')
//                    board[i][j] = 'X';
//            }
//        }
//    }
//
//    int dx[4] = { 0,0,1,-1 };
//    int dy[4] = { 1,-1,0,0 };
//    void dfs(vector<vector<char>>& board, int i, int j)
//    {
//        board[i][j] = '.';
//        for (int k = 0; k < 4; k++)
//        {
//            int x = i + dx[k];
//            int y = j + dy[k];
//            if (x >= 0 && x < n && y >= 0 && y < m && board[x][y] == 'O')
//            {
//                dfs(board, x, y);
//            }
//        }
//    }
//};


// https://leetcode.cn/problems/pacific-atlantic-water-flow/description/
//class Solution {
//public:
//    int n, m;
//    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
//    {
//        n = heights.size(), m = heights[0].size();
//        vector<vector<bool>> pacific(n, vector<bool>(m));
//        auto atlantic = pacific;
//        for (int i = 0; i < n; i++)
//        {
//            dfs(heights, i, 0, pacific);
//        }
//        for (int j = 0; j < m; j++)
//        {
//            dfs(heights, 0, j, pacific);
//        }
//
//        for (int i = 0; i < n; i++)
//        {
//            dfs(heights, i, m - 1, atlantic);
//        }
//        for (int j = 0; j < m; j++)
//        {
//            dfs(heights, n - 1, j, atlantic);
//        }
//
//        vector<vector<int>> ret;
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < m; j++)
//            {
//                if (pacific[i][j] == atlantic[i][j] && pacific[i][j] == true)
//                {
//                    ret.push_back({ i,j });
//                }
//            }
//        }
//
//        return ret;
//    }
//
//    int dx[4] = { 0,0,1,-1 };
//    int dy[4] = { 1,-1,0,0 };
//    void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& ocean)
//    {
//        ocean[i][j] = true;
//        for (int k = 0; k < 4; k++)
//        {
//            int x = dx[k] + i;
//            int y = dy[k] + j;
//            if (x >= 0 && x < n && y >= 0 && y < m && !ocean[x][y] && heights[x][y] >= heights[i][j])
//            {
//                dfs(heights, x, y, ocean);
//            }
//        }
//    }
//};


// https://leetcode.cn/problems/minesweeper/description/
//class Solution {
//public:
//    int n, m;
//    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click)
//    {
//        n = board.size(), m = board[0].size();
//        int x = click[0], y = click[1];
//        if (board[x][y] == 'M')
//        {
//            board[x][y] = 'X';
//            return board;
//        }
//        dfs(board, x, y);
//        return board;
//    }
//
//    int dx[8] = { 0,0,1,-1,-1,-1,1,1 };
//    int dy[8] = { 1,-1,0,0,1,-1,-1,1 };
//    void dfs(vector<vector<char>>& board, int i, int j)
//    {
//        // 统计地雷个数
//        int count = 0;
//        for (int k = 0; k < 8; k++)
//        {
//            int x = dx[k] + i, y = dy[k] + j;
//            if (x >= 0 && x < n && y >= 0 && y < m && board[x][y] == 'M')
//            {
//                count++;
//            }
//        }
//        // 如果周围没有地雷
//        if (!count)
//        {
//            board[i][j] = 'B';
//            for (int k = 0; k < 8; k++)
//            {
//                int x = dx[k] + i, y = dy[k] + j;
//                if (x >= 0 && x < n && y >= 0 && y < m && board[x][y] == 'E')
//                {
//                    dfs(board, x, y);
//                }
//            }
//        }
//        else
//        {
//            board[i][j] = count + '0';
//            return;
//        }
//
//    }
//};


// https://leetcode.cn/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/description/
//class Solution {
//public:
//    int ret = 0;
//    bool visit[100][100];
//    int wardrobeFinishing(int m, int n, int cnt)
//    {
//        dfs(0, 0, m, n, cnt);
//        return ret;
//    }
//
//    int dx[4] = { 0,0,1,-1 };
//    int dy[4] = { 1,-1,0,0 };
//    void dfs(int i, int j, int m, int n, int cnt)
//    {
//        visit[i][j] = true;
//        int tmpi = i, tmpj = j, sum = 0;
//        while (tmpi)
//        {
//            sum += tmpi % 10;
//            tmpi /= 10;
//        }
//        while (tmpj)
//        {
//            sum += tmpj % 10;
//            tmpj /= 10;
//        }
//        if (sum > cnt)
//            return;
//        ret++;
//        for (int k = 0; k < 4; k++)
//        {
//            int x = i + dx[k], y = j + dy[k];
//            if (x >= 0 && x < m && y >= 0 && y < n && !visit[x][y])
//            {
//                dfs(x, y, m, n, cnt);
//            }
//        }
//    }
//};


// 记忆化搜索
// 将递归可能重复出现的结果放入备忘录中，即带备忘录的递归搜索
// 1、先添加备忘录
// 2、每次递归返回时，将结果放入备忘录里
// 3、每次进入递归时，先查看备忘录
//
// 记忆化搜索与普通动态规划本质是一样的：
// 1、暴力搜索
// 2、通过将计算过的值存起来进行优化
// 只是一个是递归形式另一个是递推
//
// 问题：
// 1、不是所有的递归（深搜、爆搜）都能改成记忆化搜索的
//    
 
// https://leetcode.cn/problems/fibonacci-number/description/
//class Solution {
//public:
//    // 创建备忘录
//    int memory[31];
//    int fib(int n)
//    {
//        // 初始化
//        memset(memory, -1, sizeof(memory));
//        return dfs(n);
//    }
//
//    int dfs(int n)
//    {
//        // 查找备忘录
//        if (memory[n] != -1)
//            return memory[n];
//
//        // 将结果放入备忘录
//        // 递归出口
//        if (n == 1 || n == 0)
//        {
//            memory[n] = n;
//            return n;
//        }
//        memory[n] = dfs(n - 1) + dfs(n - 2);
//        return memory[n];
//    }
//};