/*
Given an array nums of n integers, your task is to find the maximum value of k for which there exist two adjacent subarrays of length k each, such that both subarrays are strictly increasing. Specifically, check if there are two subarrays of length k starting at indices a and b (a < b), where:

Both subarrays nums[a..a + k - 1] and nums[b..b + k - 1] are strictly increasing.
The subarrays must be adjacent, meaning b = a + k.
Return the maximum possible value of k.

A subarray is a contiguous non-empty sequence of elements within an array.
*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    pair<int, pair<vector<int>,vector<int>>> maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int max_k = 0, prev = 0, curr = 1;

        vector<vector<int>> subarrays;
        vector<int> temp = {nums[0]};

        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i - 1]){
                curr++;
                temp.push_back(nums[i]);
            }else{
                subarrays.push_back(temp);
                temp = {nums[i]};
                prev = curr;
                curr = 1;
            }

            max_k = max(max_k, max(curr / 2, min(curr, prev)));

        }

        cout<<"These are the increasing subarrays from orignal subarrays : "<<endl;
        for(auto &v : subarrays){
            for(auto x : v){
                cout<<x<<" ";
            }

            cout<<endl;
        }

        
        vector<int> sub_1, sub_2;

        for(int i = 0;i < subarrays.size() - 2; i++){
            int len_1 = subarrays[i].size();
            int len_2 = subarrays[i + 1].size();

            int k = max(len_2 / 2, min(len_1, len_2));

            if(k == max_k){
                sub_1.assign(subarrays[i].end() - k, subarrays[i].end());
                sub_2.assign(subarrays[i+1].begin(), subarrays[i+1].begin()+k);
            }
        }


        
        return {max_k, {sub_1, sub_2}};
    }

    void display(vector<int>& nums){
        for(int x : nums) cout<<x<<" ";
        cout<<endl;
    }
};

int main(){

    vector<int> nums = {2,5,7,8,9,2,3,4,3,1};
    Solution sobj;

    cout<<"Orignal array is : ";
    sobj.display(nums);


    auto result = sobj.maxIncreasingSubarrays(nums);
    
    cout<<"Max k is : "<<result.first<<endl;

    cout<<"Adjacent subarrays are : \n";

    vector<int> sub_1 = result.second.first;
    vector<int> sub_2 = result.second.second;

    cout<<"Subarray 1 : ";
    sobj.display(sub_1);

    cout<<"Subarray 2 : ";
    sobj.display(sub_2);

    return 0;
}