/*
An array is considered special if every pair of its adjacent elements contains two numbers with different parity.

You are given an array of integers nums. Return true if nums is a special array, otherwise, return false.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for(int i = 1;i < nums.size();i++){
            if(nums[i] % 2 == nums[i-1]%2){
                return false;
            }
        }

        return true;
    }
};

int main(){

    Solution s;
    vector<int> nums = {4,1,3,2};
    cout<<s.isArraySpecial(nums);
    return 0;
}