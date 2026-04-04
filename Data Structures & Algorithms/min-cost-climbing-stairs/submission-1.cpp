class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        if (size == 0 || size == 1) {
            return 0;
        }
        vector<int> spend(size+1, 0);
        spend[0] = 0;
        spend[1] = 0;
        for (int i = 2; i<size+1; ++i) {
            spend[i] = min(spend[i-2]+cost[i-2], spend[i-1]+cost[i-1]);
        }

        return spend[size];
        
    }
};
