/*
You have n computers. You are given the integer n and a 0-indexed integer array batteries where the ith battery can run a computer for batteries[i] minutes. You are interested in running all n computers simultaneously using the given batteries.

Initially, you can insert at most one battery into each computer. After that and at any integer time moment, you can remove a battery from a computer and insert another battery any number of times. The inserted battery can be a totally new battery or a battery from another computer. You may assume that the removing and inserting processes take no time.

Note that the batteries cannot be recharged.

Return the maximum number of minutes you can run all the n computers simultaneously.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxRunTime(int n, vector<int> &batteries)
    {
        long long left = 0, right = accumulate(begin(batteries), end(batteries), 0LL) / n;

        while (left < right)
        {
            long long mid = (left + right + 1) / 2, hours = 0;
            for (int b : batteries)
            {
                hours += min((long long)b, mid);
            }
            if (hours >= n * mid)
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }
};

int main()
{
    Solution sobj;

    vector<int> batteries = {8, 4, 6, 3, 5, 10};
    int n = 3;

    int ret = sobj.maxRunTime(n, batteries);

    cout<<"Total simultaneous runtime : "<<ret<<" hours\n";

}