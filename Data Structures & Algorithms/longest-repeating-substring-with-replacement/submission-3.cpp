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
        vector<int> freq(26, 0);

        for (int r = 0; r < s.size(); ++r) {
            // calculate the freq of the substring
            freq[s[r]-'A']++;
            // calculate the max_freq of the substring
            int max_freq = *max_element(freq.begin(), freq.end());
            // the length of the substring
            int length = r - l + 1;
            while (l <= r && length - max_freq > k) {
                cout << "move l pointer. " << 
                    l << r << length << max_freq << endl;
                for (auto i : freq) {
                    cout << i << endl;
                }
                freq[s[l]-'A']--;
                l++;
                length = r - l + 1;
                max_freq = *max_element(freq.begin(), freq.end());
            }
            max_length = max(max_length, length);
        }
        return max_length;
    }
};
