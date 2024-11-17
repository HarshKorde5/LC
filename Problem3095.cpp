
/*
You are given an array nums of non-negative integers and an integer k.

An array is called special if the bitwise OR of all of its elements is at least k.

Return the length of the shortest special non-empty 
subarray
 of nums, or return -1 if no special subarray exists.

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int ans = INT_MAX;

        for(int i = 0; i < n; i++) 
        {
            int val = 0;

            for(int j = i; j < n; j++) 
            {
                val |= nums[j];

                if(val >= k) 
                {
                    ans = min(ans, j - i + 1);
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

int main()
{
    Solution s;

    vector<int> nums = {1,2,3};

    cout<<s.minimumSubarrayLength(nums,2);

    return 0;
}