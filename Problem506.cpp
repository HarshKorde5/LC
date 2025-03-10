/*
You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. All the scores are guaranteed to be unique.

The athletes are placed based on their scores, where the 1st place athlete has the highest score, the 2nd place athlete has the 2nd highest score, and so on. The placement of each athlete determines their rank:

The 1st place athlete's rank is "Gold Medal".
The 2nd place athlete's rank is "Silver Medal".
The 3rd place athlete's rank is "Bronze Medal".
For the 4th place to the nth place athlete, their rank is their placement number (i.e., the xth place athlete's rank is "x").
Return an array answer of size n where answer[i] is the rank of the ith athlete.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<string> findRelativeRanks(vector<int>& score) {
            int N = score.size();
            vector<int> scoreCopy(N);
            copy(score.begin(), score.end(), scoreCopy.begin());
            
            // Save the index of each athlete
            unordered_map<int, int> scoreToIndex;
            for (int i = 0; i < N; i++) {
                scoreToIndex[scoreCopy[i]] = i;
            }
            
            // Sort scoreCopy in descending order
            sort(scoreCopy.begin(), scoreCopy.end(), greater<int>());
    
            // Assign ranks to athletes
            vector<string> rank(N);
            for (int i = 0; i < N; i++) {
                if (i == 0) {
                    rank[scoreToIndex[scoreCopy[i]]] = "Gold Medal";
                } else if (i == 1) {
                    rank[scoreToIndex[scoreCopy[i]]] = "Silver Medal";
                } else if (i == 2) {
                    rank[scoreToIndex[scoreCopy[i]]] = "Bronze Medal";
                } else {
                    rank[scoreToIndex[scoreCopy[i]]] = to_string(i + 1);
                }
            }
            
            return rank;
        }
};

int main(){
    Solution s;
    vector<int> score = {10,3,8,9,4};
    vector<string> ret = s.findRelativeRanks(score);
    for(int i = 0;i < ret.size();i++){
        cout<<ret[i]<<"\n";
    }
    return 0;
}