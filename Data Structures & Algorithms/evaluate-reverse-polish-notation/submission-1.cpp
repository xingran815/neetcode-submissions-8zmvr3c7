class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int ans;
        for (auto & t : tokens) {
            if (t == "+") {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                ans = num1 + num2;
                st.push(ans);
            } else if (t == "-") {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                ans = num1 - num2;
                st.push(ans);
             } else if (t == "*") {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                ans = num1 * num2;
                st.push(ans);
             } else if (t == "/") {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                ans = num1 / num2;
                st.push(ans);
             } else {
                ans = stoi(t);
                st.push(ans);
             }
        }
        return ans;
    }
};
