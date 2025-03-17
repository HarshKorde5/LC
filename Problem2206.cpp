/*
You are given an integer array nums consisting of 2 * n integers.

You need to divide nums into n pairs such that:

Each element belongs to exactly one pair.
The elements present in a pair are equal.
Return true if nums can be divided into n pairs, otherwise return false.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            // Track unpaired numbers
            unordered_set<int> unpaired;
    
            // Add numbers to set if unseen, remove if seen
            for (int num : nums) {
                if (unpaired.count(num)) {
                    unpaired.erase(num);
                } else {
                    unpaired.insert(num);
                }
            }
    
            // Return true if all numbers were paired
            return unpaired.empty();
        }
};

int main(){
    Solution s;
    vector<int> nums = {3,2,3,2,2,2};
    cout<<s.divideArray(nums);
    return 0;
}