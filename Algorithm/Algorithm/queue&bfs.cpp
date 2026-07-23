#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<unordered_map>
#include<algorithm>
using namespace std;


// https://leetcode.cn/problems/n-ary-tree-level-order-traversal/description/
//class Solution {
//public:
//    vector<vector<int>> levelOrder(Node* root)
//    {
//        vector<vector<int>> ret;
//        if (!root)
//            return ret;
//        queue<Node*> q;
//        q.push(root);
//        while (!q.empty())
//        {
//            int sz = q.size();
//            vector<int> tmp;
//            for (int i = 0; i < sz; i++)
//            {
//
//                Node* front = q.front();
//                q.pop();
//                tmp.push_back(front->val);
//                for (Node* child : front->children)
//                {
//                    if (child)
//                        q.push(child);
//                }
//            }
//            ret.push_back(tmp);
//        }
//
//        return ret;
//    }
//};


// https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/description/
//class Solution {
//public:
//    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
//    {
//        vector<vector<int>> ret;
//        if (!root)
//            return ret;
//        queue<TreeNode*> q;
//        q.push(root);
//        bool flag = 0;
//        while (!q.empty())
//        {
//            int sz = q.size();
//            vector<int> tmp;
//            for (int i = 0; i < sz; i++)
//            {
//                TreeNode* front = q.front();
//                tmp.push_back(front->val);
//                q.pop();
//                if (front->left)
//                    q.push(front->left);
//                if (front->right)
//                    q.push(front->right);
//            }
//            if (flag)
//            {
//                reverse(tmp.begin(), tmp.end());
//            }
//            flag = !flag;
//            ret.push_back(tmp);
//        }
//        return ret;
//    }
//};


// https://leetcode.cn/problems/maximum-width-of-binary-tree/description/
//class Solution {
//public:
//    int widthOfBinaryTree(TreeNode* root) {
//        if (!root) return 0;
//        vector<std::pair<TreeNode*, unsigned int>> heap;
//        heap.push_back({ root,1 });
//        unsigned int ret = 0;
//        while (!heap.empty())
//        {
//            auto& [x1, y1] = heap[0];
//            auto& [x2, y2] = heap.back();
//            ret = max(ret, y2 - y1 + 1);
//
//            vector<std::pair<TreeNode*, unsigned int>> tmp;
//            for (auto& [x, y] : heap)
//            {
//                if (x->left)
//                    tmp.push_back({ x->left,2 * y });
//                if (x->right)
//                    tmp.push_back({ x->right,2 * y + 1 });
//            }
//            heap = tmp;
//        }
//        return ret;
//    }
//};


// https://leetcode.cn/problems/find-largest-value-in-each-tree-row/description/
//class Solution {
//public:
//    vector<int> largestValues(TreeNode* root) {
//        vector<int> ret;
//        if (!root)   return ret;
//        queue<TreeNode*> q;
//        q.push(root);
//        while (!q.empty())
//        {
//            int sz = q.size();
//            int mx = INT_MIN;
//            for (int i = 0; i < sz; i++)
//            {
//                TreeNode* front = q.front();
//                q.pop();
//                mx = max(mx, front->val);
//                if (front->left)
//                    q.push(front->left);
//                if (front->right)
//                    q.push(front->right);
//            }
//            ret.push_back(mx);
//        }
//        return ret;
//    }
//};


// https://leetcode.cn/problems/flood-fill/description/
//class Solution {
//public:
//    typedef pair<int, int> PII;
//    int dx[4] = { 0,0,1,-1 };
//    int dy[4] = { 1,-1,0,0 };
//
//    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
//        if (image[sr][sc] == color)
//            return image;
//        int n = image.size(), m = image[0].size();
//        int prev = image[sr][sc];
//        queue<PII> q;
//        q.push({ sr,sc });
//
//        while (!q.empty())
//        {
//            auto [a, b] = q.front();
//            q.pop();
//            image[a][b] = color;
//
//            for (int i = 0; i < 4; i++)
//            {
//                int x = a + dx[i];
//                int y = b + dy[i];
//                if (x >= 0 && x < n && y >= 0 && y < m && image[x][y] == prev)
//                {
//                    q.push({ x,y });
//                }
//            }
//        }
//
//        return image;
//    }
//};


// https://leetcode.cn/problems/number-of-islands/description/
//class Solution {
//public:
//    typedef pair<int, int> PII;
//    int dx[4] = { 0,0,1,-1 };
//    int dy[4] = { 1,-1,0,0 };
//    int numIslands(vector<vector<char>>& grid) {
//        int n = grid.size(), m = grid[0].size();
//        bool visit[300][300] = { false };
//        int ret = 0;
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < m; j++)
//            {
//                queue<PII> q;
//                if (grid[i][j] == '1' && !visit[i][j])
//                {
//                    ret++;
//                    q.push({ i,j });
//                    visit[i][j] = true;
//                }
//                while (!q.empty())
//                {
//                    auto [a, b] = q.front();
//                    q.pop();
//
//                    for (int k = 0; k < 4; k++)
//                    {
//                        int x = a + dx[k];
//                        int y = b + dy[k];
//                        if (x >= 0 && x < n && y >= 0 && y < m && !visit[x][y] && grid[x][y] == '1')
//                        {
//                            q.push({ x,y });
//                            visit[x][y] = true;
//                        }
//                    }
//                }
//            }
//        }
//        return ret;
//    }
//};


// https://leetcode.cn/problems/max-area-of-island/description/
//class Solution {
//public:
//    typedef pair<int, int> PII;
//    int ret = 0, count = 0;
//    bool visit[55][55];
//    int dx[4] = { 0,0,1,-1 };
//    int dy[4] = { 1,-1,0,0 };
//    int n, m;
//    void bfs(vector<vector<int>>& grid, int i, int j)
//    {
//        queue<pair<int, int>> q;
//        q.push({ i, j });
//        visit[i][j] = true;
//        count++;
//        while (!q.empty())
//        {
//            auto [a, b] = q.front();
//            q.pop();
//            for (int k = 0; k < 4; k++)
//            {
//                int x = a + dx[k], y = b + dy[k];
//                if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1 &&
//                    !visit[x][y])
//                {
//                    q.push({ x, y });
//                    visit[x][y] = true;
//                    count++;
//                }
//            }
//        }
//    }
//
//    int maxAreaOfIsland(vector<vector<int>>& grid) {
//        n = grid.size(), m = grid[0].size();
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < m; j++)
//            {
//                if (grid[i][j] && !visit[i][j])
//                {
//                    count = 0;
//
//                    bfs(grid, i, j);
//                    ret = max(ret, count);
//                }
//            }
//        }
//        return ret;
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
//                bfs(board, i, 0);
//            if (board[i][m - 1] == 'O')
//                bfs(board, i, m - 1);
//        }
//
//        for (int j = 0; j < m; j++)
//        {
//            if (board[0][j] == 'O')
//                bfs(board, 0, j);
//            if (board[n - 1][j] == 'O')
//                bfs(board, n - 1, j);
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
//    void bfs(vector<vector<char>>& board, int i, int j)
//    {
//        board[i][j] = '.';
//        queue<pair<int, int>> q;
//        q.push({ i,j });
//        while (!q.empty())
//        {
//            auto [a, b] = q.front();
//            q.pop();
//            for (int k = 0; k < 4; k++)
//            {
//                int x = a + dx[k];
//                int y = b + dy[k];
//                if (x >= 0 && x < n && y >= 0 && y < m && board[x][y] == 'O')
//                {
//                    q.push({ x,y });
//                    board[x][y] = '.';
//                }
//            }
//        }
//
//    }
//};