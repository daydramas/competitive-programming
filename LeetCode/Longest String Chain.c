
bool predecessor(char *a, char *b) {
    int x = strlen(a);
    int y = strlen(b);
    if (x + 1 != y)
        return false;
    for (int z = 0, i; z < y; ++z) {
        bool okay = true; i = 0;
        for (int j = 0; j < z; ++j, ++i)
            if (b[j] != a[i])
                okay = false;
        for (int j = z + 1; j < y; ++j, ++i)
            if (b[j] != a[i])
                okay = false;
        if (okay)
            return true;
    }
    return false;
}
int compare(const void* a, const void* b) {
    const char *_a = *(const char **)a;
    const char *_b = *(const char **)b;
    return strlen(_a) - strlen(_b);
}
int longestStrChain(char **a, int n){
    qsort(a, n, sizeof(char*), compare);
    int dp[n + 1], ans = 0;
    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
        for (int j = 0; j < i; ++j)
            if (predecessor(a[j], a[i]) && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        if (dp[i] > ans)
            ans = dp[i];
    }
    return ans;
}