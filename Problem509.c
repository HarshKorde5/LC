/*
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,
*/

#include<stdio.h>

//memoization
int fib(int n)
{
    static int cache[31] = {0};
    
    if(cache[n] != 0)
    {
        return cache[n];
    }
    if(n <= 1)
    {
        return n;
    }
    else
    {
        cache[n] = fib(n-1) + fib(n-2);
        return cache[n];
    }

}

//tabulation
int fib1(int n)
{
    int memo[31];
    memo[0] = 0,memo[1] = 1;

    for(int i = 2;i <= n;i++)
    {
        memo[i] = memo[i - 1] + memo[i - 2];
    }

    return memo[n];
}

int main()
{
    printf("%d\n",fib(5));
    return 0;
}