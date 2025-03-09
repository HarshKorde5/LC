/*
There is a circle of red and blue tiles. You are given an array of integers colors and an integer k. The color of tile i is represented by colors[i]:

colors[i] == 0 means that tile i is red.
colors[i] == 1 means that tile i is blue.
An alternating group is every k contiguous tiles in the circle with alternating colors (each tile in the group except the first and last one has a different color from its left and right tiles).

Return the number of alternating groups.

Note that since colors represents a circle, the first and the last tiles are considered to be next to each other.


*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
    
            int n = colors.size();
            int result = 0;
            int size = n + k - 1;
    
            int alternatingElementsCount = 1;
            int lastColor = colors[0];
    
    
            for(int i = 1; i < size;i++){
    
                alternatingElementsCount = (lastColor == colors[i%n]) ? 1 : alternatingElementsCount + 1;
    
                if(alternatingElementsCount >= k){
                    result++;
                }
    
                lastColor = colors[i % n];
            }
    
    
            return result;
        }
};


int main(){
    Solution s;
    vector<int> colors = {0,1,0,1,0};
    int k = 3;
    cout<<s.numberOfAlternatingGroups(colors,k);


    return 0;
}