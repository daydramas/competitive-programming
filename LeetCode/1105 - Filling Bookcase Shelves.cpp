class Solution {
public:
    
    int n, m, dp[1000][1000];
    vector<vector<int>> a;
    
    template<class T> bool ckmin(T& x, const T& y) {
        return (x > y ? x = y, 1 : 0);
    }
    template<class T> bool ckmax(T& x, const T& y) {
        return (x < y ? x = y, 1 : 0);
    }
    int DP(int i, int j) {
        if (i > j)
            return 0;
        if (dp[i][j] != (0x3F3F3F3F))
            return dp[i][j];
        int w = 0, h = 0;
        dp[i][j] = 0x3F3F3F3F;
        for (int k = i; k <= j; ++k) {
            w += a[k][0];
            ckmax(h, a[k][1]);
            if (w <= m) {
                ckmin(dp[i][j], DP(k + 1, j) + h);
            } else {
                break;
            }
        }
        return dp[i][j];
    }
    int minHeightShelves(vector<vector<int>>& _a, int _m) {
        n = _a.size();
        m = _m;
        a = _a;
        memset(dp, 0x3F, sizeof(dp));
        return DP(0, n - 1);
    }
};