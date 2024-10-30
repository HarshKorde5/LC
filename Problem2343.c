
/*
You are given a 0-indexed array of strings nums, where each string is of equal length and consists of only digits.

You are also given a 0-indexed 2D integer array queries where queries[i] = [ki, trimi]. For each queries[i], you need to:

Trim each number in nums to its rightmost trimi digits.
Determine the index of the kith smallest trimmed number in nums. If two trimmed numbers are equal, the number with the lower index is considered to be smaller.
Reset each number in nums to its original length.
Return an array answer of the same length as queries, where answer[i] is the answer to the ith query.

Note:

To trim to the rightmost x digits means to keep removing the leftmost digit, until only x digits remain.
Strings in nums may contain leading zeros.
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


#include<stdio.h>
#include<stdlib.h>


int trim(char *val,int k)
{
    int ival = 0;
    while(*val != '\0')
    {
        ival = ival * 10 + (*val - '0');
        val++;
    }

    int iret = 0;
    while(k--)
    {
        iret = iret + ((ival%10)*10);
    }

    return iret;
}

int compare(const void* a,const void *b)
{
    return(*(int*)a - (*(int*)b));
}

int* smallestTrimmedNumbers(char** nums, int numsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize)
{
    int *ret = (int*)calloc(sizeof(int),queriesSize);
    int rindex = 0;
    int *cache = (int*)calloc(sizeof(int),numsSize);
    int cindex = 0;

    for(int i = 0;i < queriesSize;i++)
    {
        for(int j = 0;j < numsSize;j++)
        {
            cache[cindex++] = trim(nums[j],queries[i][1]);
        }
        qsort(cache,numsSize,sizeof(int),compare);

        ret[rindex++] = cache[queries[i][0]-1];

    }

    free(cache);
    *returnSize = queriesSize;

    return ret;
}


int main()
{
    char **nums = (char**)calloc(sizeof(char*),4);
    
    nums[0][] = {"102"};
    nums[1] = {"473"};
    nums[2] = {"251"};
    nums[3] = {"814"};

    int **queries = (int**)calloc(sizeof(int*),4);
    queries[0] = {1,1};
    queries[1] = {2,3};
    queries[2] = {4,2};
    queries[3] = {1,2};

    int retSize = 0;
    int queriesColSize = 2;

    int *ret = smallestTrimmedNumbers(nums,4,queries,4,&queriesColSize,&retSize);
    return 0;
}