/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.
*/

#include<stdio.h>

int singleNumber(int* nums, int numsSize)
{
    int i = 0,result = nums[0];
    for(i = 1;i < numsSize;i++)
    {
        result = result ^ nums[i];
    }
    return result;
}

int main()
{
    int arr[5] = {1,2,3,1,2};
    printf("%d\n",singleNumber(arr,5));
    return 0;
}