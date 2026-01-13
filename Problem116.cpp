/*
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.
*/
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {

        if (!root)
            return root;
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {

            int size = q.size();
            Node *prev = NULL;

            for (int i = 0; i < size; i++)
            {

                Node *node = q.front();
                q.pop();

                if (prev != NULL)
                {
                    prev->next = node;
                }

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);

                prev = node;
            }
        }

        return root;
    }
};

int main()
{

    return 0;
}