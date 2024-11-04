/*
A sentence is a list of words that are separated by a single space with no leading or trailing spaces.

For example, "Hello World", "HELLO", "hello world hello world" are all sentences.
Words consist of only uppercase and lowercase English letters. Uppercase and lowercase English letters are considered different.

A sentence is circular if:

The last character of a word is equal to the first character of the next word.
The last character of the last word is equal to the first character of the first word.
For example, "leetcode exercises sound delightful", "eetcode", "leetcode eats soul" are all circular sentences. However, "Leetcode is cool", "happy Leetcode", "Leetcode" and "I like Leetcode" are not circular sentences.

Given a string sentence, return true if it is circular. Otherwise, return false.
*/


#include<iostream>
using namespace std;

class Solution {
public:
    bool isCircularSentence(string sentence) 
    {
        bool flag = true;

        if(sentence.length() == 0)  return true;
        if(sentence[sentence.length()-1] != sentence[0])
        {
            flag = false;
            return flag;
        }
        int i = 0;
        do
        {
            if(sentence[i] == ' ')
            {
                if(sentence[i-1] != sentence[i+1])
                {
                    flag = false;
                    break;
                }
            }
            i++;
        }while(sentence[i] != '\0');

        return flag;
    }
};

int main()
{
    Solution s;
    string str(" ");

    bool ret = s.isCircularSentence(str);
    cout<<ret;
    return 0;
}