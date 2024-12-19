/*
You are given an integer array arr of length n that represents a permutation of the integers in the range [0, n - 1].

We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.

Return the largest number of chunks we can make to sort the array.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) 
    {
        int n = arr.size();
        int chunks = 0,prefixSum = 0,sortedPrefixSum = 0;

        for(int i = 0;i < n;i++)
        {
            sortedPrefixSum += i;
            prefixSum += arr[i];

            if(prefixSum == sortedPrefixSum)
            {
                chunks++;
            }
        }

        return chunks;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,0,2,3,4};

    cout<<s.maxChunksToSorted(nums);

    return 0;
}