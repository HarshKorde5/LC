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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode end = head;

        while(n > 0){
            end = end.next;
            n--;
        }

        System.out.println(head.val);
        ListNode dummy = new ListNode(0,head);
        ListNode start = dummy;

        while(end != null){
            end = end.next;
            start = start.next;
        }

        start.next = start.next.next;

        return dummy.next;
    }
}
