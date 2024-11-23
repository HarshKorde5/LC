
/*

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int row = matrix.size();

        for(int i = 0;i < row;i++)
        {
            for(int j = 0;j <= i;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }


        }

        for(int i = 0;i < row;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};

int main()
{

    vector<vecotr<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    Solution s;

    s.rotate(matrix);

    return 0;
}