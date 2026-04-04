class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        set<int> s(nums.begin(), nums.end());
        vector<int> ans;

        for (int i = 0; i < nums.size(); ++i) {
            int a = nums[i];
            int b = target - a;
            if (find(s.begin(), s.end(), b) == s.end()) {
                // not found
                continue;
            } else {
                // found
                for (int j = i + 1; j < nums.size(); ++j) {
                    if (nums[j] == b) {
                        ans.push_back(i);
                        ans.push_back(j);
                        return ans;
                    }
                }
            }
        }
        
    }
};
