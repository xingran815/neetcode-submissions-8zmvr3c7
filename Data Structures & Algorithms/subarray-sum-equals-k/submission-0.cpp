class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // prefix_2 - prefix_1 = k
        // prefix_1 = prefix_2 - k
        // calculate prefix_2 - k

        unordered_map<int, vector<int>> prefix_hmap; //<prefix_sum, indices>
        int prefix_sum = 0;
        int count = 0;
        for (int i = 0; i<nums.size(); ++i) {
            prefix_sum += nums[i];
            if (prefix_sum == k) {
                count++;
            }
            int rest = prefix_sum - k;
            auto p = prefix_hmap.find(rest);
            if (p != prefix_hmap.end()) {
                count += p->second.size();
            }
            prefix_hmap[prefix_sum].push_back(i);
        }
        return count;
    }
};