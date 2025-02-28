/*
Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums.
*/

#include<stdio.h>
#include<stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 int* runningSum(int* nums, int numsSize, int* returnSize){
    int sum=0;
    *returnSize = numsSize; //size for the new array to be returned
    
    for(int i=1;i<numsSize;i++)
    {
        nums[i]+=nums[i-1];
    }
    return nums;
}

int main(){

    int nums[] = {1,2,3,4};
    int k = 0;
    int ret = runningSum(nums,4,&k);
    return 0;
}