/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
*/


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool solve(struct TreeNode* root1,struct TreeNode* root2)
{
    if((root1 == NULL)&&(root2 == NULL))
    {
        return true;
    }
    if((root1 == NULL)||(root2 == NULL))
    {
        return false;
    }
    if(root1->val != root2->val)
    {
        return false;
    }

    bool leftRightMatch = solve(root1->left,root2->right);
    bool rightLeftMatch = solve(root1->right,root2->left);
    return(leftRightMatch && rightLeftMatch);
}
bool isSymmetric(struct TreeNode* root)
{
    return solve(root->left,root->right);
    
}

int main()
{
    return 0;
}