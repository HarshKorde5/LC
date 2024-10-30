/*
You are given two integer arrays of equal length target and arr. In one step, you can select any non-empty subarray of arr and reverse it. You are allowed to make any number of steps.

Return true if you can make arr equal to target or false otherwise.
*/

#include<stdio.h>
#include<stdbool.h>

int compare(const void* a, const void* b) 
{
   return (*(int*)a - *(int*)b);
}

bool canBeEqual(int* target, int targetSize, int* arr, int arrSize)
{
    if(targetSize != arrSize)
    {
        return false;
    }

    qsort(target,targetSize,sizeof(int),compare);
    qsort(arr,arrSize,sizeof(int),compare);

    for(int i = 0;i < arrSize;i++)
    {
        if(target[i] != arr[i])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int target[] = [1,2,3,4];
    int arr[] = [2,4,1,3];

    printf("%s\n",canBeEqual(target,4,arr,4));
    
    return 0;
}