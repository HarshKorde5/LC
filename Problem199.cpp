/*
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
*/

#include<bits/stdc++.h>
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
    void dfs(TreeNode *root, vector<int> &res, int level)
    {
        if (!root)
            return;

        if (level == res.size())
        {
            res.push_back(root->val);
        }

        dfs(root->right, res, level + 1);
        dfs(root->left, res, level + 1);
    }

    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        int level = 0;
        dfs(root, res, level);

        return res;
    }
    vector<int> rightSideView_1(TreeNode *root)
    {
        vector<int> res;
        if (!root)
            return res;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {

            res.push_back(q.back()->val);
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }

        return res;
    }
};

int main()
{

    return 0;
}