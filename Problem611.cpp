/*
Valid Triangle Number

Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{

private:

    int binarySearch(vector<int> nums, int l, int r, int x){
        while(l <= r && r < nums.size()){
            int mid = (l + r) / 2;

            if( nums[mid] >= x){
                r = mid - 1;
            }else{
                l = mid + 1;
            }

        }

        return l;
    }

public:
    // Brute Force : O(n^3)
    int triangleNumber_1(vector<int> &nums)
    {

        int count = 0;

        for (int i = 0; i < nums.size() - 2; i++)
        {
            for (int j = i + 1; j < nums.size() - 1; j++)
            {
                for (int k = j + 1; k < nums.size(); k++)
                {
                    if (

                        nums[i] + nums[j] > nums[k] &&
                        nums[j] + nums[k] > nums[i] &&
                        nums[i] + nums[k] > nums[j])
                    {
                        count++;
                    }
                }
            }
        }

        return count;
    }

    // Binary search : O(n^2 logn)
    int triangleNumber(vector<int> &nums)
    {

        int count = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++)
        {
            int k = i + 2;

            for (int j = i + 1; j < n - 1 && nums[i] != 0; j++)
            {
                k = binarySearch(nums, k, n - 1, nums[i] + nums[j]);
                count += k - j - 1;
            }
        }

        return count;
    }
};

int main()
{

    vector<int> nums = {2, 2, 3, 4};

    Solution sobj;

    int result = sobj.triangleNumber(nums);

    cout << "Total valid triangles are : " << result << "\n";

    return 0;
}