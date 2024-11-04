/*

Given a string word, compress it using the following algorithm:

Begin with an empty string comp. While word is not empty, use the following operation:
Remove a maximum length prefix of word made of a single character c repeating at most 9 times.
Append the length of the prefix followed by c to comp.
Return the string comp.

*/


#include<iostream>
using namespace std;

class Solution 
{
public:

    string compressedString(string word) 
    {
        string comp = "";

        int count = 1;

        char ch = word[0];

        for(int i = 1;word[i] != '\0';i++)
        {
            if(word[i] == ch && count < 9)  count++;
            else
            {
                comp.push_back('0' + count);
                comp.push_back(ch);
                ch = word[i];
                count = 1;
            }
        }

        comp.push_back('0' + count);
        comp.push_back(ch);

        return comp;
    }



    string compressedString1(string word) {
        string comp("");

        int i = 0;

        while(word[i] != '\0')
        {
            int j = i+1;
            int count = 1;
            while(word[j] != '\0' && word[j] == word[i])
            {
                count++;
                j++;
            }
            // cout<<count<<"\n";
            if(count > 9)
            { 
                int cnt = 0;

                while(cnt < count)
                {
                    comp.push_back('0' + ((cnt+9 < count) ? 9 : count - cnt));
                    comp.push_back(word[i]);


                    cnt += 9;
                }
            }
            else
            {
                comp.push_back('0'+count);
                comp.push_back(word[i]);
            }
            i = j;
        }

        return comp;    
    }
};

int main()
{

    string str("mmmmmmmmmmmmmmmmmmzzzzzzzzzzzzzzzzzzyyyyyyyyyyyfvs");
    
    Solution s;

    string ret(s.compressedString(str));

    cout<<ret;

    return 0;
}



// fffffffffdddddddddddddddddddddddddmmmmooooooooooss