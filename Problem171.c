/*
Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
*/

#include<stdio.h>

int titleToNumber(char* columnTitle)
{
    int n = 0;

    for(int i = 0;columnTitle[i] != '\0';i++)
    {
        n = n * 26;
        n = n + (columnTitle[i] - 'A' + 1);
    }

    return n;
}

int main()
{
    char str[] = {"XY"};

    printf("%d\n",titleToNumber(str));
    return 0;
}