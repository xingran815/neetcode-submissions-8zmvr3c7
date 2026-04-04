class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // sort the array nums
        // if the length of array is 0, return 0
        // otherwise, start the loop starting from the second number
        // have an integer last storing the last number
        // have an integer cur_count counting the number of the current consecutive sequence
        // have an integer long_count counting the number of the longest consecutive sequence
        // if it is consecutive by comparing with the last,
        // assign the number to last
        // cur_count++
        // compare cur_count and long_count
        // if it is not consecutive,
        // assign the number to last
        // cur_count = 1
        // return long_count at the end
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return 1;
        sort(nums.begin(), nums.end());
        int last = nums[0];
        int cur_count = 1;
        int long_count = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == last+1) {
                // consecutive
                last = nums[i];
                ++cur_count;
                if (cur_count > long_count)
                    long_count = cur_count;
            } if (nums[i] == last) {
                // repetitive
                // do nothing
            }
            else {
                // not consecutive
                last = nums[i];
                cur_count = 1;
            }
        }

        return long_count;

    }
};
