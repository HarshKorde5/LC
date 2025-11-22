/*
You are given an integer array nums. In one operation, you can add or subtract 1 from any element of nums.

Return the minimum number of operations to make all elements of nums divisible by 3.
*/
#include<stdio.h>

int minimumOperations(int *nums, int numsSize)
{
    int count = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] % 3 != 0)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    int nums[] = {1,2,3,4,5};
    int n = 5;
    printf("Minimum operations to make all elements of the array divisible by 3 are : %d\n",minimumOperations(nums, n));
    return 0;
}