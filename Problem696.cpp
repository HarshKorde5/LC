/*
Given a binary string s, return the number of non-empty substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        int cur = 1, pre = 0, res = 0;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == s[i - 1])
                cur++;
            else
            {
                res += min(cur, pre);
                pre = cur;
                cur = 1;
            }
        }
        return res + min(cur, pre);
    }
};

int main()
{
    Solution sobj;

    string s = "1100101000101010";

    int ret = sobj.countBinarySubstrings(s);

    cout << ret << endl;

    return 0;
}