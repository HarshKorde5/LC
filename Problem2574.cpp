/*
You are given a 0-indexed integer array nums of size n.

Define two arrays leftSum and rightSum where:

leftSum[i] is the sum of elements to the left of the index i in the array nums. If there is no such element, leftSum[i] = 0.
rightSum[i] is the sum of elements to the right of the index i in the array nums. If there is no such element, rightSum[i] = 0.
Return an integer array answer of size n where answer[i] = |leftSum[i] - rightSum[i]|.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        int lsum = 0, rsum = 0;

        for(int i = 0; i < n; i++) {
            rsum += nums[i];
        }

        for(int i = 0; i < n; i++){
            rsum -= nums[i];
            result.push_back(abs(lsum - rsum));
            lsum += nums[i];
        }
        return result;
    }
};

int main(){

    vector<int> nums = {10, 4, 8, 3};
    Solution sobj;
    vector<int> ret = sobj.leftRightDifference(nums);

    cout<<"Result : "<<endl;

    for(int x : ret){
        cout<<x<<endl;
    }

    return 0;
}