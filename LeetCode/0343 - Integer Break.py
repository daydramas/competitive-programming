class Solution:
    def integerBreak(self, n: int) -> int:
        dp = [0 for i in range(n + 1)]
        dp[0] = 1
        for i in range(n):
            for j in range(1, n):
                if i + j <= n:
                    dp[i + j] = max(dp[i + j], dp[i] * j)
        return dp[n]