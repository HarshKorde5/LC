/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.
*/


#include<stdio.h>

void moveZeroes(int* nums, int numsSize) 
{
    int curr = 0;

    for(int i = 0;i < numsSize;i++)
    {
        if(nums[i] != 0)
        {
            int temp = nums[i];
            nums[i] = nums[curr];
            nums[curr] = temp;
            curr++;
        }
    }
}

int main()
{

    int nums[] = {0,1,0,3,12};

    moveZeroes(nums,5);

    for(int i = 0;i < 5;i++)
    {
        printf("%d\t",nums[i]);

    }
    return 0;
}