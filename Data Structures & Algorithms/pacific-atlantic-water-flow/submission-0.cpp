class Solution {
    int ROW, COL;
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROW = heights.size();
        COL = heights[0].size();
        vector<vector<int>> ans;
        unordered_set<int> cell_set;
        for (int i = 0; i<ROW; ++i) {
            for (int j = 0; j<COL; ++j) {
                helper(ans, cell_set, heights, i, j);
            }
        }
        return ans;
        
    }

    void helper(vector<vector<int>> &ans, unordered_set<int> &cell_set,
            vector<vector<int>>& heights, int r, int c) {
        queue<vector<int>> q;
        q.push({r, c});
        vector<vector<int>> neighbors{{0,-1},{0,1},{-1,0},{1,0}};
        vector<vector<bool>> visit(ROW,vector<bool>(COL, false));
        visit[r][c] = true;

        bool reach_parcific = false;
        bool reach_atlantic = false;
        while(!q.empty()) {
            int size = q.size();
            for (int i = 0; i<size; ++i) {
                auto loc = q.front();
                if (cell_set.count(loc[0]*COL+loc[1]) != 0) {
                    ans.push_back({r,c});
                    cell_set.insert(r*COL+c);
                    return;
                }
                q.pop();
                if (is_pacific(loc)) reach_parcific = true;
                if (is_atlantic(loc)) reach_atlantic = true;
                if (reach_parcific && reach_atlantic) {
                    ans.push_back({r,c});
                    cell_set.insert(r*COL+c);
                    return;
                }
                for (auto nei: neighbors) {
                    int r_n = loc[0] + nei[0];
                    int c_n = loc[1] + nei[1];
                    if (min(r_n, c_n) < 0 ||
                        r_n == ROW || c_n == COL ||
                        visit[r_n][c_n] ||
                        heights[loc[0]][loc[1]] < heights[r_n][c_n]) {
                        continue;
                    }
                    visit[r_n][c_n] = true;
                    q.push({r_n, c_n});
                }

            }


        }
    }

    bool is_pacific(vector<int> loc) {
        if (loc[0] == 0 || loc[1] == 0) {
            return true;
        }
        return false;
    }
    bool is_atlantic(vector<int> loc) {
        if (loc[0] == ROW-1 || loc[1] == COL-1) {
            return true;
        }
        return false;
    }
};
