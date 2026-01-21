/*
Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_set<char> st;
        int res = 0;

        for (char c : s)
        {
            if (st.find(c) != st.end())
            {
                st.erase(c);
                res += 2;
            }
            else
            {
                st.insert(c);
            }
        }

        if (!st.empty())
        {
            res++;
        }

        return res;
    }

    int longestPalindrome_1(string s)
    {
        int oddFreqCount = 0;
        unordered_map<char, int> mp;

        for (char c : s)
        {
            mp[c]++;

            if (mp[c] % 2 == 1)
            {
                oddFreqCount++;
            }
            else
            {
                oddFreqCount--;
            }
        }

        if (oddFreqCount > 0)
        {
            return s.length() - oddFreqCount + 1;
        }
        else
        {
            return s.length();
        }
    }
};

int main()
{
    string s = "abccccdd";
    Solution sobj;
    cout << sobj.longestPalindrome(s) << endl;

    return 0;
}