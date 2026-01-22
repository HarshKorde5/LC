/*
Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).
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
    unordered_map<long long, int> mp;
    int count = 0;

    void dfs(TreeNode *root, int targetSum, long long currSum)
    {
        if (!root)
            return;

        currSum += root->val;
        if (currSum == targetSum)
        {
            count++;
        }

        if (mp.count(currSum - targetSum))
        {
            count += mp[currSum - targetSum];
        }

        mp[currSum]++;

        dfs(root->left, targetSum, currSum);
        dfs(root->right, targetSum, currSum);

        mp[currSum]--;
    }

    int pathSum(TreeNode *root, int targetSum)
    {
        dfs(root, targetSum, 0);

        return count;
    }
};
