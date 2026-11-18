# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isEvenOddTree(self, root: TreeNode | None) -> bool:
        queue = deque()
        current = root

        queue.append(current)

        even = True

        while queue:
            size = len(queue)

            prev = float("inf")

            if even:
                prev = -prev

            while size > 0:
                current = queue.popleft()
                if (even and (current.val % 2 == 0 or current.val <= prev)) or (not even and (current.val % 2 == 1 or current.val >= prev)):
                    return False

                prev = current.val
                if current.left:
                    queue.append(current.left)
                if current.right:
                    queue.append(current.right)

                size -= 1

            even = not even


        return True



            