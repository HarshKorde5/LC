/*
You are given a string s consisting only of the characters '0' and '1'. In one operation, you can change any '0' to '1' or vice versa.

The string is called alternating if no two adjacent characters are equal. For example, the string "010" is alternating, while the string "0100" is not.

Return the minimum number of operations needed to make s alternating.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(string s)
    {
        int res = 0, n = s.length();
        for (int i = 0; i < n; ++i)
            if (s[i] - '0' != i % 2)
                res++;
        return min(res, n - res);
    }
};
int main()
{
    Solution sol;
    string s = "0100";
    cout << sol.minOperations(s) << endl; // Output: 1
    return 0;
}