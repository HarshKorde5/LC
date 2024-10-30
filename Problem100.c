/*
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

*/


#include<stdio.h>
#include<stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if((p == NULL)&&(q == NULL))
    {
        return true;
    }
    if((p==NULL && q != NULL)||(p != NULL && q == NULL))
    {
        return false;
    }

    if(p->val == q->val)
    {
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
    return false;
}

int main()
{
    return 0;
}