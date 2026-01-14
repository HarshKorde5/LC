/*
Given the head of a linked list head, in which each node contains an integer value.

Between every pair of adjacent nodes, insert a new node with a value equal to the greatest common divisor of them.

Return the linked list after insertion.

The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.
*/

#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

struct ListNode *createNode(int val)
{
    struct ListNode *newNode = NULL;
    newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->val = val;
    return newNode;
}

struct ListNode *insertGreatestCommonDivisors(struct ListNode *head)
{
    if (!head || !head->next)
        return head; // null and single element

    struct ListNode *curr = head->next;
    struct ListNode *prev = head;

    while (curr)
    {
        int g = gcd(prev->val, curr->val);
        struct ListNode *newNode = createNode(g);
        newNode->next = curr;
        prev->next = newNode;

        prev = curr;
        curr = curr->next;
    }

    return head;
}

int main()
{
    return 0;
}