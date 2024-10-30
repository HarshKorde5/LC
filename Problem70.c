/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

#include<stdio.h>

int climbStairs(int n) 
{
    int nums[2] = {1,1};
    for(int i = 2;i <= n;++i)
    {
        nums[i % 2] = nums[0] + nums[1];
    }
    return nums[n % 2];
}

int main()
{
    printf("%d\n",climbStairs(3));
    return 0;
}