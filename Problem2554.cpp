
/*
You are given an integer array banned and two integers n and maxSum. You are choosing some number of integers following the below rules:

The chosen integers have to be in the range [1, n].
Each integer can be chosen at most once.
The chosen integers should not be in the array banned.
The sum of the chosen integers should not exceed maxSum.
Return the maximum number of integers you can choose following the mentioned rules.
*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) 
    {
        unordered_set<int> bannedSet(banned.begin(),banned.end());

        int count = 0;


        for(int i = 1;i <= n;i++)
        {
            if(bannedSet.count(i))  continue;


            if(maxSum - i < 0)  return count;


            maxSum -= i;

            count++;
        }

        return count;
    }

    int maxCount1(vector<int>& banned, int n, int maxSum) 
    {
        int count = 0;
        int sum = 0;

        for(int i = 1;i <= n;i++)
        {
            if(find(banned.begin(),banned.end(),i) == banned.end())
            {
                sum += i;
                count++;
            }
            

            if(sum > maxSum)
            {
                count--;
                break;
            }
        }

        return count;
    }
};

int main()
{
    Solution s;

    vector<int> banned = {1,6,5};

    cout<<s.maxCount(banned,5,6);

    return 0;
}