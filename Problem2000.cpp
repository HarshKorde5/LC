/*
Given a 0-indexed string word and a character ch, reverse the segment of word that starts at index 0 and ends at the index of the first occurrence of ch (inclusive). If the character ch does not exist in word, do nothing.

For example, if word = "abcdefd" and ch = "d", then you should reverse the segment that starts at 0 and ends at 3 (inclusive). The resulting string will be "dcbaefd".
Return the resulting string.
*/

#include<string>
#include<iostream>
using namespace std;

class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        int end = word.find(ch);
        int start = 0;
        if (end != string::npos)
        {
            while (start < end)
            {

                char temp = word[start];
                word[start] = word[end];
                word[end] = temp;

                start++;
                end--;
            }
        }

        return word;
    }
};

int main()
{
    Solution sobj;
    string word = "abcdefd";
    char ch = 'd';

    string ret = sobj.reversePrefix(word, ch);
    cout << "Reversed prefix string is : " << ret << endl;

    return 0;
}