/*
Given a binary string s ​​​​​without leading zeros, return true​​​ if s contains at most one contiguous segment of ones. Otherwise, return false
*/
#include <stdio.h>
#include <stdbool.h>

bool checkOnesSegment(char *s)
{
    while (*s)
    {
        if (*s == '0' && *(s + 1) == '1')
        {
            return false;
        }
        s++;
    }

    return true;
}

int main()
{
    char s[20] = "11000";
    bool result = checkOnesSegment(s);
    return 0;
}