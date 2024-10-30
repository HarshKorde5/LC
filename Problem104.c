/*
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode* root) {
    int left=0,right=0,height=0;
    if(root==NULL)
    {
        return height;
    }
    left=maxDepth(root->left);
    right=maxDepth(root->right);
    if(left>right)
    {
        height=left+1;
    }
    else
    {
        height=right+1;
    }
    return height;
}

int main()
{
    return 0;
}