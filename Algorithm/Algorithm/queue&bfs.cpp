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