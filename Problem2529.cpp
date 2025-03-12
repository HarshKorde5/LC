/*
Given an array nums sorted in non-decreasing order, return the maximum between the number of positive integers and the number of negative integers.

In other words, if the number of positive integers in nums is pos and the number of negative integers is neg, then return the maximum of pos and neg.
Note that 0 is neither positive nor negative.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
        // Return the first index where the value is equal to or greater than zero.
        int lowerBound(vector<int> &nums) {
            int start = 0, end = nums.size() - 1;
            int index = nums.size();
    
            while (start <= end) {
                int mid = (start + end) / 2;
    
                if (nums[mid] < 0) {
                    start = mid + 1;
                } else if (nums[mid] >= 0) {
                    end = mid - 1;
                    index = mid;
                }
            }
    
            return index;
        }
    
        // Return the first index where the value is greater than zero.
        int upperBound(vector<int> &nums) {
            int start = 0, end = nums.size() - 1;
            int index = nums.size();
    
            while (start <= end) {
                int mid = (start + end) / 2;
    
                if (nums[mid] <= 0) {
                    start = mid + 1;
                } else if (nums[mid] > 0) {
                    end = mid - 1;
                    index = mid;
                }
            }
    
            return index;
        }
    
    public:
        int maximumCount(vector<int> &nums) {
            // All integers from the first non-zero to last will be positive
            // integers.
            int positiveCount = nums.size() - upperBound(nums);
            // All integers from the index 0 to index before the first zero index
            // will be negative.
            int negativeCount = lowerBound(nums);
    
            return max(positiveCount, negativeCount);
        }
};

int main(){
    Solution s;
    vector<int> array = {-3,-2,-1,0,0,1,2};
    cout<<s.maximumCount(array);
    return 0;
}