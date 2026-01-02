/*
You are given an integer array nums with the following properties:

nums.length == 2 * n.
nums contains n + 1 unique elements.
Exactly one element of nums is repeated n times.
Return the element that is repeated n times.
*/

#include<stdio.h>

int repeatedNTimes(int *nums, int numsSize)
{
    for (int i = 0; i < numsSize - 2; i++)
    {
        if (nums[i] == nums[i + 1] || nums[i] == nums[i + 2])
        {
            return nums[i];
        }
    }

    return nums[numsSize - 1];
}

int main()
{
    int nums[] = {5,1,5,2,5,3,5,4};
    int n = 8;
    printf("Element repeated 2*n times in the array is : %d\n", repeatedNTimes(nums, n));

    return 0;
}