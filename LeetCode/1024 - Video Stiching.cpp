class Solution {
public:
    int videoStitching(vector<vector<int>>& a, int T) {
        int n = a.size();
        vector<int> dp(T + 1, 200);
        
        dp[0] = 0;
        for (int i = 1; i <= T; ++i)
            for (int j = 0; j < i; ++j) 
                for (int k = 0; k < n; ++k)
                    if (a[k][0] <= j && a[k][1] >= i)
                        dp[i] = min(dp[i], dp[j] + 1);
        return (dp[T] == 200 ? -1 : dp[T]);
    }
};