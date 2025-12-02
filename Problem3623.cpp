/*
You are given a 2D integer array points, where points[i] = [xi, yi] represents the coordinates of the ith point on the Cartesian plane.

A horizontal trapezoid is a convex quadrilateral with at least one pair of horizontal sides (i.e. parallel to the x-axis). Two lines are parallel if and only if they have the same slope.

Return the number of unique horizontal trapezoids that can be formed by choosing any four distinct points from points.

Since the answer may be very large, return it modulo 109 + 7.


*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {

        unordered_map<int, int> pointMap;

        const int mod = 1e9 + 7;


        long long result = 0, sum = 0;

        for(auto& p : points){
            pointMap[p[1]]++;            
        }
        
        for(auto& [_, p] : pointMap){
            long long edge = (long long)p * (p - 1) / 2;
            result += edge * sum;
            sum += edge;
        }

        return result % mod;
    }
};

int main()
{
    Solution sobj;

    vector<vector<int>> points = {{1,0},{2,0},{3,0},{2,2},{3,2}};
    cout<<"Total trapezoids are : "<<sobj.countTrapezoids(points)<<endl;

    return 0;
}