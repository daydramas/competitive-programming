(n, m) = map(int, input().split())
ans = 0
pw = [1]
for i in range (m):
	pw.append(pw[-1] * 2)
for i in range (n):
	a = [ int(x) for x in map(int, input().split()) ]
	dp = [ [0 for i in range (m)] for i in range (m) ]
	for i in range (m):
		dp[i][i] = pw[m] * a[i]
	for s in range (1, m):
		for i in range (m):
			j = i + s
			if j >= m:
				break
			dp[i][j] = max(dp[i][j - 1] + pw[m - s] * a[j], dp[i + 1][j] + pw[m - s] * a[i])
	ans += dp[0][m - 1]
print ans
