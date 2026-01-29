// Given the root of a binary tree, invert the tree, and return its root.

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
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return root;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            TreeNode *left = node->left;
            node->left = node->right;
            node->right = left;

            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }

        return root;
    }
    TreeNode *invertTree_1(TreeNode *root)
    {
        if (!root)
            return root;

        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

int main()
{

    return 0;
}