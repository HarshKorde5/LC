/*
Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
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

class Solution
{
public:
    void gst_1(TreeNode *root, int &sum)
    {
        if (root->right)
        {
            gst_1(root->right, sum);
        }

        int currSum = sum + root->val;
        sum = currSum;
        root->val = currSum;

        if (root->left)
        {
            gst_1(root->left, sum);
        }
    }

    void gst(TreeNode *root, int &sum)
    {
        if (!root)
            return;

        gst(root->right, sum);
        sum += root->val;
        root->val = sum;
        gst(root->left, sum);
    }

    TreeNode *bstToGst(TreeNode *root)
    {

        int sum = 0;
        gst(root, sum);

        return root;
    }
};

int main()
{

    return 0;
}