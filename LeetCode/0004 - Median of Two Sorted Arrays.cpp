class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        vector<int> c;
        int i = 0, j = 0;
        while (i < n || j < m) {
            if (i == n) {
                c.emplace_back(b[j++]);
            } else if (j == m) {
                c.emplace_back(a[i++]);
            } else if (a[i] < b[j]) {
                c.emplace_back(a[i++]);
            } else {
                c.emplace_back(b[j++]);
            }
        }
        if ((n + m) & 1) {
            return c[c.size() / 2];
        } else {
            return 1.0 * (c[c.size() / 2 - 1] + c[c.size() / 2]) / 2;
        }
    }
};