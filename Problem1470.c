/*
Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].

Return the array in the form [x1,y1,x2,y2,...,xn,yn].
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdio.h>
#include<stdlib.h>

int *shuffle(int *nums, int numsSize, int n, int *returnSize)
{

    *returnSize = numsSize;

    for (int i = n; i < numsSize; i++)
    {
        int curr = nums[i];
        int insertAt = 2 * (i - n) + 1;

        for (int j = i; j > insertAt; j--)
        {
            nums[j] = nums[j - 1];
        }

        nums[insertAt] = curr;
    }

    return nums;
}

int *shuffle_1(int *nums, int numsSize, int n, int *returnSize)
{
    int *ret = (int *)malloc(numsSize * sizeof(int));

    *returnSize = numsSize;
    int k = 0;
    for (int i = 0, j = n; j < numsSize; i++, j++)
    {
        ret[k++] = nums[i];
        ret[k++] = nums[j];
    }
    return ret;
}

int main()
{
    int nums[] = {1,2,3,4,5,6};
    int n = 3;
    int returnSize = 0;
    int numsSize = 6;

    int *ret = shuffle(nums, numsSize, n, &returnSize);
    printf("Array after shuffling : \n");
    for(int i = 0; i < numsSize; i++){
        printf("%d\n",ret[i]);
    }

    return 0;
}