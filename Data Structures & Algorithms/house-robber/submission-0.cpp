class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) {
            return 0;
        }
        if (size == 1) {
            return nums[0];
        }
        vector<int> best_rob(size+1, 0);
        best_rob[0] = 0;
        best_rob[1] = nums[0];
        for (int i = 2; i<size+1; ++i) {
            best_rob[i] = max(best_rob[i-1], best_rob[i-2]+nums[i-1]);
        }
        return best_rob[size];
    }
};
