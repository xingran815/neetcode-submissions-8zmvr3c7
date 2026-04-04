class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> row(9);
        vector<unordered_set<int>> column(9);
        vector<unordered_set<int>> tile(9);

        // for each valid element, it must follow 3 rules
        // the row rule, the column rule, and the tile rule
        // use 9 hash maps for rows, 
        // use 9 hash maps for columns,
        // use 9 hash maps for tiles,
        // whenever there is a repeated value, return false;


        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    // is a number
                    int n = board[i][j] - '0';
                    // check the row
                    if (row[i].find(n) != row[i].end())
                        return false;
                    else
                        row[i].insert(n);
                    // check the column
                    if (column[j].find(n) != column[j].end()) {
                        // found a repeated value
                        return false;
                    } else {
                        column[j].insert(n);
                    }
                    // check the tile i/3*3 + j/3
                    int t = i/3*3 + j/3;
                    if (tile[t].find(n) != tile[t].end()) {
                        // found a repeated value
                        return false;
                    } else {
                        tile[t].insert(n);
                    }
                }
            }
        }
        return true;
    }
};
