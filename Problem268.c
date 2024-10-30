/*
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
*/

#include<stdio.h>

int missingNumber(int* nums, int numsSize)
{
    long int sum = 0;
    int missing = 0;
    
    for(int i = 0;i < numsSize;i++)
    {
        sum += nums[i];
    }

    missing = (numsSize * (numsSize+1) /2) - sum;

    return missing;
}

int main()
{
    int arr[5] = {0,1,2,3,4};
    int iret = missingNumber(arr,5);
    printf("%d\n",iret);
    
    return 0;
}