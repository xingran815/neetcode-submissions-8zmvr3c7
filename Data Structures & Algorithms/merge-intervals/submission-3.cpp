class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        for (auto v : intervals) {
            cout << "start: " << v[0] << ", stop: " << v[1] << endl;
        }
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        vector<int> last = intervals[0];
        for (int i = 1; i<intervals.size(); ++i) {
            if (intervals[i][0] <= last[1]) {
                // overlapping
                int stop = max(last[1], intervals[i][1]);
                cout << "last: " << last[0] << ", " << last[1] << ", stop: " << stop << endl;
                ans.back()[1] = stop;
            } else {
                ans.push_back(intervals[i]);
            }
            last = ans.back();

        }
        return ans;
    }
};
