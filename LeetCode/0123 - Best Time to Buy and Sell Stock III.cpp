class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int a = -1e9, aa = 0, b = -1e9, bb = 0;
        for (const int& x : prices) {
            a = max(a, -x);
            aa = max(aa, a + x);
            b = max(b, aa - x);
            bb = max(bb, b + x);
        }
        return bb;
    }
};