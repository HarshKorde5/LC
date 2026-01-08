/*
Given the root of a binary tree, return the leftmost value in the last row of the tree.
*/
#include <iostream>
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
    void helper(TreeNode *root, int &leftMost, int &height, int level)
    {
        if (!root)
            return;

        if (height == level)
        {
            leftMost = root->val;
            height++;
        }

        helper(root->left, leftMost, height, level + 1);
        helper(root->right, leftMost, height, level + 1);
    }

    int findBottomLeftValue(TreeNode *root)
    {
        int leftMost = 0;
        int height = 0;
        helper(root, leftMost, height, 0);
        return leftMost;
    }

    int findBottomLeftValue_1(TreeNode *root)
    {
        int ans = root->val;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            ans = q.front()->val;
            for (int i = 0; i < size; i++)
            {

                TreeNode *node = q.front();
                q.pop();

                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
        }

        return ans;
    }
};

int main()
{
    return 0;
}