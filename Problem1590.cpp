/*
Given an array of positive integers nums, remove the smallest subarray (possibly empty) such that the sum of the remaining elements is divisible by p. It is not allowed to remove the whole array.

Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.

A subarray is defined as a contiguous block of elements in the array.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSubarray(vector<int> &nums, int p)
    {
        int n = nums.size();
        int totalSum = 0;

        // Step 1: Calculate total sum % p
        for (int num : nums)
        {
            totalSum = (totalSum + num) % p;
        }

        int target = totalSum % p;
        if (target == 0)
            return 0;

        // Step 2: Prefix sum mod tracking
        unordered_map<int, int> modMap;
        modMap[0] = -1;

        int currentSum = 0, minLen = n;

        for (int i = 0; i < n; ++i)
        {
            currentSum = (currentSum + nums[i]) % p;

            int needed = (currentSum - target + p) % p;// add +p to make (currentSum - target) a positive value 

            if (modMap.find(needed) != modMap.end())
            {
                minLen = min(minLen, i - modMap[needed]);
            }

            modMap[currentSum] = i;
        }

        return minLen == n ? -1 : minLen;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 1, 4, 2};
    int p = 6;

    int result = sol.minSubarray(nums, p);

    cout << "Minimum subarray length = " << result << endl;

    return 0;
}
