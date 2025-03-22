/*
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears at most twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding the space needed to store the output
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> findDuplicates(vector<int>& nums) {
            vector<int> result; // Result vector to store duplicate numbers
            for (int i = 0; i < nums.size(); ++i) {
                int index = abs(nums[i]) - 1; // Get the index corresponding to the number
                if (nums[index] < 0) { // If the number at index is negative, it means it's seen before
                    result.push_back(index + 1); // Add the duplicate number to the result
                } else {
                    nums[index] = -nums[index]; // Mark the number as seen by negating it
                }
            }
            return result; // Return the vector containing duplicate numbers
        }
};

int main(){

    Solution s;
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> ret = s.findDuplicates(nums);
    
    return 0;
}