/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int targetSum) {
    if(!root)   return false;

    targetSum -= root->val;

    return (targetSum == 0 && !root->left && !root->right) || hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
}