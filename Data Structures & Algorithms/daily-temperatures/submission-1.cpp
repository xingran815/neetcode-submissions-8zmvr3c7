class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        vector<int> results(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!st.empty()) {
                pair<int, int> p = st.top();
                if (temperatures[i] > p.first) {
                    results[p.second] = i - p.second;
                    st.pop();
                } else {
                    break;
                }
            }
            st.push(pair<int,int>(temperatures[i], i));
        }
        return results;
    }
};
