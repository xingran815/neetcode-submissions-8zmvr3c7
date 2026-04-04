class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur_v;
        vector<vector<int>> ans_v;

        helper(0, nums, cur_v, ans_v);
        return ans_v; 
    }

    void helper(int i, vector<int>& nums, vector<int> cur_v, 
        vector<vector<int>>& ans_v) {
        if (i > nums.size()-1) {
            ans_v.push_back(cur_v);
            return;
        }
        // to include nums[i]
        cur_v.push_back(nums[i]);
        helper(i+1, nums, cur_v, ans_v);

        // to exclude nums[i]
        cur_v.pop_back();
        helper(i+1, nums, cur_v, ans_v);
    }
};
