/*
Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.
*/


#include<iostream>
using namespace std;


class Solution {
public:
    bool rotateString(string s, string goal) 
    {
        if(s.length() != goal.length())    return false;

        string concated = s+s;

        int pos = concated.find(goal);

        return pos == -1 ? false : true;
    }

    bool rotateString1(string s, string goal) 
    {
        if(s.length() != goal.length())    return false;

        int i = 0;

        while(s[i] != goal[0] && i < s.length())
        {
            i++;
        }

        int j = 0,k = i;

        if(i >= s.length())
        {
            return false;
        }
        else
        {

            while(i < s.length() )
            {
                if(s[i] == goal[j])
                {
                    i++;
                    j++;
                }
                else
                {
                    return false;
                }
            }

            while(j < k)
            {
                if(s[j] == goal[i])
                {
                    j++;
                    i++;
                }
                else
                {
                    return false;
                }
            }
        }

        return true;
    }


};


int main()
{
    Solution s;

    string s1("gcmbf");
    string goal("fgcmb");
    cout<<s.rotateString(s1,goal);
    return 0;
}