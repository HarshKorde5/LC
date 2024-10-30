/*
Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.
*/

#include<stdio.h>
#include<stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void swap(int*a,int*b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int *nums,int numsSize,int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < numsSize && nums[left] > nums[largest])
    {
        largest = left;
    }

    if(right < numsSize && nums[right] > nums[largest])
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(&nums[i],&nums[largest]);
        heapify(nums,numsSize,largest);
    }
}

void heapSort(int *nums,int numsSize)
{
    for(int i = numsSize/2-1;i >= 0;i--)
    {
        heapify(nums,numsSize,i);
    }

    for(int i = numsSize - 1;i >= 0;i--)
    {
        swap(&nums[0],&nums[i]);
        heapify(nums,i,0);
    }
}

void sortArray(int* nums, int numsSize, int* returnSize)
{
    //int *ret = (int)calloc(numsSize,sizeof(int));

    heapSort(nums,numsSize);
    *returnSize = numsSize;
    //return nums;
}

int main()
{

    int nums[] = {5,2,3,1};
    int n = 4;
    int retsize = 0;
    sortArray(nums,n,&retsize);

    int i = 0;
    printf("Elements of array are : \n");
    for(i = 0;i < n;i++)
    {
        printf("%d\t",nums[i]);
    }
    printf("\n");
    //free(ret);
    return 0;
}