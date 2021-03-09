class Solution {
public:
    void add(int& a, const int& b) {
        a = (a + b) % 1000000007;
    }
    int numTilings(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(4, 0));
        dp[0][0] = 1;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < 4; ++j) {
                if (j & 1) {
                    add(dp[i + 1][1], dp[i][j]);
                    if (i + 2 <= n) add(dp[i + 2][0], dp[i][j]);
                } else if (j & 2) {
                    add(dp[i + 1][2], dp[i][j]);
                    if (i + 2 <= n) add(dp[i + 2][0], dp[i][j]);
                } else {
                    add(dp[i + 1][0], dp[i][j]);
                    add(dp[i + 1][1], dp[i][j]);
                    add(dp[i + 1][2], dp[i][j]);
                    if (i + 2 <= n) add(d p[i + 2][0], dp[i][j]);
                }
            }
        return dp[n][0];
    }
};