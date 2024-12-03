
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;
        result.reserve(s.size() + spaces.size());

        int i = 0;
        int j = 0;

        for(i = 0;i < s.size();i++)
        {
            if(j < spaces.size() && spaces[j] == i)
            {
                result += ' ';
                j++;
            }
            
            result += s[i];
        }


        return result;
    }
};

int main()
{

    Solution s;

    string str("LeetcodeHelpsMeLearn");

    vector<int> spaces = {8,13,15};

    cout<<s.addSpaces(str,spaces);

    return 0;
}