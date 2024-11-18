

/*

Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
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


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        
        ListNode* List = new ListNode(0);
        List->next = head;
        ListNode* prev = List;
        ListNode* curr = head;


        while(curr != NULL)
        {
            if(curr->val != val)
            {
                prev = curr;
            }
            else
            {
                prev->next = curr->next;
            }
            
            curr = curr->next;

        }


        return List->next;
    }
};

int main()
{


    return 0;
}