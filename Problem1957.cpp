/*
A fancy string is a string where no three consecutive characters are equal.

Given a string s, delete the minimum possible number of characters from s to make it fancy.

Return the final string after the deletion. It can be shown that the answer will always be unique.
*/

#include<iostream>
using namespace std;

class Solution {
public:
    string makeFancyString(string s) 
    {
        string ret = "";
        ret.push_back(s[0]);

        int cnt = 1;

        for(int i = 1;s[i] != '\0';i++)
        {
            if(s[i] == ret.back()) 
            {
                cnt++;
                if(cnt < 3)
                {
                    ret.push_back(s[i]);
                }
            }
            else
            {
                cnt = 1;
                ret.push_back(s[i]);
            }

        }

        return ret;
    }
};

int main()
{

    Solution s;
    string str("leeetcode");
    string ret(s.makeFancyString(str));
    cout<<ret;
    return 0;
}