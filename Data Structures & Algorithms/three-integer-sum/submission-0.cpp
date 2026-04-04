class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // declare the returned value ans

        // loop through nums get n1
        // use the 2sum algorithm to find the values adding up to -n1
        // sort the vector {n1, n2, n3}
        // check if ans contains {n1, n2, n3}, when not add the sorted
        // vector to ans

        set<vector<int>> s;
        for (size_t i = 0; i < nums.size(); ++i) {
            unordered_map<int, int> m;
            int target = -nums[i];
            for (size_t j = i+1; j < nums.size(); ++j) {
                int diff = target - nums[j];
                if (m.find(diff) == m.end()) {
                    // not found, add nums[j]
                    m.emplace(nums[j], j);
                } else {
                    // found diff in hash_map
                    vector<int> tmp {nums[i], nums[j], diff};
                    sort(tmp.begin(), tmp.end());
                    s.insert(tmp);
                    // if (find(ans.begin(), ans.end(), tmp) == ans.end()) {
                    //     // {n1, n2, n3} is not in the result
                    //    ans.push_back(tmp);
                    // }
                }
            }
        }
        return vector<vector<int>> (s.begin(), s.end());
    }
};
