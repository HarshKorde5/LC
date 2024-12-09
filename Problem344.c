
/*
Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.
*/

#include<stdio.h>

void reverseString(char* s, int sSize) 
{
    int l = 0,r = sSize - 1;

    while(l < r)
    {
        char t = s[l];
        s[l] = s[r];
        s[r] = t;

        l++;
        r--;
    }
}


int main()
{
    char str[10] = {"HELLO"};
    printf("Before reverse : %s\n",str);

    reverseString(str,5);

    printf("After reverse : %s\n",str);

    return 0;
}