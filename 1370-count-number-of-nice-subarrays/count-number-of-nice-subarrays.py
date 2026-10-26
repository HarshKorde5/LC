class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        counts = [0]*(len(nums)+1)
        counts[0] = 1
        odd = answer = 0
        for x in nums:
            odd += x%2
            if odd >= k: answer += counts[odd-k]
            counts[odd] += 1
        return answer
