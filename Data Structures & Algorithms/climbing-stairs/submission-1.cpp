class Solution {
public:
    int climbStairs(int n) {
        if (n==1) return 1;
        if (n==2) return 2;
        vector<int> steps(n+1, 0);
        steps[0] = 0;
        steps[1] = 1;
        steps[2] = steps[1] + 1;
        for (int i = 3; i<=n; ++i) {
            steps[i] = steps[i-1] + steps[i-2];
            cout << i << ", " << steps[i] << endl;
        }

        return steps[n];
        
    }
};
