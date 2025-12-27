/*
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
*/

#include<stdio.h>

int longestOnes(int *nums, int numsSize, int k)
{
    int start = 0;
    int end = 0;
    int zeros = 0;

    while (end < numsSize)
    {
        if (nums[end] == 0)
        {
            zeros++;
        }

        end++;

        if (zeros > k)
        {
            if (nums[start] == 0)
            {
                zeros--;
            }

            start++;
        }
    }

    return end - start;
}

int main()
{
    int nums[] = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};

    int n = 19;
    int k = 3;

    printf("Longest subarray of consecutive ones are : %d\n", longestOnes(nums, n, k));
    return 0;
}