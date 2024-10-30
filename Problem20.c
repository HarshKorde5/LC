/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

*/





#include<stdio.h>
#include<stdbool.h>

bool isValid(char* s)
{
    int k = -1;
    int len = strlen(s);
    char stack[len];
    char ret = '\0';
    bool flag = true;

    while(*s != '\0')
    {
        printf("%c",*s);
        if((*s == '(')||(*s == '[')||(*s == '{'))
        {
            stack[++k] = *s;
        }
        else
        {
            ret = stack[k];
            stack[k] = '\0';
            k--;
            if((*s == ']')&&(ret == '['))
            {
                flag = true;
            }
            else if((*s == ')')&&(ret == '('))
            {
                flag = true;
            }
            else if((*s == '}')&&(ret == '{'))
            {
                flag = true;
            }
            else
            {
                flag = false;
                break;
            }
        }
        s++;
    }

    return flag;
}

int main()
{
    bool bRet = false;
    char s[] = {"}{"};
    bRet = isValid(s);
    if(bRet)
        printf("Valid\n");
    else
        printf("Invalid\n");
    return 0;
}