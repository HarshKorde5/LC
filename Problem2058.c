/*
A critical point in a linked list is defined as either a local maxima or a local minima.

A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.

A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.

Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.

Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].


*/

struct ListNode {
    int val;
    struct ListNode *next;
};
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize)
{
    *returnSize = 2;

    int *ret = (int*)malloc(sizeof(int)*2);
    ret[0] = -1;
    ret[1] = -1;

    struct ListNode* temp = head;

    if(head == NULL)
    {
        return ret;
    }
    else if(head->next->next == NULL)
    {
        return ret;
    }
    else
    {
        ret[0] = INT_MAX;
        int a = 0,b = 0,index = 1,i = 0;

        while(temp->next->next != NULL)
        {
            if((((temp->val) < (temp->next->val))&&((temp->next->val) > (temp->next->next->val)))||(((temp->val) > (temp->next->val))&&((temp->next->val) < (temp->next->next->val))))
            {
                if(ret[1] == -1)
                {
                    a = index;
                    b = index;
                    ret[1] = index - a;
                }
                else
                {
                    ret[1] = index - a;
                    if(ret[0] > index - b)
                    {
                        ret[0] = index - b;
                    }
                    b = index;
                }
                i++;
            }
            index++;
            temp = temp->next;
        }

        if(i < 2)
        {
            ret[0] = -1;
            ret[1] = -1;
        }
    }

    
    return ret;
}

int main()
{
    return 0;
}