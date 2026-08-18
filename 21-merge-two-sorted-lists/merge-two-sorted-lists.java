/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {
    public ListNode mergeTwoLists(ListNode A, ListNode B) {
        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;

        while(A != null && B != null){
            if(A.val < B.val){
                curr.next = A;
                A = A.next;
            }else{
                curr.next = B;
                B = B.next;
            }

            curr = curr.next;
        }

        if(A != null)   curr.next = A;
        else    curr.next = B;

        return dummy.next;
    }
}