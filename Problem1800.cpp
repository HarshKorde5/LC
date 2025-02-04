/*
Given an array of positive integers nums, return the maximum possible sum of an ascending subarray in nums.

A subarray is defined as a contiguous sequence of numbers in an array.

A subarray [numsl, numsl+1, ..., numsr-1, numsr] is ascending if for all i where l <= i < r, numsi  < numsi+1. Note that a subarray of size 1 is ascending.

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = 0;

        int sum = nums[0];

        for(int i = 1;i < nums.size();i++){
            if(nums[i] <= nums[i-1]){
                maxSum = maxSum > sum ? maxSum : sum;
                sum = 0;
            }
            sum += nums[i];
        }
        maxSum = maxSum > sum ? maxSum : sum;
        return maxSum;

    }
};

int main(){
    Solution s;
    vector<int> nums = {10,20,30,5,10,50};
    cout<<s.maxAscendingSum(nums);
    return 0;
}