/*
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node
{
    int val;
    struct Node *next;
    struct Node *random;
};

struct Node *createNode(int val, struct Node *next)
{
    struct Node *new_node = NULL;
    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->next = next;
    new_node->val = val;
    return new_node;
}

struct Node *copyRandomList(struct Node *head)
{

    if (!head)
        return NULL;
    struct Node *temp = head;

    // insert new nodes in between old ones
    while (temp != NULL)
    {
        struct Node *new_node = createNode(temp->val, temp->next);
        temp->next = new_node;

        temp = new_node->next;
    }

    // copy random pointers
    temp = head;
    while (temp != NULL)
    {
        if (temp->random != NULL)
        {
            temp->next->random = temp->random->next;
        }
        else
        {
            temp->next->random = NULL;
        }
        temp = temp->next->next;
    }

    // remove the link between new->old and create new->new, old->old

    struct Node *newHead = head->next;
    struct Node *new = newHead;
    struct Node *old = head;

    while (old != NULL)
    {
        old->next = new->next;
        old = old->next;

        if (old != NULL)
        {
            new->next = old->next;
            new = new->next;
        }
    }

    return newHead;
}

int main()
{

    return 0;
}