class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> freq(nums.size()+1);
        unordered_map<int, int> hmap; // <num, freq>
        // calculate the frequency with hash_map
        // copy the nums into the bucket freq
        // loop through freq from the highest indices
        for (const int n : nums) {
            hmap[n]++;
        }
        for (const auto& p : hmap) {
            // p.first num
            // p.second freq
            freq[p.second].push_back(p.first);
        }
        int i = 0;
        vector<int> ans;
        for (auto it = freq.rbegin(); it != freq.rend(); ++it) {
            for (int n = 0; n < it->size(); ++n) {
                if (i >= k)
                    return ans;
                ans.push_back((*it)[n]);
                ++i;
            }
        }
        return ans;

        
    }
};
