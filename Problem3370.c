/*
You are given a positive number n.

Return the smallest number x greater than or equal to n, such that the binary representation of x contains only set bits
*/
#include<stdio.h>



/*
numbers which have all bits set are : 1, 3, 7, 15, ... and so on.
above numbers have binary representation as follows : 1, 11, 111, 1111, ...

What common pattern is observed in those numbers is the next number will be the 2 times current number plus 1 i.e. 2 * curr + 1
For ex : curr = 3, so next can be dervied using above formula as 2 * 3 + 1 = 7

We use this intitution to find the nearest number with all set bits after n.
*/
int smallestNumber(int n) {
    int x = 1;
    while(x < n){
        x = x * 2 + 1;
    }

    return x;
}

int main(){

    int n = 10;
    printf("Smallest/Nearest number after %d which has all set bits is : %d\n",n,smallestNumber(n));
    return 0;
}