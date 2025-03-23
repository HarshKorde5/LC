/*
Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.

Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].

For example, swapping at indices 0 and 2 in "abcd" results in "cbad".
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = s.length();
        
        if(goal.length() != n){
            return false;
        }

        if(s == goal){
            set<char> temp(s.begin(), s.end());
            return temp.size() < goal.size(); // Swapping same characters
        }

        int i = 0;
        int j = n - 1;

        while(i < j && s[i] == goal[i]){
            i++;
        }

        while(j >= 0 && s[j] == goal[j]){
            j--;
        }

        if(i < j){
            swap(s[i], s[j]);
        }

        return s == goal;
    }
};

int main(){

    Solution s;
    string str = {"ab"};
    string goal = {"ab"};
    cout<<s.buddyStrings(str,goal);
    return 0;
}