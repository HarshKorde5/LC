/*
Given an integer array nums, find the subarray with the largest sum, and return its sum.
*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    //Kadane's algorithm
    int maxSubArray(vector<int>& nums){

        int currMax = 0, maxTillNow = INT_MIN;

        for(int c : nums){
            currMax = max(c, currMax + c);
            maxTillNow = max(maxTillNow, currMax);
        }


        return maxTillNow;
    }

    //DP+Tabulation
    int maxSubArray_2(vector<int>& nums) {

        int n = size(nums);

        vector<vector<int>> dp(2, vector<int>(n));

        dp[0][0] = dp[1][0] = nums[0];

        for(int i = 1;i < n;i++){
            dp[1][i] = max(dp[1][i-1]+nums[i], nums[i]);
            dp[0][i] = max(dp[1][i], dp[0][i-1]);
        }

        return dp[0].back();
    }


    //TLE
    int maxSubArray_1(vector<int>& nums) {
        int n = size(nums), ans = INT_MIN;

        for(int i = 0; i < n; i++){
            for(int j = i, currSum = 0; j < n; j++){
                currSum += nums[j];
                ans = max(ans, currSum);
            }
        }

        return ans;
    }
};


int main(){
    Solution sobj;

    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    cout<<sobj.maxSubArray(nums)<<endl;

    return 0;
}