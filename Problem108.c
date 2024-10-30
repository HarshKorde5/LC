/*
Given an integer array nums where the elements are sorted in ascending order, convert it to a 
height-balanced binary search tree.
*/

#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *sortedArrayToBST(int *nums, int numsSize)
{
    if (numsSize == 0)
    {
        return NULL;
    }
    int midIndex = numsSize >> 1;
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = nums[midIndex];
    node->left = sortedArrayToBST(&nums[0], midIndex);
    node->right = sortedArrayToBST(&nums[midIndex + 1], numsSize - midIndex - 1);
    return node;
}

int main()
{
    
    return 0;
}