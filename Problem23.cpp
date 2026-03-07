/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.
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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
        {
            return NULL;
        }

        int n = lists.size();

        while (n > 1)
        {
            for (int i = 0; i < n / 2; i++)
            {
                lists[i] = mergeTwoLists(lists[i], lists[n - i - 1]);
            }

            n = (n + 1) / 2;
        }

        return lists[0];
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (!l1)
            return l2;

        if (!l2)
            return l1;

        ListNode dummy(0);

        ListNode *tail = &dummy;

        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
            }

            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;

        return dummy.next;
    }
};

int main()
{
    Solution s;

    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ListNode *l3 = new ListNode(2);
    l3->next = new ListNode(6);

    vector<ListNode *> lists = {l1, l2, l3};

    ListNode *mergedHead = s.mergeKLists(lists);

    // Print the merged linked list
    while (mergedHead)
    {
        cout << mergedHead->val << " ";
        mergedHead = mergedHead->next;
    }
    cout << endl;

    return 0;
}