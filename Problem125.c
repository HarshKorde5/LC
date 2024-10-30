/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

*/

#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
bool isAlphaNumber(char c)
{
    if(c >= 'a' && c <= 'z')
    {
        return true;
    }
    if(c >= 'A' && c <= 'Z') 
    {
        return true;
    }
    if(c >= '0' && c <= '9') 
    {
        return true;
    }

    return false;
}

bool isPalindrome(char* s)
{
    int left = 0, right = strlen(s) - 1;
    while (left < right)
    {
        while (left < right && !isAlphaNumber(s[left]))
        {
            left++;
        }
        while (left < right && !isAlphaNumber(s[right]))
        {
            right--;
        }
        if(tolower(s[left++]) != tolower(s[right--]))
        {
            return false;
        }
    }
    return true;
}
int main()
{
    char arr[10] = "amfiwujvnd";
    printf("%d\n",isPalindrome(arr));

    return 0;
}