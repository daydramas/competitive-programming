
bool equal(char * a, char * b, int i, int l) {
    for (int j = 0; j < l; ++j, ++i)
        if (a[i] != b[j])
            return false;
    return true;
}
bool wordBreak(char * s, char ** a, int n){
    int m = strlen(s);
    int dp[m + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = true;
    for (int j = 0; j < m; ++j) {
        if (!dp[j]) continue;
        for (int i = 0, l; i < n; ++i) {
            l = strlen(a[i]);
            if (j + l <= m && equal(s, a[i], j, l))
                dp[j + l] = true;
        }
    }
    return dp[m];
                
}