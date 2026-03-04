/*
Given an m x n binary matrix mat, return the number of special positions in mat.

A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<int> rows(mat.size()), cols(mat[0].size());

        for(int i = 0; i < rows.size(); i++){
            for(int j = 0; j < cols.size(); j++){
                if(mat[i][j]){
                    rows[i]++;
                    cols[j]++;                    
                }
            }
        }

        int res = 0;
        for(int i = 0; i < rows.size(); i++){
            for(int j = 0; j < cols.size(); j++){
                if(mat[i][j] && rows[i] == 1 && cols[j] == 1){
                    res++;
                }
            }
        }

        return res;
    }
};

int main() {

    vector<vector<int>> mat = {
        {1,0,0},
        {0,0,1},
        {1,0,0}
    };

    Solution obj;
    int result = obj.numSpecial(mat);

    cout << "Number of special positions: " << result << endl;

    return 0;
}