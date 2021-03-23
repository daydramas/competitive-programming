class Solution {
public:
    void ckmin(int8_t &a, const int8_t& b) {
        if (a == -1)
            a = b;
        else
            a = min(a, b);
    }
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int8_t dp[1 << n][n];
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; ++i)
            dp[1 << i][i] = 0;
        for (int i = 0; i < (1 << n); ++i)
            for (int _ = 0; _ < 2; ++_)
                for (int j = 0; j < n; ++j)
                    if (dp[i][j] != -1)
                        if (i & (1 << j)) {
                            for (int k : graph[j])
                                ckmin(dp[i | (1 << k)][k], dp[i][j] + 1);
                        }
        int8_t ans = -1;
        for (int i = 0; i < n; ++i)
            ckmin(ans, dp[(1 << n) - 1][i]);
        return ans;
    }
};