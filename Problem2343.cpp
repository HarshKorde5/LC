/*
You are given a 0-indexed array of strings nums, where each string is of equal length and consists of only digits.

You are also given a 0-indexed 2D integer array queries where queries[i] = [ki, trimi]. For each queries[i], you need to:

Trim each number in nums to its rightmost trimi digits.
Determine the index of the kith smallest trimmed number in nums. If two trimmed numbers are equal, the number with the lower index is considered to be smaller.
Reset each number in nums to its original length.
Return an array answer of the same length as queries, where answer[i] is the answer to the ith query.

Note:

To trim to the rightmost x digits means to keep removing the leftmost digit, until only x digits remain.
Strings in nums may contain leading zeros.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> smallestTrimmedNumbers(vector<string>& nums,
                                           vector<vector<int>>& queries) {
            int n = nums.size();
            vector<int> ans;
    
            for (auto& query : queries) {
                int k = query[0], trimLen = query[1];
                vector<string> temp(n);
    
                for (int i = 0; i < n; i++) {
                    temp[i] = nums[i].substr(nums[i].size() - trimLen, trimLen);
                }
    
                vector<int> idx(n);
                for (int i = 0; i < n; i++)
                    idx[i] = i;
    
                sort(idx.begin(), idx.end(), [&](int i, int j) {
                    if (temp[i] == temp[j])
                        return i < j;
                    return temp[i] < temp[j];
                });
    
                ans.push_back(idx[k - 1]); // 1-based indexing for queries
            }
    
            return ans;
    }
};

int main(){
    vector<string> nums = {"102","473","251","814"};
    vector<vector<int>> queries = {{1,1},{2,3},{4,2},{1,2}};

    Solution s;

    vector<int> ret = s.smallestTrimmedNumbers(nums,queries);

    for(int i = 0;i < nums.size();i++){
        cout<<ret[i]<<"\t";
    }
    cout<<"\n";

    return 0;
}