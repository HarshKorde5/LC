/*
Given two integer arrays nums1 and nums2, return an array of their 
intersection
. Each element in the result must be unique and you may return the result in any order.
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    int k = 0;
    bool *intersect = calloc(1001, sizeof(bool));

    for (int i = 0; i < nums1Size; i++) {
        intersect[nums1[i]] = true;
    }
    for(int i = 0; i < nums2Size; i++){
        if(intersect[nums2[i]] == true){
            nums1[k++] = nums2[i];
            intersect[nums2[i]] = false;
        }
    }
    free(intersect);
    *returnSize = k;
    return nums1;    
}

int main()
{
    int nums1[4] = {1,2,2,1};
    int nums2[2] = {2,2};
    int retsize = 0;
    int iRet[] = intersect(nums1,4,nums2,2,&retsize);

    return 0;
}