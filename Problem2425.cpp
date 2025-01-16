/*
You are given two 0-indexed arrays, nums1 and nums2, consisting of non-negative integers. There exists another array, nums3, which contains the bitwise XOR of all pairings of integers between nums1 and nums2 (every integer in nums1 is paired with every integer in nums2 exactly once).

Return the bitwise XOR of all integers in nums3.


*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    /////////////////////////////////////////////////////////////////////
    // Brute Force : TLE
    /////////////////////////////////////////////////////////////////////
    int xorAllNums1(vector<int>& nums1, vector<int>& nums2) {
        int result = 0;
        for(int i = 0;i < nums1.size();i++){
            for(int j = 0;j < nums2.size();j++){
                result ^= (nums1[i]^nums2[j]);     
            }
        }
        return result;
        
    }
    //////////////////////////////////////////////////////////////////////
    //  nums1.size and nums2.size even-odd factor
    //////////////////////////////////////////////////////////////////////
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int x1 = 0,x2 = 0;

        if(nums1.size() % 2 != 0){
            for(int i = 0;i < nums2.size();i++){
                x2 ^= nums2[i];
            }
        }

        if(nums2.size() % 2 != 0){
            for(int i = 0;i < nums1.size();i++){
                x1 ^= nums1[i];
            }
        }

        return x1 ^ x2;
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {4,5,6,7};

    cout<<s.xorAllNums(nums1,nums2);
    return 0;
}