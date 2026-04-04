class Solution {
    int ROW, COL;
public:
    // helper function starts from the treasure loc,
    // uses BFS to traverse each neighbor, 
    // assign each available INF to the level
    void islandsAndTreasure(vector<vector<int>>& grid) {
        ROW = grid.size();
        COL = grid[0].size();
        
        for (int i = 0; i<ROW; ++i) {
            for (int j = 0; j<COL; ++j) {
                if (grid[i][j] == 0) {
                    helper(grid, i, j);
                }
            }
        }
        // helper(grid, 0, 2);
    }

    void helper(vector<vector<int>>& grid, int r, int c) {
        queue<vector<int>> loc_q;
        loc_q.push({r, c});
        vector<vector<int>> neighbors{{-1,0},{1,0},{0,-1},{0,1}};
        int cnt = 0;
        vector<vector<bool>> visit(ROW, vector<bool>(COL, false));


        while (!loc_q.empty()) {
            int size = loc_q.size();
            cnt++;
            for (int i = 0; i<size; ++i) {
                vector<int> loc = loc_q.front();
                loc_q.pop();
                visit[loc[0]][loc[1]] = true;
                for (auto &nei : neighbors) {
                    int r_n = loc[0] + nei[0];
                    int c_n = loc[1] + nei[1];
                    if (min(r_n, c_n) < 0 ||
                        r_n == ROW || c_n == COL ||
                        grid[r_n][c_n] == 0 || grid[r_n][c_n] == -1 ||
                        visit[r_n][c_n] || 
                        grid[r_n][c_n] <= cnt) {
                        continue;
                    }
                    grid[r_n][c_n] = cnt;
                    loc_q.push({r_n, c_n});
                }
            }
        }
    }

};
