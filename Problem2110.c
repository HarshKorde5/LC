/*
You are given an integer array prices representing the daily price history of a stock, where prices[i] is the stock price on the ith day.

A smooth descent period of a stock consists of one or more contiguous days such that the price on each day is lower than the price on the preceding day by exactly 1. The first day of the period is exempted from this rule.

Return the number of smooth descent periods.
*/

#include<stdio.h>

long long getDescentPeriods(int* prices, int pricesSize) {
    int currLen = 1;
    long long total = 0;
    for(int i = 1; i < pricesSize; i++){
        if(prices[i-1] - prices[i] == 1){
            currLen++;
        }else{
            total += ((long long)currLen*(currLen+1))/2;
            currLen = 1;
        }
    }

    total += ((long long)currLen*(currLen + 1) )/ 2;

    return total;
}


int main(){
    int prices[] = {9,8,7,6,5,3,2,4,2,4,5,7,6,5,3,2};
    int n = 16;

    long long ret = getDescentPeriods(prices,n);
    
    printf("Total descent periods are : %lld\n",ret);

    return 0;
}