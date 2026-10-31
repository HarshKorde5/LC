# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        removed = set(nums)
        dummy = ListNode(0)
        tail, current = dummy, head
        while current:
            following = current.next
            current.next = None
            if current.val not in removed:
                tail.next = current
                tail = current
            current = following
        return dummy.next
