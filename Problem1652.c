/*
You have a bomb to defuse, and your time is running out! Your informer will provide you with a circular array code of length of n and a key k.

To decrypt the code, you must replace every number. All the numbers are replaced simultaneously.

If k > 0, replace the ith number with the sum of the next k numbers.
If k < 0, replace the ith number with the sum of the previous k numbers.
If k == 0, replace the ith number with 0.
As code is circular, the next element of code[n-1] is code[0], and the previous element of code[0] is code[n-1].

Given the circular array code and an integer key k, return the decrypted code to defuse the bomb!
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include<stdio.h>
#include<stdlib.h>

int* decrypt(int* code, int codeSize, int k, int* returnSize)
{
    int *ret = calloc(sizeof(int),codeSize);
    *returnSize = codeSize;
    if(k == 0)
    {
        return ret;
    }

    int i = 0,j = 0,sum = 0;

    if(k > 0)
    {
        for(i = 0;i < codeSize;i++)
        {
            j = i + 1;
            sum = 0;
            while(j <= i + k)
            {
                sum += code[(j % codeSize)];
                j++;
            }
            ret[i] = sum;
        }
    }
    else    
    {

        for(i = 0;i < codeSize;i++)
        {
            j = 1;
            sum = 0;

            for(j = 1;j <= -k;j++)
            {
                sum += code[((i + codeSize - j )% codeSize)];
            }
            ret[i] = sum;
        }
    }

    return ret;
}

int main()
{

    int code[] = {2,4,9,3};
    int retsize = 0;
    int *ret = decrypt(code,4,-2,&retsize);

    for(int i = 0;i < 4;i++)
    {
        printf("%d\n",ret[i]);
    }

    free(ret);
    return 0;
}