/*
Given the root of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest. You may return the result in any order.
*/


#include<stdio.h>
#include<stdlib.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


bool toDelete(int val, int* to_delete, int to_deleteSize) {
    for (int i = 0; i < to_deleteSize; i++) {
        if (to_delete[i] == val) {
            return true;
        }
    }
    return false;
}

struct TreeNode* helper(struct TreeNode* root, int* to_delete, int to_deleteSize, struct TreeNode*** forest, int* forestSize) {
    if (!root) return NULL;
    
    root->left = helper(root->left, to_delete, to_deleteSize, forest, forestSize);
    root->right = helper(root->right, to_delete, to_deleteSize, forest, forestSize);
    
    if (toDelete(root->val, to_delete, to_deleteSize)) {
        if (root->left) {
            (*forest)[*forestSize] = root->left;
            (*forestSize)++;
        }
        if (root->right) {
            (*forest)[*forestSize] = root->right;
            (*forestSize)++;
        }
        free(root);
        return NULL;
    }
    
    return root;
}

struct TreeNode** delNodes(struct TreeNode* root, int* to_delete, int to_deleteSize, int* returnSize) {
    *returnSize = 0;
    struct TreeNode** forest = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 1000);
    
    root = helper(root, to_delete, to_deleteSize, &forest, returnSize);
    
    if (root) {
        forest[*returnSize] = root;
        (*returnSize)++;
    }
    
    return forest;
}