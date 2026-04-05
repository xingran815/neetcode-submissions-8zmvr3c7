class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        vector<int> min_change(amount+1, INT_MAX);
        min_change[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (auto c : coins) {
                if (i-c < 0 || min_change[i-c] == -1) {
                    continue;
                }
                min_change[i] = min(min_change[i], min_change[i-c]+1);
            }
            min_change[i] = (min_change[i] == INT_MAX) ? -1 : min_change[i];
        }
        return min_change[amount];
    }
};
