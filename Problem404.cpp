/*
Given the root of a binary tree, return the sum of all left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.
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
    int sumOfLeftLeaves(TreeNode *root, bool f = false)
    {
        if (!root)
            return 0;

        if (!root->left && !root->right && f)
        {
            return root->val;
        }

        int l = sumOfLeftLeaves(root->left, true);
        int r = sumOfLeftLeaves(root->right, false);

        return l + r;
    }
};

int main()
{

    return 0;
}