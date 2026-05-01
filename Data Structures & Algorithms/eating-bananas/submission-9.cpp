class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max_k = *max_element(piles.begin(), piles.end());
        int k = max_k;

        int l = 1, r = max_k;
        while (l <= r) {
            int m = (l + r) / 2;
            int hour = time(piles, m);
            if (hour <= h) {
                k = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return k;
    }
    int time(vector<int>& piles, int k) {
        int t = 0;
        for (int i = 0; i < piles.size(); ++i) {
            t += (piles[i] + k - 1) / k;
        }
        return t;
    }
};
