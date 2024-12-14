/*
You are given a sorted unique integer array nums.

A range [a,b] is the set of all integers from a to b (inclusive).

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b

*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;

        if(nums.empty())   
        {
            return result;
        }

        int start = nums[0];

        for(int i = 1;i <= nums.size();i++)
        {
            if(i == nums.size() || nums[i] != nums[i-1]+1)
            {
                if(start == nums[i - 1])
                {
                    result.push_back(to_string(start));
                }
                else
                {
                    result.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
                }

                if(i < nums.size())
                {
                    start = nums[i];
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution s;

    vector<int> nums = {0,1,2,4,5,7};

    vector<string> ret = s.summaryRanges(nums);

    for(int i = 0;i < ret.size();i++)
    {
        cout<<ret[i]<<endl;
    }


    return 0;
}