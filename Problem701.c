/*
You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.
*/
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *insertIntoBST_recurrsion(struct TreeNode *root, int val)
{
    if (!root)
    {
        struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        node->val = val;
        node->left = NULL;
        node->right = NULL;
        return node;
    }

    if (root->val < val)
    {
        root->right = insertIntoBST(root->right, val);
    }
    else
    {
        root->left = insertIntoBST(root->left, val);
    }

    return root;
}
struct TreeNode *insertIntoBST(struct TreeNode *root, int val)
{
    struct TreeNode *newnode =
        (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->val = val;

    if (!root)
        return newnode;

    struct TreeNode *curr = root;

    while (1)
    {
        if (curr->val < val)
        {
            if (curr->right)
            {
                curr = curr->right;
            }
            else
            {
                curr->right = newnode;
                break;
            }
        }
        else
        {
            if (curr->left)
            {
                curr = curr->left;
            }
            else
            {
                curr->left = newnode;
                break;
            }
        }
    }

    return root;
}

int main()
{

    return 0;
}