class Solution {
public:
    int findMin(vector<int> &nums) {
        int ans = nums[0];
        int l = 0, r = nums.size()-1;

        while (l <= r) {
            int m = (l+r)/2;
            if (nums[m] <= nums[r]) {
                ans = (nums[m] < ans) ? nums[m] : ans;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }


        return ans;
    }
};
