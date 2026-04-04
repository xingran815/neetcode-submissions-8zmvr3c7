class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans_v;
        if (nums.empty()) {
            return ans_v;
        }
        vector<int> cur_v;
        int total = 0;
        backtrack(nums, 0, target, total, cur_v, ans_v);
        return ans_v; 
    }
    void backtrack(vector<int>& nums, 
        int i,
        int target,
        int total, 
        vector<int>& cur,
        vector<vector<int>>& ans) {
        if (total == target) {
            ans.push_back(cur);
            return;
        }
        if (i > nums.size()-1 || total > target) {
            return;
        }

        // solutions including nums[i]
        cur.push_back(nums[i]);
        total += nums[i];
        cout << i << ", ";
        print_arr(cur);
        cout << "total: " << total << endl;
        backtrack(nums, i, target, total, cur, ans);

        // solutions excluding nums[i]
        cur.pop_back();
        total -= nums[i];
        backtrack(nums, i+1, target, total, cur, ans);
    }

    void print_arr(vector<int> arr) {
        for (auto i : arr) {
            cout << i << ", ";
        }
    }
};
