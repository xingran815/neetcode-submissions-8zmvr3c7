class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // have two stack data structure
        // stack left and stack right to store the smaller indices of
        // the current height
        // calculate the weight according to the left and right stack
        // iterate
        // width = s_right - s_left - 1
        stack<int> s_left, s_right;
        int max_rec = 0;
        for (int i = 0; i < heights.size(); ++i) {
            if (i == 0) {
                s_left.push(-1);
            }
            if (i == heights.size() - 1) {
                s_right.push(heights.size());
            }
            for (int left = i - 1; left >= 0; --left) {
                if (heights[left] < heights[i]) {
                    s_left.push(left);
                    break;
                } else if (left == 0) {
                    s_left.push(-1);
                }
            }
            for (int right = i + 1; right < heights.size(); ++right) {
                if (heights[right] < heights[i]) {
                    s_right.push(right);
                    break;
                } else if (right == heights.size()-1) {
                    s_right.push(heights.size());
                }
            }
            cout << "left index: " << s_left.top() << ", right index: " <<
                s_right.top() << ", width: " << 
                s_right.top()-s_left.top()-1 << endl;
            int rec = heights[i] * (s_right.top()-s_left.top()-1);
            if (rec > max_rec) {
                max_rec = rec;
            }
        }
        return max_rec;
        
    }
};
