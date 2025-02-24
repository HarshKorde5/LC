/*
You are given an integer array nums of size n. For each index i where 0 <= i < n, define a 
subarray
 nums[start ... i] where start = max(0, i - nums[i]).

Return the total sum of all elements from the subarray defined for each index in the array.
*/

#include<stdio.h>

int subarraySum1(int* nums, int numsSize) {
    int start = 0;
    int i = 0,j = 0;
    int sum = 0;
    for(i = 0;i < numsSize;i++){

        start = 0 > (i - nums[i]) ? 0 : (i - nums[i]);

        for(j = start;j <= i;j++){
            sum += nums[j];
        }
    }

    return sum;
}

int subarraySum(int* nums, int numsSize) {
    int res = nums[0];
    for (int i = 1, n = numsSize; i < n; i++){
        int j = i - nums[i] - 1;
        nums[i] += nums[i - 1];
        res += nums[i] - (j >= 0 ? nums[j] : 0);
    }
    return res;
    
}

int main(){
    int nums[] = {3,1,1,2};

    printf("%d\n",subarraySum(nums,4));
    return 0;
}