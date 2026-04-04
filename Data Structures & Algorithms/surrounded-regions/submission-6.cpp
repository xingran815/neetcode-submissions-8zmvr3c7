class Solution {
    // find the 'O's that are not surrounded, mark them in an 
    int COL, ROW;
public:
    void solve(vector<vector<char>>& board) {
        ROW = board.size();
        COL = board[0].size();
        vector<vector<bool>> mark(ROW, vector<bool>(COL, false));
        for (int i = 0; i<ROW; ++i) {
            if (board[i][0] == 'O' && !mark[i][0]) {
                helper(board, mark, i, 0);
            }
            if (COL>1 && board[i][COL-1] == 'O' && !mark[i][COL-1]) {
                helper(board, mark, i, COL-1);
            }
        }
        for (int j = 0; j<COL; ++j) {
            if (board[0][j] == 'O' && !mark[0][j]) {
                helper(board, mark, 0, j);
            }
            if (ROW>1 && board[ROW-1][j] == 'O' && !mark[ROW-1][j]) {
                helper(board, mark, ROW-1, j);
            }

        }
        for (int i = 1; i<ROW-1; ++i) {
            for (int j = 1; j<COL-1; ++j) {
                if (board[i][j] == 'O' && !mark[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
    void helper(vector<vector<char>>& board, vector<vector<bool>>& mark, int r, int c) {
        if (min(r,c)<0 || r==ROW || c==COL ||
            mark[r][c] || board[r][c]=='X') {
            return;
        }
        mark[r][c] = true;
        helper(board, mark, r+1, c);
        helper(board, mark, r-1, c);
        helper(board, mark, r, c+1);
        helper(board, mark, r, c-1);
    }
};
