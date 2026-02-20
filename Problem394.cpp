/*
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string decodeString(string s)
    {
        stack<int> numStack;
        stack<string> strStack;

        int currNum = 0;
        string currString = "";

        for (char ch : s)
        {
            if (isdigit(ch))
            {
                currNum = currNum * 10 + (ch - '0');
            }
            else if (ch == '[')
            {
                numStack.push(currNum);
                strStack.push(currString);
                currNum = 0;
                currString = "";
            }
            else if (ch == ']')
            {
                int repeat = numStack.top();
                numStack.pop();

                string prevString = strStack.top();
                strStack.pop();

                string temp = "";
                for (int i = 0; i < repeat; i++)
                {
                    temp += currString;
                }

                currString = prevString + temp;
            }
            else
            {
                currString += ch;
            }
        }

        return currString;
    }
};

int main()
{
    Solution sobj;
    string s = "2[abc]3[cd]ef";
    string ret = sobj.decodeString(s);
    cout<<ret;
    return 0;
}