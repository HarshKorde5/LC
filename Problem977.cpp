#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        vector<int> result(n, 0);

        int left = 0, right = n - 1;

        for(int i = n - 1; i >= 0; i--){
            if(abs(nums[left]) > abs(nums[right])){
                result[i] = nums[left] * nums[left];
                left++;
            }else{
                result[i] = nums[right] * nums[right];
                right--;
            }
        }

        return result;

    }
};

int main(){

    vector<int> nums = {-4, -1, 0, 3, 10};

    Solution sobj; 
    vector<int> ret = sobj.sortedSquares(nums);
    cout<<"Result array : "<<endl;

    for(int i : ret){
        cout<<i<<endl;
    }

    return 0;
}