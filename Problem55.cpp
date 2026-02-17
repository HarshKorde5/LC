/*
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {

        // our initial reach is 0 only
        int reach = 0;

        for (int pos = 0; pos < nums.size(); pos++)
        {

            // our curr pos moved ahead of maximum reach we had
            if (reach < pos)
            {
                return false;
            }

            // as we can reach this pos what can be next maximum we can reach from curr pos?
            reach = max(reach, pos + nums[pos]);
        }

        return true;
    }

private:
    bool canJump_2(vector<int> &nums, int idx, vector<int> &dp)
    {
        if (idx == nums.size() - 1)
            return true;

        if (nums[idx] == 0)
            return false;

        if (dp[idx] != -1)
            return dp[idx];

        int reach = idx + nums[idx];

        for (int jump = idx + 1; jump <= reach; jump++)
        {
            if (jump < nums.size() && canJump_2(nums, jump, dp))
            {
                return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }

    bool canJump_2(vector<int> &nums)
    {

        vector<int> dp(nums.size(), -1);
        return canJump_2(nums, 0, dp);
    }

    bool canJump_1(vector<int> &nums, int idx = 0)
    {
        if (idx == nums.size() - 1)
            return true; // reached last index

        if (nums[idx] == 0)
            return false; // reached a position from where 0 moves can be made further

        int reach = idx + nums[idx];
        for (int jump = idx + 1; jump <= reach; jump++)
        {

            // if true, taking this jump gives us last idx
            if (jump < nums.size() && canJump_1(nums, jump))
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    vector<int> nums = {3,2,1,0,4};
    Solution sobj;
    bool ret = sobj.canJump(nums);
    cout<<ret<<endl;
    return 0;
}