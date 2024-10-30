/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

*/


#include<stdio.h>


int compare(const void* a,const void *b)
{
    return ((*(int*)a) - (*(int*)b));
}

bool containsDuplicate(int* nums, int numsSize)
{
    qsort(nums,numsSize,sizeof(int),compare);
    bool flag = false;
    for(int i = 1;i < numsSize;i++)
    {
        if(nums[i -1] == nums[i])
        {
            flag = true;
            break;
        }
    }
    return flag;
}

int main()
{
    int arr[] = {3,4,3,2,1};
    return 0;
}