/*
Given the root of a binary tree, return the most frequent subtree sum. If there is a tie, return all the values with the highest frequency in any order.

The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself).
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
    int sumOfSubtree(TreeNode *root, unordered_map<int, int> &sumFreq,
                     int &maxFreq)
    {
        if (root == NULL)
            return 0;

        int lsum = sumOfSubtree(root->left, sumFreq, maxFreq);
        int rsum = sumOfSubtree(root->right, sumFreq, maxFreq);

        int sum = root->val + lsum + rsum;

        sumFreq[sum]++;
        maxFreq = max(maxFreq, sumFreq[sum]);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode *root)
    {
        unordered_map<int, int> sumFreq;
        int maxFreq = 0;
        sumOfSubtree(root, sumFreq, maxFreq);

        vector<int> result;
        for (auto &it : sumFreq)
        {
            if (it.second == maxFreq)
            {
                result.push_back(it.first);
            }
        }

        return result;
    }
};

int main()
{
    return 0;
}