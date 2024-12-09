/*
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
*/


#include<stdio.h>

void reverse(int* nums,int numsSize,int start,int end)
{
    while(start < end)
    {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;

        start++;
        end--;
    }
}

void rotate(int* nums, int numsSize, int k) 
{
    k = k % numsSize;
        
    reverse(nums,numsSize,0,numsSize-1);

    reverse(nums,numsSize,0,k-1);

    reverse(nums,numsSize,k,numsSize-1);
}



int main()
{

    int nums[] = {1,2,3,4,5,6,7,8,9,10};

    rotate(nums,10,3);

    for(int i = 0;i < 10;i++)
    {
        printf("%d\t",nums[i]);
    }

    printf("\n");

    return 0;
}