/*
There are n kids with candies. You are given an integer array candies, where each candies[i] represents the number of candies the ith kid has, and an integer extraCandies, denoting the number of extra candies that you have.

Return a boolean array result of length n, where result[i] is true if, after giving the ith kid all the extraCandies, they will have the greatest number of candies among all the kids, or false otherwise.

Note that multiple kids can have the greatest number of candies.
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    int i = 0,max = candies[0];

    for(i = 1;i < candiesSize;i++){

        max = candies[i] > max ? candies[i] : max;
    }

    bool *ret = (bool*)calloc(sizeof(bool),candiesSize);
    *returnSize = candiesSize;

    for(i = 0;i < candiesSize;i++){
        ret[i] = (candies[i] + extraCandies) >= max ? true : false;
    }

    return ret;
}

int main(){

    int candies[] = {2,3,5,1,3};
    int candiesSize = 5;
    int extraCandies = 3;
    int returnSize = 0;
    int i = 0;
    bool *ret = kidsWithCandies(candies,candiesSize,extraCandies,&returnSize);
    for(i = 0;i < returnSize;i++){

        printf("%d\t",ret[i]);
    }

    printf("\n");
    return 0;
}