/*
21. Merge Two Sorted Lists

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
*/


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    
    if((list1 == NULL)&&(list2 == NULL))      //if both ll are empty
        return list1;
    else if((list1 == NULL)&&(list2 != NULL))     //if l1 is empty
        return list2;
    else if((list1 != NULL)&&(list2 == NULL))     //if l2 is empty
        return list1;
    else
    {
        if (list1->val <= list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
    
}

void Insert(struct ListNode **Head,int iNo)
{
    struct ListNode* temp = *Head;
    struct ListNode* newn = NULL;

    newn = (struct ListNode*)malloc(sizeof(struct ListNode));
    newn->val = iNo;
    newn->next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    
}

void Display(struct ListNode *head)
{
    
    while(head != NULL)
    {
        printf("%d\t",head->val);
        head = head->next;
    }
    printf("\n");
}

int main()
{ 
    struct ListNode* first1 = NULL;
    struct ListNode* first2 = NULL;
    struct ListNode *ret = NULL;

    Insert(&first1,2);
    Insert(&first1,2);
    Insert(&first1,4);
    Display(first1);
    Insert(&first2,1);
    Insert(&first2,3);
    Insert(&first2,4);
    Display(first2);

    ret = mergeTwoLists(first1,first2);
    Display(ret);

    return 0;
}