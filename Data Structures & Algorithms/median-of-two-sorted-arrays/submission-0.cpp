class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // binary search
        // apply binary search in vector num2,
        // calculate the total number of elements m+n, and its half (m+n)/2
        // say we m2 elements in num2, we should have (m+n)/2 - m2 elements in num1
        // end condition:
        // [m2] should be smaller than all the rest elements in num1
        // [m1] should be smaller than all the rest elements in num2
        // is m+n odd or even?
        // odd, the median number is of index (m+n)/2+1
        // even, the median number is between indices (m+n)/2 and (m+n)/2+1
        int first_half = (nums1.size()+nums2.size()+1)/2;
        bool even = (nums1.size()+nums2.size())%2 == 0;
        vector<int> &short_v = nums1, &long_v = nums2;
        if (nums1.size() > nums2.size()) {
            swap(short_v, long_v);
        }
        int l = 0;
        int r = short_v.size();
        while (l <= r) {
            int m_s = (l+r)/2;
            int m_l = first_half - m_s;
            int s_left, s_right, l_left, l_right;
            s_left = (m_s <= 0) ? INT_MIN : short_v[m_s-1];
            s_right = (m_s >= short_v.size())? INT_MAX : short_v[m_s];
            l_left = (m_l <= 0) ? INT_MIN : long_v[m_l-1];
            l_right = (m_l >= long_v.size())? INT_MAX : long_v[m_l];

            if (s_left <= l_right && l_left <= s_right) {
                if (even)  {
                    return ((double)max(s_left, l_left) + min(s_right, l_right))/2.0;
                } else {
                    return max(s_left, l_left);
                }
            } else if (s_left > l_right) {
                r = m_s - 1;
            } else {
                l = m_s + 1;
            }
        }
        return -1;
        
    }
};
