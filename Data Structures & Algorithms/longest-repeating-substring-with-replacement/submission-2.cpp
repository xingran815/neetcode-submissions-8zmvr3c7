class Solution {
public:
    int characterReplacement(string s, int k) {
        // length - max_freq <= k, then the length is valid
        // int length = 0
        // vector<int> freq(26, 0);
        // sliding r from 0 to the last index

        string sub_s = "";
        int l = 0;
        int max_length = 0;

        for (int r = 0; r < s.size(); ++r) {
            vector<int> freq(26, 0);
            // calculate the freq of the substring
            for (int i = l; i <= r; ++i) {
                freq[s[i]-'A']++;
            }
            auto p_freq = max_element(freq.begin(), freq.end());
            // calculate the max_freq of the substring
            int max_freq = *p_freq;
            // the length of the substring
            int length = r - l + 1;
            if (length - max_freq <= k) {
                max_length = max(length, max_length);
            } else {
                l++;
            }

        }
        return max_length;
    }
};
