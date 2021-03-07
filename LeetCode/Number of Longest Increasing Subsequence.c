

int findNumberOfLIS(int* a, int n){
    int dp[n], dp2[n], ans = 0, ans2 = 0;
    memset(dp, 0, sizeof(dp));
    memset(dp2, 0, sizeof(dp2));
    
    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
        for (int j = 0; j < i; ++j)
            if (a[i] > a[j] && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;
        if (dp[i] > ans)
            ans = dp[i];
    }
    for (int i = 0; i < n; ++i) {
        if (dp[i] == 1)
            dp2[i] = 1;
        else
            for (int j = 0; j < i; ++j)
                if (a[i] > a[j] && dp[j] + 1 == dp[i])
                    dp2[i] += dp2[j];
        if (dp[i] == ans)
            ans2 += dp2[i];
    }
    return ans2;
}