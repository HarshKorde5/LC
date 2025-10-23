/*
You are given a string s consisting of digits. Perform the following operation repeatedly until the string has exactly two digits:

For each pair of consecutive digits in s, starting from the first digit, calculate a new digit as the sum of the two digits modulo 10.
Replace s with the sequence of newly calculated digits, maintaining the order in which they are computed.
Return true if the final two digits in s are the same; otherwise, return false.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.length();

        for(int i = 1; i <= n -2; i++){
            for(int j = 0; j <= n - 1 - i; j++){
                s[j] = ((s[j] - '0') + (s[j + 1] - '0')) % 10 + '0';
            }
        }

        return s[0] == s[1];
    }
};

int main(){

    string s = "3902";
    Solution sobj;

    cout<<"Result "<<sobj.hasSameDigits(s);

    return 0;
}