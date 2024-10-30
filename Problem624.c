/*
You are given m arrays, where each array is sorted in ascending order.

You can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a - b|.

Return the maximum distance.
*/


#include<stdio.h>
#include<stdlib.h>

int maxDistance(int** arrays, int arraysSize, int* arraysColSize)
{
    int allMax = arrays[0][arraysColSize[0]-1];
    int allMin = arrays[0][0];
    int maxDist = 0;

    for(int i = 1;i < arraysSize;i++)
    {
        int max = arrays[i][arraysColSize[i]-1];
        int min = arrays[i][0];

        int dist1 = max - allMin;
        int dist2 = allMax - min;

        //maxDist = (dist1 > maxDist) ? dist1 : (dist2 > maxDist) ? dist2 : maxDist;

        if(dist1 > maxDist)
        {
            maxDist = dist1;
        }

        if(dist2 > maxDist)
        {
            maxDist = dist2;
        }


        if(min < allMin)
        {
            allMin = min;
        }
        if(max > allMax)
        {
            allMax = max;
        }
    }

    return maxDist;

}

int main()
{
    int **arr = (int**)calloc(sizeof(int*),3);

    int arr[0] = (int*)calloc(sizeof(int),3);
    int arr[1] = (int*)calloc(sizeof(int),2);
    int arr[2] = (int*)calloc(sizeof(int),3);

    arr[0][0] = 1;
    arr[0][1] = 2;
    arr[0][2] = 3;

    arr[1][0] = 4;
    arr[1][2] = 5;

    arr[2][0] = 1;
    arr[2][1] = 2;
    arr[2][2] = 3;

    int colSize[3] = {3,2,3};

    printf("%d\n",maxDistance(arr,3,colSize));

    free(arr);

    return 0;
}