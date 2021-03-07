

int lengthOfLIS(int* a, int n){
    int dp[n], ans = 0;
    memset(dp, 0, sizeof(dp));
    
    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
        for (int j = 0; j < i; ++j)
            if (a[i] > a[j] && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;
        if (dp[i] > ans)
            ans = dp[i];
    }
    return ans;
}