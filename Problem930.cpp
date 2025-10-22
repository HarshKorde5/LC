/*
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.


*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    //hashmap
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int totalCount = 0;
        int currentSum = 0;

        unordered_map<int, int> freq;   //{prefix : number of occurence}

        for(int num : nums){
            currentSum += num;

            if(currentSum == goal){
                totalCount++;
            }

            if(freq.find(currentSum - goal) != freq.end()){
                totalCount += freq[currentSum - goal];
            }


            freq[currentSum]++;
        }


        return totalCount;
    }

    
};


int main(){

    Solution sobj;

    vector<int> nums = {1,0,1,0,1};
    int goal = 2;
    cout<<"Count of subarrays with goal "<<goal<<" is : "<<sobj.numSubarraysWithSum(nums,goal)<<endl;
    return 0;
}