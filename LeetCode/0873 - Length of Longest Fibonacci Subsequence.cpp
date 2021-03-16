class Solution {
public:
    int lenLongestFibSubseq(vector<int>& a) {
        unordered_set<int> us(begin(a), end(a));
        int n = a.size();
        int x, y, z, c, ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j) {
                x = a[i], y = a[j], z = x + y, c = 2;
                while (us.find(z) != us.end()) {
                    c++;
                    x = y, y = z, z = x + y;
                } 
                ans = max(ans, c);
            }
        return (ans <= 2 ? 0 : ans);
    }
};