class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        int buy = 0;
        int sell = 0;

        int n = prices.size();

        while(sell < n) {

            int diff = prices[sell] - prices[buy];

            profit = max(profit, diff);

            if(prices[sell] < prices[buy]) {
                buy = sell;
                continue;
            }

            sell++;
        }

        return profit;
    }
};