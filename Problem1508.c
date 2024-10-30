/*
You are given the array nums consisting of n positive integers. You computed the sum of all non-empty continuous subarrays from the array and then sorted them in non-decreasing order, creating a new array of n * (n + 1) / 2 numbers.

Return the sum of the numbers from index left to index right (indexed from 1), inclusive, in the new array. Since the answer can be a huge number return it modulo 109 + 7.
*/


#include<stdio.h>
#include<stdlib.h>

int compare(const void* a,const void* b)
{
    return ((*(const int*)a) - (*(const int*)b));
}

int rangeSum(int* nums, int numsSize, int n, int left, int right)
{

    int len = n*(n+1)/2;
    int i = 0,j = 0,k = 0,index = 0;

    int *sum = (int*)malloc(sizeof(int)*len);

    for(i = 0;i < numsSize;i++)
    {
        long long temp = 0;
        for(j = i;j < numsSize;j++)
        {
            temp += nums[j];
            sum[index++] = temp;
        }
    }

    qsort(sum,len,sizeof(int),compare);

    long long ret_sum = 0;

    for(i = left-1;i < right;i++)
    {
        ret_sum += sum[i];
        ret_sum %= (1000000000 + 7);
    }

    free(sum);

    return ret_sum;
}

int main()
{
    int arr[] = {1,2,3,4};

    printf("%d\n",rangeSum(arr,4,4,1,5));

    return 0;
}