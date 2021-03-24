class Solution {
public:
    void up(int& a, const int& b) {
        a = max(a, b);
    }
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i)
            dp[i][i] = 1;
        for (int i = n - 1; i >= 0; --i)
            for (int j = i + 1; j < n; ++j) {
                up(dp[i][j], dp[i + 1][j]);
                up(dp[i][j], dp[i][j - 1]);
                if (s[i] == s[j])
                    up(dp[i][j], dp[i + 1][j - 1] + 2);
            }
        return dp[0][n - 1];
    }
};