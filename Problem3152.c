/*
An array is considered special if every pair of its adjacent elements contains two numbers with different parity.

You are given an array of integer nums and a 2D integer matrix queries, where for queries[i] = [fromi, toi] your task is to check that 
subarray
 nums[fromi..toi] is special or not.

Return an array of booleans answer such that answer[i] is true if nums[fromi..toi] is special.

*/


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool checkParity(int* nums,int start,int end)
{
    
    bool flag = nums[start]%2;
    bool retFlag = true;

    for(int i = start+1;i <= end;i++)
    {
        
        if((nums[i]%2)==(flag))
        {
            retFlag = false;
            break;
        }
        else
        {
            flag = nums[i] % 2;
        }
    }

    return retFlag;
}


//BruteForce TLE
bool* isArraySpecial1(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) 
{

    bool *retArray = (bool*)calloc(queriesSize,sizeof(bool));
    int k = 0;

    for(int i = 0;i < queriesSize;i++)   
    {
        bool ret = checkParity(nums,queries[i][0],queries[i][1]);

        retArray[k++] = ret;
    }

    *returnSize = queriesSize;

    return retArray;
}

//PrefixSum
bool* isArraySpecial2(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) 
{
    bool *result = (bool*)calloc(queriesSize,sizeof(bool));
    *returnSize = queriesSize;

    int prefix[numsSize];
    prefix[0] = 0;
    for(int i = 1;i < numsSize;i++)
    {
        if(nums[i]%2 == nums[i-1]%2)
        {
            prefix[i] = prefix[i-1]+1;
        }
        else
        {
            prefix[i] = prefix[i-1];
        }
    }


    for(int i = 0;i < queriesSize;i++)
    {
        result[i] = prefix[queries[i][1]] - prefix[queries[i][0]] == 0;
    }

    return result;
}


//MaxReach
bool* isArraySpecial(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) 
{
    bool *result = (bool*)calloc(queriesSize,sizeof(bool));
    *returnSize = queriesSize;
    int maxReach[numsSize];

    int end = 0;


    for(int start = 0;start < numsSize;start++)
    {
        end = start > end ? start : end;

 
        while(end < numsSize - 1 && nums[end] % 2 != nums[end + 1] % 2)
        {
            end++;
        }


        maxReach[start] = end;
    }

    for(int i = 0;i < queriesSize;i++)
    {
        result[i] = queries[i][1] <= maxReach[queries[i][0]];
    }


    return result;
}


int main()
{
    int nums[] = {4,3,1,6};
    int c = 0,rs = 0;

    int *col = &c;
    int *retSize = &rs;

    int** queries = (int**)malloc(2 * sizeof(int*));
    for (int i = 0; i < 2; i++) {
        queries[i] = (int*)malloc(2 * sizeof(int));
    }

    queries[0][0] = 0;
    queries[0][1] = 2;

    queries[1][0] = 2;
    queries[1][1] = 3;

    bool *ret = isArraySpecial(nums,4,queries,2,col,retSize);

    for(int i = 0;i < 2;i++)
    {
        printf("%d\t",ret[i]);

    }

    printf("\n");
    return 0;
}