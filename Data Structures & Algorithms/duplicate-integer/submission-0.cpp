class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        if (nums.size() == 0)
            return false;
        set<int> s;
        int count = 0;
        for (auto i=nums.cbegin(); i<nums.cend(); ++i) {
            ++count;
            s.insert(*i);
            if (s.size() != count)
                return true;
        }
        return false;
    }
};