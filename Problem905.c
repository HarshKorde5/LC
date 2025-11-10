/*

Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.

Return any array that satisfies this condition.
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>

int *sortArrayByParity(int *nums, int numsSize, int *returnSize)
{
    int eveIdx = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] % 2 == 0)
        {
            int temp = nums[i];
            nums[i] = nums[eveIdx];
            nums[eveIdx] = temp;
            eveIdx++;
        }
    }

    *returnSize = numsSize;

    return nums;
}

int main()
{

    int nums[] = {3, 1, 2, 4};

    int numsSize = 4;

    int returnSize = 0;

    int *ret = sortArrayByParity(nums, numsSize, &returnSize);

    printf("Sorted array by parity is : \n");
    for (int i = 0; i < numsSize; i++)
    {

        printf("%d\n", ret[i]);
    }

    return 0;
}