class Solution {
public:
    int findMin(vector<int> &nums) {
        // if the the array is rotated, the last element is lower 
        // than the first element
        // if [m] < [m-1] found
        // if [m] < [r] r = m;
        // ir [m] > [l] l = m;

        int n = nums.size();
        int l = 0;
        int r = n - 1;
        if (nums[l] <= nums[r]) {
            return nums[l];
        }
        while (l + 1 != r) {
            int m = (l+r)/2;
            if (nums[m] < nums[r]) {
                r = m;
            } else if (nums[m] > nums[l]) {
                l = m;
            }
        }
        return nums[r];
    }
};
