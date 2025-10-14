/*
Given an array nums of n integers and an integer k, determine whether there exist two adjacent subarrays of length k such that both subarrays are strictly increasing. Specifically, check if there are two subarrays starting at indices a and b (a < b), where:

Both subarrays nums[a..a + k - 1] and nums[b..b + k - 1] are strictly increasing.
The subarrays must be adjacent, meaning b = a + k.
Return true if it is possible to find two such subarrays, and false otherwise.
*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {

        int n = nums.size();
        int curr = 1, prev = 0;

        for(int i = 1; i < n; i++){
            if(nums[i] > nums[ i - 1]){
                curr++;
            }else{
                prev = curr;
                curr = 1;
            }

            if( (curr >= k && prev >= k) || (curr >= 2*k)){
                return true;
            }
        }
        return false;        
    }
};

int main(){

    Solution sobj;

    vector<int> nums = {2,5,7,8,9,2,3,4,3,1};
    int k = 3;

    cout<<sobj.hasIncreasingSubarrays(nums, k)<<endl;

    return 0;
}