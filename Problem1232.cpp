/*
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. 
Check if these points make a straight line in the XY plane
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool checkStraightLine(vector<vector<int>>& coordinates) {
            if(coordinates.size() <= 2) return true;
            int x1 = coordinates[0][0];
            int y1 = coordinates[0][1];
            int x2 = coordinates[1][0];
            int y2 = coordinates[1][1];
            for(int i=2;i<coordinates.size();i++){
                int x = coordinates[i][0];
                int y = coordinates[i][1];
                if((y2 - y1) * (x1 - x) != (y1 - y) * (x2 - x1))
                    return false;
            }
            return true;
        }
};

int main(){

    Solution s;
    vector<vector<int>> coordinates = {{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}};
    cout<<s.checkStraightLine(coordinates);
    return 0;
}
