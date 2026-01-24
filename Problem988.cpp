/*
You are given the root of a binary tree where each node has a value in the range [0, 25] representing the letters 'a' to 'z'.

Return the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

As a reminder, any shorter prefix of a string is lexicographically smaller.

For example, "ab" is lexicographically smaller than "aba".
A leaf of a node is a node that has no children.
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
    void dfs(TreeNode *root, string &ans, string curr)
    {
        if (!root)
            return;

        curr = (char)(root->val + 'a') + curr;

        if (!root->left && !root->right)
        {
            if (ans == "" || curr < ans)
            {
                ans = curr;
            }
        }

        dfs(root->left, ans, curr);
        dfs(root->right, ans, curr);
    }
    string smallestFromLeaf(TreeNode *root)
    {
        string ans = "";
        dfs(root, ans, "");
        return ans;
    }
};

int main()
{

    return 0;
}