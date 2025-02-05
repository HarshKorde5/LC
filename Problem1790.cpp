/*
You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.

Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.
*/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int firstIndexDiff = 0;
        int secondIndexDiff = 0;
        int numDiffs = 0;

        for(int i = 0;i < s1.size();i++){
            if(s1[i] != s2[i]){
                numDiffs++;

                if(numDiffs > 2){
                    return false;
                }else if(numDiffs == 1){
                    firstIndexDiff = i;
                }else{
                    secondIndexDiff = i;
                }
            }

        }


        

        return s1[firstIndexDiff] == s2[secondIndexDiff] && s1[secondIndexDiff] == s2[firstIndexDiff];
    }   
};

int main(){
    Solution s;
    string s1 = "bank",s2 = "kanb";

    cout<<s.areAlmostEqual(s1,s2);

    return 0;
}