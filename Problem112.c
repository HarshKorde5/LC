/*
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.
*/

#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
bool hasPathSum(struct TreeNode* root, int targetSum)
{
    if (!root) 
    {
        return false;
    }
    if (!root->left && !root->right) 
    {
        return targetSum == root->val;
    }
    return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);

}

int main()
{

    return 0;
}