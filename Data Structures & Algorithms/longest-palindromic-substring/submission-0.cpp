class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        int count = 0;
        for (int n = 0; n < s.size(); ++n) {
            // even numbers
            {
                int i=n, j=n+1;
                while (i>=0 && j < s.size() && s[i] == s[j]) {
                    int len = j - i + 1;
                    if (len > count) {
                        count = len;
                        ans = s.substr(i, len);
                    }
                    i--;
                    j++;
                }
            }
            // odd numbers
            {
                int i=n, j=n;
                while (i>=0 && j < s.size() && s[i] == s[j]) {
                    int len = j - i + 1;
                    if (len > count) {
                        count = len;
                        ans = s.substr(i, len);
                    }
                    i--;
                    j++;
                }
            }
        }
        return ans;
    }
};
