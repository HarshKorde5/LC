//Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.
#include<stdio.h>


int removeElement(int* nums, int numsSize, int val) 
{
    int i = 0,j = 0;

    for(i = 0; i < numsSize; i++)
    {
        if(nums[i] != val)
        {
            nums[j++] = nums[i];
        }
    }
    return j;
}


int main()
{

    int arr[] = {3,2,2,3};

    int ret = removeElement(arr,4,2);

    return 0;
}
