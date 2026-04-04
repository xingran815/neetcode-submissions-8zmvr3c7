class Solution {
public:
    int search(vector<int>& nums, int target) {
        // the bin_index = (begein_idx + end_idx)/2
        // comare the value of nums[bin_idx]
        // if nums[bin_idx] > target
        //      end_idx = bin_idx
        // else 
        //      begin_idx = bin_idx
        if (nums.size() <= 1) {
            if (nums[0] == target) {
                return 0;
            } else {
                return -1;
            }
        }
        int bin_idx = -1;
        int begin_idx = 0;
        int end_idx = nums.size() - 1;
        while (begin_idx+1 != end_idx) {
            bin_idx = (begin_idx+end_idx)/2;
            if (nums[bin_idx] > target) {
                end_idx = bin_idx;
            } else if (nums[bin_idx] < target) {
                begin_idx = bin_idx;
            } else {
                return bin_idx;
            }
        } 
        if (nums[begin_idx] == target) {
            return begin_idx;
        } else if (nums[end_idx] == target) {
            return end_idx;
        } else {
            return -1;
        }
    }
};
