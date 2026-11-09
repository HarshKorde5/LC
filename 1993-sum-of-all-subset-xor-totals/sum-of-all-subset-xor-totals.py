class Solution:
    def subsetXORSum1(self, nums: List[int]) -> int:

        def rec(nums, index, currXOR):

            if index >= len(nums):
                return currXOR

            withI = rec(nums, index + 1, currXOR ^ nums[index])
            withoutI = rec(nums, index + 1, currXOR)

            return withI + withoutI

        return rec(nums, 0, 0)
    
    def subsetXORSum(self, nums: List[int]) -> int:
        def dfs(i, total):
            if i == len(nums):
                return total

            return dfs(i + 1, total ^ nums[i]) + dfs(i + 1, total)

        return dfs(0,0)