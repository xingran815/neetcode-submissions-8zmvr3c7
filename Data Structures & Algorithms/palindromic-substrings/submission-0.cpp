class Solution {
public:
    int countSubstrings(string s) {
        int size = s.size();
        vector<vector<bool>> palin_2d(size, vector<bool>(size, false));
        int count = 0;
        for (int i = size-1; i>=0; --i) {
            for (int j = i; j<size; ++j) {
                if (s[i] == s[j] && (j-i < 2 || palin_2d[i+1][j-1])) {
                    palin_2d[i][j] = true;
                    count++;
                }
            }
        }
        return count;
    }
};
