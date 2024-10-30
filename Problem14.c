/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Input: strs = ["flower","flow","flight"]
Output: "fl"
*/

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize)
{
    int i = 0,j = 0;
    for(i = 1; i < strsSize; i++)
    {
        for(j = 0; strs[0][j] != '\0'; j++)
        {
            if(!strs[i][j] || (strs[0][j] != strs[i][j]))
            { // terminate loop if chars differ
                break;
            }
        }
    }
    char *brr = (char*)malloc(sizeof(char)*j);
    for(i = 0;i<j;i++)
    {
        brr[i] = strs[0][i];
    }
    return brr;
    /*
    int i = 0,j = 0,k = 0;
    bool flag = false;
    char *brr = (char*)malloc(sizeof(char)*10);
    char **temp = strs;
    char prev = '\0';

    while(temp[0][j] != '\0')
    {
        prev = temp[0][j];

        flag = true;
        for(i = 0;i < strsSize;i++)
        {
            if((strs[i][j] == '\0')||(prev != strs[i][j]))
            {
                flag = false;
                break;
            }
        }

        if(flag)
        {
            brr[k] = prev;
            k++;
            j++;
        }
        else
        {
            break;
        }

    }

    return brr;
    */
}

int main()
{
    int i = 0;
    char *strs[] = {"flower","flow","flight"};
    char *ret = NULL;
    
    ret = longestCommonPrefix(strs,3);

    printf("%s\n",ret);
    return 0;
}