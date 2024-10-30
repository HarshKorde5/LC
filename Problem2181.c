/*
You are given the head of a linked list, which contains a series of integers separated by 0's. The beginning and end of the linked list will have Node.val == 0.

For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes. The modified list should not contain any 0's.

Return the head of the modified linked list.
*/


#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};


struct ListNode* mergeNodes(struct ListNode* head)
{
    if(head == NULL)
    {
        head = (struct ListNode*)malloc(sizeof(struct ListNode));
        head->val = 0;
        head->next = NULL;
        return head;
    }

    struct ListNode* sum_ptr = head;
    struct ListNode* traverse_ptr = head->next;;
    int sum = 0;

    while(traverse_ptr->next != NULL)
    {
        if(traverse_ptr->val == 0)
        {
            sum_ptr->val = sum;
            sum_ptr = sum_ptr->next;
            sum = 0;
        }
        else
        {
            sum = sum + traverse_ptr->val;
        }

        traverse_ptr = traverse_ptr->next;
    }

    sum_ptr->val = sum;
    sum_ptr->next = NULL;
    
    return head;
}


int main()
{
    

    return 0;
}