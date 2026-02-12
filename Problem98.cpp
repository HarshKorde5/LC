/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys strictly less than the node's key.
The right subtree of a node contains only nodes with keys strictly greater than the node's key.
Both the left and right subtrees must also be binary search trees.
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
    bool inorder(TreeNode *root, TreeNode *&prev)
    {
        if (!root)
            return true;

        if (!inorder(root->left, prev))
            return false;

        if (prev && prev->val >= root->val)
            return false;
        prev = root;

        return inorder(root->right, prev);
    }

    bool isValidBST_1(TreeNode *root)
    {
        TreeNode *prev = NULL;
        return inorder(root, prev);
    }

    bool isValidBST(TreeNode *root, TreeNode *minNode = NULL, TreeNode *maxNode = NULL)
    {
        if (!root)
            return true;

        if (minNode && minNode->val >= root->val || maxNode && maxNode->val <= root->val)
            return false;

        return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
    }
};

int main() { return 0; }