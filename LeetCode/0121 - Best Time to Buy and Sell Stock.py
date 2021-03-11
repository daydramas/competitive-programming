class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        prefix = [10001 for i in range(n + 1)]
        suffix = [-1 for i in range(n + 1)]
        for i in range(n):
            prefix[i + 1] = min(prefix[i], prices[i])
        for i in reversed(range(n)):
            suffix[i] = max(suffix[i + 1], prices[i])
        ans = 0
        for i in range(n):
            ans = max(ans, -1 * prefix[i] + suffix[i])
        return ans