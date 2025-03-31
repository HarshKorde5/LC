/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);

*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string convert(string s, int numRows) {
            if (numRows == 1 || numRows >= s.length()) {
                return s;
            }
    
            int idx = 0, d = 1;
            vector<vector<char>> rows(numRows);
    
            for (char c : s) {
                rows[idx].push_back(c);
                if (idx == 0) {
                    d = 1;
                } else if (idx == numRows - 1) {
                    d = -1;
                }
                idx += d;
            }
    
            string result;
            for (const auto& row : rows) {
                for (char c : row) {
                    result += c;
                }
            }
    
            return result;   
    
        }
};


int main(){

    Solution s;
    string str = {"PAYPALISHIRING"};
    cout<<s.convert(str,4);
    return 0;
}