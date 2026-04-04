class MinStack {
private:
    stack<int> minst;
    stack<int> st;
public:

    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if (minst.empty()) {
            minst.push(val);
        } else if (val <= minst.top()) {
            minst.push(val);
        }
    }
    
    void pop() {
        if (st.top() == minst.top()) {
            minst.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};
