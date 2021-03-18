class Solution {
public:
    void ckmax(int& a, const int& b) {
        a = max(a, b);
    }
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();

        int dp[n][1005];
        memset(dp, 0, sizeof(dp));       
        auto get = [&](int i, int j) -> int {
            return A[i] - A[j] + 500;  
        };
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                ckmax(dp[j][get(j, i)], 2);
        int ans = 0;
        for (int j = 0; j < n; ++j)
            for (int i = 0; i < j; ++i) {
                ckmax(dp[j][get(j, i)], dp[i][get(j, i)] + 1);
                ckmax(ans, dp[j][get(j, i)]);
            }
        return ans;
        
    }
};