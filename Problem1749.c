/*
You are given an integer array nums. The absolute sum of a subarray [numsl, numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 + numsr).

Return the maximum absolute sum of any (possibly empty) subarray of nums.

Note that abs(x) is defined as follows:

If x is a negative integer, then abs(x) = -x.
If x is a non-negative integer, then abs(x) = x.
*/

#include<stdio.h>

int maxAbsoluteSum(int* nums, int numsSize) {

    int minPrefixSum = 0, maxPrefixSum = 0,i = 0, prefixSum = 0;

    for(i = 0;i < numsSize;i++){
        prefixSum += nums[i];

        minPrefixSum = minPrefixSum < prefixSum ? minPrefixSum : prefixSum;
        maxPrefixSum = maxPrefixSum > prefixSum ? maxPrefixSum : prefixSum;
    }
    
    return maxPrefixSum - minPrefixSum;
}

int main(){

    int nums[] = {2,-5,1,-4,3,-2};
    int n = 6;
    printf("%d\n",maxAbsoluteSum(nums,n));
    return 0;
}