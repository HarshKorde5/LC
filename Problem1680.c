/*
Given an integer n, return the decimal value of the binary string formed by concatenating the binary representations of 1 to n in order, modulo 109 + 7.
*/

#include <stdio.h>

#define MOD 1000000007

int concatenatedBinary(int n)
{
    long len = 0;
    long long ans = 0;

    for (long i = 1; i <= n; i++)
    {
        if ((i & (i - 1)) == 0)
        {
            len++;
        }

        ans = (ans << len) % MOD;

        ans = (ans + i) % MOD;
    }

    return (int)ans;
}

int main()
{

    printf("Result :: %d\n", concatenatedBinary(12));
    return 0;
}