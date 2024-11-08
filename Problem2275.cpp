/*
The bitwise AND of an array nums is the bitwise AND of all integers in nums.

For example, for nums = [1, 5, 3], the bitwise AND is equal to 1 & 5 & 3 = 1.
Also, for nums = [7], the bitwise AND is 7.
You are given an array of positive integers candidates. Evaluate the bitwise AND of every combination of numbers of candidates. Each number in candidates may only be used once in each combination.

Return the size of the largest combination of candidates with a bitwise AND greater than 0.



*/


#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& candidates) 
    {
        int i = 0,n = candidates.size();
        vector<int> bitCount(24);

        for(int no : candidates)
        {
            for(i = 0;i < 24;i++)
            {
                if((no & (1 << i))!= 0)
                {
                    bitCount[i]++;
                }
            }
        }

        return *max_element(bitCount.begin(),bitCount.end());
    }
};


int main()
{
    vector<int> nums = {16,17,71,62,12,24,14};
    Solution s;
    cout<<s.largestCombination(nums);
    return 0;
}

