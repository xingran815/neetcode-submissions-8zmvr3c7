class Solution {
public:
    int numSquares(int n) {
        // bottom -> top dynamic programming
        // i = 1...sqrt[n]
        // sol[n] = min(sol[n], 1 + sol[n-i^2]);
        vector<int> sol(n+1, n);
        sol[0] = 0;
        for (int i = 1; i<=n; ++i) {
            for (int s = 1; s*s<=i; ++s) {
                sol[i] = min(sol[i], 1+sol[i-s*s]);
            }
        }
        return sol[n];
    }
};