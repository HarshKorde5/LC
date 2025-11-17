/*
Given an binary array nums and an integer k, return true if all 1's are at least k places away from each other, otherwise return false.
*/
#include<stdbool.h>
#include<stdio.h>

bool kLengthApart(int *nums, int numsSize, int k)
{

    int i = 0, prev = -1;

    while (i < numsSize)
    {

        if (nums[i] == 1)
        {

            if (prev != -1 && i - prev <= k)
            {
                return false;
            }
            prev = i;
        }

        i++;
    }

    return true;
}

int main()
{
    int n = 6;
    int nums[] = {1,0,0,1,0,1};
    int k = 2;
    bool ret = kLengthApart(nums,n, k);

    if(ret){
        printf("All ones in the array are %d length apart!\n",k);        
    }else{
        printf("All ones in the array are not %d length apart!\n",k);        
    }
    return 0;
}