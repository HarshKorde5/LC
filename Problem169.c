/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
*/

#include<stdio.h>

int majorityElement(int* nums, int numsSize)
{
    int count = 0;
    int k = 0;

    for(int i = 0; i < numsSize; i++){
        if(count == 0){
            k = nums[i];
        }
        count += (nums[i] == k) ? 1 : -1;
    }
    return k;
}

int main()
{
    int arr[] = {2,2,1,1,1,2,2};

    printf("%d\n",majorityElement(arr,7));

    return 0;
}