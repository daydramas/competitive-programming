class Solution {
public:
    bool ckmax(int& a, const int& b) {
        return (a < b ? a = b, 1 : 0);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n + 1][2][2], a[n + 1];
        for (int i = 1; i <= n; ++i)
            a[i] = prices[i - 1];
        memset(dp, -0x3F, sizeof(dp));
        dp[0][0][0] = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < 2; ++j)
                for (int k = 0; k < 2; ++k) {
                    ckmax(dp[i + 1][j][k], dp[i][j][k]);
                    if (k) {
                        ckmax(dp[i + 1][j][0], dp[i][j][k]);
                    } else {
                        if (!j)
                            ckmax(dp[i + 1][1][k], dp[i][j][k] - a[i + 1]);
                        else
                            ckmax(dp[i + 1][0][1], dp[i][j][k] + a[i + 1]);
                    }
                }
        int ans = 0;
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
                ckmax(ans, dp[n][j][k]);
        return ans;
    }   
};