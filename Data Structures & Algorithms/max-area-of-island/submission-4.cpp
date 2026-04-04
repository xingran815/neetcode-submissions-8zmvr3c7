class Solution {
    int COL;
    int ROW;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        this->ROW = grid.size();
        this->COL = grid[0].size();
        vector<vector<bool>> visit(ROW,vector<bool>(COL,false));
        for (int r = 0; r < ROW; ++r) {
            for (int c = 0; c<COL; ++c) {
                if (grid[r][c] == 1 && !visit[r][c]) {
                    max_area = max(max_area, bfs(grid,r,c,visit));
                }
            }
        }
        return max_area;
    }
    int bfs(vector<vector<int>>& grid, int r_i, int c_i,
            vector<vector<bool>>& visit) {
        // create the queue of the initial location
        queue<vector<int>> loc_q;
        loc_q.push({r_i,c_i});
        visit[r_i][c_i] = true;
        vector<vector<int>> neighbour({{-1,0},{1,0},{0,-1},{0,1}});

        int count = 0;
        while (!loc_q.empty()) {
            int size = loc_q.size();
            // loop over the locations on the same level
            for (int i=0; i<size; ++i) {
                int r = loc_q.front()[0];
                int c = loc_q.front()[1];
                count++;
                cout << i << ", " << r << ", " << c << endl;
                loc_q.pop();
                for (auto & n : neighbour) {
                    int r_n = n[0];
                    int c_n = n[1];
                    if (min(r+r_n,c+c_n)<0 ||
                        r+r_n==ROW || c+c_n==COL ||
                        visit[r+r_n][c+c_n] ||
                        grid[r+r_n][c+c_n] == 0) {
                        // out of boundary, visited, sea
                        continue;
                    }
                    // add the eligable loc to the queue, and make it visited
                    visit[r+r_n][c+c_n] = true;
                    loc_q.push({r+r_n,c+c_n});
                }
            }
        }
        return count;
    }
};
