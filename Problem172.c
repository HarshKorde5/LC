/*
Given an integer n, return the number of trailing zeroes in n!.

Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.


*/

#include<stdio.h>

int trailingZeroes(int n) 
{
    int ret = 0;

    //number of trailing zeros in n! is number of 5's in n!
    //25/5 is 5 but also 25 is 5x5 i.e 2 5's so add more 2 5's and so on
    while(n != 0)
    {
        ret = ret + n/5;
        n = n/5;
    }

    return ret;
    
}

int main()
{

    printf("%d\n",trailingZeroes(125));
    return 0;
}