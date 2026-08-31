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
public class Solution {
    private ListNode cur;

    public boolean isPalindrome(ListNode head) {
        cur = head;
        return rec(head);
    }

    private boolean rec(ListNode node) {
        if (node != null) {
            if (!rec(node.next)) {
                return false;
            }
            if (cur.val != node.val) {
                return false;
            }
            cur = cur.next;
        }
        return true;
    }
}