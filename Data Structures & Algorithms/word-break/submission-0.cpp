class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.size();
        vector<bool> have_break(size+1, false);
        unordered_set<string> dict_set(wordDict.begin(), wordDict.end());
        
        have_break[0] = true;
        for (int i = 1; i<size+1; ++i) {
            for (int j = i-1; j>=0; --j) {
                if (have_break[j]) {
                    cout << s.substr(j, i-j) << endl;
                    if (dict_set.count(s.substr(j, i-j))) {
                        have_break[i] = true;
                        break;
                    }
                }
                
            }
        }
        return have_break[size];
        
    }
};
