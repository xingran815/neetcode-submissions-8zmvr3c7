class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0;
        int r = m*n - 1;
        while (l <= r) {
            int bin = (l+r)/2;
            int idx0 = bin/n;
            int idx1 = bin%n;
            cout << "idx0: " << idx0 << ", idx1: " << idx1 <<
                ", l: " << l << ", r: " << r << ", bin: " << bin << endl;
            if (matrix[idx0][idx1] > target) {
                r = bin - 1;
            } else if (matrix[idx0][idx1] < target) {
                l = bin + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
