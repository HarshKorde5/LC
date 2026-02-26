/*
Given the binary representation of an integer as a string s, return the number of steps to reduce it to 1 under the following rules:

If the current number is even, you have to divide it by 2.

If the current number is odd, you have to add 1 to it.

It is guaranteed that you can always reach one for all test cases.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSteps(string s)
    {
        int carry = 0, steps = 0;
        for (int i = s.length() - 1; i > 0; i--)
        {
            if ((s[i] - '0') + carry == 1)
            {
                steps += 2;
                carry = 1;
            }
            else
            {
                steps++;
            }
        }
        return steps + carry;
    }
};

int main()
{

    string s  = "1101";
    Solution sobj;
    cout<<"Count of steps required to convert string to 1 :: "<<sobj.numSteps(s)<<endl;
    return 0;
}