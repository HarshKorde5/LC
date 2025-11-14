/*
You are given a positive integer n, indicating that we initially have an n x n 0-indexed integer matrix mat filled with zeroes.

You are also given a 2D integer array query. For each query[i] = [row1i, col1i, row2i, col2i], you should do the following operation:

Add 1 to every element in the submatrix with the top left corner (row1i, col1i) and the bottom right corner (row2i, col2i). That is, add 1 to mat[x][y] for all row1i <= x <= row2i and col1i <= y <= col2i.
Return the matrix mat after performing every query.
*/

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> rangeAddQueries_1(int n, vector<vector<int>>& queries) {

        vector<vector<int>> result(n, vector<int>(n,0));

        for(auto& q : queries){
            int r1 = q[0];
            int c1 = q[1];
            int r2 = q[2];
            int c2 = q[3];

            for(int i = r1; i <= r2; i++){
                for(int j =c1; j <= c2; j++ ){
                    result[i][j]++;
                }
            }
        }


        return result;
    }

    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> matrix(n, vector<int>(n,0));

        for(auto& q : queries){
            int r1 = q[0];
            int c1 = q[1];
            int r2 = q[2];
            int c2 = q[3];

            matrix[r1][c1] += 1;

            if (r2+1 < n){
                matrix[r2 + 1][c1] -= 1;
            }

            if(c2 + 1 < n){
                matrix[r1][c2+1] -= 1;
            }

            if(r2 + 1 < n && c2 + 1 < n){
                matrix[r2+1][c2+1] += 1;
            }
        }


        for(int i = 0; i < n; i++){
            for(int j = 1; j < n; j++){
                matrix[i][j] += matrix[i][j - 1];
            }
        }

        for(int j = 0; j < n; j++){
            for(int i = 1; i < n; i++){
                matrix[i][j] += matrix[i - 1][j];
            }
        }


        return matrix;
    }
};


int main(){
    Solution sol;

    int n = 5;

    vector<vector<int>> queries = {{1,1,3,3}, {2,2,4,4}};

    vector<vector<int>> ret = sol.rangeAddQueries(n,queries);


    cout<<"Result matrix after operations is : "<<endl;
    for(auto& row : ret){
        for(auto& cell : row){
            cout<<cell<<" ";
        }
        cout<<endl;
    }


    return 0;
}