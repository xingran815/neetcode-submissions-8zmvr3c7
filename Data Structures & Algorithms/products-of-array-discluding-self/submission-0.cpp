class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> p1(size);
        vector<int> p2(size);

        p1[0] = 1;
        for (int i = 1; i < size; ++i) {
            p1[i] = p1[i-1] * nums[i-1];
        }
        p2[size-1] = 1;
        for (int j = size-2; j >= 0; --j) {
            p2[j] = p2[j+1] * nums[j+1];
        }
        vector<int> ans(size);
        for (int k = 0; k < size; ++k) {
            cout << p1[k] << ' ' << p2[k] << endl;
            ans[k] = p1[k] * p2[k];
        }

        return ans;

    }
};
