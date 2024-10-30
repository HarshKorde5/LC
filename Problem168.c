/*
Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

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

char* convertToTitle(int columnNumber)
{
    char *ans = calloc(10,sizeof(char));
    int i = 0;

    while(columnNumber > 0)
    {
        columnNumber--;

        ans[i++] = 65 + (columnNumber % 26);
        
        columnNumber /= 26;
    }

    int head = 0,tail = i - 1;

    while(head < tail)
    {
        char temp = ans[head];
        ans[head] = ans[tail];
        ans[tail] = temp;
        head++;
        tail--;
    }
    return ans;

}

int main()
{
    char *str = convertToTitle(2002);
    printf("%s\n",str);
    free(str);
    return 0;
}