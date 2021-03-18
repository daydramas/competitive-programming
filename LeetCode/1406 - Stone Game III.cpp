class Solution {
public:
    
    string stoneGameIII(vector<int>& a) {
        #define ckmax(a, b) a = max(a, b)
        int n = a.size();
        int dp[n + 1];
        memset(dp, -0x3F, sizeof(dp));
        dp[n] = 0;
        for (int i = n; i > 0; --i) {
            if (i >= 3) {
                ckmax(dp[i - 3],a[i - 1] + a[i - 2] + a[i - 3] - dp[i]);
            }
            if (i >= 2) {
                ckmax(dp[i - 2], + a[i - 1] + a[i - 2] - dp[i]);
            }
            if (i >= 1) {
                ckmax(dp[i - 1], a[i - 1] - dp[i]);
            }
        }
        if (dp[0] == 0)
            return "Tie";
        if (dp[0] < 0)
            return "Bob";
        else return "Alice";
    }
};