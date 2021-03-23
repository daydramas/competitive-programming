class Solution {
public:
    void ckmin(int& a, const int& b) {
        a = min(a, b);
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int n, int m, int k) {
        int dp[n + 1][k + 1][m + 1];
        memset(dp, 69, sizeof(dp));
        if (houses[0]) {
            dp[1][1][houses[0]] = 0;
        } else {
            for (int i = 1; i <= m; ++i)
                dp[1][1][i] = cost[0][i - 1];
        }
        for (int i = 1; i <= m; i++)
        for (int i = 2; i <= n; ++i)
            for (int j = 1; j <= k; ++j) {
                if (houses[i - 1] == 0) {
                    for (int l = 1; l <= m; ++l)
                        for (int o = 1; o <= m; ++o) {
                            if (l == o) ckmin(dp[i][j][l], dp[i - 1][j][o] + cost[i - 1][l - 1]);
                            else ckmin(dp[i][j][l], dp[i - 1][j - 1][o] + cost[i - 1][l - 1]);
                        }
                } else {
                    int l = houses[i - 1];
                    for (int o = 1; o <= m; ++o) {
                        if (l == o) ckmin(dp[i][j][l], dp[i - 1][j][o]);
                        else ckmin(dp[i][j][l], dp[i - 1][j - 1][o]);
                    }
                }
            }
        int ans = 1e9;
        for (int i = 1; i <= m; ++i)
            ckmin(ans, dp[n][k][i]);
        return (ans == 1e9 ? -1 : ans);
    }
};