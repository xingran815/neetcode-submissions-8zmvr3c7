class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> cur;
        dfs(ans, cur, s, 0, 1);
        return ans;
    }
    void dfs(vector<vector<string>> &ans, vector<string> &cur, string &s, int i, int len) {
        if (i > s.size()-1) {
            return;
        }
        if (i+len-1 > s.size()-1) {
            return;
        }

        // check the palindrome of the current substring
        // even
        bool parlindrome = true;
        if (len % 2 == 0) {
            int l = i + (len-1)/2;
            int r = i + len/2;
            while (l >= i && r <= s.size()-1) {
                if (s[l] != s[r]) {
                    // NOT palindrome
                    parlindrome = false;
                    break;
                }
                l--;
                r++;
            }
        } else {
            // odd
            int l = i + len/2;
            int r = i + len/2;
            while (l >= i && r <= s.size()-1) {
                if (s[l] != s[r]) {
                    // NOT palindrome
                    parlindrome = false;
                    break;
                }
                l--;
                r++;
            }
        }
        if (parlindrome) {
            cur.push_back(s.substr(i, len));
            if (i+len > s.size()-1) {
                ans.push_back(cur);
            }
            dfs(ans, cur, s, i+len, 1);
            cur.pop_back();
        }
        dfs(ans, cur, s, i, len+1);


        // situation 1:
        // check the palindrome
        // pushs substring starting from i with length len to the cur
        // call next dfs
        // increment the length
    }
};
