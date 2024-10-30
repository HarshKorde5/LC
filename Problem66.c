#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) 
{
    int i = 0;
    bool flag = false;

    for(i = digitsSize-1;i >= 0;i--)
    {
        if(digits[i] == 9)
        {
    
            digits[i] = 0;
            if(i == 0)
            {
                flag = true;
            }
            continue;
        }
        else
        {
            digits[i] = digits[i] + 1;
            break;
        }
    }

    if(flag == true)
    {
        int * newArr = NULL;
        newArr = (int *)malloc(sizeof(int)*(digitsSize+1));
        newArr[0] = 1;
        *returnSize = digitsSize+1;
        return newArr;
    }
    else
    {
        *returnSize = digitsSize;
        return digits;
    }
}

int main()
{
    int digits[] = {1,1,1};
    int * ret = NULL;
    int retsize = 0;
    ret = plusOne(digits,3,&retsize);
    for(int i = 0;i < retsize;i++)
    {
        printf("%d\t",ret[i]);
    }
    return 0;
}