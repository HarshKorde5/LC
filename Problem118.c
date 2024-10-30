/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it.
*/

#include<stdio.h>
#include<stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes)
{
    int **res = (int**)malloc(numRows*sizeof(int*));

    *returnSize = numRows; 

    *returnColumnSizes = (int*)malloc(numRows*sizeof(int));

    for (int i = 0; i < numRows; i++)
    {
        (*returnColumnSizes)[i] = i+1;
    }

    res[0] = (int*)malloc(1*sizeof(int));

    res[0][0] = 1; 

    for (int i = 1; i < numRows; i++)
    {
        res[i] = (int*)malloc((i+1)*sizeof(int));
        for (int j = 0; j < i+1; j++)
        {
            if (j == 0)
            {
                res[i][j] = 1;
            }
            else if (j == i)
            {
                res[i][j] = 1;
            }
            else
            {
                res[i][j] = res[i-1][j-1] + res[i-1][j];
            }
        }
    }

    return res; 

}

int main()
{
    int **ret = NULL;
    int retSize;
    int *retColSize = NULL;

    ret = generate(5,&retSize,&retColSize);

    for(int i = 0;i < 5;i++)
    {
        for(int j = 0;j <= i;j++)
        {
            printf("%d\t",ret[i][j]);
        }
        printf("\n");
    }

    free(ret);
    free(retColSize);

    return 0;
}