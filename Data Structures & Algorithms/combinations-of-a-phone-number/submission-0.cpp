class Solution {
    vector<string> translator{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        return helper(digits, 0);
        
    }

    vector<string> helper (string &digits, int i) {
        if (i == digits.size()) {
            return {""};
        }
        vector<string> perms = helper(digits, i+1);
        vector<string> ans;

        int dig = (int)(digits[i]-'0');
        string &pattern = translator[dig];
        for (auto &p : perms) {
            for (char c: pattern) {
                string copy = p;
                cout << "before inserting: " << copy << endl;
                cout << "size of copy: " << copy.size() << endl;
                cout << c << endl;
                copy.insert(0,1,c);
                cout << "after inserting: " << copy << endl;
                cout << "size of copy: " << copy.size() << endl;
                ans.push_back(copy);
            }
        }
        return ans;
    }
};
