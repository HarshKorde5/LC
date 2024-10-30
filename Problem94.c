/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.

*/


struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int i = 0;
int arr[100] = {0};

void Inorder(struct TreeNode* root)
{
    if(root != NULL)
    {
        Inorder(root->left);
        arr[i++] = root->val;
        Inorder(root->right);
    }
}
int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    Inorder(root);
    int * ret = malloc(sizeof(int)*i);
    for(int j = 0;j < i;j++)
    {
        ret[j] = arr[j];
    }
    *returnSize = i;
    i = 0;  //for multiple test cases its needed
    return ret;
}

int main()
{
    return 0;
}