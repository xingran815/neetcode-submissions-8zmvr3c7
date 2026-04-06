class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // dynamic programming
        // starting from the back
        int size = nums.size();
        int res = 1;
        vector<int> pick(size, 1);
        pick[size-1] = 1;
        for (int i = size-2; i>=0; --i) {
            for (int j = i+1; j < size; ++j) {
                if (nums[i] < nums[j]) {
                    pick[i] = max(pick[i], pick[j]+1);
                } 
            }
            res = max(res, pick[i]);
        }
        return res;
        
    }
};
