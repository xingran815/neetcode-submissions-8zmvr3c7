class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int i_left = size-1;
        for (int i = size-2; i >= 0; --i) {
            if (i + nums[i] >= i_left) {
                i_left = i;
            }

        }
        return i_left == 0;
        
    }
};
