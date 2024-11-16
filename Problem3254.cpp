/*
You are given an array of integers nums of length n and a positive integer k.

The power of an array is defined as:

Its maximum element if all of its elements are consecutive and sorted in ascending order.
-1 otherwise.
You need to find the power of all 
subarrays
 of nums of size k.

Return an integer array results of size n - k + 1, where results[i] is the power of nums[i..(i + k - 1)].

*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<int> result;

        int start = 0,end = k;

        while(end <= n)
        {
            int power = nums[start];
            int max = 0;
            for(int i = start;i < end-1;i++)
            {
                if(nums[i+1]-nums[i] != 1)
                {
                    power = -1;
                    break;
                }
            }

            if(power == -1)
            {
                result.push_back(power);
            }
            else
            {
                result.push_back(nums[end-1]);
            }

            start++;
            end = start + k;
        }

        return result;
    }
};

int main()
{
    Solution s;
    
    vector<int> nums = {1,2,3,4,5};

    vector<int> ret = s.resultsArray(nums,3);

    for(int i = 0;i < ret.size();i++)
    {
        cout<<ret[i]<<"\n";
    }


    return 0;
}