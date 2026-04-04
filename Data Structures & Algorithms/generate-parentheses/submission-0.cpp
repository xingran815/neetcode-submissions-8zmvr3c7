class Solution {
private:
    int LEN;
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        LEN = n*2;
        string s = "";
        stack<char> q;
        helper(ans, s, q, '(');
        return ans;
    }

    // a queue for tracking the parentheses
    // vector<string> ans for the results
    // string as the temporary results
    void helper(vector<string> &ans, string s, stack<char> q, char c) {
        // backtracking problem
        // when the criterion is satisfied
        //      push the string to the vector
        //      return
        // otherwise, check if the front, back parenthese can be push_back into the string
        //      if not, return
        // add '{' - call helper (c='{') 
        // add '}' - call helper (c='{') 
        if (s.size() > LEN) {
            return;
        }
        if (c == ')') {
            if (!q.empty() && q.top() == '(') {
                cout << ") is added" << endl;
                q.pop();
                s += ')';
            } else {
                cout << ") isn't added" << endl;
                return;
            }
        } else {
            cout << "( is given" << endl;
            q.push('(');
            s += '(';
        }
        if (q.size() == 0 && s.size() == LEN) {
            ans.push_back(s);
            return;
        }
        helper(ans, s, q, '(');
        helper(ans, s, q, ')');
    }

};
