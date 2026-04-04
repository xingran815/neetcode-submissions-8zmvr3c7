class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur_s;
        backtrack(ans, cur_s, 0, 0, n);
        return ans;
    }

    void backtrack(vector<string> &ans, string &cur_s, int front, int back, int n) {
        if (front == n && back == n) {
            ans.push_back(cur_s);
            return;
        }

        // front <= n, back < front; add back
        if (front < n) {
            cur_s += '(';
            backtrack(ans, cur_s, front+1, back, n);
            cur_s.pop_back();
        }
        if (back < front) {
            cur_s += ')';
            backtrack(ans, cur_s, front, back+1, n);
            cur_s.pop_back();
        }
    }
};
