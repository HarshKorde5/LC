#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0, currSum = 0;
        int res = INT_MAX;

        for(right = 0; right < nums.size(); right++){

            currSum += nums[right];

            while(currSum >= target){
                res = min(res, right - left + 1);
                currSum -= nums[left];
                left++;
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};

int main(){
    Solution sobj;

    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    int result = sobj.minSubArrayLen(target, nums);
    cout << "The minimum length of a contiguous subarray with sum at least " << target << " is: " << result << endl;
    
    return 0;
}