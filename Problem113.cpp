/*
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.
*/
#include<bits/stdc++.h>
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
    vector<vector<int>> result;

    void dfs(TreeNode *root, int targetSum, int currSum, vector<int> &path)
    {

        if (!root)
            return;

        currSum += root->val;
        path.push_back(root->val);
        cout << path.back() << endl;

        if (!root->left && !root->right && currSum == targetSum)
        {
            result.push_back(path);
        }

        dfs(root->left, targetSum, currSum, path);
        dfs(root->right, targetSum, currSum, path);

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<int> path;
        dfs(root, targetSum, 0, path);

        return result;
    }
};

int main()
{

    return 0;
}