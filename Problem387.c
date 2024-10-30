/*
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
*/


#include<stdio.h>

int firstUniqChar(char* s) 
{
    int i = 0,j = 0;
    bool flag = false;

    while(s[i] != '\0')
    {
        j = 0;
        while(s[j] != '\0')
        {
            if(j != i)
            {
                if(s[i] == s[j])
                {
                    break;
                }
            }
            

            j++;
        }
        if(s[j] == '\0')
        {
            return i;
        }
        i++;
    }

    return -1;
}

int main()
{
    int str = {"leetcode"};

    printf("%d\n",firstUniqChar(str));
    return 0;
}