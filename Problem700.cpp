/*
You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.
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
    TreeNode *dfs(TreeNode *root, int val)
    {
        if (!root)
            return NULL;

        if (root->val == val)
        {
            return root;
        }

        if (val > root->val)
        {
            return dfs(root->right, val);
        }

        return dfs(root->left, val);
    }

    TreeNode *searchBST(TreeNode *root, int val)
    {
        return dfs(root, val);
    }

    TreeNode *searchBST_1(TreeNode *root, int val)
    {
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                if (node->val == val)
                {
                    return node;
                }

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }

        return NULL;
    }
};

int main()
{
    return 0;
}