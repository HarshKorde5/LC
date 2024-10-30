/*

Given a string s, find the length of the longest 
substring
 without repeating characters.


*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int lengthOfLongestSubstring(char* s)
{

    int *table = (int*)calloc(sizeof(int),256);
    int n = strlen(s);
    int maxLen = 0;
    char *start = s,*end = s;

    while(end < s + n)
    {
        if(table[*end] == 0)
        {
            table[*end] = 1;
            end++;
            if(end - start > maxLen)
            {
                maxLen = end - start;
            }
        }
        else
        {
            table[*start] = 0;
            start++;
        }
    }

    free(table);
    return maxLen;
}

int main()
{
    char str[] = {"ababacd"};
    printf("%d\n",lengthOfLongestSubstring(str));
    return 0;
}