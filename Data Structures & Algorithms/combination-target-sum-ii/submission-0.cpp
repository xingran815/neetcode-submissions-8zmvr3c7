class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        if (candidates.empty()) {
            return ans;
        }
        sort(candidates.begin(), candidates.end());
        int total = 0;
        backtrack(candidates, target, 0, total, cur, ans);
        return ans;
    }

    void backtrack(vector<int>& candidates,
        int target,
        int i,
        int total,
        vector<int> & cur,
        vector<vector<int>> & ans) {
        
        if (target == total) {
            ans.push_back(cur);
            return;
        }
        if (i > candidates.size()-1 || total > target) {
            return;
        }

        // include [i]
        cur.push_back(candidates[i]);
        total += candidates[i];
        cout << i << ", ";
        print_arr(cur);
        cout << "total: " << total << endl;
        backtrack(candidates, target, i+1, total, cur, ans);

        // exclude [i]
        cur.pop_back();
        total -= candidates[i];
        while (i < candidates.size()-1 && candidates[i] == candidates[i+1]) {
            i++;
        }
        backtrack(candidates, target, i+1, total, cur, ans);
    }
    void print_arr(vector<int> arr) {
        for (auto i : arr) {
            cout << i << ", ";
        }
    }
};
