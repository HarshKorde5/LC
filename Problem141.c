/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle1(struct ListNode *head)
{
    while(head)
    {
        if(head->val == '!@#')
        {
            return true;
        }
        head->val = '!@#';
        head = head->next;
    }
    return false;
}

//SlowFast approach
bool hasCycle2(struct ListNode *head)
{
    bool flag = false;

    if(head == NULL || head->next == NULL)
    {
        return false;
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while(slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if(fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if(slow == fast)
        {
            flag = true;
            break;
        }
    }

    return flag;
}

int main()
{
    return 0;
}