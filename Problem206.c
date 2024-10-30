
//Given the head of a singly linked list, reverse the list, and return the reversed list.


#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}NODE,*PNODE,**PPNODE;

PNODE reverseLL(PNODE head)
{
    PNODE temp = head;
    PNODE prev = NULL;
    PNDOE nextNode = NULL;

    while(temp != NULL)
    {
        nextNode = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nextNode;
    }

    return head;
}

int main()
{

    return 0;
}