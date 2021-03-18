class Solution {
public:
    int maxJumps(vector<int>& a, int d) {
        int n = a.size();
        int b[n];
        bool ok[n][n];
        for (int i = 0; i < n; ++i) {
            ok[i][i] = 1;
            for (int j = i + 1; j < n; ++j) {
                ok[i][j] = ok[i][j - 1];
                if (a[j] >= a[i] || j - i > d)
                    ok[i][j] = 0;
            }
            for (int j = i - 1; j >= 0; --j) {
                ok[i][j] = ok[i][j + 1];
                if (a[j] >= a[i] || i - j > d)
                    ok[i][j] = 0;
            }
        }
        for (int i = 0; i < n; ++i)
            b[i] = i;
        sort(b, b + n, [&](int i, int j) -> bool {
            return a[i] < a[j];
        });
        int dp[n], ans = 0;
        for (int _i = 0, i; _i < n; ++_i) {
            i = b[_i], dp[i] = 1;
            for (int _j = 0, j; _j < _i; ++_j) {
                j = b[_j];
                if (ok[i][j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
        
    }
};