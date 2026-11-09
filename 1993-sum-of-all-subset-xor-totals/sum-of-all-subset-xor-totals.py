class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:

        def rec(nums, index, currXOR):

            if index >= len(nums):
                return currXOR

            withI = rec(nums, index + 1, currXOR ^ nums[index])
            withoutI = rec(nums, index + 1, currXOR)

            return withI + withoutI

        return rec(nums, 0, 0)
            