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

    public boolean isPalindrome_01(ListNode head) {
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
        public boolean isPalindrome(ListNode head) {
        ListNode fast = head, slow = head;

        // find middle (slow)
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
        }

        // reverse second half
        ListNode prev = null;
        while (slow != null) {
            ListNode tmp = slow.next;
            slow.next = prev;
            prev = slow;
            slow = tmp;
        }

        // check palindrome
        ListNode left = head, right = prev;
        while (right != null) {
            if (left.val != right.val) {
                return false;
            }
            left = left.next;
            right = right.next;
        }

        return true;
    }
}