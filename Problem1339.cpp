/*
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
*/

#include <iostream>
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
    long long best = 0;
    int MOD = 1e9 + 7;
    int totalSum = 0;

    int sumOfSubTree(TreeNode *root)
    {
        if (!root)
            return 0;
        return root->val + sumOfSubTree(root->left) + sumOfSubTree(root->right);
    }

    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;

        int lsum = dfs(root->left);
        int rsum = dfs(root->right);

        int currSum = root->val + lsum + rsum;

        long long currProd = 1LL * currSum * (totalSum - currSum);
        best = max(currProd, best);
        return currSum;
    }

    int maxProduct(TreeNode *root)
    {
        totalSum = sumOfSubTree(root);
        dfs(root);
        return best % MOD;
    }
};

int main()
{

    return 0;
}