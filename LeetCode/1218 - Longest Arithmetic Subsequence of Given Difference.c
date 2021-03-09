
void ckmax(int *a, int b) {
    if (*a < b)
        *a = b;
}
int longestSubsequence(int* a, int n, int dif){
    int dp[20005], ans = 0, _a;
    for (int i = 0; i < n; ++i)
        a[i] += 10000;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i) {
        _a = a[i] - dif;
        if (_a >= 0 && _a <= 20000)
            ckmax(&dp[a[i]], dp[_a] + 1);
        else
            ckmax(&dp[a[i]], 1);
        ckmax(&ans, dp[a[i]]);
    }
    return ans;
}