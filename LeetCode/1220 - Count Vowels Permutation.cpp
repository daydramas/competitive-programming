class Solution {
public:
    void add(int& a, const int& b) {
        a = (a + b) % 1000000007;
    }
    int countVowelPermutation(int n) {
        int dp[n][5];
        memset(dp, 0, sizeof(dp));
        vector<int> pre[5] = {{1, 4, 2}, {0, 2}, {1, 3}, {2}, {3, 2}};
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < 5; ++j)
                if (!i)
                    dp[i][j] = 1;
                else
                    for (int k : pre[j])
                        add(dp[i][j], dp[i - 1][k]);
        int ans = 0;
        for (int i = 0; i < 5; ++i)
            add(ans, dp[n - 1][i]);
        return ans;
    }
};