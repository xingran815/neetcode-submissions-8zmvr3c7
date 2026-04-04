class Solution {
public:
    bool isPalindrome(string s) {
        int i_l = 0;
        int i_r = s.size()-1;

        // till the left pointer equals to the right pointer
        // if left pointer doesn't point to a letter, skip one to the right
        // if right pointer doesn't point to a letter, skip one to the left
        // if both pointers point to a letter, compare them
        // if they are not the same, return false

        while (i_l < i_r) {
            if (!isalnum(s[i_l])) {
                i_l++;
            } else if (!isalnum(s[i_r])) {
                i_r--;
            } else {
                if (tolower(s[i_l]) != tolower(s[i_r])) {
                    return false;
                }
                i_l++;
                i_r--;
            }
        }
        return true;
    }
};
