/*
Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.
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
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> res;

        if (!root)
            return res;

        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}}); // node, col, row

        while (!q.empty())
        {

            auto p = q.front();
            q.pop();

            TreeNode *node = p.first;

            int row = p.second.second;
            int col = p.second.first;

            mp[col][row].insert(node->val);

            if (node->left)
            {
                q.push({node->left, {col - 1, row + 1}});
            }
            if (node->right)
            {
                q.push({node->right, {col + 1, row + 1}});
            }
        }

        for (auto &c : mp)
        {
            vector<int> col;

            for (auto &r : c.second)
            {
                col.insert(col.end(), r.second.begin(), r.second.end());
            }
            res.push_back(col);
        }

        return res;
    }
};

int main()
{

    return 0;
}