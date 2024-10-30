//Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

//You must write an algorithm with O(log n) runtime complexity.


#include<stdio.h>

int searchInsert(int* nums, int numsSize, int target)
{
    int i = 0;
    for(i = 0;i < numsSize;i++)
    {
        if(nums[i] >= target)
        {
            break;
        }
    }
    return i;
}

int main()
{

    int arr[] = {1,3,5,7};

    int ret = searchInsert(arr,4,2);
    
    return 0;
}