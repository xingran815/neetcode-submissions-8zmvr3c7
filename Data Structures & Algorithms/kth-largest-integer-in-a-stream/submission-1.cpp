class KthLargest {
    int K;
    priority_queue<int, vector<int>, greater<int>> min_pq;
public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for (int i : nums) {
            min_pq.push(i);
        }
        while (min_pq.size() > K) {
            min_pq.pop();
        }
    }
    
    int add(int val) {
        min_pq.push(val);
        if (min_pq.size() > K) {
            min_pq.pop();
        }
        return min_pq.top();
    }
};
