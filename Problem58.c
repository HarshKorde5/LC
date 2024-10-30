//Given a string s consisting of words and spaces, return the length of the last word in the string.

#include<stdio.h>

int lengthOfLastWord(char* s)
{
    int len = 0,last_len = 0;
    
    while(*s != '\0')
    {
        if(*s == ' ')
        {
            if(len != 0)
                last_len = len;
            len = 0;
        }
        else
        {
            len++;
        }
        s++;
    }

    if(len != 0)
        last_len = len;

    return last_len;
}

int main()
{
    char str[] = {"Hello World"};

    int ret = lengthOfLastWord(str);

    return 0;
}