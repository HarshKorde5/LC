/*

Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.

A pair (i, j) is fair if:

0 <= i < j < n, and
lower <= nums[i] + nums[j] <= upper
*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) 
    {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        long long lcount = 0,ucount = 0;

        int left = 0,right = n - 1;

        
        while(left < right)
        {
            int sum = nums[left] + nums[right];

            if(sum < upper + 1)
            {
                ucount += (right - left);
                left++;
            }
            else
            {
                right--;
            }

        }


        left = 0;
        right = n -1;

        while(left < right)
        {
            int sum = nums[left] + nums[right];

            if(sum < lower)
            {
                lcount += (right - left);
                left++;
            }
            else
            {
                right--;
            }

        }

        return ucount - lcount;
    }

};


int main()
{

    Solution s;

    vector<int> nums = {0,1,7,4,4,5};
    cout<<s.countFairPairs(nums,3,6);
    return 0;
}