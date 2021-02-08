# AtCoder Frog 1

[Problem Link](https://atcoder.jp/contests/dp/tasks/dp_a)

[Solution Link](/Solutions/AtCoder/DP/A.cpp)

Let `dp[i]` be the minimum cost such that the last jump is at position `i`. 

Then, we have two transitions since we can move either from `i` to `i+1` or `i+2`
- `dp[i+1] = min(dp[i+1], dp[i] + abs(h[i+1]-h[i]))`
- `dp[i+2] = min(dp[i+2], dp[i] + abs(h[i+2]-h[i]))`

Our answer is `dp[N]`.