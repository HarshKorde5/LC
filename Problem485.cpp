//Given a binary array nums, return the maximum number of consecutive 1's in the array.


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int count = 0;
        int maxi = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;
            }
            maxi = max(maxi, count);
            if (nums[i] == 0) {
                count = 0;
            }
        }
        return maxi;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,1,0,1,1,1};
    cout<<s.findMaxConsecutiveOnes(nums);
    return 0;
}