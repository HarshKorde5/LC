/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int climbStairs(int n)
    {
        if (n == 0 || n == 1)
        {
            return 1;
        }

        int prev = 1, curr = 1;

        for (int i = 2; i <= n; i++)
        {
            int temp = curr;
            curr += prev;
            prev = temp;
        }

        return curr;
    }

private:
    // tabulation
    int climbStairs_3(int n)
    {
        if (n == 0 || n == 1)
        {
            return 1;
        }

        vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }

    // memoization
    int climbStairs(int n, unordered_map<int, int> &memo)
    {
        if (n == 0 || n == 1)
        {
            return 1;
        }

        if (memo.find(n) == memo.end())
        {
            memo[n] = climbStairs(n - 1, memo) + climbStairs(n - 2, memo);
        }

        return memo[n];
    }

    int climbStairs_2(int n)
    {
        unordered_map<int, int> memo;
        return climbStairs(n, memo);
    }

    // recurssive tle
    int climbStairs_1(int n)
    {
        if (n == 0 || n == 1)
        {
            return 1;
        }

        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

int main()
{

    Solution sobj;

    int n = 5;

    int ret = sobj.climbStairs(5);
    cout << ret << endl;

    return 0;
}