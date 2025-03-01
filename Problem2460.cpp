/*
You are given a 0-indexed array nums of size n consisting of non-negative integers.

You need to apply n - 1 operations to this array where, in the ith operation (0-indexed), you will apply the following on the ith element of nums:

If nums[i] == nums[i + 1], then multiply nums[i] by 2 and set nums[i + 1] to 0. Otherwise, you skip this operation.
After performing all the operations, shift all the 0's to the end of the array.

For example, the array [1,0,2,0,0,1] after shifting all its 0's to the end, is [1,2,1,0,0,0].
Return the resulting array.

Note that the operations are applied sequentially, not all at once.
*/

#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> applyOperations(vector<int>& nums) {
            int n = nums.size();
            int writeIndex = 0;
    
            for (int index = 0; index < n; index++) {
                
                if (index < n - 1 && nums[index] == nums[index + 1] && nums[index] != 0) {
                    nums[index] *= 2;
                    nums[index + 1] = 0;
                }
    
                
                if (nums[index] != 0) {
                    if (index != writeIndex) {
                        swap(nums[index], nums[writeIndex]);
                    }
                    writeIndex++;
                }
            }
    
            return nums;
        }
};

int main(){

    Solution s;
    vector<int> nums = {1,2,2,1,1,0};
    nums = s.applyOperations(nums);

    return 0;
}