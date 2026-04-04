class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> v_prefix_max(height.size(), 0);
        vector<int> v_suffix_max(height.size(), 0);

        int prefix_max = 0, suffix_max = 0;
        int sum = 0;
        v_prefix_max[0] = 0;
        for (int i = 1; i < height.size(); ++i) {
            prefix_max = max(prefix_max, height[i-1]);
            v_prefix_max[i] = prefix_max;
        }
        v_suffix_max[height.size()-1] = 0;
        for (int i = height.size()-2; i >= 0; --i) {
            suffix_max = max(suffix_max, height[i+1]);
            v_suffix_max[i] = suffix_max;
        }
        for (int i = 0; i < height.size(); ++i) {
            int water_lvl = min(v_suffix_max[i], v_prefix_max[i]);
            water_lvl = (water_lvl > height[i]) ? water_lvl-height[i] : 0;
            sum += water_lvl;
        }
        return sum;
        
    }
};
