int compare(const void* a, const void* b) {
    const int *_a = *(const int **)a;
    const int *_b = *(const int **)b;
    if (_a[0] == _b[0])
        return _a[1] - _b[1];
    return _a[0] - _b[0];
}

int maxEnvelopes(int** a, int n, int* m) {
    int dp[n], ans = 0;
    memset(dp, 0, sizeof(dp));
    
    qsort(a, n, sizeof(int*), compare);
    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
        for (int j = 0; j < i; ++j)
            if (a[i][0] > a[j][0] && a[i][1] > a[j][1]
               && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;
        if (dp[i] > ans)
            ans = dp[i];
    }
    return ans;
}