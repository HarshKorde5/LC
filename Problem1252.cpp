/*
There is an m x n matrix that is initialized to all 0's. There is also a 2D array indices where each indices[i] = [ri, ci] represents a 0-indexed location to perform some increment operations on the matrix.

For each location indices[i], do both of the following:

Increment all the cells on row ri.
Increment all the cells on column ci.
Given m, n, and indices, return the number of odd-valued cells in the matrix after applying the increment to all locations in indices.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int oddCells(int m, int n, vector<vector<int>> &indices)
    {
        vector<int> r(m, 0);
        vector<int> c(n, 0);

        for (int i = 0; i < indices.size(); i++)
        {
            r[indices[i][0]]++;
            c[indices[i][1]]++;
        }

        int oddRows = 0;
        for (int i = 0; i < m; i++)
        {
            if (r[i] % 2 == 1)
            {
                oddRows++;
            }
        }

        int oddCols = 0;
        for (int i = 0; i < n; i++)
        {
            if (c[i] % 2 == 1)
            {
                oddCols++;
            }
        }

        int result = oddRows * n + oddCols * m - 2 * oddRows * oddCols;
        return result;
    }

    int oddCells_1(int m, int n, vector<vector<int>> &indices)
    {

        vector<vector<int>> matrix(m, vector<int>(n, 0));

        for (auto &x : indices)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[x[0]][j]++;
            }

            for (int i = 0; i < m; i++)
            {
                matrix[i][x[1]]++;
            }
        }

        int result = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] % 2 != 0)
                {
                    result++;
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> indices = {{0,1}, {1,1}};
    int m = 2;
    int n = 3;
    int ret = sol.oddCells(m,n,indices);
    cout<<"Total odd cells are : "<<ret<<endl;
    return 0;
}