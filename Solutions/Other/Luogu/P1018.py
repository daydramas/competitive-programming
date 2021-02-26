n, k = map(int, input().split())
s = input()

k += 1

dp = [[-1e9 for j in range(k + 1)] for i in range(n + 1)]
dp[0][0] = 1
for i in range(1, n + 1):
	for j in range(1, k + 1):
		for l in range(1, i + 1):
			if dp[i - l][j - 1] == -1e9:
				continue
			dp[i][j] = max(dp[i][j], dp[i - l][j-1] * int(s[(i - l) : i]))
print(dp[n][k]) 