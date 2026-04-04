class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i_l = 0;
        int i_r = heights.size() - 1;
        int maxarea = 0;

        while (i_l < i_r) {
            int area = min(heights[i_l], heights[i_r]) * (i_r-i_l);
            if (area > maxarea) {
                maxarea = area;
            }
            if (heights[i_l] < heights[i_r]) {
                i_l++;
            } else {
                i_r--;
            }
        }
        return maxarea;
    }
};
