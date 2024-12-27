/*
You are given an integer array values where values[i] represents the value of the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i between them.

The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.

Return the maximum score of a pair of sightseeing spots.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    ///////////////////////////////////////////////////////////////
    //  Brute Force : TLE
    ///////////////////////////////////////////////////////////////
    int maxScoreSightseeingPair1(vector<int>& values) {
        int maxScore = 0;

        for(int i = 0;i < values.size();i++)
        {
            for(int j = i + 1;j < values.size();j++)
            {
                int value = (values[i] + i)+(values[j] - j);
                maxScore = value > maxScore ? value : maxScore;
            }
        }

        return maxScore;
    }

    ///////////////////////////////////////////////////////////////////////
    //  Running sum of values[i] + i and adding it to current value[j] - j
    //  Keep mainting maximum values : O(n)
    ///////////////////////////////////////////////////////////////////////
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0;
        int prev = values[0];

        for(int j = 1;j < values.size();j++)
        {
            ans = (values[j] - j  + prev) > ans ? (values[j] - j + prev) : ans; 

            prev = (values[j] + j) > prev ? values[j] + j : prev;
        }

        return ans;
    }

};

int main()
{
    vector<int> values = {8,1,5,2,6};
    Solution s;

    cout<<s.maxScoreSightseeingPair(values);
    return 0;
}