/*
Given an array of integers nums, half of the integers in nums are odd, and the other half are even.

Sort the array so that whenever nums[i] is odd, i is odd, and whenever nums[i] is even, i is even.

Return any answer array that satisfies this condition.
*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    // extra space
    vector<int> sortArrayByParityII_1(vector<int>& arr) {
        int n=arr.size();
        vector<int> answer(n,1);
        int j=0,k=1;
        for(int i=0;i<n;i++){
            if(arr[i]%2==0 ){
                answer[j] = arr[i];
                j+=2;
            }
            else {
                answer[k] = arr[i];
                k+=2;
            }
        }
        return answer;
    }

    // In-place solution
    vector<int> sortArrayByParityII(vector<int>& nums) {

        int i = 0, j = 1;
        int n = nums.size();
        
        // sort(nums.begin(), nums.end());      //if we need the array to be in sorted order


        while(i < n && j < n){
            if(nums[i] % 2 != 0 && nums[j] % 2 != 1){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }

            if(nums[i] % 2 == 0) i += 2;
            if(nums[j] % 2 == 1) j += 2;
        }

        return nums;
    }
};


int main(){

    Solution sobj;

    vector<int> nums = {4,2,5,7};

    vector<int> result = sobj.sortArrayByParityII(nums);

    for( int n : result){

        cout<<n<<endl;
    }

    return 0;
}