/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    ////////////////////////////////////////////////////////////////////////
    //  sorting solution 2
    ////////////////////////////////////////////////////////////////////////
    vector<vector<int>> merge(vector<vector<int>>& v) 
    {
        sort(v.begin(),v.end());

        vector<vector<int>> r;

        vector<int> prev = v[0];

        for(int i = 1;i < v.size();i++)
        {
            vector<int> temp = v[i];

            if(temp[0] <= prev[1])
            {
                prev[1] = max(temp[1],prev[1]);
            }
            else
            {
                r.push_back(prev);
                prev = temp;
            }
        }

        r.push_back(prev);
        return r;
    }

    /////////////////////////////////////////////////////////////////////////
    //  sorting solution 1
    ////////////////////////////////////////////////////////////////////////
    vector<vector<int>> merge1(vector<vector<int>>& intervals) 
    {

        vector<vector<int>> result;

        sort(intervals.begin(),intervals.end());

        for(int i = 0;i < intervals.size();i++)
        {
            
            if(result.empty() || result.back()[1] < intervals[i][0])
            {
                result.push_back(intervals[i]);
            }
            else
            {
                result.back()[1] = max(result.back()[1],intervals[i][1]);
            }
        }

        return result;
    }
};

int main()
{
    Solution s;

    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};

    vector<vector<int>> ret = s.merge(intervals);

    for(auto& i : ret)
    {
        cout<<i[0]<<","<<i[1]<<endl;
    }
    return 0;
}