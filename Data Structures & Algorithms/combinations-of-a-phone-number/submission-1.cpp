class Solution {
    vector<string> translator{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        return helper(digits, digits.size()-1);
        
    }

    vector<string> helper (string &digits, int i) {
        if (i == -1) {
            return {""};
        }
        vector<string> perms = helper(digits, i-1);
        vector<string> ans;

        int dig = (int)(digits[i]-'0');
        string &pattern = translator[dig];
        for (auto &p : perms) {
            for (char c: pattern) {
                string copy = p;
                copy.push_back(c);
                ans.push_back(copy);
            }
        }
        return ans;
    }
};
