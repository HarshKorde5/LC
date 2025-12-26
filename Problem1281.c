/*
Given an integer number n, return the difference between the product of its digits and the sum of its digits.
*/
#include<stdio.h>

int subtractProductAndSum(int n)
{
    int sumOfDigits = 0;
    int productOfDigits = 1;

    while (n > 0)
    {
        sumOfDigits += (n % 10);
        productOfDigits *= (n % 10);

        n /= 10;
    }

    return productOfDigits - sumOfDigits;
}

int main()
{

    int n = 234;
    printf("Difference between Product of Digits and Sum of Digits is : %d\n",subtractProductAndSum(n));

    return 0;
}