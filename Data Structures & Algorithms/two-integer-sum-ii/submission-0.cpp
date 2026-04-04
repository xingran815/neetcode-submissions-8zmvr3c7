class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // i_l starts from the left side of the vector
        // i_r starts from the right side of the vector
        // while i_l < i_r
        // when [i_l] + [i_r] == target, return
        // when [i_l] + [i_r] < target, i_l++
        // when [i_l] + [i_r] > target, i_r--

        // !! 1-indexed array

        int i_l = 0;
        int i_r = numbers.size()-1;

        vector<int> ans;
        while (i_l < i_r) {
            if (numbers[i_l] + numbers[i_r] == target) {
                ans.push_back(i_l+1);
                ans.push_back(i_r+1);
                return ans;
            } else if (numbers[i_l] + numbers[i_r] < target) {
                i_l++;
            } else {
                // numbers[i_l] + numbers[i_r] > target
                i_r--;
            }
        }
    }
};
