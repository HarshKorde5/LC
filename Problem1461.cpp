//Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {
        if (k > s.size())
            return false;

        unordered_set<string> seen;

        for (int i = 0; i <= s.size() - k; i++)
        {
            seen.insert(s.substr(i, k));
        }

        return seen.size() == pow(2, k);
    }
};

int main()
{
    Solution sobj;
    string s = "00110110";
    int k = 2;

    cout << sobj.hasAllCodes(s, k);
    return 0;
}