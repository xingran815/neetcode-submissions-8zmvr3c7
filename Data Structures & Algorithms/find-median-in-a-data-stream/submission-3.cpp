class MedianFinder {
    // use two heaps, min_heap and max_heap
    // max_heap for the left half
    // min_heap for the right half
    // max_heap.top() <= min_heap.top()
    // max_heap.size() ~= min_heap.size() + 1
    // when total is odd, the median should be in max_heap
    // when total is even, the median should be the avg of tops of min_heap and max_heap
private:
    int total;
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<>> min_heap;
public:
    MedianFinder() {
        total = 0;
    }
    
    void addNum(int num) {
        total++;
        // fill the left half firstly
        if (max_heap.empty()) {
            max_heap.push(num);
            return;
        }
        // fill the right half secondly
        if (min_heap.empty()) {
            if (num < max_heap.top()) {
                // swap the top of min_heap and max_heap
                min_heap.push(max_heap.top());
                max_heap.pop();
                max_heap.push(num);
            } else {
                min_heap.push(num);
            }
            return;
        }
        if (num <= max_heap.top()) {
            max_heap.push(num);
            if (max_heap.size() > (total+1)/2) {
                // move one element from min_heap to max_heap
                int tmp = max_heap.top();
                max_heap.pop();
                min_heap.push(tmp);
            }
        } else {
            min_heap.push(num);
            if (min_heap.size() > total - (total+1)/2) {
                // move one element from min_heap to max_heap
                int tmp = min_heap.top();
                min_heap.pop();
                max_heap.push(tmp);
            }
        }
        // cout << max_heap.top() << ", " << min_heap.top() << endl;
    }
    
    double findMedian() {
        if (total % 2 == 1) {
            // odd
            return max_heap.top();
        } else {
            // even
            int a = max_heap.top();
            int b = min_heap.top();
            return (a+b)/2.0;
        }
        
    }
};
