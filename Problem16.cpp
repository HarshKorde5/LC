/*
Given an integer array nums of length n and an integer target, find three integers at distinct indices in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int closestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++)
        {
            int l = i + 1;
            int r = n - 1;

            while (l < r)
            {
                int currSum = nums[i] + nums[l] + nums[r];

                if (abs(currSum - target) < abs(closestSum - target))
                {
                    closestSum = currSum;
                }

                if (currSum < target)
                {
                    l++;
                }
                else if (currSum > target)
                {
                    r--;
                }
                else
                {
                    return currSum;
                }
            }
        }

        return closestSum;
    }
};

int main()
{

    Solution sobj;

    vector<int> nums = {1, 2, 4, 2, 4, 9, -1, -3, -5};

    int target = 11;

    int ret = sobj.threeSumClosest(nums, target);

    cout << "Closest sum to " << target << " is :: " << ret << endl;

    return 0;
}