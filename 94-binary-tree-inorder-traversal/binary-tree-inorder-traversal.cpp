/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    vector<int> res;

public:
    vector<int> inorderTraversal_rec(TreeNode* root) {
        inorder(root);
        return res;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stack;
        TreeNode* curr = root;
        vector<int> res;

        while (curr || !stack.empty()) {
            while (curr) {
                stack.push(curr);
                curr = curr->left;
            }

            curr = stack.top();
            stack.pop();
            res.push_back(curr->val);
            curr = curr->right;
        }

        return res;
    }

private:
    void inorder(TreeNode* node) {
        if (!node) {
            return;
        }
        inorder(node->left);
        res.push_back(node->val);
        inorder(node->right);
    }
};