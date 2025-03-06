/*

You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2]. Each integer appears exactly once except a which appears twice and b which is missing. The task is to find the repeating and missing numbers a and b.

Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.

 
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            int n = grid.size();
            long long sum_n = (long long)n * n * (n * n + 1) / 2;
            long long sum_squares = (long long)n * n * (n * n + 1) * (2 * n * n + 1) / 6;
            long long grid_sum = 0, grid_sum_squares = 0;
    
            for (const auto& row : grid) {
                for (int num : row) {
                    grid_sum += num;
                    grid_sum_squares += (long long)num * num;
                }
            }
    
            long long diff_sum = grid_sum - sum_n;
            long long diff_sum_squares = grid_sum_squares - sum_squares; 
            long long sum_ab = diff_sum_squares / diff_sum;
    
            int a = (diff_sum + sum_ab) / 2;
            int b = (sum_ab - diff_sum) / 2; 
    
            return {a, b}; 
        }


        vector<int> findMissingAndRepeatedValues1(vector<vector<int>>& grid) {
            int n = grid.size();
            int missing = -1, repeat = -1;
    
            // Store frequency of each number in the grid
            unordered_map<int, int> freq;
            for (auto& row : grid) {
                for (int num : row) {
                    freq[num]++;
                }
            }
    
            // Check numbers from 1 to n^2 to find missing and repeated values
            for (int num = 1; num <= n * n; num++) {
                if (!freq.count(num)) {
                    missing = num;  // Number not present in grid
                } else if (freq[num] == 2) {
                    repeat = num;  // Number appears twice
                }
            }
    
            return {repeat, missing};
        }
};

int main(){

    Solution s;

    vector<vector<int>> grid = {{9,1,7},{8,9,2},{3,4,6}};
    vector<int> ret = s.findMissingAndRepeatedValues(grid);
    
    return 0;
}