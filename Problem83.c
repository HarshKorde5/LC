/*
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
*/



struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head)
{
    struct ListNode* curr = head;
    struct ListNode* temp = NULL;
    while(curr != NULL)
    {
        if(curr->next == NULL)
        {
            break;
        }
        if(curr->val == curr->next->val)
        {
            temp = curr->next->next;
            free(curr->next);
            curr->next=temp;
        }
        else
        {
            curr=curr->next;
        }
    }
    return head;
}

int main()
{

    
    return 0;
}