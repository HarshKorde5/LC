
/*
You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:

The length of the subarray is k, and
All the elements of the subarray are distinct.
Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.

A subarray is a contiguous non-empty sequence of elements within an array.

*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) 
    {

        unordered_map<int,int> mymap;

        int start = 0,end = 0;
        long long result = 0;
        int n = nums.size();
        long long sum = 0,prevSum = 0;

        for(end = 0;end < k;end++)
        {
            mymap[nums[end]]++;
            prevSum += nums[end];
        }


        while(end <= n)
        {
            if(mymap.size() == k)       //if equals k means the subarray contains k distinct elements
            {
                sum = max(prevSum,sum);
            }

            if(start < n)
            {
                mymap[nums[start]]--;       //remove starting element i.e.slide window

                if(mymap[nums[start]] == 0)     
                {
                    mymap.erase(nums[start]);
                }

                prevSum -= nums[start];     //remove the sum starting element from sum also
                start++;
            }

            if(end < n)
            {
                mymap[nums[end]]++;         //add new end 
                prevSum += nums[end];
            }

            end++;
        }

        return sum;
    }
};


int main()
{

    Solution s;

    vector<int> nums = {1,5,4,2,9,9,9};

    cout<<s.maximumSubarraySum(nums,3);


    return 0;
}