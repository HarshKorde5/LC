/*
You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.
*/

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
    void dfs(TreeNode *root, int &sum, int curr)
    {
        if (!root)
            return;

        curr = (curr * 10) + root->val;
        if (!root->left && !root->right)
        {
            sum += curr;
        }

        dfs(root->left, sum, curr);
        dfs(root->right, sum, curr);
    }
    int sumNumbers(TreeNode *root)
    {
        int sum = 0;
        dfs(root, sum, 0);

        return sum;
    }
};

int main()
{

    return 0;
}