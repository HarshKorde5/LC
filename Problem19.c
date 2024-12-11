
/*

Given the head of a linked list, remove the nth node from the end of the list and return its head.

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

//Count and delete approach
struct ListNode* removeNthFromEnd1(struct ListNode* head, int n) 
{
    if(head->next == NULL)    return NULL;

    int count = 0;
    struct ListNode* temp = head;

    while(temp != NULL)
    {
        count++;
        temp = temp -> next;
    }

    if(count - n - 1 == -1)
    {
        return head->next;
    }

    temp = head;

    for(int i = 0;i < count-n-1;i++)
    {
        temp = temp->next;
    }   

    struct ListNode* tempX = temp->next;

    temp->next = temp->next->next;

    free(tempX);

    return head;
}

//two pointers approach
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) 
{
    struct ListNode* slow = head;
    struct ListNode* fast = head;


    for(int i = 1;i <= n;i++)
    {
        fast = fast->next;
    }

    if(fast == NULL)
    {
        return head->next;
    }

    while(fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = slow->next->next;

    return head;
}


int main()
{
    return 0;
}