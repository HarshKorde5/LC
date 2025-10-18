#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int cnt = 0, prev = INT_MIN;

        for(int num : nums){
            int curr = min(max(num - k, prev + 1), num + k);

            if(curr > prev){
                cnt++;
                prev = curr;
            }
        }

        return cnt;
    }
};


int main(){
    Solution sobj;
    vector<int> nums = {1,2,2,3,3,4};

    cout<<sobj.maxDistinctElements(nums, 2)<<endl;

    return 0;
}