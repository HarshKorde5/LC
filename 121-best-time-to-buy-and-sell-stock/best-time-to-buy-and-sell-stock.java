class Solution {
    public int maxProfit(int[] prices) {
        int buyIdx = 0, sellIdx = 1;

        int profit = 0;

        while(sellIdx < prices.length){
            if(prices[buyIdx] < prices[sellIdx]){
                profit = (prices[sellIdx] - prices[buyIdx]) > profit ? (prices[sellIdx] - prices[buyIdx]) : profit;
            }else{
                buyIdx = sellIdx;
            }

            sellIdx++;
        }

        return profit;
    }
}