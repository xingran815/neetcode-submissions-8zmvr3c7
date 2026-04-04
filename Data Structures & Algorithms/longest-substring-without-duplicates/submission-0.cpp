class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // two pointers l, r = 0, 1
        // use hash_map to store the <char, int>(character, idx) pair
        // of the current non repeating substring
        // max(substring.len, max_len) is the longest substring length
        // if there is a repetitive character, 
        // start l from the next character, 
        // delete all the chars in hash_map
        int l = 0, r = 1;
        if (s.size() < 2) {
            return s.size();
        }
        int n = s.size();
        // hash map
        unordered_map<char, int> hmap;
        hmap.emplace(s[l], l);
        int max_len = 1;
        while (r < n) {
            auto p = hmap.find(s[r]);
            if (p != hmap.end()) {
                // [r] exists in the substring
                // delete the characters from l to p.second
                int tmp = p->second;
                while (l <= tmp) {
                    hmap.erase(s[l]);
                    l++;
                }
            }
            hmap.emplace(s[r], r);
            max_len = max(max_len, (int)hmap.size());
            r++;
        }
        return max_len;
    }
};
