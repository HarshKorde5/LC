/*
You are given an integer array nums. Transform nums by performing the following operations in the exact order specified:

Replace each even number with 0.
Replace each odd numbers with 1.
Sort the modified array in non-decreasing order.
Return the resulting array after performing these operations.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        int k = nums.size() - 1;

        for (int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 != 0){
                result[k--] = 1;
            }
        }

        return result;
    }
};

int main(){
    Solution sobj;

    vector<int> nums = {1,5,1,4,2};

    vector<int> ret = sobj.transformArray(nums);

    for(int num : ret){
        cout<<num<<endl;
    }


    return 0;
}