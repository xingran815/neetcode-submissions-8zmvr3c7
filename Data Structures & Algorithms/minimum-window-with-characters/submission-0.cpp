class Solution {
public:
    string minWindow(string s, string t) {
        // sliding window
        // slide pointer l from 0 to size-1,
        // for each pointer l, shrink pointer r, find the minimal length
        // of the sliding window

        // use vector<int> 52 to store the frequency of the letters
        vector<int> s_freq(52, 0);
        vector<int> t_freq(52, 0);
        unordered_set<char> t_appear(t.begin(), t.end());
        for (char c : s) {
            s_freq[c2i(c)]++;
        }
        for (char c : t) {
            t_freq[c2i(c)]++;
        }
        int match = 0;
        for (int i = 0; i < t_freq.size(); ++i) {
            if (t_freq[i] != 0) {
                if (t_freq[i] <= s_freq[i]) {
                    match++;
                } else {
                    // even the whole string s doesn't contain every 
                    // character in t
                    return "";
                }
            }
        }
        int min_length = s.size();
        string ans = s;

        // sliding window l 0 -> size-1
        //                r size-1 ->0
        for (int l = 0; l < s.size()-1; ++l) {
            vector<int> s_freq_dup = s_freq;
            for (int r = s.size()-1; r > l; r--) {
                // remove s[r]
                int idx = c2i(s[r]);
                s_freq_dup[idx]--;
                if (t_freq[idx] > 0 && t_freq[idx] > s_freq_dup[idx]) {
                    // invalid
                    break;
                } else {
                    if (r-l < min_length) {
                        ans = s.substr(l, r-l);
                        cout << "l: " << l << ", r: " << r
                            << ", idx: " << idx << ", s_freq_dup: " << s_freq_dup[idx]
                            << ", t_freq: " << t_freq[idx] << ", ans:" << ans << endl;
                        min_length = r-l;
                    }
                }
            }
            s_freq[c2i(s[l])]--;
            if (t_freq[c2i(s[l])] > 0 && t_freq[c2i(s[l])] > s_freq[c2i(s[l])]) {
                // there is no substring in s that matches t
                cout << "l: " << s[l] << endl;
                break;
            } else {
                if (s.size()-1-l<min_length) {
                    ans = s.substr(l+1, s.size()-1-l);
                    min_length = s.size()-1-l;
                    cout << "ans: " << ans << endl;
                }
            }
        }
        return ans;
    }
    int c2i(char c) {
        int idx;
        if (c >= 'a' && c <= 'z') {
            idx = c - 'a';
        } else {
            idx = c - 'A' + 26;
        }
        return idx;
    }
};
