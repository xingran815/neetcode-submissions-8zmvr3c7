class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // sort the piles
        sort(piles.begin(), piles.end());
        int l = 1;
        int r = piles[piles.size()-1];
        int m;

        if (h == piles.size()) {
            return piles[piles.size()-1];
        }
        int candidate = INT_MAX;
        while (l <= r) {
            m = (l+r)/2;
            int time = 0;
            for (int i = 0; i < piles.size(); ++i) {
                time = time + ceil(((double)piles[i])/m);
            }
            cout << "m: " << m << ", time: " << time << endl;
            if (time == h) {
                candidate = min(candidate, m);
                r = m - 1;
            } else if (time < h) {
                candidate = min(candidate, m);
                r = m - 1;
            } else if (time > h) {
                l = m + 1;
            }
        }
        return candidate;
    }
};
