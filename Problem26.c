//Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

#include<stdio.h>

int removeDuplicates(int* nums, int numsSize) {
 
    int ans = 0;


    for(int i = 1;i < numsSize;i++)
    {   
        if(nums[i] != nums[ans])
        {
            ans++;
            nums[ans] = nums[i];
        }
    }

    return ans+1;
}

int main()
{
    int iret = 0;
    int arr[10] = {0,0,1,1,1,2,2,3,3,4};
    iret = removeDuplicates(arr,10);
    printf("%d\n",iret);
    return 0;
}