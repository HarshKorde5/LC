/**
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.
 */


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit1(vector<int>& prices) {
        
        int profit = 0;        
        int buy = prices[0];

        for(int i = 1;i < prices.size();i++){
            if(prices[i] <= buy){
                buy = prices[i];
            }else{
                profit += (prices[i] - buy);
                buy = prices[i];
            }
        }

        return profit;
    }

    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        
        for(int i = 1; i < prices.size(); i++) 
        {
            if(prices[i] > prices[i-1])
            {
                maxProfit += (prices[i] - prices[i-1]);
            }
        }
        return maxProfit;
    }

};

int main(){
    Solution s;
    vector<int> prices = {7,1,5,3,6,4};
    cout<<s.maxProfit(prices);
    return 0;
}