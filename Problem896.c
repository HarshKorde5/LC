/*
An array is monotonic if it is either monotone increasing or monotone decreasing.

An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].

Given an integer array nums, return true if the given array is monotonic, or false otherwise.
*/
#include<stdbool.h>
#include<stdio.h>

bool isMonotonic(int *nums, int numsSize)
{
    if (numsSize == 1)
        return true;

    bool isInc = true;
    bool isDec = true;

    for (int i = 1; i < numsSize; i++)
    {
        if (!isInc && !isDec)
        {
            return false;
        }

        if (nums[i] < nums[i - 1])
        {
            isInc = false;
        }

        if (nums[i] > nums[i - 1])
        {
            isDec = false;
        }
    }

    return isInc || isDec;
}


int main(){
    int nums[] = {1,2,2,4};

    int numsSize = 4;

    printf("Is array monotonic? : %d\n",isMonotonic(nums,numsSize));


    return 0;
}