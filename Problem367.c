/*
Given a positive integer num, return true if num is a perfect square or false otherwise.

A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.

You must not use any built-in library function, such as sqrt.
*/

#include<stdio.h>
#include<stdbool.h>

bool isPerfectSquare(int num)
{
    long long high = num,low = 1,mid = 0;
    while(low <= high)
    {
        mid = (high + low)/2;

        if(mid*mid <= num)
        {
            low = mid+1;
        }
        else
        {
            high = mid -1;
        }
    }

    if(high*high == num)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    printf("%s\n",isPerfectSquare(16));
    return 0;
}