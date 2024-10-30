/*

Topics
Companies
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
*/

#include<stdio.h>
#include<stdbool.h>

bool isAnagram(char* s, char* t)
{
    if(strlen(s) != strlen(t))
    {
        return false;
    }

    int count[26] = {0};

    for(int i = 0;i < strlen(s);i++)
    {
        count[s[i]-97]++;
        count[t[i]-97]--;
    }

    bool flag = true;

    for(int i = 0;i < 26;i++)
    {
        if(count[i] != 0)
        {
            flag = false;
            break;
        }
    }

    return flag;
}

int main()
{
    return 0;
}