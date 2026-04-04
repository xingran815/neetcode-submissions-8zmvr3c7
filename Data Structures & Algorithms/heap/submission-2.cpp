class MinHeap {
private:
    vector<int> heap;
public:
    MinHeap() {
        // create a dummy number
        // as a heap is index 1 based
        heap.push_back(0);
    }

    void push(int val) {
        heap.push_back(val);
 
        // adjust the heap structure
        int i = heap.size()-1;
        while (i/2>0 && heap[i/2] > heap[i]) {
            // swap heap[i/2] and heap[i]
            int tmp = heap[i];
            heap[i] = heap[i/2];
            heap[i/2] = tmp;
            // adjust i
            i = i/2;
        }

    }

    int pop() {
        cout << "before poping: ";
        for (int i : heap) {
            cout << i << ", ";
        }
        cout << endl;
        if (heap.size() < 2) {
            // minheap is empty
            return -1;
        }
        int minimum = heap[1];

        // move the last element to the first element to keep the heap structure
        int i = heap.size()-1;
        heap[1] = heap[i];
        heap.pop_back();

        // maintain the order property: the parent is smaller than the children
        i = 1;
        adj_minheap(i);
        return minimum;
    }

    int top() {
        if (heap.size() < 2) {
            return -1;
        } else {
            return heap[1];
        }
    }

    void heapify(const vector<int>& arr) {
        if (heap.size() != 1) {
            // reinitialize the min heap
            heap.clear();
            heap.push_back(0);
        }
        for (int i = 0; i < arr.size(); ++i) {
            heap.push_back(arr[i]);
        }
        // starting from the node that has children
        int cur = (heap.size()-1)/2;
        while (cur>0) {
            adj_minheap(cur);
            cur--;
        }

    }
    void adj_minheap(int i) {
        while (i*2 < heap.size()) {
            // non-leaf node i
            if (i*2+1 < heap.size() && heap[i*2+1] < heap[i*2] &&
                heap[i] > heap[i*2+1]) {
                // swap the parent with the right child
                int tmp = heap[i*2+1];
                heap[i*2+1] = heap[i];
                heap[i] = tmp;
                i = i*2+1;
            } else if (heap[i] > heap[i*2]) {
                // swap the parent with the left child
                int tmp = heap[i*2];
                heap[i*2] = heap[i];
                heap[i] = tmp;
                i = i*2;
            } else {
                // min heap is adjusted
                break;
            }
        }
    }
};
