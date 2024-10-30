/*
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it

*/

#include<stdio.h>
#include<stdlib.h>

int* getRow(int rowIndex, int* returnSize)
{
    *returnSize = rowIndex + 1;

    int* row = (int*)malloc(*returnSize * sizeof(int));

    for (int i = 0; i <= rowIndex; i++)
    {
        row[i] = 1;
        for (int j = i - 1; j > 0; j--)
        {
            row[j] = row[j] + row[j - 1];
        }
    }

    return row;
}

int main()
{

    return 0;
}