/*
Given an integer array nums, handle multiple queries of the following type:

Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class NumArray { // 12 ms, faster than 99.87%
    public:
        vector<int>& preSum; // `preSum` will reference to `nums` array, no copy at all!
        
        NumArray(vector<int>& nums) : preSum(nums) {
            for (int i = 1; i < preSum.size(); ++i)
                preSum[i] += preSum[i-1]; 
        }
        
        int sumRange(int left, int right) {
            if (left == 0) return preSum[right];
            return preSum[right] - preSum[left-1];
        }
};

/**
    * Your NumArray object will be instantiated and called as such:
    * NumArray* obj = new NumArray(nums);
    * int param_1 = obj->sumRange(left,right);
    */

int main(){
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    int left = 0, right = 2;
    NumArray* obj = new NumArray(nums);
    int param_1 = obj->sumRange(left,right);
    return 0;
}