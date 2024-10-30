/*

Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.
*/


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* luckyNumbers (int** matrix, int matrixSize, int* matrixColSize, int* returnSize) 
{
    int minarr[matrixSize];
    int maxarr[*matrixColSize];
    for(int i = 0;i < matrixSize;i++)
    {
        int min = matrix[i][0];
        for(int j = 0;j < matrixColSize[0];j++)
        {
            if(matrix[i][j] < min)
            {
                min = matrix[i][j];
            }

        }
        minarr[i] = min;
    }

    for(int i = 0;i < matrixColSize[0];i++)
    {
        int max = matrix[0][i];
        for(int j = 0;j < matrixSize;j++)
        {
            if(matrix[j][i] > max)
            {
                max = matrix[j][i];
            }
        }
        maxarr[i] = max;
    }

    int max = *matrixColSize > matrixSize ? *matrixColSize : matrixSize;

    int *ret = (int*)malloc(sizeof(int)*max);
    int k = 0;

    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixColSize[0]; j++)
        {
            if (minarr[i] == maxarr[j])
            {
                ret[k++] = minarr[i];
            }
        }
    }
    *returnSize = k;
    return ret;
}

int main()
{
    return 0;
}