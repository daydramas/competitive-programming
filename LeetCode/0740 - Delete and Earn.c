

int deleteAndEarn(int* a, int n){
    int c[20005], dp[20005];
    memset(c, 0, sizeof(c));
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i)
        ++c[a[i]];
    dp[0] = 0;
    dp[1] = c[1];
    for (int i = 2; i <= 20001; ++i) {
        dp[i] = dp[i - 2] + c[i] * i;
        if (dp[i - 1] > dp[i])
            dp[i] = dp[i - 1];
    }
    return dp[20001];
}