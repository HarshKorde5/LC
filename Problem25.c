/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

Example : 1->2->3->4->5->6->7 and k = 3
Result : 3->2->1->6->5->4->7
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *reverseLinkedList(struct ListNode *start,
                                   struct ListNode *end)
{
    struct ListNode *stop = end->next;
    struct ListNode *curr = start;
    struct ListNode *prev = end->next;

    while (curr != stop)
    {
        struct ListNode *next_node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_node;
    }
    return prev;
}

struct ListNode *reverseKGroup(struct ListNode *head, int k)
{
    if (!head || k == 1)
    {
        return head;
    }

    struct ListNode dummy;
    dummy.next = head;

    struct ListNode *prevGroup = &dummy;
    struct ListNode *start = head;
    struct ListNode *end = head;

    while (start != NULL)
    {

        end = start;
        for (int i = 1; i < k && end; i++)
        {
            end = end->next;
        }

        if (!end)
            break;

        struct ListNode *nextGroup = end->next;
        struct ListNode *reversedGroup = reverseLinkedList(start, end);

        prevGroup->next = reversedGroup;
        prevGroup = start;
        start = nextGroup;
    }

    return dummy.next;
}

int main()
{
    return 0;
}