class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        // if it is an open bracket, push it in
        // if it is a close bracket, check if the top is the
        // corresponding open bracket,
        // if yes, pop it
        // if not, return false
        // after the loop, when the size of the stack is not zero,
        // return false
        // otherwise, return true
        for (auto c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else if (c == ')') {
                if ((! st.empty()) && st.top() == '(') {
                    st.pop();
                } else {
                    return false;
                }
            } else if (c == ']') {
                if ((! st.empty()) && st.top() == '[') {
                    st.pop();
                } else {
                    return false;
                }
            } else if (c == '}') {
                if ((! st.empty()) && st.top() == '{') {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        if (! st.empty())
            return false;
        return true;
        
    }
};
