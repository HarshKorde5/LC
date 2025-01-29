/*
Given an unsorted array of integers nums, return the length of the longest continuous increasing subsequence (i.e. subarray). The subsequence must be strictly increasing.

A continuous increasing subsequence is defined by two indices l and r (l < r) such that it is [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] and for each l <= i < r, nums[i] < nums[i + 1].
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int maxLen = 0;
        int cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                maxLen = maxLen > cnt ? maxLen : cnt;
                cnt = 1;
            } else {
                cnt++;
            }
        }
        maxLen = maxLen > cnt ? maxLen : cnt;
        return maxLen;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,3,5,4,7};

    cout<<s.findLengthOfLCIS(nums);
    return 0;
}