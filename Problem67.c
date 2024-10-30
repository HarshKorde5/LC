/*
Given two binary strings a and b, return their sum as a binary string.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void addBinary(char * a, char * b)
{
    int sizeA = strlen(a);
    int sizeB = strlen(b);
    int sizeOutput = (sizeA > sizeB ? sizeA : sizeB) + 1;
    char * output = (char *)malloc(sizeOutput + 1);
    int sum = 0;
    
    output[sizeOutput] = '\0';
    
    while(sizeA > 0 || sizeB > 0 || sum > 0) {
        
        if(sizeA > 0) {
            sum += a[--sizeA] - '0';
        }
        if(sizeB > 0) {
            sum += b[--sizeB] - '0';
        }
        output[--sizeOutput] = sum % 2 + '0';
        sum /= 2;
    }
    printf("%s",output + sizeOutput);
}


int main()
{
    char a[] = {"1010"};
    char b[] = {"1011"};

    addBinary(a,b);

    return 0;
}