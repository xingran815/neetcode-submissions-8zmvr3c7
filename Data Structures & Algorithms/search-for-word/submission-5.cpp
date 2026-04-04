class Solution {
private:
    int ROW, COL;
    int match;

public:
    bool exist(vector<vector<char>>& board, string word) {
        match = false;
        ROW = board.size();
        COL = board[0].size();
        for (int r = 0; r < board.size(); ++r) {
            for (int c = 0; c < board[0].size(); ++c) {
                if (board[r][c] == word[0]) {
                    cout << "found the first: " << r << ", " << c << endl;
                    vector<vector<bool>> visit(ROW, vector<bool>(COL, false));
                    dfs(board, word, 0, r, c, visit);
                    if (match) {
                        return match;
                    }
                }
            }
        }
        return match;
    }

    void dfs(vector<vector<char>>& board, string &word, int i, int r, int c,
        vector<vector<bool>> &visit) {
        if (min(r,c)<0 || r>=ROW || c>=COL ||
            visit[r][c] ||
            board[r][c] != word[i]) {
            return;
        }
        visit[r][c] = true;
        if (i+1 == word.size()) {
            match = true;
            return;
        }
        dfs(board, word, i+1, r+1, c, visit);
        dfs(board, word, i+1, r-1, c, visit);
        dfs(board, word, i+1, r, c+1, visit);
        dfs(board, word, i+1, r, c-1, visit);
        visit[r][c] = false;
    }
};
