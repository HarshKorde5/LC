/*
Given the root of an n-ary tree, return the preorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
private:
    void travel(Node *root, vector<int> &result)
    {
        if (root == nullptr)
        {
            return;
        }

        result.push_back(root->val);
        for (Node *child : root->children)
        {
            travel(child, result);
        }
    }

public:
    vector<int> preorder(Node *root)
    {
        vector<int> result;
        travel(root, result);
        return result;
    }
};

int main()
{
    return 0;
}