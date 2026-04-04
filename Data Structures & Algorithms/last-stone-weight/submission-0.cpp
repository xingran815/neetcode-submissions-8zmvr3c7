class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> max_pq(stones.begin(), stones.end());
        while (max_pq.size() > 1) {
            int x = max_pq.top();
            max_pq.pop();
            int y = max_pq.top();
            max_pq.pop();
            if (x == y) {
                continue;
            } else {
                int remaining = max(x,y) - min(x,y);
                max_pq.push(remaining);
            }
        }
        if (max_pq.empty()) {
            return 0;
        }
        return max_pq.top();
    }
};
