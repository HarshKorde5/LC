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

/*
Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level x such that the sum of all the values of nodes at level x is maximal.
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxLevelSum(TreeNode *root)
    {
        int maxSum = INT_MIN;
        int currLevel = 1;
        int maxLevel = 0;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            int currSum = 0;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                currSum += node->val;

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            if (currSum > maxSum)
            {
                maxLevel = currLevel;
                maxSum = currSum;
            }
            currLevel++;
        }

        return maxLevel;
    }
};

int main()
{

    return 0;
}