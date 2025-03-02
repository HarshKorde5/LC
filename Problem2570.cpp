/*
You are given two 2D integer arrays nums1 and nums2.

nums1[i] = [idi, vali] indicate that the number with the id idi has a value equal to vali.
nums2[i] = [idi, vali] indicate that the number with the id idi has a value equal to vali.
Each array contains unique ids and is sorted in ascending order by id.

Merge the two arrays into one array that is sorted in ascending order by id, respecting the following conditions:

Only ids that appear in at least one of the two arrays should be included in the resulting array.
Each id should be included only once and its value should be the sum of the values of this id in the two arrays. If the id does not exist in one of the two arrays, then assume its value in that array to be 0.
Return the resulting array. The returned array must be sorted in ascending order by id.
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            vector<vector<int>>ans;
            int temp1=0, temp2=0;
            int n1 = nums1.size(), n2 = nums2.size();
            while(temp1<n1 && temp2<n2){
                if(nums1[temp1][0]==nums2[temp2][0]){
                    ans.push_back({nums1[temp1][0],nums1[temp1][1]+nums2[temp2][1]});
                    temp1++;temp2++;
                }
                else if(nums1[temp1][0]<nums2[temp2][0]){
                    ans.push_back({nums1[temp1][0],nums1[temp1][1]});
                    temp1++;               
                }
                else{
                    ans.push_back({nums2[temp2][0],nums2[temp2][1]});
                    temp2++;                
                }
            }
    
            while(temp1<n1){
                ans.push_back({nums1[temp1][0],nums1[temp1][1]});
                temp1++; 
            }
    
            while(temp2<n2){
                ans.push_back({nums2[temp2][0],nums2[temp2][1]});
                temp2++; 
            }
            return ans; 
        }
};

int main(){

    Solution s;
    vector<vector<int>> nums1 = {{1,2},{2,3},{4,5}};
    vector<vector<int>> nums2 = {{1,4},{3,2},{4,1}};

    vector<vector<int>> ret = s.mergeArrays(nums1,nums2);

    return 0;
}