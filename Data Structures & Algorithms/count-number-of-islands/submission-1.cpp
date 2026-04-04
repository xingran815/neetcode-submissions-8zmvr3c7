class Solution {
    int ROW;
    int COL;
public:
    int numIslands(vector<vector<char>>& grid) {
        this->ROW = grid.size();
        this->COL = grid[0].size();
        int ans = 0;
        for (int r=0; r<grid.size(); ++r) {
            for (int c=0; c<grid[0].size(); ++c) {
                if (grid[r][c] == '1') {
                    bfs(grid, r, c);
                    ans++;
                }
            }
        }

        return ans;
    }

    void bfs(vector<vector<char>>& grid, int r_i, int c_i) {
        queue<vector<int>> q;
        q.push({r_i,c_i});
        vector<vector<int>> neighbour = {{-1,0},{0,-1},{1,0},{0,1}};

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i<size; ++i) {
                auto pr = q.front();
                q.pop();
                int r = pr[0];
                int c = pr[1];
                grid[r][c] = '0';
                for (auto n : neighbour) {
                    int r_n = n[0];
                    int c_n = n[1];
                    if (min(r+r_n, c+c_n) < 0 ||
                        r+r_n == this->ROW ||
                        c+c_n == this->COL ||
                        grid[r+r_n][c+c_n] == '0') {
                            continue;
                    }
                    q.push({r+r_n, c+c_n});
                }


            }
        }

    }
};
