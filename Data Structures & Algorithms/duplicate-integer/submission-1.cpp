class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        if (s.size() != nums.size()) {
            return true;
        } else {
            return false;
        }
        
    }
};