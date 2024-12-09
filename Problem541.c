/*
Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.

If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original.
*/


#include<stdio.h>
#include<string.h>

void reverse(char *s,int l,int r)
{
    while(l < r)
    {
        char t = s[l];
        s[l] = s[r];
        s[r] = t;

        l++;
        r--;
    }
}

char* reverseStr(char* s, int k) 
{
    int n = strlen(s);

    int l = 0,r = 0;

    for(int i = 0;i < n;i = i + 2*k)
    {
        l = i;
        r = i+k-1 < n - 1 ? i + k - 1 : n - 1;

        reverse(s,i,r);
    }

    return s;
}

int main()
{
    char str[20] = {"abcdefg"};

    printf("Before operation : %s\n",str);

    char *ret = reverseStr(str,2);

    printf("After operation : %s\n",ret);

    return 0;
}