
/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {

        //arrays to store last seen index of characters in s and t;
        int s_array[256] = {0};
        int t_array[256] = {0};

        int n =  s.size();  


        //loop through each character
        for(int i = 0;i < n;i++)
        {


            //if mapping btwn the characters in s and t is not the same as before return false;
            if(s_array[s[i]] != t_array[t[i]])
            {
                return false;
            }


            //update mapping for characters
            s_array[s[i]] = i + 1;      //add 1 to index to differentiate from default value 0
            t_array[t[i]] = i + 1;

        }


        //if all characters are mapped consistently return true;
        return true;
    }
};


int main()
{
    Solution s1;

    string s("egg");
    string t("add");

    cout<<s1.isIsomorphic(s,t);

    return 0;
}