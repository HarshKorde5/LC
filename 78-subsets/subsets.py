class Solution:
    def subsets(self, nums: list[int]) -> list[list[int]]:
        res = []
        sub = []

        def dfs(i):
            if i >= len(nums):
                res.append(sub.copy())
                return
            
            sub.append(nums[i])
            dfs(i + 1)
            sub.pop()
            dfs(i + 1)
        
        dfs(0)
        return res