#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution
{
public:
    bool isUnivalTree(TreeNode *root, int val = -1)
    {
        if (!root)
            return true;
        if (val < 0)
            val = root->val;
        return root->val == val && isUnivalTree(root->left, val) &&
               isUnivalTree(root->right, val);
    }
    bool isUnivalTree_1(TreeNode *root)
    {
        if (!root)
            return true;

        if (root->left && root->val != root->left->val)
            return false;
        if (root->right && root->val != root->right->val)
            return false;

        return isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};

int main()
{
    return 0;
}