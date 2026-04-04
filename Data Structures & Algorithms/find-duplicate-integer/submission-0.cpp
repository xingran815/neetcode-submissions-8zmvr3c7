class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (nums[abs(num)] < 0) {
                return abs(num);
            } else {
                nums[abs(num)] = -nums[abs(num)];
            }
        }
        return 0;
    }
};
