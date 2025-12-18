/*
You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.

A row i is weaker than a row j if one of the following is true:

The number of soldiers in row i is less than the number of soldiers in row j.
Both rows have the same number of soldiers and i < j.
Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> res;
        int n = mat.size();

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == 1) {
                    sum++;
                }
            }
            res.push_back({sum, i});
        }

        sort(res.begin(), res.end());

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(res[i].second);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> mat = {
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 1}
    };

    int k = 3;

    vector<int> result = sol.kWeakestRows(mat, k);

    cout << "The " << k << " weakest rows are: ";
    for (int idx : result) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}
