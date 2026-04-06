class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.size();
        vector<int> have_break;
        have_break.reserve(size+1);
        unordered_set<string> dict_set(wordDict.begin(), wordDict.end());
        
        have_break.push_back(0);
        for (int i = 1; i<size+1; ++i) {
            int size_dp = have_break.size();
            for (int n = size_dp-1; n>=0; --n) {
                int j = have_break[n];
                if (dict_set.count(s.substr(j, i-j))) {
                    have_break.push_back(i);
                    break;
                }
                
            }
        }
        return have_break.back() == size;
        
    }
};
