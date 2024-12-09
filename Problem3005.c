/*
You are given an array nums consisting of positive integers.

Return the total frequencies of elements in nums such that those elements all have the maximum frequency.

The frequency of an element is the number of occurrences of that element in the array.

*/

#include<stdio.h>

int maxFrequencyElements(int* nums, int numsSize) 
{
    // static int map[101][101];
    int map[101] = {0};
    int maxFreq = 0;
    int sum = 0;

    for(int i = 0;i < numsSize;i++)
    {
        map[nums[i]]++;

        if(map[nums[i]] > maxFreq)
        {
            maxFreq = map[nums[i]];
            sum = map[nums[i]];
        }
        else if(map[nums[i]] == maxFreq)
        {
            sum += map[nums[i]];
        }
    }

    return sum;
}


int main()
{
    int nums[] = {1,2,3,1,2,2,3,4,5,2};
    printf("%d\n",maxFrequencyElements(nums,10));
    return 0;
}