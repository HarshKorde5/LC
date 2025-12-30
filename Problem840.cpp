/*
A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

Given a row x col grid of integers, how many 3 x 3 magic square subgrids are there?

Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        int ans = 0;
        for (int row = 0; row + 2 < grid.size(); row++)
        {
            for (int col = 0; col + 2 < grid[row].size(); col++)
            {

                if (isMagicSquare(grid, row, col))
                {
                    ans++;
                }
            }
        }
        return ans;
    }

    bool isMagicSquare(vector<vector<int>> &grid, int row, int col)
    {

        bool seen[10] = {false};
        // check if elements are between 0-9
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int num = grid[row + i][col + j];

                if (num < 1 || num > 9)
                {
                    return false;
                }

                if (seen[num])
                {
                    return false;
                }

                seen[num] = true;
            }
        }

        // check if diagonal sums are equal
        int diagonal_1 = grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
        int diagonal_2 = grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col];

        if (diagonal_1 != diagonal_2)
        {
            return false;
        }

        // check if all rowSums are equal
        int rowSum = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                rowSum += grid[row + i][col + j];
            }
            if (rowSum != diagonal_1)
            {
                return false;
            }
            rowSum = 0;
        }

        // check if all colSum are equal
        int colSum = 0;
        for (int j = 0; j < 3; j++)
        {
            for (int i = 0; i < 3; i++)
            {
                colSum += grid[row + i][col + j];
            }
            if (colSum != diagonal_1)
            {
                return false;
            }

            colSum = 0;
        }

        return true;
    }
};

int main()
{
    vector<vector<int>> grid = {{4, 3, 8, 4}, {9, 5, 1, 9}, {2, 7, 6, 2}};
    Solution sobj;

    cout << "Count of valid magic subgrids is : " << sobj.numMagicSquaresInside(grid) << endl;
    return 0;
}