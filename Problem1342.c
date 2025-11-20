/*
Given an integer num, return the number of steps to reduce it to zero.

In one step, if the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.
*/

#include<stdio.h>

int numberOfSteps(int num) {

    int count = 0;
    
    while(num != 0){

        num = (num % 2 == 0) ? num / 2 : num - 1;
        count++;
    }

    return count;
}

int main(){

    int num = 123;

    printf("Number of steps required to convert %d into 0 are : %d\n", num, numberOfSteps(num));

    return 0;
}