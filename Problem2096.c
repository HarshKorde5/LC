/*
You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.

Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:

'L' means to go from a node to its left child node.
'R' means to go from a node to its right child node.
'U' means to go from a node to its parent node.
Return the step-by-step directions of the shortest path from node s to node t.
*/

#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
char    *find(struct TreeNode* root, char *str, int pos, int val)
{
    if (!root)
        return (NULL);
    if (root->val == val)
    {
        str[pos] = 0;
        return (str);
    }
    char *s = NULL;
    str[pos] = 'L';
    s = find(root->left, str, pos + 1, val);
    if (!s)
    {
        str[pos] = 'R';
        s = find(root->right, str, pos + 1, val);
    }
    return (s);
}

char* getDirections(struct TreeNode* root, int startValue, int destValue) {
    char s1[100001], s2[100001];
    int i = 0, j = 0, k = 0, len;
    char *res;
    
    find(root, &s1[0], 0, startValue);
    find(root, &s2[0], 0, destValue);
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    len = strlen(&s1[i]) + strlen(&s2[i]) + 1;
    res = malloc(len);
    while (s1[i + j])
        res[j++] = 'U';
    while (s2[i + k])
    {
        res[j + k] = s2[i + k];
        k++;
    }
    res[j + k] = 0;
    return (res);
}

int main()
{
    return 0;
}