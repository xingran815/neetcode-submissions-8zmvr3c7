class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> ans;

        for (int i = 0; i < nums.size(); ++i) {
            int a = nums[i];
            int b = target - a;
            // check if b is in the vector
            if (m.find(b) == m.end()) {
                // not found, insert a to the hash_map
                m.emplace(a, i);
                continue;
            } else {
                // found b in the hash_map
                ans.push_back(m[b]);
                ans.push_back(i);
                return ans;
            }
        }
        
    }
};
