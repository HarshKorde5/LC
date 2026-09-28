# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: TreeNode | None) -> int:
        if not root:
            return 0

        l:int = self.minDepth(root.left)
        r = self.minDepth(root.right)

        return l+r+1 if (l == 0 or r == 0) else 1 + min(l,r)