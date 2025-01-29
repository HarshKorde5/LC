/*
Given a circular array nums, find the maximum absolute difference between adjacent elements.

Note: In a circular array, the first and last elements are adjacent.
*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int maxAdjacentDistance(int* nums, int numsSize) {

    if(numsSize <= 1){
        return 0;
    }

    int last = nums[numsSize - 1];
    int ans = 0;

    for(int i = 0;i < numsSize;i++){
        ans = ans > abs(nums[i] - last) ? ans : abs(nums[i] - last);
        last = nums[i];
    }

    return ans;
}

int main(){

    int nums[] = {1,2,4};

    printf("%d\n",maxAdjacentDistance(nums,3));

    return 0;
}