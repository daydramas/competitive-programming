class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        int dp[n]; bool p[n][n];
        memset(dp, 69, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            p[i][i] = 1;
            if (i)
                p[i][i - 1] = 1;
        }
        for (int i = n - 1; i >= 0; --i)
            for (int j = i + 1; j < n; ++j)
                if (s[i] == s[j] && p[i + 1][j - 1])
                    p[i][j] = 1;
                else
                    p[i][j] = 0;
        for (int i = 0; i < n; ++i)
            if (p[0][i])
                dp[i] = 0;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (p[i + 1][j])
                    dp[j] = min(dp[j], dp[i] + 1);
        return dp[n - 1];
    }
};