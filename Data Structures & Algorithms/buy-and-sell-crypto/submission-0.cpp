class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // loop through the prices with two pointers l and r
        // r > l
        // if the price of r is lower than the price of pointer l
        // assign the current pointer l, and r = l+1
        // if the price of r is higher than the price of pointer l
        // profit = [r] - [l]
        // move r, 
        int l = 0, r = 1;
        int max_profit = 0;
        while (r < prices.size()) {
            if (prices[r] < prices[l]) {
                l = r;
                r = l + 1;
            } else {
                int profit = prices[r] - prices[l];
                max_profit = max(profit, max_profit);
                r = r + 1;
            }
        }
        return max_profit;
    }
};
