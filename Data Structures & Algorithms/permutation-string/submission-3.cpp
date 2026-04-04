class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // s1's length is size1, s2's length is size2
        // having a sliding window of length size1 in string s2
        // if the sliding window is the permutation of s1, then return true
        // use a hash map to record the letter and its frequency.
        vector<int> s1_freq(26, 0);
        vector<int> s2_subfreq(26, 0);

        // 1. construct s1 hash map
        for (char c : s1) {
            s1_freq[c-'a']++;
        }

        // 2. sliding window
        int l = 0;                 // starting pointer
        int r = 0; // ending pointer
        while (r < s2.size()) {
            // 3. construct s2 sub map
            cout << "r: " << s2[r] << endl;
            s2_subfreq[s2[r]-'a']++;
            if (r-l+1 == s1.size()) {
                // length of sliding window = s1.size()
                // 4. compare s1_map and s2_submap
                bool permutation = true;
                for (int i = 0; i < 26; i++) {
                    if (s1_freq[i] != s2_subfreq[i]) {
                        permutation = false;
                        break;
                    }
                }
                if (permutation) {
                    return true;
                }
                // iterate pointer l 
                s2_subfreq[s2[l]-'a']--;
                l++;
            }
            r++;
        }
        return false;
    }
};
