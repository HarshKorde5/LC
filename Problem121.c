/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/

#include<stdio.h>

int maxProfit(int* prices, int pricesSize)
{
    int buy = prices[0];
    int max = 0;
    
    for(int i = 1; i < pricesSize; ++i)
    {
        if(buy - prices[i] > 0)
        {
            buy = prices[i];
        }
        if(prices[i] - buy > max)
        {
            max = prices[i] - buy;
        }
    }

    return max;
}

int main()
{

    int arr[10] = {7,1,5,3,6,4};

    int ret = maxProfit(arr,10);
    printf("%d\n",ret);
    return 0;
}