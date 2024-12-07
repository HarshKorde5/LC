/*
Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.
*/


#include<stdio.h>

int addDigits(int num) 
{
    // return (num - 1) % 9 + 1;

    while(num >= 10)
    {
        int a = num / 10;
        int b = num % 10;
        num = a + b;
    }


    return num;
}

int main()
{
    printf("%d\n",addDigits(38));
    return 0;
}