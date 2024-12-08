/*
Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

*/


#include<stdio.h>
#include<stdbool.h>

bool isPowerOfTwo1(int n) 
{

    return n > 0 && (n & (n - 1)) == 0;         //A power of two in binary has only one 1 and the rest 0s.
                                                //( n ) & ( (n - 1) ) should be 0 because subtracting 1 flips all bits after the rightmost 1
    
}

bool isPowerOfTwo(int n) 
{

    if(n <= 0)  return false;

    while(n % 2 == 0) 
    {
        n /= 2;
    }

    return n == 1;
    
}

int main()
{

    printf("%d\n",isPowerOfTwo(3));

    return 0;
}