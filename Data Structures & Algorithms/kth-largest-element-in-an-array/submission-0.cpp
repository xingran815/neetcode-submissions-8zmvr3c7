class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // use minimum priority_queue, the smallest element is the first element
        priority_queue<int, vector<int>, greater<int>> min_pq;
        for (int n : nums) {
            min_pq.push(n);
            if (min_pq.size() > k)
                min_pq.pop();
        }
        return min_pq.top();
        
    }
};
