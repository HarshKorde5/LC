/*
Given a string s, return the longest palindromic substring in s.
*/

#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

////////////////////////////////////////////////////////////////////
//  Brute Force : O(n^3)
////////////////////////////////////////////////////////////////////
char* longestPalindrome1(char* s) 
{
    bool check(char* s,int i,int j)
    {
        int left = i;
        int right = j - 1;

        while(left < right)
        {
            if(s[left] != s[right])
            {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }

    int length = strlen(s);
    char* result = strdup("");

    for(int len = length;len > 0;len--)
    {
        for(int start = 0;start <= (length-len);start++)
        {
            if(check(s,start,start+len))
            {
                free(result);
                result = strndup(s+start,len);
                return result;
            }
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////
// Dynamic Programming
////////////////////////////////////////////////////////////////////
char* longestPalindrome2(char* s) 
{
    int n = strlen(s);
    bool dp[n][n];
    memset(dp,false,sizeof dp);
    int ans[2] = {0,0};

    // substrings of length 1 are always palindromic so set it true
    for(int i = 0;i < n;i++)
    {
        dp[i][i] = true;
    }

    // check palindromic substrings of length 2 
    for(int i = 0;i < n-1;i++)
    {
        if(s[i] == s[i+1])
        {
            dp[i][i+1] = true;
            ans[0] = i;
            ans[1] = i + 1;

        }
        else
        {
            dp[i][i+1] = false;
        }
    }

    //check for substrings of each length expanding till end
    // starting from 2 as we intitialized substrings of length 1 and 2 before 
    for(int diff = 2;diff < n;diff++)
    {
        for(int i = 0;i < n-diff;i++)
        {
            int j = i + diff;
            if(s[i] == s[j] && dp[i+1][j-1])
            {
                dp[i][j] = true;
                ans[0] = i;
                ans[1] = j;
            }
            else
            {
                dp[i][j] = false;
            }
        }
    }


    s[ans[1] + 1] = '\0';
    return s+ans[0];
}


////////////////////////////////////////////////////////////////////
//  Expanding from center
////////////////////////////////////////////////////////////////////
char* longestPalindrome(char* s) 
{
    if(!s || strlen(s) == 0)    return s;

    int stringLength = strlen(s);
    
    char *palindrome(char *s,int left,int right)
    {
        int stringLengthLocal = strlen(s);
        while(left >= 0 && right <= stringLengthLocal && s[left] == s[right])
        {
            left--;
            right++;
        }

        char *p = (char*)malloc(sizeof(char)*(right - left));
        memcpy(p,&s[left+1],sizeof(char)*(right-left - 1));
        p[right - left - 1] = '\0';
        return p;
    }



    int start = 0,len = 0;
    for(int i = 0;i < stringLength;i++)
    {
        char *odd = palindrome(s,i,i);
        char *even = palindrome(s,i,i+1);
        int max_len = strlen(odd) > strlen(even) ? strlen(odd) : strlen(even);

        if(max_len > len)
        {
            start = i - (max_len - 1)/2;
            len = max_len;
        }

        free(odd);
        free(even);
    }

    char *ans = (char*)malloc(sizeof(char)*(len+1));
    strncpy(ans,&s[start],len);
    ans[len] = '\0';

    return ans;
}

int main()
{
    char str[100];

    printf("Enter a string : ");
    scanf("%[^\n]s",str);

    char *ret = longestPalindrome(str);

    printf("Result :: %s\n",ret);
    return 0;
}