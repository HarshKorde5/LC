

/*
You are given an m x n matrix of characters box representing a side-view of a box. Each cell of the box is one of the following:

A stone '#'
A stationary obstacle '*'
Empty '.'
The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions.

It is guaranteed that each stone in box rests on an obstacle, another stone, or the bottom of the box.

Return an n x m matrix representing the box after the rotation described above.

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution 
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) 
    {
        int m = box.size();
        int n = box[0].size();

        vector<vector<char>> rotatedBox(n,vector<char>(m,'.'));

        for(int i = 0;i < m;i++)
        {
            int currEmptyCell = n - 1;

            for(int j = n - 1;j >= 0;j--)
            {
                if(box[i][j] == '#')
                {
                    rotatedBox[currEmptyCell][m - i - 1] = '#';
                    // rotatedBox[i][j] = '.';

                    currEmptyCell--;
                }


                if(box[i][j] == '*')
                {
                    rotatedBox[j][m - i - 1] = '*';
                    currEmptyCell = j - 1;
                }
            }
        }

        return rotatedBox;
    }
};

int main()
{
    vector<vector<char>> box = {{'#','#','*','.','*','.'},
              {'#','#','#','*','.','.'},
              {'#','#','#','.','#','.'}};


    Solution s;

    vector<vector<char>> ret = s.rotateTheBox(box);


    return 0;
}