/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    // Brute force : TLE
    vector<int> productExceptSelf_1(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);

        for(int i = 0; i < n; i++){
            int product = 1;
            for(int j = 0; j < n; j++){

                if(i == j) continue;
                product *= nums[j];
            }

            result[i] = product;
        }
        return result;
    }

    // Prefix and Suffix : Extra Space
    vector<int> productExceptSelf_2(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix(n,1);
        vector<int> suffix(n,1);

        for(int i = 1;i < n; i++){
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }


        for(int i = n - 2;i >= 0; i--){
            prefix[i] = prefix[i + 1] * nums[i + 1];
        }

        vector<int> result(n, 1);

        for(int i = 0; i < n; i++){
            result[i] = prefix[i] * suffix[i];            
        }

        return result;
    }


    // O(n) time, O(1) Space(Exculding result vector)
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> result(n, 1);

        for(int i = 1; i < n; i++){
            result[i] = result[i - 1]* nums[i - 1];
        }

        int mul = 1;
        for(int i = n - 2; i >= 0; i--){
            mul *= nums[i+1];
            result[i] = result[i] * mul;
        }

        return result;
    }
};

int main(){

    vector<int> nums = {1,2,3,4,5};

    Solution sobj;

    vector<int> result = sobj.productExceptSelf(nums);

    for(int n : result){
        cout<<n<<endl;
    }
    
    return 0;
}