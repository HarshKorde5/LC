/*
Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

Return the answer in an array.
*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    // vector<int> smallerNumbersThanCurrent_1(vector<int>& nums) {
        
    // }

    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> answer;
        int i, j;
        int count[101] = {0, 0, 0};
		int len = nums.size();
        for(i = 0; i < len; i++) {
            count[nums[i]]++;
        }
        for(i = 1; i < 101; i++) {
            count[i] += count[i - 1];
        }
        for(i = 0; i < len; i++) {
            if(nums[i] == 0)
                answer.push_back(0);
            else
                answer.push_back(count[nums[i] - 1]);
                
        }
        return answer;
    }
};

int main(){
    Solution sobj;

    vector<int> nums = {8,1,2,2,3};

    vector<int> ret = sobj.smallerNumbersThanCurrent(nums);

    cout<<"Result array : \n";
    for(int x : ret ){
        cout<<x<<endl;
    }

    return 0;
}