class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        return helper(0, nums);
    }
    vector<vector<int>> helper(int i, vector<int>& nums) {
        if (i == nums.size()) {
            return {{}};
        }
        vector<vector<int>> perms = helper(i+1, nums);
        vector<vector<int>> ans;
        for (int k = 0; k < perms.size(); ++k) {
            for (int j = 0; j < perms[k].size()+1; ++j) {
                vector<int> copy = perms[k];
                copy.insert(copy.begin()+j, nums[i]);
                ans.push_back(copy);
            }
        }
        return ans;
    }
};
