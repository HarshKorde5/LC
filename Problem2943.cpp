/*
You are given the two integers, n and m and two integer arrays, hBars and vBars. The grid has n + 2 horizontal and m + 2 vertical bars, creating 1 x 1 unit cells. The bars are indexed starting from 1.

You can remove some of the bars in hBars from horizontal bars and some of the bars in vBars from vertical bars. Note that other bars are fixed and cannot be removed.

Return an integer denoting the maximum area of a square-shaped hole in the grid, after removing some bars (possibly none).
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getMaxGap(vector<int> &bars)
    {
        sort(bars.begin(), bars.end());
        int count = 2, res = 2;
        for (int i = 1; i < bars.size(); i++)
        {
            count = (bars[i - 1] + 1 == bars[i]) ? count + 1 : 2;
            res = max(count, res);
        }

        return res;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int> &hBars, vector<int> &vBars)
    {
        int gap = min(getMaxGap(hBars), getMaxGap(vBars));
        return gap * gap;
    }
};

int main()
{
    int n = 2, m = 3;
    vector<int> hBars = {2, 3}, vBars = {2, 4};

    Solution sobj;

    int ret = sobj.maximizeSquareHoleArea(n, m, hBars, vBars);
    cout << "Maximum square area is : " << ret << endl;

    return 0;
}