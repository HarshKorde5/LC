
/*
Given a 2D integer array matrix, return the transpose of matrix.

The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) 
    {
        const int m = matrix.size();
        const int n = matrix[0].size();

        vector<vector<int>> result(n,vector<int>(m,0));
        
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                result[j][i] = matrix[i][j];
            }
        }

        return result;

    }
};


int main()
{

    vector<vector<int>> matrix = {{1,2,3},{4,5,6}};

    Solution s;

    vector<vector<int>> ret = s.transpose(matrix);

    return 0;
}