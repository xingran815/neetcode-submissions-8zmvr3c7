class Solution {
public:
    bool canPartition(vector<int>& nums) {
        unordered_set<int> poss_sub_sum{0, nums[0]};
        int total = nums[0];
        int size = nums.size();
        if (size == 1) {
            return false;
        }

        for (int n = 1; n < size-1 ; ++n) {
            unordered_set<int> nextDP;
            for (auto i: poss_sub_sum) {
                nextDP.insert(i+nums[n]);
            }
            poss_sub_sum.insert(nextDP.begin(), nextDP.end());
            total += nums[n];
        }
        if ((total+nums[size-1])%2 == 1) {
            return false;
        }
        int candidate_2 = (total+nums[size-1])/2;
        int candidate_1 = (total+nums[size-1])/2 - nums[size-1];
        cout << candidate_1 << ", " << candidate_2 << endl;
        return poss_sub_sum.count(candidate_1) && poss_sub_sum.count(candidate_2);

        
    }
};
