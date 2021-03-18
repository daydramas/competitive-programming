
void add(int* a, int b) {
    *a = (*a + b) % 1000000007;
}
int dieSimulator(int n, int* a, int _){
    int dp[n][6][16];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < 6; ++i)
        dp[0][i][1] = 1;
    for (int k = 1; k < n; ++k) {
        for (int i = 0; i < 6; ++i) {
            for (int j = 2; j <= a[i]; ++j)
                add(&dp[k][i][j], dp[k - 1][i][j - 1]);
            for (int j = 0; j < 6; ++j)
                if (j != i)
                    for (int l = 1; l <= a[j]; ++l)
                        add(&dp[k][i][1], dp[k - 1][j][l]);
        }
    }
    int ans = 0;
    for (int i = 0; i < 6; ++i)
        for (int j = 1; j <= a[i]; ++j)
            add(&ans, dp[n - 1][i][j]);
    return ans;
}