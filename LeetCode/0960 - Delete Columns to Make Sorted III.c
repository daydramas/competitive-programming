
int compare(const void* a, const void* b) {
    const char *_a = *(const char **)a;
    const char *_b = *(const char **)b;
    const int m = strlen(_a);
    for (int i = 0; i < m; ++i)
        if (_a[i] != _b[i])
            return _a[i] - _b[i];
    return 0;
}

int minDeletionSize(char ** a, int n){
    int m = strlen(a[0]);
    int dp[m], ans = 0;
    memset(dp, 0, sizeof(dp));
    
    qsort(a, n, sizeof(char*), compare);
    for (int i = 0; i < m; ++i) {
        dp[i] = 1;
        for (int j = 0; j < i; ++j) {
            bool okay = true;
            for (int k = 0; k < n; ++k)
                if (a[k][j] > a[k][i])
                    okay = false;
            if (okay && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;
        }
        if (dp[i] > ans)
            ans = dp[i];
    } 
    return m - ans;
}