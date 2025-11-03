/*
Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.

Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, so she asks Bob for help. Bob can remove some balloons from the rope to make it colorful. You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) that Bob needs to remove the ith balloon from the rope.

Return the minimum time Bob needs to make the rope colorful.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int timeRequired = 0;
        int n = colors.size();
        int i = 0, j = 0;
        while(i < n){

            j = i + 1;
            int currSum = neededTime[i], currMax = neededTime[i];

            while(j < n && colors[i] == colors[j]){
                currSum += neededTime[j];
                currMax = (currMax > neededTime[j]) ? currMax : neededTime[j];
                j++;
            }

            timeRequired += (currSum - currMax);
            i = j;

        }

        return timeRequired;
    }
};

int main(){
    string colors = "abaac";
    vector<int> neededTime = {1,2,3,4,5};

    Solution sobj;
    cout<<"Minimum time required to make string colorful is : "<<sobj.minCost(colors, neededTime)<<endl;



    return 0;
}