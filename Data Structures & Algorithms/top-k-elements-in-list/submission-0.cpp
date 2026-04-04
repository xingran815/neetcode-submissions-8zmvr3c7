class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // firstly, convert vector nums to hash_map<num, count>
        // secondly, convert the hash_map to multi_map<count, num>
        unordered_map<int, int> hmap;
        for (const auto n : nums) {
            if (hmap.find(n) == hmap.end()) {
                // not found
                hmap[n] = 1;
            } else {
                // found
                hmap[n]++;
            }
        }
        vector<pair<int, int>> tmp;
        for (auto& p : hmap) {
            tmp.push_back({p.second, p.first});
        }
        sort(tmp.rbegin(), tmp.rend());
        vector<int> ans;
        for (auto it = tmp.cbegin(); it < tmp.cbegin() + k; ++it) {
            cout << it->second << endl;
            ans.push_back(it->second);
        }
        return ans;
    }
};
