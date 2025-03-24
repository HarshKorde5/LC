/*
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isSubsequence(string s, string t) {
            int sp = 0;
            int tp = 0;
    
            while (sp < s.length() && tp < t.length()) {
                if (s[sp] == t[tp]) {
                    sp++;
                }
                tp++;
            }
    
            return sp == s.length();        
        }
};

int main(){
    string str = {"axc"};
    string t = {"ahbgdc"};

    Solution s;
    cout<<s.isSubsequence(str,t);

    return 0;
}