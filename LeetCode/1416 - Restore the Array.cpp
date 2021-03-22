`class Solution {
public:
    int numberOfArrays(string s, int k) {
        int n = s.length();
        int m = to_string(k).length();
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 0; i < n; ++i)
            if (dp[i] && s[i] != '0')
                for (int l = 1; l <= m && l + i <= n; ++l) {
                    long long t = stoll(s.substr(i, l));
                    if (t >= 1 && t <= k)
                        dp[i + l] = (dp[i + l] + dp[i]) % 1000000007;
                }
        return dp[n];
    }
};