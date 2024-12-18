/*
You are given an integer array prices where prices[i] is the price of the ith item in a shop.

There is a special discount for items in the shop. If you buy the ith item, then you will receive a discount equivalent to prices[j] where j is the minimum index such that j > i and prices[j] <= prices[i]. Otherwise, you will not receive any discount at all.

Return an integer array answer where answer[i] is the final price you will pay for the ith item of the shop, considering the special discount.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    //////////////////////////////////////////////////////////////////////////////////
    //  using stack 
    //////////////////////////////////////////////////////////////////////////////////

    vector<int> finalPrices1(vector<int>& prices) {
        vector<int> result =  prices;

        stack<int> stack;

        for(int i = 0;i < prices.size();i++)
        {
            while(!stack.empty() && prices[stack.top()] >= prices[i])
            {
                result[stack.top()] -= prices[i];
                stack.pop();

            }

            stack.push(i);

        }

        return result;
    }

    //////////////////////////////////////////////////////////////////////////////////
    //  Brute Force
    //////////////////////////////////////////////////////////////////////////////////

    vector<int> finalPrices(vector<int>& prices) {

        vector<int> result = prices;

        int n = prices.size();

        for(int i = 0;i < n;i++)
        {

            for(int j = i+1;j < n;j++)
            {
                if(prices[j] <= prices[i])
                {
                    result[i] = prices[i] - prices[j];
                    break;
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution s;

    vector<int> prices = {8,4,6,2,3};

    vector<int> ret = s.finalPrices(prices);

    for(int i = 0;i < 5;i++)
    {
        cout<<ret[i]<<"\n";
    }

    return 0;
}