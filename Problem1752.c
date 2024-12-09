
/*

Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.
*/

#include<stdio.h>
#include<stdbool.h>

bool check(int* nums, int numsSize) 
{
    int cnt = 0;
    
    for(int i = 0;i < numsSize;i++)    
    {
        if(nums[i] > nums[(i+1)%numsSize])
        {
            cnt++;
        }
    }

    return cnt <= 1;
}
int main()
{
    int nums[] = {2,1,3,4};

    printf("%d\n",check(nums,4));

    return 0;
}