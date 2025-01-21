/**
Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* root , vector<string>&ans , string &str){
        if(root==NULL) return ;
        str = str + to_string(root->val) ;
        if(root->right == NULL && root->left == NULL){
            ans.push_back(str);
            return;
        }
        str = str + "-" + ">" ;
        string str2 = str ;
        helper(root->left,ans,str);
        helper(root->right,ans,str2);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans(0) ;
        string str ;
        helper(root,ans,str);
        return ans ;
    }
};

int main(){

    return 0;
}