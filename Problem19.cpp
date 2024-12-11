
/*

Given the head of a linked list, remove the nth node from the end of the list and return its head.

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


#include<iostream>
using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if(head->next == NULL && n == 1)
        {
            return NULL;
        }

        ListNode* f = head;
        ListNode* d = f;

        queue<ListNode*> q;

        int c = 1;

        while(d->next != NULL)
        {
            if(q.size() >= n)
            {
                q.pop();
            }

            q.push(d);

            d = d->next;
            c++;
        }
        

        if(c == n)
        {
            return head->next;
        }

        if(q.size() > 0)
        {
            q.front()->next = q.front()->next->next;
        }

        return f;
    }
};

int main()
{
    return 0;
}