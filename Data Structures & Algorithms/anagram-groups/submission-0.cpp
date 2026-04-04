class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> m;
        for (const auto& str : strs) {
            vector<int> count(26, 0);
            for (char c : str) {
                count[c - 'a']++;
            }
            string s;
            s += to_string(count[0]);
            for (int i = 1; i < 26; ++i) {
                s += ',';
                s += to_string(count[i]);
            }
            m[s].push_back(str);
        }

        for (const auto& p: m) {
            ans.push_back(p.second);
        }

        return ans;
    }
};
