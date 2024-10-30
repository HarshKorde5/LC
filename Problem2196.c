/*
You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,

If isLefti == 1, then childi is the left child of parenti.
If isLefti == 0, then childi is the right child of parenti.
Construct the binary tree described by descriptions and return its root.

The test cases will be generated such that the binary tree is valid.


*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool check_stack(struct TreeNode* stack[],int top,int no)
{
    bool flag = false;
    while(top != -1)
    {
        if(stack[top]->val == no)
        {
            flag = true;
            break;
        }
        top--;
    }
    return false;
}

struct TreeNode* createBinaryTree(int** descriptions, int descriptionsSize, int* descriptionsColSize)
{
    struct TreeNode* stack[descriptionsSize];
    int top = -1;
    bool child_flag = false;
    struct TreeNode* root = NULL;

    for(int i = 0;i < descriptionsSize;i++)
    {
        check_stack(stack,top,descriptions[i][0])
        
    }
}