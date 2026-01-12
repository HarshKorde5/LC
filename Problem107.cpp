/*
Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void dfs(TreeNode *root, vector<vector<int>> &result, int level)
    {
        if (!root)
            return;

        if (result.size() == level)
        {
            result.push_back({});
        }

        result[level].push_back(root->val);

        dfs(root->left, result, level + 1);
        dfs(root->right, result, level + 1);
    }

    vector<vector<int>> levelOrderBottom_dfs(TreeNode *root)
    {
        vector<vector<int>> result;
        dfs(root, result, 0);

        reverse(result.begin(), result.end());
        return result;
    }

    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> result;
        if (!root)
            return result;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                level.push_back(node->val);

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            result.push_back(level);
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
    return 0;
}