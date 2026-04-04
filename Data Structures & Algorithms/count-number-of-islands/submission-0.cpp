class Solution {
    int COL, ROW;
public:
    int numIslands(vector<vector<char>>& grid) {
        this->ROW = grid.size();
        this->COL = grid[0].size();
        int ans = 0;
        for (int r=0; r<grid.size(); ++r) {
            for (int c=0; c<grid[0].size(); ++c) {
                if (grid[r][c] == '1') {
                    traverse_island(grid, r, c);
                    ans++;
                }
            }
        }

        return ans;
        
    }
    void traverse_island(vector<vector<char>>& grid,
        int r,
        int c) {
        if (min(r,c) < 0 ||
            r == this->ROW || c == this->COL ||
            grid[r][c] == '0') {
            return;
        }
        grid[r][c] = '0';
        traverse_island(grid, r+1, c);
        traverse_island(grid, r, c+1);
        traverse_island(grid, r-1, c);
        traverse_island(grid, r, c-1);
    }
};
