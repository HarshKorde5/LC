/*
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include<stdio.h>
#include<stdlib.h>

int* countBits1(int n, int* returnSize) {
    int *ret = (int*)malloc(sizeof(int)*(n+1));
    *returnSize = n+1;

    int i = 0,k = 0;

    for(i = 0;i <= n;i++){
        int sum = 0;
        int num = i;

        while(num != 0){
            sum += num % 2;
            num = num/2;
        }

        ret[k++] = sum;
    }

    return ret;
}

int* countBits(int n, int* returnSize) {

    int *ret = (int*)malloc(sizeof(int)*(n+1));
    *returnSize = n+1;

    ret[0] = 0;

    for(int i = 1;i <= n;i++){
        ret[i] = ret[i / 2] + (i % 2);
    }

    return ret;
}

int main(){
    int k = 0;

    int *ret = countBits(5,&k);

    for(int i = 0;i < k;i++){
        printf("%d\n",ret[i]);
    }
    return 0;
}