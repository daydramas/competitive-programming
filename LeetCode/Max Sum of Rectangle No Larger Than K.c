

int maxSumSubmatrix(int** a, int n, int *_m, int _k) {
    int m = *_m;
    int b[n + 1][m + 1];
    memset(b, 0, sizeof(b));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            b[i][j] = a[i - 1][j - 1] + b[i - 1][j] + b[i][j - 1]
                    - b[i - 1][j - 1];
        }
    int ans = -1e9;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            for (int k = i; k <= n; ++k)
                for (int l = j; l <= m; ++l) {
                    int sum = b[k][l] - b[k][j - 1] - b[i - 1][l] 
                            + b[i - 1][j - 1];
                    if (sum <= _k && sum > ans)
                        ans = sum;
                }
    return ans;
            

}