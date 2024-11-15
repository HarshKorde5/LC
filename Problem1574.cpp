
/*
Given an integer array arr, remove a subarray (can be empty) from arr such that the remaining elements in arr are non-decreasing.

Return the length of the shortest subarray to remove.

A subarray is a contiguous subsequence of the array.
*/


#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        int findLengthOfShortestSubarray(vector<int>& arr) 
        {
            int start = 0;

            int n = arr.size();

            while(start < n - 1 && arr[start] <= arr[start + 1])
            {
                start++;
            }

            if(start == n-1)   return 0;

            int end = n - 1;

            while(end > 0 && arr[end - 1] <= arr[end])
            {
                end--;
            }


            int result = min(n -start-1, end);

            int i = 0,j = end;
            while(i <= start && j < n)
            {
                if(arr[i] <= arr[j])
                {
                    result = min(result,j-i-1);
                    i++;
                }
                else
                {
                    j++;
                }
            }

            return result;
        }
};


int main()
{
    Solution s;
    
    vector<int> nums = {1,2,3,10,4,2,3,5};

    cout<<s.findLengthOfShortestSubarray(nums);

    return 0;
}