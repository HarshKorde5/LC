/*
Given a 0-indexed integer array nums of length n and an integer target, return the number of pairs (i, j) where 0 <= i < j < n and nums[i] + nums[j] < target.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
public:

    int countPairs(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end());


        int left = 0,right = nums.size()-1,count = 0;

        while(left <= right)
        {
            int mid = (left + right)/2;

            if(nums[left]+nums[right] < target)         //means there are still pairs who will staisfy  sum < target so move frwd from left
            {
                count += right - left;
                left++;
            }
            else                                        //this means sum exceeded target i.e. sum > target
            {
                right--;
            }
        }

        return count;
        
    }
    int countPairs1(vector<int>& nums, int target) 
    {
        int cnt = 0;
        for(int i = 0;i < nums.size()-1;i++)    
        {
            for(int j = i+1;j < nums.size();j++)
            {
                if(nums[i]+nums[j] < target)
                {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};

int main()
{
    Solution s;

    vector<int>nums = {-1,1,2,3,1};
    cout<<s.countPairs(nums,2);
}