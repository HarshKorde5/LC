/*
In MATLAB, there is a handy function called reshape which can reshape an m x n matrix into a new one with a different size r x c keeping its original data.

You are given an m x n matrix mat and two integers r and c representing the number of rows and the number of columns of the wanted reshaped matrix.

The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the reshape operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();

        if(r*c != m*n) return mat;

        int x = 0, y = 0;

        vector<vector<int>> result(r, vector<int>(c));

        for(int i = 0;i < m*n; i++){
            result[i / c][i % c] = mat[i / n][i % n];
        }

        return result;
    }
};

int main(){

    Solution sobj;
    vector<vector<int>> mat = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12}
    };

    int r = 4, c = 3;

    cout << "Original matrix:\n";
    for (auto &row : mat) {
        for (auto &val : row)
            cout << val << " ";
        cout << endl;
    }

    vector<vector<int>> reshaped = sobj.matrixReshape(mat, r, c);

    cout << "\nReshaped matrix (" << r << "x" << c << "):\n";
    for (auto &row : reshaped) {
        for (auto &val : row)
            cout << val << " ";
        cout << endl;
    }
    
    return 0;
}

