/*
Write a function that takes the binary representation of a positive integer and returns the number of 
set bits it has (also known as the Hamming weight).

*/


#include<stdio.h>
#include<stdlib.h>

int hammingWeight(int n) {
    int is_one=0;
    if(n&1)
        is_one = 1;
    return is_one + (n==0?0:hammingWeight(n/2));    
}


int * convert_to_binary (int n, int size)
{
    int *array = malloc(size * sizeof(int));
    int i = size - 1;
    while (n > 0 && i >= 0)
    {
        array[i] = n % 2;
        n = n / 2;
        i--;
    }
    return array;
}

int hammingWeight1(int n)
{
    int length_b = (int)log2(n) + 1, count = 0;
    int *arr = convert_to_binary(n, length_b);
    for (int i = 0; i < length_b; i++)
        if (arr[i] == 1)
            count++;
    return count;
}