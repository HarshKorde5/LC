/*
We are given a list nums of integers representing a list compressed with run-length encoding.

Consider each adjacent pair of elements [freq, val] = [nums[2*i], nums[2*i+1]] (with i >= 0).  For each such pair, there are freq elements with value val concatenated in a sublist. Concatenate all the sublists from left to right to generate the decompressed list.

Return the decompressed list.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> decompressRLElist(vector<int> &nums)
    {
        vector<int> res;
        for (int i = 0; i < nums.size(); i += 2)
        {
            int freq = nums[i];
            int val = nums[i + 1];

            while (freq--)
            {
                res.push_back(val);
            }
        }

        return res;
    }
};

int main()
{
    vector<int> nums = {1,2,3,4};
    Solution sol;
    vector<int> ret = sol.decompressRLElist(nums);

    cout<<"Decompressed list is :"<<endl;

    for(int x : ret){
        cout<<x<<endl;
    }

    return 0;
}