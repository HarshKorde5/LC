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
    int dfs(TreeNode *root, int &maxPath)
    {
        if (!root)
            return 0;

        int left = max(0, dfs(root->left, maxPath));
        int right = max(0, dfs(root->right, maxPath));

        maxPath = max(maxPath, left + right + root->val);

        return max(left, right) + root->val;
    }
    int maxPathSum(TreeNode *root)
    {
        int maxPath = INT_MIN;
        dfs(root, maxPath);
        return maxPath;
    }
};

int main()
{

    return 0;
}