class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> cur;

        backtrack(ans, nums, cur, 0);
        return ans;
    };
    void backtrack(vector<vector<int>> &ans, vector<int>& nums,
        vector<int> &cur, int i) {
        if (i >= nums.size()) {
            ans.push_back(cur);
            return;
        }

        cur.push_back(nums[i]);
        backtrack(ans, nums, cur, i+1);

        cur.pop_back();
        while (i < nums.size() - 1 && nums[i] == nums[i+1]) {
            i++;
        }
        backtrack(ans, nums, cur, i+1);
    };
};
