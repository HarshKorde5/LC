/*
You are given a sorted array nums of n non-negative integers and an integer maximumBit. You want to perform the following query n times:

Find a non-negative integer k < 2maximumBit such that nums[0] XOR nums[1] XOR ... XOR nums[nums.length-1] XOR k is maximized. k is the answer to the ith query.
Remove the last element from the current array nums.
Return an array answer, where answer[i] is the answer to the ith query.
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> getMaximumXor1(vector<int>& nums, int maximumBit) 
    {
        int n = nums.size();
        vector<int> productArray(n);

        productArray[0] = nums[0];

        for(int i = 1;i < n;i++)
        {
            productArray[i] = productArray[i-1]^nums[i];
        }


        int mask = (1 << maximumBit) - 1;

        vector<int> result(n);
        for(int i = 0;i < n;i++)
        {
            
            result[i] = productArray[n-i-1] ^ mask;
        }

        return result;
    }

    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) 
    {
        int mask = (1 << maximumBit) - 1, n = nums.size();

        vector<int> res(n);

        for(int i = 0, curr = 0; i < n; i++) 
        {
            curr = curr ^ nums[i];

            res[n-i-1] = (~curr) & mask;
        }

        return res;
    }
};


int main()
{
    Solution s;
    vector<int> nums = {0,1,1,3};

    vector<int> ret = s.getMaximumXor(nums,2);

    for(int i = 0;i < nums.size();i++)
    {
        cout<<"\n"<<ret[i];
    }

    return 0;
}