
/*
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include<stdio.h>
#include<stdlib.h>

struct ListNode* middleNode(struct ListNode* head) 
{
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while(fast != NULL && fast->next != NULL)   
    {
        fast = fast->next;
        if(fast != NULL)
        {
            fast = fast -> next;
        }
        slow = slow->next;
    }

    return slow;
}

int main()
{
    return 0;
}