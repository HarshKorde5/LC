/*
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        unordered_map<int,int> mp;

        for(int i = 0;i < nums.size();i++)
        {
            if(mp.count(nums[i]))
            {
                if(abs(i - mp[nums[i]]) <= k)
                {
                    return true;
                }
            }

            mp[nums[i]] = i;
        }


        return false;

    }

    bool containsNearbyDuplicate1(vector<int>& nums, int k) 
    {
        int n = nums.size();

        int i = 0;

        if(k == 0)  return false;


        while(i < n)
        {
            int j = i + 1;

            while(j < n && j <= i + k)
            {
                if(nums[i] == nums[j])
                {
                    return true;
                }
                j++;
            }

            i++;
        }


        return false;
    }
};



int main()
{

    Solution s;
    vector<int> nums = {1,2,3,1};

    cout<<s.containsNearbyDuplicate(nums,3);
    return 0;
}