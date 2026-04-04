class Solution {
    int ROW, COL;
public:
    int orangesRotting(vector<vector<int>>& grid) {
        ROW = grid.size();
        COL = grid[0].size();
        vector<vector<int>> days(ROW, vector<int>(COL, INT_MAX));
        int max_day = 0;
        for (int i = 0; i<ROW; ++i) {
            for (int j = 0; j<COL; ++j) {
                if (grid[i][j] == 2) {
                    helper(grid, days, i, j);
                }
            }
        }
        for (int i = 0; i<ROW; ++i) {
            for (int j = 0; j<COL; ++j) {
                if (grid[i][j] == 1) {
                    max_day = max(max_day, days[i][j]);
                }
            }
        }
        return (max_day==INT_MAX ? -1 : max_day);
        
    }
    int helper(vector<vector<int>>& grid, vector<vector<int>>& visit, int r, int c) {
        queue<vector<int>> loc_q;
        loc_q.push({r, c});
        vector<vector<int>> neighbors{{-1,0},{1,0},{0,-1},{0,1}};
        int cnt = 0;
        int max_cnt = 0;
        visit[r][c] = 0;

        while (!loc_q.empty()) {
            int size = loc_q.size();
            cnt++;
            for (int i = 0; i<size; ++i) {
                vector<int> loc = loc_q.front();
                loc_q.pop();
                for (auto &nei : neighbors) {
                    int r_n = loc[0] + nei[0];
                    int c_n = loc[1] + nei[1];
                    if (min(r_n, c_n) < 0 ||
                        r_n == ROW || c_n == COL ||
                        grid[r_n][c_n] == 0 || grid[r_n][c_n] == 2 ||
                        visit[r_n][c_n] <= cnt) {
                        continue;
                    }
                    visit[r_n][c_n] = cnt;
                    max_cnt = cnt;
                    cout << r_n<< ", "<<c_n<<", "<<cnt<<endl;
                    loc_q.push({r_n, c_n});
                }
            }
        }
        return max_cnt;
    }
};
