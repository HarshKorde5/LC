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

    private void reverse(ListNode head, ListNode tail){
        ListNode prev = tail;
        while(head != tail){
            ListNode next = head.next;
            head.next = prev;
            prev = head;
            head = next;
        }
    }

    private ListNode getKthNode(ListNode head, int k){
        while(head != null && k > 0){
            head = head.next;
            k--;
        }

        return head;
    }
    
    public ListNode reverseKGroup(ListNode head, int k) {

        ListNode dummy = new ListNode(0,head);
        ListNode prevGroup = dummy;

        while(true){
            ListNode tail = getKthNode(prevGroup, k);

            if(tail == null)    break;

            ListNode nextGroup = tail.next;
            System.out.println("prevGroup => "+(prevGroup != null ? prevGroup.val : prevGroup)+" tail => "+(tail != null ? tail.val : tail)+" nextGroup => "+(nextGroup != null? nextGroup.val : nextGroup));

            reverse(prevGroup.next, tail.next);

            ListNode tmp = prevGroup.next;
            prevGroup.next = tail;
            prevGroup = tmp;
        }

        return dummy.next;
    }
}
