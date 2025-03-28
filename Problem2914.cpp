/*
You are given a 0-indexed binary string s having an even length.

A string is beautiful if it's possible to partition it into one or more substrings such that:

Each substring has an even length.
Each substring contains only 1's or only 0's.
You can change any character in s to 0 or 1.

Return the minimum number of changes required to make the string s beautiful.
*/

#include<iostream>
using namespace std;

class Solution {
public:
    int minChanges(string s) 
    {
        int count = 0;

        for(int i = 0;i < s.length() - 1;i = i + 2)
        {
            if(s[i] != s[i + 1])
            {
                count++;
            }
        }

        return count;
    }
};


int main()
{
    Solution s;
    string str("1001");

    cout<<s.minChanges(str);
    return 0;
}