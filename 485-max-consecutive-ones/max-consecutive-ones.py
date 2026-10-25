class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:

        res = 0
        cnt = 0

        for x in nums:
            if x == 0:
                res = max(res, cnt)
                cnt = 0
            else:
                cnt += 1

        return max(res,cnt)