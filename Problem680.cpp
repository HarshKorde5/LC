/*
Given a string s, return true if the s can be palindrome after deleting at most one character from it.
*/
#include <string>
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    bool validPalindrome1(string s) {
        int left = 0, right = s.length() - 1;
        
        while (left < right) {
            if (s[left] != s[right]) {
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            }
            left++;


            right--;
        }
        return true;
    }
    bool validPalindrome2(string s)
    {
        int cnt = 0;
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            if (s[l] != s[r])
            {
                if (s[l + 1] == s[r])
                {
                    if (s[l] == s[r - 1])
                    {
                        ++l;
                        --r;
                    }
                    else
                    {
                        l += 2;
                        --r;
                        ++cnt;
                    }
                }
                else if (s[l] == s[r - 1])
                {
                    r -= 2;
                    ++l;
                    ++cnt;
                }
                else
                    return false;
            }
            else
            {
                ++l;
                --r;
            }
        }
        return cnt < 2;
    }
        bool validPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
            if (s[i] != s[j]) {
                int i1 = i, j1 = j - 1, i2 = i + 1, j2 = j;
                while (i1 < j1 && s[i1] == s[j1]) {i1++; j1--;};
                while (i2 < j2 && s[i2] == s[j2]) {i2++; j2--;};
                return i1 >= j1 || i2 >= j2;
            }
        return true;
    }
private:
    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};




int main(){

    Solution s;

    string str = {"abcucucuceffecucucuba"};
    cout<<s.isPalindrome(str);

    return 0;
}