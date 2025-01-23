
/*
You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.

Return the number of servers that communicate with any other server.
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //////////////////////////////////////////////////////////////
    //  Brute Force : O(m.n.(m+n))
    //////////////////////////////////////////////////////////////
    int countServers1(vector<vector<int>>& grid) {

        const int m = grid.size(),n = grid[0].size();

        int result = 0;

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){

                if(grid[i][j] == 1){

                    bool flag = false;

                    for(int k = 0;k < n;k++){
                        if(k != j && grid[i][k] == 1){
                            flag = true;
                            break;
                        }
                    }

                    if(flag){
                        result++;
                    }else{
                        for(int k = 0;k < m;k++){
                            if(k != i && grid[k][j] == 1){
                                flag = true;
                                break;
                            }
                        }

                        if(flag){
                            result++;
                        }
                    }

                }

            }
        }
        return result;
    }

    ///////////////////////////////////////////////////////////////
    // Track using two arrays
    ///////////////////////////////////////////////////////////////
    int countServers(vector<vector<int>>& grid) {
        vector<int> row(size(grid[0]),0), col(size(grid),0);

        for(int i = 0;i < size(grid);i++){
            for(int j = 0;j < size(grid[0]);j++){
                if(grid[i][j]){
                    row[j]++;
                    col[i]++;
                }
            }
        }

        int result = 0;

        for(int i = 0;i < size(grid);i++){
            for(int j = 0;j < size(grid[0]);j++){
                if(grid[i][j]){
                    result +=  row[j] > 1 || col[i] > 1;
                }
            }
        }

        return result;


    }
};

int main(){
    vector<vector<int>> grid = {{{1,1,0,0},{0,0,1,0},{0,0,1,0},{0,0,0,1}}};
    Solution s;
    cout<<s.countServers(grid);
    return 0;
}