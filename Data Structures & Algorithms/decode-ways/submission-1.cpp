class Solution {
public:
    int numDecodings(string s) {
        // size[1], 1
        // size[2], if the 10 <= num[last 2] <=26, 1 + size[1], otherwise size[1]
        // size[3], if the 10 <= num[last 2] <=26, size[2]+ size[1], otherwise size[2]
        int size = s.size();
        if (size == 0) {
            return size;
        }
        if (size == 1) {
            if (s[0] == '0')
                return 0;
            return 1;
        }
        vector<int> ways(size+1, 0);
        ways[0] = 0;
        if (s[0] == '0') {
            ways[1] = 0;
        } else {
            ways[1] = 1;
        }
        if (s[0] == '1' || (s[0] == '2' && (s[1]-'0' >= 0 && s[1]-'0' <= 6))) {
            ways[2] = 1;
        }
        if (s[1] != '0') {
            ways[2] += ways[1];
        }
        for (int i = 3; i < size+1; ++i) {
            if (s[i-2] == '1' || (s[i-2] == '2' && (s[i-1]-'0' >= 0 && s[i-1]-'0' <= 6))) {
                // 10 <= s[last 2] <=26
                ways[i] = ways[i-2];
            } 
            if (s[i-1] != '0') {
                ways[i] += ways[i-1];
            }
        }
        return ways[size];
        
    }
};
