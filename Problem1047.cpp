/*
You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.


*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string removeDuplicates(string s) {
    int i = 0, n = s.length();
    for (int j = 0; j < n; ++j, ++i) {
        s[i] = s[j];
        if (i > 0 && s[i - 1] == s[i]) // count = 2
            i -= 2;
    }
    return s.substr(0, i);
}

int main(){

    string str = {"abbaca"};
    cout<<removeDuplicates(str);
    return 0;
}