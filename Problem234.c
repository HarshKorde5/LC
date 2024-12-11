/*
Given the head of a singly linked list, return true if it is a 
palindrome
 or false otherwise.
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

struct ListNode* reverse(struct ListNode* head)
{
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;

    while(curr != NULL)
    {
        struct ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

bool isPalindrome(struct ListNode* head)
{
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }


    struct ListNode* rev = reverse(slow);

    while(rev != NULL)
    {
        if(head->val != rev->val)
        {
            return false;
        }

        head = head->next;

        rev = rev->next;
    }

    return true;
}

int main()
{
    return 0;
}