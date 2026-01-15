/*
Given the head of a linked list, rotate the list to the right by k places.
*/
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head)
            return head;

        ListNode *curr = head;
        int count = 1;

        while (curr->next)
        {
            count++;
            curr = curr->next;
        }
        ListNode *last = curr;

        k = k % count;
        curr = head;

        for (int i = 1; i < count - k; i++)
        {
            curr = curr->next;
        }

        last->next = head;
        last = curr->next;
        curr->next = nullptr;

        return last;
    }
};

int main()
{
    return 0;
}