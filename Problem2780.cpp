/*
An element x of an integer array arr of length m is dominant if more than half the elements of arr have a value of x.

You are given a 0-indexed integer array nums of length n with one dominant element.

You can split nums at an index i into two arrays nums[0, ..., i] and nums[i + 1, ..., n - 1], but the split is only valid if:

0 <= i < n - 1
nums[0, ..., i], and nums[i + 1, ..., n - 1] have the same dominant element.
Here, nums[i, ..., j] denotes the subarray of nums starting at index i and ending at index j, both ends being inclusive. Particularly, if j < i then nums[i, ..., j] denotes an empty subarray.

Return the minimum index of a valid split. If no valid split exists, return -1.
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            int x = nums[0], count = 0, xCount = 0, n = nums.size();
            for(auto& num : nums){
                if(num == x){
                    count++;
                }else{
                    count--;
                }
    
                if(count == 0){
                    x = num;
                    count = 1;
                }
            }
    
            for (auto& num : nums) {
                if (num == x) {
                    xCount++;
                }
            }
    
    
            count = 0;
            for(int i = 0; i < n; i++){
                if(nums[i] == x){
                    count++;
                }
    
                int remainingCount = xCount - count;
    
                if(count * 2 > i + 1 && remainingCount * 2 > n - i - 1){
                    return i;
                }
            }
    
    
            return -1;
        }
};
int main(){
    Solution s;
    vector<int> nums = {2,1,3,1,1,1,7,1,2,1};
    cout<<s.minimumIndex(nums);
    return 0;
}