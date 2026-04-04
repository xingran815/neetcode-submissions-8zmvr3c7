class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> max_pq;
        for (auto p : points) {
            int dis_square = p[0]*p[0] + p[1]*p[1];
            max_pq.push({dis_square, {p[0], p[1]}});
        }
        while (max_pq.size() > k) {
            max_pq.pop();
        }
        vector<vector<int>> ans;
        while (!max_pq.empty()) {
            auto p = max_pq.top();
            ans.push_back({p.second.first, p.second.second});
            max_pq.pop();
        }

        return ans;
        
    }
};
