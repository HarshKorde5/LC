/*
Given a binary tree

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
            Node *prev = nullptr;

            for (int i = 0; i < size; i++)
            {
                Node *curr = q.front();
                q.pop();

                if (prev)
                {
                    prev->next = curr;
                }

                prev = curr;

                if (curr->left)
                {
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    q.push(curr->right);
                }
            }
        }

        return root;
    }
    Node *connect_1(Node *root)
    {
        if (!root)
            return root;

        Node *curr = root;
        Node *nextDummy = new Node(0);
        Node *prev = nextDummy;

        while (curr)
        {
            if (curr->left)
            {
                prev->next = curr->left;
                prev = prev->next;
            }

            if (curr->right)
            {
                prev->next = curr->right;
                prev = prev->next;
            }

            if (curr->next)
            {
                curr = curr->next;
            }
            else
            {
                curr = nextDummy->next;
                nextDummy->next = NULL;
                prev = nextDummy;
            }
        }

        return root;
    }
};

int main()
{

    return 0;
}