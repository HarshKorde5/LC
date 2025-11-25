/*
Given a positive integer k, you need to find the length of the smallest positive integer n such that n is divisible by k, and n only contains the digit 1.

Return the length of n. If there is no such n, return -1.

Note: n may not fit in a 64-bit signed integer.
*/
#include<stdio.h>

int smallestRepunitDivByK(int k) {
    if (k % 2 == 0 || k % 5 == 0) {
        return -1;
    }

    int r = 0;
    for (int l = 1; l < k+1; l++) {
        r = (r * 10 + 1) % k;
        if (r == 0) {
            return l;
        }
    }

    return -1;
}

int main(){

    int k = 7;

    int ret = smallestRepunitDivByK(k);

    printf("Smallest repeated unit of 1's divisible by %d is : ",k);
    for(int i = 1; i <= ret; i++){
        printf("1");
    }

    printf("\n");
    return 0;
}