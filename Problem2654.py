"""
You are given a 0-indexed array nums consisiting of positive integers. You can do the following operation on the array any number of times:

Select an index i such that 0 <= i < n - 1 and replace either of nums[i] or nums[i+1] with their gcd value.
Return the minimum number of operations to make all elements of nums equal to 1. If it is impossible, return -1.

The gcd of two integers is the greatest common divisor of the two integers.
"""

from math import gcd
from typing import List

class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n, num1, g = len(nums), 0, 0

        for x in nums:
            if x == 1:
                num1 += 1
            g = gcd(g, x)

        if num1 > 0:
            return n - num1
        if g > 1:
            return -1

        min_len = n
        for i in range(n):
            g = 0
            for j in range(i, n):
                g = gcd(g, nums[j])
                if g == 1:
                    min_len = min(min_len, j - i + 1)
                    break

        return min_len + n - 2


def main():
    sol = Solution()

    test_cases = [
        [2, 6, 3, 4],
        [4, 3, 6, 8],
        [1, 1, 1],
        [2, 4, 6, 8],
        [7, 9, 3]
    ]

    for nums in test_cases:
        result = sol.minOperations(nums)
        print(f"nums = {nums} → minOperations = {result}")


if __name__ == "__main__":
    main()