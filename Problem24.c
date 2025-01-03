/*
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
*/
#include<stdio.h>
#include<stdlib.h>


typedef struct ListNode {
    int val;
    struct ListNode *next;
}NODE,*PNODE,**PPNODE;

struct ListNode* swapPairs(struct ListNode* head) {

    if(head == NULL || head -> next == NULL){
        return head;
    }

    PNODE dummy = (PNODE)malloc(sizeof(NODE));

    PNODE prev = dummy;
    PNODE curr = head;

    while(curr != NULL && curr->next != NULL){
        prev->next = curr->next;
        curr->next = prev->next->next;
        prev->next->next = curr;

        prev = curr;
        curr = curr->next;
    }

    return dummy->next;
}

int main()
{
    
    return 0;
}