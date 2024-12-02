
/*
Given a sentence that consists of some words separated by a single space, and a searchWord, check if searchWord is a prefix of any word in sentence.

Return the index of the word in sentence (1-indexed) where searchWord is a prefix of this word. If searchWord is a prefix of more than one word, return the index of the first word (minimum index). If there is no such word return -1.

A prefix of a string s is any leading contiguous substring of s.
*/


#include<iostream>
#include<string_view>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) 
    {
        stringstream ss(sentence);
 
        vector<string> v;
    
        string s;

        while (getline(ss, s, ' ')) 
        {
            v.push_back(s);
        }

        for(int i = 0;i < v.size();i++)
        {
            if(v[i].starts_with(searchWord))    return i+1;
        }

        return -1;
    }
};

int main()
{

    Solution s;

    string sentence("i love eating burger");
    string searchWord("burg");

    cout<<s.isPrefixOfWord(sentence,searchWord);

    return 0;
}